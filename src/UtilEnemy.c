#include "Banks/SetAutoBank.h"

#include "SGB.h"
#include "BankManager.h"
#include "ZGBMain.h"
#include "Keys.h"
#include "Palette.h"
#include "Scroll.h"
#include "Sprite.h"
#include "SpriteManager.h"

#include "custom_datas.h"

#define TURN_CLOCKWISE 1
#define TURN_COUNTERCLOCKWISE 2
#define TURN_OPPOSITE 3

extern Sprite* s_orpheus;
extern UINT8 orpheus_attack_cooldown;
extern SONG song_selection;
extern MACROMAP current_map;
extern UINT8 area_enemy_counter;
extern UINT8 in_dialog;

extern void skeleton_update_anim(Sprite* s_enemy, SPRITE_STATES new_state) BANKED;
extern void skeletonshield_update_anim(Sprite* s_enemy, SPRITE_STATES new_state) BANKED;
extern void dog_update_anim(Sprite* s_enemy, SPRITE_STATES new_state) BANKED;
extern void infernalimp_update_anim(Sprite* s_enemy, SPRITE_STATES new_state) BANKED;
extern void lostsoul_update_anim(Sprite* s_enemy, SPRITE_STATES new_state) BANKED;
extern void tartarus_update_anim(Sprite* s_enemy, SPRITE_STATES new_state) BANKED;
extern void ooze_update_anim(Sprite* s_enemy, SPRITE_STATES new_state) BANKED;
extern void sentinel_update_anim(Sprite* s_enemy, SPRITE_STATES new_state) BANKED;
extern void siren_update_anim(Sprite* s_enemy, SPRITE_STATES new_state) BANKED;
extern void shadow_update_anim(Sprite* s_enemy, SPRITE_STATES new_state) BANKED;


extern void spawn_death_animation(UINT16 spawnx, UINT16 spawny) BANKED;

void e_start(struct EnemyInfo* e_data, SPRITE_STATES new_state) BANKED;
void e_configure(Sprite* s_enemy, UINT8 sprite_type) BANKED;
void e_change_state(Sprite* s_enemy, SPRITE_STATES new_state, UINT8 sprite_type) BANKED;
void e_update_anim(Sprite* s_enemy, UINT8 sprite_type) BANKED;
void e_management(Sprite* s_enemy) BANKED;
void e_check_sprite_collision(Sprite* s_enemy) BANKED;
void e_check_tile_collision(Sprite* s_enemy, UINT8 e_sprite_type) BANKED;
void e_turn(Sprite* s_enemy, UINT8 e_sprite_type, UINT8 forced_wise) BANKED;
void e_destroy(Sprite* s_enemy, UINT8 e_sprite_type) BANKED;
void e_spawn_hitnote(INT16 arg_spawnx, UINT16 arg_spawny) BANKED;
UINT8 e_is_damaged_by_fire(UINT8 arg_tile, UINT8 arg_sprite_type) BANKED;
UINT8 e_is_damaged_by_pit(UINT8 arg_tile, UINT8 arg_sprite_type) BANKED;

extern void orpheus_change_state(Sprite* arg_s_orpheus, SPRITE_STATES arg_new_state) BANKED;


void e_start(struct EnemyInfo* e_data, SPRITE_STATES new_state) BANKED{
    e_data->e_state = new_state;
    e_data->frmskip_wait = e_data->frmskip;
    e_data->vx = 0;
    e_data->vy = 0;
    e_data->tile_collision = 0;
    e_data->wait = 0;
    e_data->e_configured = 0;
}

void e_configure(Sprite* s_enemy, UINT8 sprite_type) BANKED{
    e_update_anim(s_enemy, sprite_type);
    struct EnemyInfo* e_data = (struct EnemyInfo*) s_enemy->custom_data;
    e_data->e_configured = 1;
}

