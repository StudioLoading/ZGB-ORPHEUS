#include "Banks/SetAutoBank.h"

#include "BankManager.h"
#include "ZGBMain.h"
#include "Scroll.h"
#include "Sprite.h"
#include "SpriteManager.h"
#include "string.h"
#include "Palette.h"
#include "Print.h"

#include "custom_datas.h"
#include "UtilAnim.h"
#include "Dialog.h"


extern UINT8 flag_button_pushable;
extern UINT8 spawned_ball;
extern MACROMAP current_map;
extern CHOSEN_LANGUAGE chosen_language;
extern UINT8 anim_counter;
extern INT8 orpheus_hp;

UINT8 river_verse = 0u;

void spawn_death_animation(UINT16 spawnx, UINT16 spawny) BANKED;
void spawn_ball(UINT8 arg_type, UINT16 arg_spawnball_x, UINT16 arg_spawnball_y, UINT8 arg_direction) BANKED;
void draw_button(UINT16 x, UINT16 y, UINT8 t) BANKED;
UINT8 is_enemy(UINT8 arg_sprite_type) BANKED;
UINT8 is_boss(UINT8 arg_sprite_type) BANKED;
UINT8 is_level_on_boss() BANKED;
UINT8 is_level_with_button() BANKED;
UINT8 is_level_with_repushable_button() BANKED;
UINT8 is_level_with_enemies() BANKED;
UINT8 prepare_dialog(WHOSTALKING arg_whostalking) BANKED;
void invert_river_verse() BANKED;
void spawn_item(ITEM_TYPE arg_item_type, UINT16 arg_spawnx, UINT16 arg_spawny, UINT8 arg_hp_max) BANKED;
void level_common_anim() BANKED;

extern UINT8 prepare_dialog_en(WHOSTALKING arg_whostalking) BANKED;
extern UINT8 prepare_dialog_jp(WHOSTALKING arg_whostalking) BANKED;

void spawn_item(ITEM_TYPE arg_item_type, UINT16 arg_spawnx, UINT16 arg_spawny, UINT8 arg_hp_max) BANKED{
    if(arg_hp_max > 0 && orpheus_hp >= arg_hp_max){ return; }
    Sprite* s_item = SpriteManagerAdd(SpriteItem, arg_spawnx, arg_spawny);
    struct ItemInfo* item_data = (struct ItemInfo*) s_item->custom_data; 
    item_data->item_type = arg_item_type;
    item_data->i_configured = 1;
}

UINT8 prepare_dialog(WHOSTALKING arg_whostalking) BANKED{
    UINT8 result = 0;
    switch(chosen_language){
        case ENG: result = prepare_dialog_en(arg_whostalking); break;
        case JAP: result = prepare_dialog_jp(arg_whostalking); break;
    }
    return result;
}

void draw_button(UINT16 x, UINT16 y, UINT8 t) BANKED{
    set_bkg_tile_xy(x, y, t);
    set_bkg_tile_xy(x, y+1, t+1);
    set_bkg_tile_xy(x+1, y, t+2);
    set_bkg_tile_xy(x+1, y+1, t+3);
}

void spawn_death_animation(UINT16 spawnx, UINT16 spawny) BANKED{
	Sprite* s_death_skull = SpriteManagerAdd(SpriteDeath, spawnx, spawny);
	struct EnemyInfo* dskull_data = (struct EnemyInfo*)s_death_skull->custom_data;
	dskull_data->tile_collision = DEATH_SKULL;
	dskull_data->e_configured = 1u;
}

UINT8 is_level_with_button() BANKED{
	return current_map == BOSS_AEACUS || current_map == HADES_06 
        || current_map == HADES_09 || current_map == HADES_14
        || current_map == HADES_17 || current_map == HADES_19
        || current_map == HADES_21 || current_map == HADES_23;
}

UINT8 is_level_with_repushable_button() BANKED{
	return current_map == HADES_06 || current_map == HADES_14 || current_map == HADES_21 || is_level_on_boss();
}

UINT8 is_level_with_enemies() BANKED{
	return current_map == HADES_03 || current_map == HADES_04 
            || current_map == HADES_06 || current_map == HADES_07
            || current_map == HADES_10 || current_map == HADES_11
            || current_map == HADES_14 || current_map == HADES_16
            || current_map == HADES_20 || current_map == HADES_21
            || current_map == HADES_26;
}

UINT8 is_level_on_boss() BANKED{
    UINT8 result = 0u;
    switch(current_map){
        case BOSS_CHARON:
        case BOSS_CERBERUS:
        case BOSS_MINOS:
        case BOSS_AEACUS:
        case BOSS_HADES:
        case HADES_26:
            result = 1u;
        break;
    }
    return result;
}

