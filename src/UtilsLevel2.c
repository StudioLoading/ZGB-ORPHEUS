#include "Banks/SetAutoBank.h"

#include "SGB.h"
#include "BankManager.h"
#include "ZGBMain.h"
#include "Fade.h"
#include "Keys.h"
#include "Scroll.h"
#include "Sprite.h"
#include "SpriteManager.h"
#include "string.h"
#include "Palette.h"
#include "Print.h"

#include "custom_datas.h"
#include "UtilAnim.h"

extern UINT8 flag_button_pushable;
extern UINT8 spawned_ball;

void spawn_death_animation(UINT16 spawnx, UINT16 spawny) BANKED;
void spawn_ball(UINT8 arg_type, UINT16 arg_spawnball_x, UINT16 arg_spawnball_y, UINT8 arg_direction) BANKED;
void draw_button(UINT16 x, UINT16 y, UINT8 t) BANKED;
UINT8 is_enemy(UINT8 arg_sprite_type) BANKED;

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

void spawn_ball(UINT8 arg_type, UINT16 arg_spawnball_x, UINT16 arg_spawnball_y, UINT8 arg_direction) BANKED{
	if(spawned_ball == 0u){
		flag_button_pushable = 0u;
		Sprite* s_ball = SpriteManagerAdd(arg_type, arg_spawnball_x, arg_spawnball_y);
		struct EnemyInfo* ball_data = (struct EnemyInfo*) s_ball->custom_data;
		switch(arg_direction){
			case J_UP: ball_data->vx = 0; ball_data->vy = -1; break;
			case J_DOWN: ball_data->vx = 0; ball_data->vy = 1; break;
			case J_LEFT: ball_data->vx = -1; ball_data->vy = 0; break;
			case J_RIGHT: ball_data->vx = 1; ball_data->vy = 0; break;
		}
		ball_data->e_configured = 1;
	}
}

UINT8 is_enemy(UINT8 arg_sprite_type) BANKED{
    UINT8 result = 0u;
    switch(arg_sprite_type){
        case SpriteSkeleton:
        case SpriteSkeletonshield:
        case SpriteLostsoul:
        case SpriteInfernalimp:
        case SpriteOoze:
        case SpriteSentinel:
        case SpriteSiren:
        case SpriteShadow:
        case SpriteBanshee:
        case SpriteTartarus:
        case SpriteMagma:
        case SpriteFrost:
        case SpriteSerpent:
            result = 1u;
        break;
    }
    return result;
}