void e_update_anim(Sprite* s_enemy, UINT8 sprite_type) BANKED{
    struct EnemyInfo* e_data = (struct EnemyInfo*) s_enemy->custom_data;
    switch(sprite_type){
        case SpriteSkeleton:
            skeleton_update_anim(s_enemy, e_data->e_state);
        break;
        case SpriteSkeletonshield:
            skeletonshield_update_anim(s_enemy, e_data->e_state);
        break;
        case SpriteDog:
            dog_update_anim(s_enemy, e_data->e_state);
        break;
        case SpriteInfernalimp:
            infernalimp_update_anim(s_enemy, e_data->e_state);
        break;
        case SpriteLostsoul:
            lostsoul_update_anim(s_enemy, e_data->e_state);
        break;
        case SpriteTartarus:
            tartarus_update_anim(s_enemy, e_data->e_state);
        break;
        case SpriteOoze:
            ooze_update_anim(s_enemy, e_data->e_state);
        break;
        case SpriteSentinel:
            sentinel_update_anim(s_enemy, e_data->e_state);
        break;
        case SpriteSiren:
            siren_update_anim(s_enemy, e_data->e_state);
        break;
        case SpriteShadow:
            shadow_update_anim(s_enemy, e_data->e_state);
        break;
    }
}

void e_change_state(Sprite* s_enemy, SPRITE_STATES new_state, UINT8 e_sprite_type) BANKED{
    struct EnemyInfo* e_data = (struct EnemyInfo*) s_enemy->custom_data;
    if(e_data->e_state == new_state){
        return;
    }
    switch(new_state){
        case WALK_DOWN: e_data->wait = 0; e_data->vx = 0; e_data->vy = 1;break;
        case WALK_UP: e_data->wait = 0; e_data->vx = 0; e_data->vy = -1;break;
        case WALK_RIGHT: 
            if(e_sprite_type != SpriteLostsoul && e_sprite_type != SpriteOoze && e_sprite_type != SpriteSiren ){e_data->vy = 0;}
            e_data->wait = 0; e_data->vx = 1;  break;
        case WALK_LEFT: 
            if(e_sprite_type != SpriteLostsoul && e_sprite_type != SpriteOoze){
                e_data->vy = 0;
            }
            e_data->wait = 0;
            e_data->vx = -1;
        break;
        case IDLE_DOWN: case IDLE_UP: case IDLE_LEFT: case IDLE_RIGHT:
            switch(e_sprite_type){
                case SpriteSkeleton:
                case SpriteSkeletonshield:
                case SpriteSentinel:
                case SpriteDog:
                case SpriteShadow:
                    e_data->wait = 160u;
                break;
                case SpriteLostsoul:
                case SpriteOoze:
                case SpriteSiren:
                    e_data->wait = 120u;
                break;
                case SpriteTartarus:
                    e_data->wait = 40u;
                break;
                case SpriteInfernalimp:
                    e_data->wait = 80u;
                break;
            }
        break;
        case HIT:
            switch(e_sprite_type){
                case SpriteSkeleton:
                case SpriteSkeletonshield:
                case SpriteLostsoul:
                case SpriteInfernalimp:
                case SpriteTartarus:
                case SpriteOoze:
                case SpriteSentinel:
                case SpriteSiren:
                case SpriteShadow:
                    e_data->wait = orpheus_attack_cooldown;
                break;
            }
        break;
        case DIE:
            area_enemy_counter--;
            SpriteManagerRemoveSprite(s_enemy);
            spawn_death_animation(s_enemy->x, s_enemy->y);
        break;
        case PREATTACK_RIGHT:
        case PREATTACK_UP:
        case PREATTACK_LEFT:
        case PREATTACK_DOWN:
            switch(e_sprite_type){
                case SpriteDog: e_data->wait = 100; break;
                case SpriteSentinel: e_data->wait = 80; break;
            } 
        break;
        case ATTACK:
            switch(e_sprite_type){
                case SpriteLostsoul:
                    e_spawn_hitnote(s_enemy->x + 2, s_enemy->y + 4);
                break;
                case SpriteOoze:
                case SpriteSiren:
                    if(e_data->vx != 2 && e_data->vx != -2){
                        e_data->vx *= 2;
                    }
                break;
            }
            e_data->wait = 0;
        break;
    }
    switch(e_data->e_state){
        case GENERIC_IDLE: 
            if(s_orpheus->x > s_enemy->x){new_state = IDLE_RIGHT;}
            else{new_state = IDLE_LEFT;}
        break;
    }
    e_data->e_state = new_state;
    /*if(e_data->e_configured == 0 ||
        (e_data->wait && e_data->wait < 100 && e_data->tile_collision == 0) ||
        (e_data->tile_collision) ||
        (new_state == ATTACK)
    ){*/
        e_update_anim(s_enemy, e_sprite_type);
    //}
}

