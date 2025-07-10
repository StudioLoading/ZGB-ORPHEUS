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


extern UINT8 in_dialog;
extern Sprite* s_orpheus;

extern void e_destroy(Sprite* s_enemy, UINT8 e_sprite_type) BANKED;
extern void e_check_tile_collision(Sprite* s_enemy, UINT8 e_sprite_type) BANKED;
extern void e_change_state(Sprite* s_enemy, SPRITE_STATES new_state, UINT8 sprite_type) BANKED;
extern UINT8 e_is_damaged_by_fire(UINT8 arg_tile, UINT8 arg_sprite_type) BANKED;
extern UINT8 e_is_damaged_by_pit(UINT8 arg_tile, UINT8 arg_sprite_type) BANKED;
extern void e_turn(Sprite* s_enemy, UINT8 e_sprite_type, UINT8 forced_wise) BANKED;
extern void e_destroy(Sprite* s_enemy, UINT8 e_sprite_type) BANKED;

void e_dog_management(Sprite* s_enemy) BANKED;


void e_dog_management(Sprite* s_enemy) BANKED{
    if(in_dialog) return;
    struct EnemyInfo* e_data = (struct EnemyInfo*) s_enemy->custom_data;
    UINT8 e_sprite_type = s_enemy->type;
    if(e_data->frmskip_wait > 0){
        e_data->frmskip_wait--;
    }
    if(e_data->e_state != WALK_DOWN && e_data->e_state != WALK_UP && 
        e_data->e_state != WALK_LEFT && e_data->e_state != WALK_RIGHT &&
        e_data->e_state != PREATTACK_DOWN && e_data->e_state != PREATTACK_UP && 
        e_data->e_state != PREATTACK_LEFT && e_data->e_state != PREATTACK_RIGHT &&
        e_data->e_state != HIT){
        if(e_data->wait > 0){
            e_data->wait--;
            return;
        }
    }
    if(e_data->frmskip_wait == 0){
        e_data->frmskip_wait = e_data->frmskip;
        INT16 delta_x = s_orpheus->x - s_enemy->x;
        INT16 delta_y = s_orpheus->y - s_enemy->y;
        switch (e_data->e_state){
            case IDLE_RIGHT:
                if(delta_y < 24 && delta_y > -8 && delta_x > 0 && delta_x < 50){
                    e_change_state(s_enemy, PREATTACK_RIGHT, s_enemy->type);                    
                }
            break;
            case IDLE_UP:
                if(delta_x < 24 && delta_x > -8 && delta_y < 0 && delta_y > -50){
                    e_change_state(s_enemy, PREATTACK_UP, s_enemy->type);                    
                }
            break;
            case IDLE_LEFT:
                if(delta_y < 16 && delta_y > -12 && delta_x < 0 && delta_x > -50){
                    e_change_state(s_enemy, PREATTACK_LEFT, s_enemy->type);                    
                }
            break;
            case IDLE_DOWN:
                if(delta_x < 16 && delta_x > -12 && delta_y > 0 && delta_y < 50){
                    e_change_state(s_enemy, PREATTACK_DOWN, s_enemy->type);                    
                }
            break;
            case WALK_DOWN:
            case WALK_UP:
            case WALK_LEFT:
            case WALK_RIGHT:
            case HIT:{
                UINT8 tile = GetScrollTile((THIS->x + 2) >> 3, (THIS->y+2) >> 3);
                if(tile == 0){
                    tile = GetScrollTile((THIS->x + 12) >> 3, (THIS->y+12) >> 3); 
                }
                if(tile == 0){
                    tile = GetScrollTile((THIS->x + 2) >> 3, (THIS->y+12) >> 3); 
                }
                if(tile == 0){
                    tile = GetScrollTile((THIS->x + 12) >> 3, (THIS->y+2) >> 3); 
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
            }break;
            case PREATTACK_RIGHT:
                if(s_enemy->anim_frame == 0){
                    if(e_data->e_configured == 1 && s_enemy->type == SpriteDog){
                        Sprite* s_note = SpriteManagerAdd(SpriteOrpheusnote, s_enemy->x+18, s_enemy->y - 2);
                        struct NoteInfo* notedata = (struct NoteInfo*) s_note->custom_data;
                        notedata->is_enemy = 0u;
                        e_data->e_configured = 2;
                    }
                }else{
                    e_data->e_configured = 1;
                }
                e_data->wait--;
                if(e_data->wait == 0){ 
                    e_change_state(s_enemy, WALK_RIGHT, s_enemy->type);
                }
            break;
            case PREATTACK_UP:
                if(s_enemy->anim_frame == 0){
                    if(e_data->e_configured == 1 && s_enemy->type == SpriteDog){
                        Sprite* s_note = SpriteManagerAdd(SpriteOrpheusnote, s_enemy->x+2, s_enemy->y - 4);
                        struct NoteInfo* notedata = (struct NoteInfo*) s_note->custom_data;
                        notedata->is_enemy = 0u;
                        e_data->e_configured = 2;
                    }
                }else{
                    e_data->e_configured = 1;
                }
                e_data->wait--;
                if(e_data->wait == 0){ 
                    e_change_state(s_enemy, WALK_UP, s_enemy->type);
                }
            break;
            case PREATTACK_LEFT:
                if(s_enemy->anim_frame == 0){
                    if(e_data->e_configured == 1 && s_enemy->type == SpriteDog){
                        Sprite* s_note = SpriteManagerAdd(SpriteOrpheusnote, s_enemy->x+18, s_enemy->y - 2);
                        struct NoteInfo* notedata = (struct NoteInfo*) s_note->custom_data;
                        notedata->is_enemy = 0u;
                        e_data->e_configured = 2;
                    }
                }else{
                    e_data->e_configured = 1;
                }
                e_data->wait--;
                if(e_data->wait == 0){ 
                    e_change_state(s_enemy, WALK_LEFT, s_enemy->type);
                }
            break;
            case PREATTACK_DOWN:
                if(s_enemy->anim_frame == 0){
                    if(e_data->e_configured == 1 && s_enemy->type == SpriteDog){
                        Sprite* s_note = SpriteManagerAdd(SpriteOrpheusnote, s_enemy->x+2, s_enemy->y - 4);
                        struct NoteInfo* notedata = (struct NoteInfo*) s_note->custom_data;
                        notedata->is_enemy = 0u;
                        e_data->e_configured = 2;
                    }
                }else{
                    e_data->e_configured = 1;
                }
                e_data->wait--;
                if(e_data->wait == 0){
                    e_change_state(s_enemy, WALK_DOWN, s_enemy->type);
                }
            break;
        }
    }
}