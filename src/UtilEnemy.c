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
extern UINT8 area_enemy_counter;
extern UINT8 in_dialog;
extern struct ItemSpawnedByCommon item_spawned_by_common;
extern UINT8 spawned_enemy_counter;

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
extern void banshee_update_anim(Sprite* s_enemy, SPRITE_STATES new_state) BANKED;
extern void magma_update_anim(Sprite* s_enemy, SPRITE_STATES new_state) BANKED;
extern void frost_update_anim(Sprite* s_enemy, SPRITE_STATES new_state) BANKED;
extern void serpent_update_anim(Sprite* s_enemy, SPRITE_STATES new_state) BANKED;
extern void wyrmling_update_anim(Sprite* s_enemy, SPRITE_STATES new_state) BANKED;
extern void devourer_update_anim(Sprite* s_enemy, SPRITE_STATES new_state) BANKED;
extern void revenant_update_anim(Sprite* s_enemy, SPRITE_STATES new_state) BANKED;
extern void minion_update_anim(Sprite* s_enemy, SPRITE_STATES new_state) BANKED;
extern void skeletoncerberus_update_anim(Sprite* s_enemy, SPRITE_STATES new_state) BANKED;
extern void impminos_update_anim(Sprite* s_enemy, SPRITE_STATES new_state) BANKED;

extern UINT8 is_enemy(UINT8 arg_sprite_type) BANKED;
extern void spawn_death_animation(UINT16 spawnx, UINT16 spawny) BANKED;

void e_start(struct EnemyInfo* e_data, SPRITE_STATES new_state) BANKED;
void e_configure(Sprite* s_enemy) BANKED;
void e_change_state(Sprite* s_enemy, SPRITE_STATES new_state) BANKED;
void e_update_anim(Sprite* s_enemy) BANKED;
void e_management(Sprite* s_enemy) BANKED;
void e_check_sprite_collision(Sprite* s_enemy) BANKED;
void e_check_tile_collision(Sprite* s_enemy, UINT8 e_sprite_type) BANKED;
void e_turn(Sprite* s_enemy, UINT8 forced_wise) BANKED;
void e_destroy(Sprite* s_enemy) BANKED;
Sprite* e_spawn_hitnote(INT16 arg_spawnx, UINT16 arg_spawny, NOTE_MOVEMENT_TYPE arg_movement_type) BANKED;
ENEMY_REACTION e_is_damaged_by_fire(UINT8 arg_tile, UINT8 arg_sprite_type) BANKED;
UINT8 e_is_damaged_by_pit(UINT8 arg_tile, UINT8 arg_sprite_type) BANKED;
UINT8 e_is_attack(UINT8 arg_sprite_type) BANKED;
UINT8 e_is_guard(UINT8 arg_sprite_type) BANKED;

extern void orpheus_change_state(Sprite* arg_s_orpheus, SPRITE_STATES arg_new_state) BANKED;


void e_start(struct EnemyInfo* e_data, SPRITE_STATES new_state) BANKED{
    e_data->e_state = new_state;
    e_data->frmskip_wait = e_data->frmskip;
    e_data->vx = 0;
    e_data->vy = 0;
    e_data->tile_collision = 0;
    e_data->wait = 0;
    e_data->e_configured = 0;
    spawned_enemy_counter++;
}

void e_configure(Sprite* s_enemy) BANKED{
    e_update_anim(s_enemy);
    struct EnemyInfo* e_data = (struct EnemyInfo*) s_enemy->custom_data;
    e_data->e_configured = 1;
}

