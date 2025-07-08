#include "Banks/SetAutoBank.h"

#include "BankManager.h"
#include "ZGBMain.h"
#include "Music.h"
#include "Palette.h"
#include "Scroll.h"
#include "Sprite.h"
#include "SpriteManager.h"
#include "string.h"
#include "Print.h"

#include "custom_datas.h"
#include "Dialog.h"
#include "UtilAnim.h"

#define ANIM_COUNTER_MAX 84
IMPORT_MAP(maphades005);
IMPORT_MAP(hudmap);
//IMPORT_TILES(font);
DECLARE_MUSIC(battle);


const UINT8 coll_t_hades005[] = {1,3,4,5,9,10,11,13,14,17,18,19,20,66,
75,76,
//here the hit tiles
113, 114, 115, 120,
//prev
6,7,8,2,
//next
88,90,92,94,96,98,100,102,104,
0};
const UINT8 coll_s_hades005[] = {0};

Sprite* s_charon = 0;
UINT16 end_demo_counter = 600u;
UINT8 boss_intro = 0u;//0 init; 1 make Orpheus move up; 2 stop Orpheus and show a cutscene; 3 play; 4 boss dead

extern UINT8 dialog_block_interact;
extern UINT8 in_dialog;
extern UINT8 init_block_button;
extern Sprite* s_orpheus;
extern UINT16 orpheus_spawnx;
extern UINT16 orpheus_spawny;
extern UINT8 tutorial_go;
extern UINT8 current_map;
extern UINT8 orpheus_haskey;
extern MACROMAP max_map;
extern MACROMAP solved_map;
extern UINT16 idle_countdown;
extern UINT8 area_enemy_counter;
extern UINT8 anim_counter;
extern Sprite* s_charon_boat;
extern Sprite* s_charon_hand_left;
extern Sprite* s_charon_hand_right;
extern INT8 a_walk_counter_y;
extern UINT8 death_countdown;

extern void e_configure(Sprite* s_enemy, UINT8 sprite_type) BANKED;
extern void level_common_start() BANKED;
extern void level_common_update_play() BANKED;
extern void init_write_dialog(UINT8 nlines) BANKED;
extern void write_dialog() BANKED;
extern UINT8 prepare_dialog(WHOSTALKING arg_whostalking) BANKED;
extern void press_release_button(UINT16 x, UINT16 y, UINT8 t) BANKED;
extern void spawn_death_animation(UINT16 spawnx, UINT16 spawny) BANKED;

void START() {
	level_common_start();
	//SPRITES
		s_orpheus = SpriteManagerAdd(SpriteOrpheus, orpheus_spawnx, orpheus_spawny);
		if(solved_map < current_map){
			switch(current_map){
				case BOSS_CHARON:{
					area_enemy_counter = 1;
				}break;
			}
		}
	//INITSCROLL & BOSS SPRITES
		switch(current_map){
			case BOSS_CHARON: 
				InitScroll(BANK(maphades005), &maphades005, coll_t_hades005, coll_s_hades005);
				s_charon = SpriteManagerAdd(SpriteCharon, ((UINT16) 11u << 3), ((UINT16) 5u << 3));
				Sprite* s_heart = SpriteManagerAdd(SpriteItem, ((UINT16) 16u << 3), ((UINT16) 14u << 3) - 3u);
				struct ItemInfo* heart_data = (struct ItemInfo*) s_heart->custom_data;
				heart_data->item_type = HEART;
				heart_data->i_configured = 1u;
			break;
		}
	//HUD
        //INIT_FONT(font, PRINT_WIN);
        INIT_HUD(hudmap);
	//VARS
		PlayMusic(battle, 1);
	//PER STAGE
		if(boss_intro == 0){
			boss_intro = 1;
			a_walk_counter_y = -52;
		}
}

void UPDATE() {
	if(current_map == BOSS_CHARON && a_walk_counter_y == 0 && boss_intro == 1){
		boss_intro = 2;
	}
	switch(boss_intro){
		case 2:{
			prepare_dialog(BOSS_CHARON_INTRO);
			SetState(StateCartel);
			boss_intro = 3;
		}break;
		case 0://on Orpheus death!
		case 3:
			level_common_update_play();
		break;
		case 4:	//DEATH COOLDOWN BEFORE CHANGING SCREEN
			if(death_countdown){
				death_countdown--;
				switch(death_countdown){
					case 100u:
						SpriteManagerRemoveSprite(s_charon_hand_left);
						SpriteManagerRemoveSprite(s_charon_hand_right);
					break;
					case 60u:
                        spawn_death_animation(s_charon->x + 4u, s_charon->y + 12u);
					break;
					case 50u:
						SpriteManagerRemoveSprite(s_charon);
					break;
					case 0u:{
						boss_intro = 0;//reset
						prepare_dialog(BOSS_CHARON_BEATED);
						SetState(StateCartel);
					}
				}
			}
		break;
	}
	//GHOSTS
	/*	if(current_map == HADES_THREE){
			if(idle_countdown < 10 && idle_countdown > 0){
				UINT16 ghost_spawnx = ((UINT16) 19u << 3);
				INT8 ghost_vx = -1;
				MirroMode ghost_mirror = NO_MIRROR;
				if(s_orpheus->x > scroll_target->x){
					ghost_spawnx = ((UINT16) 1u << 3);
					ghost_vx = 1;
					ghost_mirror = V_MIRROR;
				}
				Sprite* s_ghost = SpriteManagerAdd(SpriteGhost, ghost_spawnx, s_orpheus->y + 4u);
				struct EnemyInfo* ghost_data = (struct EnemyInfo*) s_ghost->custom_data;
				ghost_data->vx = ghost_vx;
				s_ghost->mirror = ghost_mirror;
				idle_countdown = 0;
			}
		}
	*/
	//ANIMS
		anim_counter++;
		if(anim_counter >= (ANIM_COUNTER_MAX + 12)){
			anim_counter = 0u;
		}
		switch(anim_counter){
			case 0u: Anim_Charon_0(); break;
			case 12u: Anim_Charon_1(); break;
			case 24u: Anim_Charon_2(); break;
			case 36u: Anim_Charon_3(); break;
			case 48u: Anim_Charon_4(); break;
			case 60u: Anim_Charon_5(); break;
			case 72u: Anim_Charon_6(); break;
			case 84u: Anim_Charon_7(); break;
		}
}
