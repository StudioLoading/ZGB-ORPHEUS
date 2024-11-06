#include "Banks/SetAutoBank.h"

#include "SGB.h"
#include "BankManager.h"
#include "ZGBMain.h"
#include "Keys.h"
#include "Scroll.h"
#include "Sprite.h"
#include "SpriteManager.h"
#include "string.h"
#include "Print.h"

#include "custom_datas.h"

#define V_CAMERA 2

Sprite* s_camera;
Sprite* s_orpheus;
UINT8 redraw_hud = 0;
SONG song_selection;
UINT8 move_camera_up = 0u;
UINT8 move_camera_down = 0u;
UINT8 move_camera_left = 0u;
UINT8 move_camera_right = 0u;
UINT16 move_camera_desty = 0u;
UINT16 move_camera_destx = 0u;

extern struct OrpheusInfo* orpheus_info;
extern INT8 a_walk_counter_x;
extern INT8 a_walk_counter_y;
extern INT8 orpheus_hp_max;
extern INT8 orpheus_hp;
extern INT8 countdown;
extern INT8 orpheus_power_max;
extern UINT8 tutorial_go;

void level_common_start() BANKED;
void level_common_update_play() BANKED;
void move_camera() BANKED;
void UpdateHUD() BANKED;
void fill_bar_idx(UINT8 i, UINT8 r) BANKED;

extern void e_configure(Sprite* s_enemy, UINT8 sprite_type) BANKED;

void level_common_start() BANKED{
	//SCROLL LIMITS
        scroll_top_movement_limit = 72u;
        scroll_bottom_movement_limit = 72u;
	//SPRITES
		if(tutorial_go == 0){
			scroll_target = SpriteManagerAdd(SpriteCamera, ((UINT16) 30u << 3), ((UINT16) 64u << 3));
		}
	//VARS
		redraw_hud = 1;
		move_camera_up = 0u;
		move_camera_desty = 0u;
		move_camera_destx = 0u;
		move_camera_down = 0u;
		move_camera_left = 0u;
}

void level_common_update_play() BANKED{
	// move camera
		if(move_camera_up || move_camera_down || move_camera_left || move_camera_right){
			move_camera();
			return;
		}
	// orpheus_scroll_deltay
		INT16 orpheus_scroll_deltay = s_orpheus->y - scroll_target->y;
		if(orpheus_scroll_deltay < -72){
			move_camera_up = 1;
			move_camera_desty = scroll_target->y - 144u;
			a_walk_counter_y = -32;
			return;
		}else if(orpheus_scroll_deltay > 40){
			move_camera_down = 1;
			move_camera_desty = scroll_target->y + 144u;
			a_walk_counter_y = +32;
			return;
		}
	// orpheus_scroll_deltax
		INT16 orpheus_scroll_deltax = s_orpheus->x - scroll_target->x;
		if(orpheus_scroll_deltax < - 80){
			move_camera_left= 1;
			move_camera_destx = scroll_target->x - 160u;
			a_walk_counter_x = -8;
			return;
		}else if(orpheus_scroll_deltax > 72){
			move_camera_right = 1;
			move_camera_destx = scroll_target->x + 160u;
			a_walk_counter_x = +8;
			return;
		}
	// select button
		if(KEY_TICKED(J_SELECT)){
			song_selection++;
			if(song_selection == 3){
				song_selection = ATTRACT;
			}
			redraw_hud = 1;
		}
	// update HUD
		if(redraw_hud != 0){
			UpdateHUD();
		}
}

void move_camera() BANKED{
	if(move_camera_up){
		if(scroll_target->y > move_camera_desty){
			scroll_target->y -= V_CAMERA;
		}else{
			a_walk_counter_y = -8;
			move_camera_up = 0;
		}
	}else if(move_camera_down){
		if(scroll_target->y < move_camera_desty){
			scroll_target->y+=V_CAMERA;
		}else{
			a_walk_counter_y = +4;
			move_camera_down = 0;
		}
	}else if(move_camera_left){
		if(scroll_target->x > move_camera_destx){
			scroll_target->x-=V_CAMERA;
		}else{
			a_walk_counter_x = -4;
			move_camera_left = 0;
		}
	}else if(move_camera_right){
		if(scroll_target->x < move_camera_destx){
			scroll_target->x+=V_CAMERA;
		}else{
			a_walk_counter_x = +4;
			move_camera_right = 0;
		}
	}
}