void e_update_anim(Sprite* arg_s_enemy) BANKED{
    struct EnemyInfo* e_data = (struct EnemyInfo*) arg_s_enemy->custom_data;
    switch(arg_s_enemy->type){
        case SpriteSkeleton:
            skeleton_update_anim(arg_s_enemy, e_data->e_state);
        break;
        case SpriteSkeletonshield:
            skeletonshield_update_anim(arg_s_enemy, e_data->e_state);
        break;
        case SpriteDog:
            dog_update_anim(arg_s_enemy, e_data->e_state);
        break;
        case SpriteInfernalimp:
            infernalimp_update_anim(arg_s_enemy, e_data->e_state);
        break;
        case SpriteLostsoul:
            lostsoul_update_anim(arg_s_enemy, e_data->e_state);
        break;
        case SpriteTartarus:
            tartarus_update_anim(arg_s_enemy, e_data->e_state);
        break;
        case SpriteOoze:
            ooze_update_anim(arg_s_enemy, e_data->e_state);
        break;
        case SpriteSentinel:
            sentinel_update_anim(arg_s_enemy, e_data->e_state);
        break;
        case SpriteSiren:
            siren_update_anim(arg_s_enemy, e_data->e_state);
        break;
        case SpriteShadow:
            shadow_update_anim(arg_s_enemy, e_data->e_state);
        break;
        case SpriteBanshee:
            banshee_update_anim(arg_s_enemy, e_data->e_state);
        break;
        case SpriteMagma:
            magma_update_anim(arg_s_enemy, e_data->e_state);
        break;
        case SpriteFrost:
            frost_update_anim(arg_s_enemy, e_data->e_state);
        break;
        case SpriteSerpent:
            serpent_update_anim(arg_s_enemy, e_data->e_state);
        break;
        case SpriteWyrmling:
            wyrmling_update_anim(arg_s_enemy, e_data->e_state);
        break;
        case SpriteDevourer:
            devourer_update_anim(arg_s_enemy, e_data->e_state);
        break;
        case SpriteRevenant:
            revenant_update_anim(arg_s_enemy, e_data->e_state);
        break;
        case SpriteMinion:
            minion_update_anim(arg_s_enemy, e_data->e_state);
        break;
        case SpriteSkeletoncerberus:
            skeletoncerberus_update_anim(arg_s_enemy, e_data->e_state);
        break;
        case SpriteImpminos:
            impminos_update_anim(arg_s_enemy, e_data->e_state);
        break;
    }
}

UINT8 e_is_attack(UINT8 arg_sprite_type) BANKED{
    UINT8 result = 0u;
    switch(arg_sprite_type){
        case SpriteLostsoul:
        case SpriteOoze:
        case SpriteSiren:
        case SpriteBanshee:
        case SpriteRevenant:
            result = 1u;
        break;
    }
    return result;
}

UINT8 e_is_guard(UINT8 arg_sprite_type) BANKED{
    UINT8 result = 0u;
    switch(arg_sprite_type){
        case SpriteDog:
        case SpriteSentinel:
        case SpriteTartarus:
        case SpriteMagma:
        case SpriteFrost:
        case SpriteMinion:
            result = 1u;
        break;
    }
    return result;
}