void e_management(Sprite* s_enemy) BANKED{
    if(in_dialog) return;
    struct EnemyInfo* e_data = (struct EnemyInfo*) s_enemy->custom_data;
    UINT8 e_sprite_type = s_enemy->type;
    if(e_data->e_state != WALK_DOWN && e_data->e_state != WALK_UP && 
        e_data->e_state != WALK_LEFT && e_data->e_state != WALK_RIGHT &&
        e_data->e_state != HIT && e_data->e_state != ATTACK){
        if(e_data->wait > 0){
            e_data->wait--;
        }else{
            e_turn(s_enemy, e_sprite_type, 0);
        }
    }
    if(e_data->e_state == HIT){
        // aumento velocità abbassando frameskip
            e_data->frmskip = 4u;
        //fix MIRROR for rounding animation
            if(s_enemy->anim_frame == 3){
                s_enemy->mirror = V_MIRROR;
            }else{s_enemy->mirror = NO_MIRROR;}
        //CALCULATE PUSH/PULL VX;VY, ENEMY AS ORIGIN OF AXIS
            UINT16 delta_x = 0;
            e_data->vx = 1;
            e_data->vy = 1;
            if(s_orpheus->x < s_enemy->x){
                e_data->vx = -1;
                delta_x = s_enemy->x - s_orpheus->x;
            }else{delta_x = s_orpheus->x - s_enemy->x;}
            UINT16 delta_y = 0;
            if(s_orpheus->y < s_enemy->y){
                e_data->vy = -1;
                delta_y = s_enemy->y - s_orpheus->y;
            }else{
                delta_y = s_orpheus->y - s_enemy->y;
            }
            if((delta_x << 1) < delta_y){
                e_data->vy = e_data->vy*2;
                e_data->vx = 0;
            }
            if((delta_y <<1) < delta_x){
                e_data->vx = e_data->vx*2;
                e_data->vy = 0;
            }
            switch(song_selection){
                case ATTRACT: break;
                case REPEL: 
                    e_data->vx = -e_data->vx;
                    e_data->vy = -e_data->vy;
                break;
                case SLEEP:
                    e_data->vx = 0;
                    e_data->vy = 0;
                break;
            }
            if(e_data->wait > 0){
                e_data->wait--;
            }else{
                e_change_state(s_enemy, GENERIC_WALK, e_sprite_type);
            }
    }else{
        e_data->wait++;//USING AS RANDOM TO CLOCKWISE TURNING
        //ripristino frameskip
        //e_data->frmskip = 12u;
        if(e_data->e_state == ATTACK){
            if(e_data->wait > 100){
                e_change_state(s_enemy, WALK_DOWN, s_enemy->type);
            }
        }
    }
    if(e_data->frmskip_wait > 0){
        e_data->frmskip_wait--;
    }else{
        e_data->frmskip_wait = e_data->frmskip;
        //CHANGE DIRECTION
            INT16 delta_y = (INT16)s_enemy->y - (INT16)s_orpheus->y; 
            INT16 delta_x = (INT16)s_enemy->x - (INT16)s_orpheus->x;
            switch (e_data->e_state){
                case WALK_LEFT:
                case WALK_RIGHT:
                    if(e_data->wait < 30){//check if Orpheus is over or above enemy
                        if(delta_y > 40){//enemy molto sotto orpheus
                            e_change_state(s_enemy, WALK_UP, e_sprite_type);
                        }else if(delta_y < -40){//enemy molto sopra orpheus
                            e_change_state(s_enemy, WALK_DOWN, e_sprite_type);
                        }
                    }
                break;
                case WALK_UP:
                case WALK_DOWN:
                    //if(e_data->wait < 30){//check if Orpheus is over or above enemy
                        if(delta_x > 40){//enemy molto a destra di orpheus
                            e_change_state(s_enemy, WALK_LEFT, e_sprite_type);
                        }else if(delta_x < -40){//enemy molto a sinistra di orpheus
                            e_change_state(s_enemy, WALK_RIGHT, e_sprite_type);
                        }
                    //}
                break;
                case IDLE_DOWN: case IDLE_LEFT: case IDLE_RIGHT: case IDLE_UP:
                    e_data->wait--;
                    if(e_data->wait == 0){
                        if(e_data->e_state == IDLE_DOWN) e_change_state(s_enemy, WALK_DOWN, s_enemy->type);
                        if(e_data->e_state == IDLE_LEFT) e_change_state(s_enemy, WALK_LEFT, s_enemy->type);
                        if(e_data->e_state == IDLE_RIGHT) e_change_state(s_enemy, WALK_RIGHT, s_enemy->type);
                        if(e_data->e_state == IDLE_UP) e_change_state(s_enemy, WALK_UP, s_enemy->type);
                        return;
                    }
                break;
            }
        //TRANSLATE SPRITE
            switch (e_data->e_state){
                case WALK_DOWN:
                case WALK_UP:
                case WALK_LEFT:
                case WALK_RIGHT:
                case HIT:{
                    UINT8 tile = GetScrollTile((THIS->x + 4) >> 3, (THIS->y+4) >> 3);
                    if(tile == 0){
                        tile = GetScrollTile((THIS->x + 12) >> 3, (THIS->y+12) >> 3); 
                    }
                    UINT8 is_against_fire = e_is_damaged_by_fire(tile, e_sprite_type);
                    UINT8 is_against_pit = e_is_damaged_by_pit(tile, e_sprite_type);
                    if(is_against_fire || is_against_pit){
                        if(e_data->e_state != HIT){
                            e_turn(s_enemy, e_sprite_type, 0);
                        }else{
                            e_destroy(s_enemy, e_sprite_type);
                        }
                    }
                    e_data->tile_collision = TranslateSprite(THIS, e_data->vx << delta_time, e_data->vy << delta_time);
                    if(e_data->tile_collision){
                        e_check_tile_collision(s_enemy, e_sprite_type);
                    }
                }
                case ATTACK:
                    if(s_enemy->type == SpriteOoze || s_enemy->type == SpriteSiren){
                        e_data->tile_collision = TranslateSprite(THIS, e_data->vx << delta_time, e_data->vy << delta_time);
                    }
                break;
            }
    }
    if(e_data->e_state != ATTACK){
        switch(s_enemy->type){
            case SpriteLostsoul:
            case SpriteOoze:
            case SpriteSiren:
                if(e_data->wait == 200){
                    e_change_state(s_enemy, ATTACK, s_enemy->type);
                }
            break;
        }
    }
}