void spawn_ball(UINT8 arg_type, UINT16 arg_spawnball_x, UINT16 arg_spawnball_y, UINT8 arg_direction) BANKED{
	if(spawned_ball == 0u || is_level_on_boss()){
		flag_button_pushable = 0u;
		Sprite* s_ball = SpriteManagerAdd(arg_type, arg_spawnball_x, arg_spawnball_y);
		struct EnemyInfo* ball_data = (struct EnemyInfo*) s_ball->custom_data;
		switch(arg_direction){
            case 0: ball_data->e_state = MOVE_TO_SAVED_ORPHEUS; break; 
			case J_UP: ball_data->vx = 0; ball_data->vy = -1; break;
			case J_DOWN: ball_data->vx = 0; ball_data->vy = 1; break;
			case J_LEFT: ball_data->vx = -1; ball_data->vy = 0; break;
			case J_RIGHT: ball_data->vx = 1; ball_data->vy = 0; break;
            case (J_DOWN + J_LEFT):
                ball_data->vy = 1;
                ball_data->vx = -1;
            break;
            case (J_DOWN + J_RIGHT):
                ball_data->vy = 1;
                ball_data->vx = 1;
            break;
            case (J_DOWN + J_DOWN + J_RIGHT):
                ball_data->vy = 2;
                ball_data->vx = 1;
            break;
            case (J_DOWN + J_DOWN + J_LEFT):
                ball_data->vy = 2;
                ball_data->vx = -1;
            break;
		}
		ball_data->e_configured = 1;
	}
}

UINT8 is_enemy(UINT8 arg_sprite_type) BANKED{
    UINT8 result = 0u;
    switch(arg_sprite_type){
        case SpriteSkeleton:
        case SpriteSkeletonshield:
        case SpriteSkeletoncerberus:
        case SpriteLostsoul:
        case SpriteInfernalimp:
        case SpriteImpminos:
        case SpriteOoze:
        case SpriteSentinel:
        case SpriteSiren:
        case SpriteShadow:
        case SpriteBanshee:
        case SpriteTartarus:
        case SpriteMagma:
        case SpriteFrost:
        case SpriteSerpent:
        case SpriteWyrmling:
        case SpriteDevourer:
        case SpriteRevenant:
        case SpriteMinion:
        case SpriteMinosscale:
        case SpriteAeacusbody:
        case SpriteAeacusblade:
        case SpriteRadamanthus:
        case SpriteBlade:
            result = 1u;
        break;
    }
    return result;
}

UINT8 is_boss(UINT8 arg_sprite_type) BANKED{
    UINT8 result = 0u;
    switch(arg_sprite_type){
        case SpriteCerberushead:
        case SpriteMinosscale:
        case SpriteAeacusbody:
        case SpriteRadamanthus:
            result = 1u;
        break;
    }
    return result;
}

void invert_river_verse() BANKED{
	if(river_verse == 0){
		river_verse = 1;
	}else{
		river_verse = 0;
	}
}

void level_common_anim() BANKED{
    anim_counter++;
    if(anim_counter >= ANIM_COUNTER_MAX){
        anim_counter = 0u;
    }
    //ANIMS FIRE
    if(current_map > TUTORIAL && !is_level_on_boss()){
        switch(anim_counter){
            case 0u: AnimFire_0();
            break;
            case 8u: AnimFire_1();
            break;
            case 16u: AnimFire_2();
            break;
            case 24u: AnimFire_3();
            break;
        }
    }
    //ANIMS RIVER
		if(current_map >= HADES_06 && !is_level_on_boss()){
			if(river_verse == 0){//to the left
				switch(anim_counter){
					case 0u: Anim_Water_0(); break;
					case 4u: Anim_Water_1(); break;
					case 8u: Anim_Water_2(); break;
					case 12u: Anim_Water_3(); break;
					case 16u: Anim_Water_4(); break;
					case 20u: Anim_Water_5(); break;
					case 24u: Anim_Water_6(); break;
					case 28u: Anim_Water_7(); break;
				}
			}else{
				switch(anim_counter){                    
					case 0u: Anim_Water_0(); break;
					case 4u: Anim_Water_7(); break;
					case 8u: Anim_Water_6(); break;
					case 12u: Anim_Water_5(); break;
					case 16u: Anim_Water_4(); break;
					case 20u: Anim_Water_3(); break;
					case 24u: Anim_Water_2(); break;
					case 28u: Anim_Water_1(); break;
				}
			}
		}
}
