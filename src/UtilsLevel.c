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

#define V_CAMERA 2
#define MAX_WAIT_CHAR 4

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
UINT8 dialog_ready = 0u;
UINT8 counter_char = 0u;
UINT8 wait_char = MAX_WAIT_CHAR;
UINT8 writing_line = 1u;
UINT8 n_lines = 0u;
UINT8 has_lyre = 0u;
UINT8 button_pressed = 0u;
MACROMAP current_map = TUTORIAL;
MACROMAP next_map = HADES_ZERO;
MACROMAP prev_map = TUTORIAL;
UINT16 orpheus_nextmap_spawnx = ((UINT16) 10u << 3);
UINT16 orpheus_nextmap_spawny = ((UINT16) 15u << 3);
UINT16 orpheus_prevmap_spawnx = ((UINT16) 29u << 3);
UINT16 orpheus_prevmap_spawny = ((UINT16) 7u << 3);
UINT16 orpheus_spawnx = ((UINT16) 28u << 3) - 4u;
UINT16 orpheus_spawny = ((UINT16) 79u << 3);
UINT16 camera_spawnx = ((UINT16) 30u << 3);
UINT16 camera_spawny = ((UINT16) 64u << 3);
UINT16 camera_prev_spawnx = ((UINT16) 30u << 3);
UINT16 camera_prev_spawny = ((UINT16) 64u << 3);
UINT16 camera_next_spawnx = ((UINT16) 10u << 3);
UINT16 camera_next_spawny = ((UINT16) 11u << 3) + 4u;
UINT8 in_dialog = 0u;
extern struct OrpheusInfo* orpheus_info;
extern INT8 a_walk_counter_x;
extern INT8 a_walk_counter_y;
extern INT8 orpheus_hp_max;
extern INT8 orpheus_hp;
extern INT8 countdown;
extern INT8 orpheus_power_max;
extern UINT8 tutorial_go;
extern UINT8 J_INT;
extern UINT8 J_ATK;
extern unsigned char EMPTY_STRING_20[];
extern SPRITE_STATES new_state;

void level_common_start() BANKED;
void level_common_update_play() BANKED;
void move_camera() BANKED;
void UpdateHUD() BANKED;
void fill_bar_idx(UINT8 i, UINT8 r) BANKED;
void show_next_character() BANKED;
void init_write_dialog(UINT8 nlines) BANKED;
void press_release_button(UINT16 x, UINT16 y, UINT8 t) BANKED;
void draw_button(UINT16 x, UINT16 y, UINT8 t) BANKED;
void go_to_next_map() BANKED;

extern void e_configure(Sprite* s_enemy, UINT8 sprite_type) BANKED;
extern unsigned char get_char(UINT8 arg_writing_line, UINT8 counter_char) BANKED;