UINT8 e_is_damaged_by_fire(UINT8 arg_tile, UINT8 arg_sprite_type) BANKED{
    UINT8 result = 0;
    if(arg_sprite_type == SpriteInfernalimp || arg_sprite_type == SpriteSentinel){
        result = 0;
    }else{
        result = arg_tile == 84u || arg_tile == 85u || arg_tile == 86u || arg_tile == 87u;
    }
    return result;
}

UINT8 e_is_damaged_by_pit(UINT8 arg_tile, UINT8 arg_sprite_type) BANKED{
    UINT8 result = 0u;
    if(arg_sprite_type == SpriteLostsoul || arg_sprite_type == SpriteOoze || arg_sprite_type == SpriteSiren){
        result = 0;
    }else{
        result = arg_tile == 20u || arg_tile == 21u || arg_tile == 66u || ( arg_tile >= 78u && arg_tile <= 83u);
    }
    return result;
}

void e_spawn_hitnote(INT16 arg_spawnx, UINT16 arg_spawny) BANKED{
    Sprite* s_hitnote = SpriteManagerAdd(SpriteOrpheusnote, arg_spawnx, arg_spawny);
    s_hitnote->lim_x = arg_spawnx;
    s_hitnote->lim_y = arg_spawny;
    struct NoteInfo* e_hitnotedata = (struct NoteInfo*) s_hitnote->custom_data;
    e_hitnotedata->is_enemy = 1u;
    e_hitnotedata->vx = 2;
    if(arg_spawnx > s_orpheus->x){ 
        e_hitnotedata->vx = -2;
    }
    e_hitnotedata->vy = 1;
    if(arg_spawny > s_orpheus->y){ 
        e_hitnotedata->vy = -1;
    }
    e_hitnotedata->wait = 0u;
	e_hitnotedata->frmskip = 0;
	e_hitnotedata->frmskip_max = 8;

}