void e_change_state(Sprite* s_enemy, SPRITE_STATES new_state) BANKED{
    UINT8 e_sprite_type = s_enemy->type;
    struct EnemyInfo* e_data = (struct EnemyInfo*) s_enemy->custom_data;
    if(e_data->e_state == new_state || e_data->e_state == FROZEN && new_state != DIE){
        return;
    }
    switch(new_state){
        case WALK_DOWN: 
            e_data->wait = 0;
            e_data->vx = 0;
            e_data->vy = 1;
        break;
        case WALK_UP:
            e_data->wait = 0; 
            e_data->vx = 0;
            e_data->vy = -1;
        break;
        case WALK_RIGHT: 
            if(!e_is_attack(e_sprite_type)){
                e_data->vy = 0;
            }
            e_data->wait = 0;
            e_data->vx = 1;
        break;
        case WALK_LEFT: 
            if(!e_is_attack(e_sprite_type)){
                e_data->vy = 0;
            }
            e_data->wait = 0;
            e_data->vx = -1;
        break;
        case IDLE_DOWN: case IDLE_UP: case IDLE_LEFT: case IDLE_RIGHT:
            switch(e_sprite_type){
                case SpriteSkeleton:
                case SpriteSkeletonshield:
                case SpriteSkeletoncerberus:
                case SpriteSentinel:
                case SpriteDog:
                case SpriteShadow:
                case SpriteSerpent:
                case SpriteDevourer:
                    e_data->wait = 160u;
                break;
                case SpriteLostsoul:
                case SpriteOoze:
                case SpriteSiren:
                case SpriteBanshee:
                case SpriteRevenant:
                    e_data->wait = 120u;
                break;
                case SpriteTartarus:
                case SpriteMagma:
                case SpriteFrost:
                    e_data->wait = 100u;
                break;
                case SpriteMinion:
                case SpriteInfernalimp:
                case SpriteImpminos:
                    e_data->wait = 80u;
                break;
            }
        break;
        case HIT:
            if(is_enemy(e_sprite_type)){
                e_data->wait = orpheus_attack_cooldown;
            }
        break;
        case DIE:
            if(area_enemy_counter){
                area_enemy_counter--;
            }
            spawned_enemy_counter--;
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
                case SpriteBanshee:
                    e_spawn_hitnote(s_enemy->x + 2, s_enemy->y + 4, NOTE_MOV_SIN);
                break;
                case SpriteOoze:
                case SpriteSiren:
                case SpriteRevenant:
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
    e_update_anim(s_enemy);
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
            e_turn(s_enemy, 0);
        }
    }
    if(e_data->e_state == HIT){
        //ADD SPEED BY FRAMESKIP DECREASING
            e_data->frmskip = 4u;
        //MIRROR FOR ROUNDING ANIMATION
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
                e_change_state(s_enemy, GENERIC_WALK);
            }
    }else{
        e_data->wait++;//USING AS RANDOM TO CLOCKWISE TURNING
        //ripristino frameskip
        //e_data->frmskip = 12u;
        if(e_data->e_state == ATTACK){
            if(e_data->wait > 100){
                e_change_state(s_enemy, WALK_DOWN);
            }
        }
    }
    //IDLE TO WALK
        switch (e_data->e_state){
            case IDLE_DOWN: case IDLE_LEFT: case IDLE_RIGHT: case IDLE_UP:
                e_data->wait--;
                if(e_data->wait == 0){
                    if(e_data->e_state == IDLE_DOWN) e_change_state(s_enemy, WALK_DOWN);
                    if(e_data->e_state == IDLE_LEFT) e_change_state(s_enemy, WALK_LEFT);
                    if(e_data->e_state == IDLE_RIGHT) e_change_state(s_enemy, WALK_RIGHT);
                    if(e_data->e_state == IDLE_UP) e_change_state(s_enemy, WALK_UP);
                    return;
                }
            break;
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
                            e_change_state(s_enemy, WALK_UP);
                        }else if(delta_y < -40){//enemy molto sopra orpheus
                            e_change_state(s_enemy, WALK_DOWN);
                        }
                    }
                break;
                case WALK_UP:
                case WALK_DOWN:
                    //if(e_data->wait < 30){//check if Orpheus is over or above enemy
                        if(delta_x > 40){//enemy molto a destra di orpheus
                            e_change_state(s_enemy, WALK_LEFT);
                        }else if(delta_x < -40){//enemy molto a sinistra di orpheus
                            e_change_state(s_enemy, WALK_RIGHT);
                        }
                    //}
                break;
            }
        //TRANSLATE SPRITE
            switch (e_data->e_state){
                case WALK_DOWN:
                case WALK_UP:
                case WALK_LEFT:
                case WALK_RIGHT:
                case HIT:{
                    UINT8 tile = GetScrollTile((THIS->x + 4) >> 3, (THIS->y+6) >> 3);
                    if(tile == 0){
                        tile = GetScrollTile((THIS->x + 12) >> 3, (THIS->y+12) >> 3); 
                    }
                    ENEMY_REACTION is_against_fire = e_is_damaged_by_fire(tile, e_sprite_type);
                    ENEMY_REACTION is_against_pit = e_is_damaged_by_pit(tile, e_sprite_type);
                    if(is_against_fire == ENEMY_REACT_DIE || is_against_pit == ENEMY_REACT_DIE){
                        if(e_data->e_state != HIT){
                            e_turn(s_enemy, 0);
                        }else{
                            e_destroy(s_enemy);
                        }
                    }
                    e_data->tile_collision = TranslateSprite(THIS, e_data->vx << delta_time, e_data->vy << delta_time);
                    if(e_data->tile_collision){
                        e_check_tile_collision(s_enemy, e_sprite_type);
                    }
                }
                case ATTACK:
                    if(s_enemy->type == SpriteOoze || s_enemy->type == SpriteSiren || s_enemy->type == SpriteWyrmling || s_enemy->type == SpriteRevenant){
                        e_data->tile_collision = TranslateSprite(THIS, e_data->vx << delta_time, e_data->vy << delta_time);
                    }
                break;
            }
    }
    if(e_data->e_state != ATTACK){
        if(e_is_attack(s_enemy->type)){
            if(e_data->wait == 200){
                e_change_state(s_enemy, ATTACK);
            }
        }
    }
}