void level_common_start() BANKED{
	//SCROLL LIMITS
        scroll_top_movement_limit = 72u;
        scroll_bottom_movement_limit = 72u;
	//SPRITES
		scroll_target = SpriteManagerAdd(SpriteCamera, camera_spawnx, camera_spawny);
		if(tutorial_go == 0){
			print_target = PRINT_WIN;
			PRINT(0, 0, EMPTY_STRING_20);
			PRINT(0, 1, EMPTY_STRING_20);
			PRINT(0, 2, EMPTY_STRING_20);
		}else{
			redraw_hud = 1;
		}
	//VARS
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
		if(KEY_TICKED(J_SELECT) && has_lyre){
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
	// log
    /*
	switch(orpheus_info->ow_state){
        case WALK_RIGHT:{
			if(KEY_PRESSED(J_INT)){
				PRINT(0,0,"WALKING RIGHT JINT");
			}else{
				PRINT(0,0,"WALKING RIGHT      ");
			}
		}break;
        default: PRINT(0,0,"OTHER               ");
    }
	*/
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
	//STRUCTURE
		INT8 idx = 0;
		for(idx = 0; idx <= 19; idx++){
			UPDATE_HUD_TILE(idx,0,0);
		}
		UPDATE_HUD_TILE(0,1,52);
		UPDATE_HUD_TILE(0,2,53);
		UPDATE_HUD_TILE(5,1,47);
		UPDATE_HUD_TILE(5,2,54);
		UPDATE_HUD_TILE(6,1,0);
		UPDATE_HUD_TILE(6,2,0);
		UPDATE_HUD_TILE(13,1,25);
		UPDATE_HUD_TILE(13,2,26);
		UPDATE_HUD_TILE(19,1,27);
		UPDATE_HUD_TILE(19,2,28);

	//HP
		idx = 0;
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
		if(has_lyre){
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
		}else{//non ho la lira, annerisco
			UPDATE_HUD_TILE(7,1,25);
			UPDATE_HUD_TILE(7,2,26);
			UPDATE_HUD_TILE(8,1,27);
			UPDATE_HUD_TILE(8,2,28);

			UPDATE_HUD_TILE(9,1,25);
			UPDATE_HUD_TILE(9,2,26);
			UPDATE_HUD_TILE(10,1,27);
			UPDATE_HUD_TILE(10,2,28);

			UPDATE_HUD_TILE(11,1,25);
			UPDATE_HUD_TILE(11,2,26);
			UPDATE_HUD_TILE(12,1,27);
			UPDATE_HUD_TILE(12,2,28);
		}
	//BAR
		//if(countdown < orpheus_power_max || has_lyre == 0){
		if(countdown == 0 || has_lyre == 0){
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
		if(has_lyre){
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
}

void init_write_dialog(UINT8 nlines) BANKED{
    wait_char = MAX_WAIT_CHAR;
	dialog_ready = 0u; 
    writing_line = 1u;
    counter_char = 0u;
	n_lines = nlines;
	in_dialog = 1u;
}

void write_dialog() BANKED{	
    if(KEY_TICKED(J_UP)){init_write_dialog(n_lines);}
    switch(dialog_ready){
		case 0u:
		{
			dialog_ready = 1;
			print_target = PRINT_WIN;
			PRINT(0, 0, EMPTY_STRING_20);
			PRINT(0, 1, EMPTY_STRING_20);
			PRINT(0, 2, EMPTY_STRING_20);
		}
		break;
		case 1:
		{
        if(KEY_PRESSED(J_ATK) || KEY_PRESSED(J_INT) || KEY_PRESSED(J_DOWN)){
            wait_char = 1u;
        }
        wait_char--;
        if(wait_char == 0u){//mostra lettera successiva
            if(writing_line <= n_lines){
				show_next_character();
			}else{
				if(KEY_TICKED(J_UP)){
					init_write_dialog(n_lines);
				}else if(KEY_TICKED(J_ATK) || KEY_TICKED(J_INT)){
					dialog_ready = 2u;
				}
			}
        }
		}
		break;
		case 2u:
			redraw_hud = 1;
			in_dialog = 0u;
		break;
	}
}

void show_next_character() BANKED{
    unsigned char to_print[2] = " ";
	to_print[0] = get_char(writing_line, counter_char);
    UINT8 writing_line_on_video = (writing_line-1)%3;
    PRINT(counter_char, writing_line_on_video, to_print);
    wait_char = MAX_WAIT_CHAR;
    counter_char++;
    if(counter_char == 21u){
        counter_char = 0u;
        writing_line++;
        if((writing_line-1)%3 == 0 && writing_line < n_lines){
			PRINT(0, 0, EMPTY_STRING_20);
			PRINT(0, 1, EMPTY_STRING_20);
			PRINT(0, 2, EMPTY_STRING_20);
        }
    }
}

void fill_bar_idx(UINT8 i, UINT8 r) BANKED{
	UPDATE_HUD_TILE(14+i,1,45-r);
	UPDATE_HUD_TILE(14+i,2,46-r);
}

void press_release_button(UINT16 x, UINT16 y, UINT8 t) BANKED{
    draw_button(x, y, t);
	if(button_pressed == 0){
		button_pressed = 1;
	}else if(button_pressed == 1){
		button_pressed = 0;
	}
}

void draw_button(UINT16 x, UINT16 y, UINT8 t) BANKED{
    set_bkg_tile_xy(x, y, t);
    set_bkg_tile_xy(x, y+1, t+1);
    set_bkg_tile_xy(x+1, y, t+2);
    set_bkg_tile_xy(x+1, y+1, t+3);
}

void go_to_next_map() BANKED{
	orpheus_prevmap_spawnx = orpheus_spawnx;
	orpheus_prevmap_spawny = orpheus_spawny;
	orpheus_spawnx = orpheus_nextmap_spawnx;
	orpheus_spawny = orpheus_nextmap_spawny;
	camera_prev_spawnx = camera_spawnx;
	camera_prev_spawny = camera_spawny;
	camera_spawnx = camera_next_spawnx;
	camera_spawny = camera_next_spawny;
	UINT8 next_state = StateTutorial;
	a_walk_counter_x = 0;
	a_walk_counter_y = 0;
	current_map = next_map;
	switch(next_map){
		case HADES_ZERO:
			next_map = HADES_ONE;
			prev_map = TUTORIAL;
			orpheus_nextmap_spawnx = ((UINT16) 4u << 3);
			orpheus_nextmap_spawny = ((UINT16) 4u << 3);
			camera_next_spawnx = ((UINT16) 10u << 3);
			camera_next_spawny = ((UINT16) 11u << 3) + 4u;
			orpheus_prevmap_spawnx = ((UINT16) 29u << 3);
			orpheus_prevmap_spawny = ((UINT16) 6u << 3);
			//a_walk_counter_y = -8;
			next_state = StateHades00;
		break;
		case HADES_ONE:
			next_map = HADES_TWO;
			prev_map = HADES_ZERO;
			orpheus_nextmap_spawnx = 0;//TODO
			orpheus_nextmap_spawny = 0;//TODO
			camera_next_spawnx = 0;//TODO
			camera_next_spawny = 0;//TODO
			a_walk_counter_y = 16;
			new_state = IDLE_DOWN;
			next_state = StateHades00;
		break;
	}
	SetState(next_state);
}

void go_to_prev_map() BANKED{
	camera_next_spawnx = camera_spawnx;
	camera_next_spawny = camera_spawny;
	camera_spawnx = camera_prev_spawnx;
	camera_spawny = camera_prev_spawny;
	orpheus_nextmap_spawnx = orpheus_spawnx;
	orpheus_nextmap_spawny = orpheus_spawny;
	current_map = prev_map;
	UINT8 next_state = StateTutorial;
	a_walk_counter_x = 0;
	a_walk_counter_y = 0;
	switch(prev_map){
		case TUTORIAL:
			next_map = HADES_ZERO;
			prev_map = TUTORIAL;
			orpheus_spawnx = orpheus_prevmap_spawnx;
			orpheus_spawny = orpheus_prevmap_spawny;
			camera_spawnx = ((UINT16) 30u << 3);
			camera_spawny = ((UINT16) 11u << 3);
		break;
		case HADES_ZERO:
			next_map = HADES_ONE;
			prev_map = TUTORIAL;
			orpheus_spawnx = ((UINT16) 10u << 3);
			orpheus_spawny = ((UINT16) 4u << 3);
			camera_prev_spawnx = ((UINT16) 10u << 3);
			camera_prev_spawny = ((UINT16) 11u << 3) + 4;
			orpheus_prevmap_spawnx = ((UINT16) 29u << 3) + 4;
			orpheus_prevmap_spawny = ((UINT16) 7u << 3);
			next_state = StateHades00;
		break;
	}
	SetState(next_state);
}