void e_check_sprite_collision(Sprite* s_enemy) BANKED{
    UINT8 scroll_e_tile;
    Sprite* iespr;
    SPRITEMANAGER_ITERATE(scroll_e_tile, iespr) {
        if(CheckCollision(s_enemy, iespr)) {
            switch(iespr->type){
                case SpriteOrpheus:
                case SpriteOrpheuslyre:
                    /*if(orpheus_info->ow_state != HIT && orpheus_info->ow_state != DIE){
                            struct EnemyInfo* e_data = (struct EnemyInfo*) iospr->custom_data;
                            if(e_data->vx != orpheus_info->vx && orpheus_info->vy == 0){
                                push_vx = e_data->vx;
                            }
                            if(e_data->vy != orpheus_info->vy && orpheus_info->vx == 0){
                                push_vy = e_data->vy;
                            }*/
                    orpheus_change_state(s_orpheus, HIT);
                    //}
                break;
            }
        }
    }
}

void e_check_tile_collision(Sprite* s_enemy, UINT8 e_sprite_type) BANKED{
    struct EnemyInfo* e_data = (struct EnemyInfo*) s_enemy->custom_data;
    switch(e_sprite_type){
        case SpriteSkeleton:
        case SpriteSkeletonshield:
        case SpriteLostsoul:
        case SpriteTartarus:
        case SpriteShadow:
            if(e_data->e_state != HIT){
                e_turn(s_enemy, e_sprite_type, 0);
            }
        break;
        case SpriteInfernalimp:
        case SpriteOoze:
        case SpriteSiren:
            if(e_data->e_state != HIT){
                e_turn(s_enemy, e_sprite_type, TURN_CLOCKWISE);
            }
        break;
        case SpriteDog:
        case SpriteSentinel:
            e_turn(s_enemy, e_sprite_type, TURN_COUNTERCLOCKWISE);
        break;
    }
}