ENEMY_REACTION e_is_damaged_by_fire(UINT8 arg_tile, UINT8 arg_sprite_type) BANKED{
    ENEMY_REACTION result = ENEMY_REACT_NONE;
    switch(arg_sprite_type){
        case SpriteInfernalimp:
        case SpriteImpminos:
        case SpriteSentinel:
        case SpriteMagma:{
            result = ENEMY_REACT_PASSTHROUGH;
        }break;
        default:{
            result = arg_tile == 84u || arg_tile == 85u || arg_tile == 86u || arg_tile == 87u;
            if(result){
                result = ENEMY_REACT_DIE;
            }
        }
        break;
    }
    return result;
}

ENEMY_REACTION e_is_damaged_by_pit(UINT8 arg_tile, UINT8 arg_sprite_type) BANKED{
    ENEMY_REACTION result = ENEMY_REACT_NONE;
    switch(arg_sprite_type){
        case SpriteLostsoul:
        case SpriteOoze:
        case SpriteSiren:
        case SpriteWyrmling:
        case SpriteRevenant:
        case SpriteMinion:
            result = ENEMY_REACT_PASSTHROUGH;
        break;
        default:{
            result = arg_tile == 20u || arg_tile == 66u || ( arg_tile >= 78u && arg_tile <= 83u);
            if(result){
                result = ENEMY_REACT_DIE;
            }
        }break;
    }
    return result;
}

Sprite* e_spawn_hitnote(INT16 arg_spawnx, UINT16 arg_spawny, NOTE_MOVEMENT_TYPE arg_movement_type) BANKED{
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
    e_hitnotedata->movement = arg_movement_type;
    e_hitnotedata->wait = 0u;
	e_hitnotedata->frmskip = 0;
	e_hitnotedata->frmskip_max = 8;
    return s_hitnote;
}