void UpdateHUD() BANKED{
	redraw_hud = 0;
	//HP
		INT8 idx = 0;
		for(idx = 1; idx <= orpheus_hp_max; idx++){
			if(idx <= orpheus_hp){
				UPDATE_HUD_TILE(idx,1,1);
				UPDATE_HUD_TILE(idx,2,2);
			}else{
				UPDATE_HUD_TILE(idx,1,3);
				UPDATE_HUD_TILE(idx,2,4);
			}
		}
	//WEAPON
		switch(song_selection){
			case ATTRACT:
				UPDATE_HUD_TILE(7,1,5);
				UPDATE_HUD_TILE(7,2,6);
				UPDATE_HUD_TILE(8,1,7);
				UPDATE_HUD_TILE(8,2,8);

				UPDATE_HUD_TILE(9,1,17);
				UPDATE_HUD_TILE(9,2,18);
				UPDATE_HUD_TILE(10,1,19);
				UPDATE_HUD_TILE(10,2,20);

				UPDATE_HUD_TILE(11,1,21);
				UPDATE_HUD_TILE(11,2,22);
				UPDATE_HUD_TILE(12,1,23);
				UPDATE_HUD_TILE(12,2,24);
			break;
			case SLEEP:
				UPDATE_HUD_TILE(7,1,9);
				UPDATE_HUD_TILE(7,2,10);
				UPDATE_HUD_TILE(8,1,11);
				UPDATE_HUD_TILE(8,2,12);

				UPDATE_HUD_TILE(9,1,13);
				UPDATE_HUD_TILE(9,2,14);
				UPDATE_HUD_TILE(10,1,15);
				UPDATE_HUD_TILE(10,2,16);
				
				UPDATE_HUD_TILE(11,1,21);
				UPDATE_HUD_TILE(11,2,22);
				UPDATE_HUD_TILE(12,1,23);
				UPDATE_HUD_TILE(12,2,24);
			break;
			case REPEL:
				UPDATE_HUD_TILE(7,1,9);
				UPDATE_HUD_TILE(7,2,10);
				UPDATE_HUD_TILE(8,1,11);
				UPDATE_HUD_TILE(8,2,12);

				UPDATE_HUD_TILE(9,1,17);
				UPDATE_HUD_TILE(9,2,18);
				UPDATE_HUD_TILE(10,1,19);
				UPDATE_HUD_TILE(10,2,20);

				UPDATE_HUD_TILE(11,1,48);
				UPDATE_HUD_TILE(11,2,49);
				UPDATE_HUD_TILE(12,1,50);
				UPDATE_HUD_TILE(12,2,51);
			break;
		}
	//BAR
		if(countdown < orpheus_power_max){
			UPDATE_HUD_TILE(14,1,45);
			UPDATE_HUD_TILE(14,2,46);
			UPDATE_HUD_TILE(15,1,45);
			UPDATE_HUD_TILE(15,2,46);
			UPDATE_HUD_TILE(16,1,45);
			UPDATE_HUD_TILE(16,2,46);
			UPDATE_HUD_TILE(17,1,45);
			UPDATE_HUD_TILE(17,2,46);
			UPDATE_HUD_TILE(18,1,45);
			UPDATE_HUD_TILE(18,2,46);
		}
		//countdown orpheus_power_max
		// 5 pezzi
		// ogni pezzo divisibile per 8
		UINT8 countdown_unita = countdown >> 3;
		UINT8 resto = 0u;
		if(countdown < 8){
			resto = countdown;
		}else{
			resto = countdown%8;
		}
		if(countdown_unita < 1){
			fill_bar_idx(0, resto << 1);
		}else if(countdown_unita < 2){
			fill_bar_idx(0, 16);
			fill_bar_idx(1, resto << 1);
		}else if(countdown_unita < 3){
			fill_bar_idx(0, 16);
			fill_bar_idx(1, 16);
			fill_bar_idx(2, resto << 1);
		}else if(countdown_unita < 4){
			fill_bar_idx(0, 16);
			fill_bar_idx(1, 16);
			fill_bar_idx(2, 16);
			fill_bar_idx(3, resto << 1);
		}else if(countdown_unita < 5){
			fill_bar_idx(0, 16);
			fill_bar_idx(1, 16);
			fill_bar_idx(2, 16);
			fill_bar_idx(3, 16);
			fill_bar_idx(4, resto << 1);
		}else{
			fill_bar_idx(0, 16);
			fill_bar_idx(1, 16);
			fill_bar_idx(2, 16);
			fill_bar_idx(3, 16);
			fill_bar_idx(4, 16);
		}
}

void fill_bar_idx(UINT8 i, UINT8 r) BANKED{
		UPDATE_HUD_TILE(14+i,1,45-r);
		UPDATE_HUD_TILE(14+i,2,46-r);
}