void e_turn(Sprite* s_enemy, UINT8 e_sprite_type, UINT8 forced_wise) BANKED{
    struct EnemyInfo* e_data = (struct EnemyInfo*) s_enemy->custom_data;
    //mi scosto dalla collisione
        if(e_data->tile_collision){
            if(e_data->vx > 0){ THIS->x-=2; }
            if(e_data->vx < 0){ THIS->x+=2; }
            if(e_data->vy > 0){ THIS->y-=2; }
            if(e_data->vy < 0){ THIS->y+=2; }
        }
    UINT8 wise = forced_wise;
    if(wise == 0){// non ho forzato la girata
        if(e_data->wait > 120u){
            wise = TURN_CLOCKWISE;
        }else{
            wise = TURN_COUNTERCLOCKWISE;
        }
        e_data->e_configured++;//used as a counter on same turn wise
        if(e_data->e_configured < 5 && wise == TURN_COUNTERCLOCKWISE){
            wise = TURN_CLOCKWISE;
        }else if(e_data->e_configured < 9 && wise == TURN_CLOCKWISE){
            wise = TURN_COUNTERCLOCKWISE;
        }else if(e_data->e_configured >= 9){
            wise = TURN_OPPOSITE;
            e_data->e_configured = 1;
        }
    }
    switch(wise){
        case TURN_CLOCKWISE:
            switch(e_data->e_state){
                case IDLE_DOWN: case WALK_DOWN: e_change_state(s_enemy, IDLE_LEFT, e_sprite_type); break;
                case IDLE_LEFT: case WALK_LEFT: e_change_state(s_enemy, IDLE_UP, e_sprite_type); break;
                case IDLE_UP: case WALK_UP: e_change_state(s_enemy, IDLE_RIGHT, e_sprite_type); break;
                case IDLE_RIGHT: case WALK_RIGHT: e_change_state(s_enemy, IDLE_DOWN, e_sprite_type); break;
            }
        break;
        case TURN_COUNTERCLOCKWISE:        
            switch(e_data->e_state){
                case IDLE_DOWN: case WALK_DOWN: e_change_state(s_enemy, IDLE_RIGHT, e_sprite_type); break;
                case IDLE_LEFT: case WALK_LEFT: e_change_state(s_enemy, IDLE_DOWN, e_sprite_type); break;
                case IDLE_UP: case WALK_UP: e_change_state(s_enemy, IDLE_LEFT, e_sprite_type); break;
                case IDLE_RIGHT: case WALK_RIGHT: e_change_state(s_enemy, IDLE_UP, e_sprite_type); break;
            }
        break;
        case TURN_OPPOSITE:
            switch(e_data->e_state){
                case IDLE_DOWN: case WALK_DOWN: e_change_state(s_enemy, IDLE_UP, e_sprite_type); break;
                case IDLE_LEFT: case WALK_LEFT: e_change_state(s_enemy, IDLE_RIGHT, e_sprite_type); break;
                case IDLE_UP: case WALK_UP: e_change_state(s_enemy, IDLE_DOWN, e_sprite_type); break;
                case IDLE_RIGHT: case WALK_RIGHT: e_change_state(s_enemy, IDLE_LEFT, e_sprite_type); break;
            }
        break;
    }
    if(e_sprite_type != SpriteDog && e_sprite_type != SpriteOoze && e_sprite_type != SpriteSentinel){//se non è un cane, riparti subito
        switch(e_data->e_state){
            case IDLE_LEFT: 
                e_change_state(s_enemy, WALK_LEFT, e_sprite_type); break;
            case IDLE_RIGHT: 
                e_change_state(s_enemy, WALK_RIGHT, e_sprite_type); break;
            case IDLE_UP: 
                e_change_state(s_enemy, WALK_UP, e_sprite_type); break;
            case IDLE_DOWN: 
                e_change_state(s_enemy, WALK_DOWN, e_sprite_type); break;
            case GENERIC_WALK:
                e_change_state(s_enemy, WALK_DOWN, e_sprite_type); break;
            break;
        }
    }
}

void e_destroy(Sprite* s_enemy, UINT8 e_sprite_type) BANKED{
    if(current_map == HADES_FIVE){
        Sprite* s_key = SpriteManagerAdd(SpriteItem, s_enemy->x + 8u, s_enemy->y + 10u);
        struct ItemInfo* key_data = (struct ItemInfo*) s_key->custom_data;
        key_data->item_type = KEY;
        key_data->i_configured = 1u;
    }
    e_change_state(s_enemy, DIE, e_sprite_type);
}