void e_check_sprite_collision(Sprite* s_enemy) BANKED{
    UINT8 scroll_e_tile;
    Sprite* iespr;
    SPRITEMANAGER_ITERATE(scroll_e_tile, iespr) {
        if(CheckCollision(s_enemy, iespr)) {
            switch(iespr->type){
                case SpriteOrpheus:
                case SpriteOrpheuslyre:
                    orpheus_change_state(s_orpheus, HIT);
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
        case SpriteSkeletoncerberus:
        case SpriteLostsoul:
        case SpriteTartarus:
        case SpriteShadow:
        case SpriteMagma:
        case SpriteFrost:
        case SpriteSerpent:
        case SpriteDevourer:
            if(e_data->e_state != HIT){
                e_turn(s_enemy, 0);
            }
        break;
        case SpriteInfernalimp:
        case SpriteImpminos:
        case SpriteOoze:
        case SpriteSiren:
        case SpriteBanshee:
        case SpriteWyrmling:
        case SpriteRevenant:
        case SpriteMinion:
            if(e_data->e_state != HIT){
                e_turn(s_enemy, TURN_CLOCKWISE);
            }
        break;
        case SpriteDog:
        case SpriteSentinel:
            if(e_data->e_state != HIT){
                e_turn(s_enemy, TURN_COUNTERCLOCKWISE);
            }
        break;
    }
}

void e_turn(Sprite* s_enemy, UINT8 forced_wise) BANKED{
    struct EnemyInfo* e_data = (struct EnemyInfo*) s_enemy->custom_data;
    //MOVE BACK FROM COLLISION TILE
        if(e_data->tile_collision){
            if(e_data->vx > 0){ THIS->x-=2; }
            if(e_data->vx < 0){ THIS->x+=2; }
            if(e_data->vy > 0){ THIS->y-=2; }
            if(e_data->vy < 0){ THIS->y+=2; }
        }
    UINT8 wise = forced_wise;
    if(wise == 0){//CALCULATE TURN IF NOT FORCED FROM ARG
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
    //TURN
        switch(wise){
            case TURN_CLOCKWISE:
                switch(e_data->e_state){
                    case IDLE_DOWN: case WALK_DOWN: e_change_state(s_enemy, IDLE_LEFT); break;
                    case IDLE_LEFT: case WALK_LEFT: e_change_state(s_enemy, IDLE_UP); break;
                    case IDLE_UP: case WALK_UP: e_change_state(s_enemy, IDLE_RIGHT); break;
                    case IDLE_RIGHT: case WALK_RIGHT: e_change_state(s_enemy, IDLE_DOWN); break;
                }
            break;
            case TURN_COUNTERCLOCKWISE:        
                switch(e_data->e_state){
                    case IDLE_DOWN: case WALK_DOWN: e_change_state(s_enemy, IDLE_RIGHT); break;
                    case IDLE_LEFT: case WALK_LEFT: e_change_state(s_enemy, IDLE_DOWN); break;
                    case IDLE_UP: case WALK_UP: e_change_state(s_enemy, IDLE_LEFT); break;
                    case IDLE_RIGHT: case WALK_RIGHT: e_change_state(s_enemy, IDLE_UP); break;
                }
            break;
            case TURN_OPPOSITE:
                switch(e_data->e_state){
                    case IDLE_DOWN: case WALK_DOWN: e_change_state(s_enemy, IDLE_UP); break;
                    case IDLE_LEFT: case WALK_LEFT: e_change_state(s_enemy, IDLE_RIGHT); break;
                    case IDLE_UP: case WALK_UP: e_change_state(s_enemy, IDLE_DOWN); break;
                    case IDLE_RIGHT: case WALK_RIGHT: e_change_state(s_enemy, IDLE_LEFT); break;
                }
            break;
        }
    //NOT A GUARD? MOVE!
        if(!e_is_guard(s_enemy->type)){
            switch(e_data->e_state){
                case IDLE_LEFT:
                    e_change_state(s_enemy, WALK_LEFT); break;
                case IDLE_RIGHT: 
                    e_change_state(s_enemy, WALK_RIGHT); break;
                case IDLE_UP: 
                    e_change_state(s_enemy, WALK_UP); break;
                case IDLE_DOWN: 
                    e_change_state(s_enemy, WALK_DOWN); break;
                case GENERIC_WALK:
                    e_change_state(s_enemy, WALK_DOWN); break;
                break;
            }
        }
}

void e_destroy(Sprite* s_enemy) BANKED{
    if(item_spawned_by_common.sprite_type == s_enemy->type && 
        item_spawned_by_common.spawned == 0){
        Sprite* s_key = SpriteManagerAdd(SpriteItem, s_enemy->x + 8u, s_enemy->y + 10u);
        struct ItemInfo* key_data = (struct ItemInfo*) s_key->custom_data;
        key_data->item_type = KEY;
        key_data->i_configured = 1u;
        item_spawned_by_common.spawned = 1;
    }
    e_change_state(s_enemy, DIE);
}
