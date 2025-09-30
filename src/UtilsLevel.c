#include "Banks/SetAutoBank.h"

#include "BankManager.h"
#include "ZGBMain.h"
#include "Fade.h"
#include "Keys.h"
#include "Music.h"
#include "Scroll.h"
#include "Sprite.h"
#include "SpriteManager.h"
#include "string.h"
#include "Palette.h"
#include "Print.h"

#include "custom_datas.h"
#include "UtilAnim.h"

#define V_CAMERA 2
#define MAX_WAIT_CHAR 4
#define REPUSHABLE_BUTTON_COOLDOWN_MAX 400
#define CAMERA_SHAKE_DURATION 10
#define CAMERA_SHAKE_FRMSKIP_MAX_INIT 8

#define SPAWNX_CAMERA_TUTORIAL 30
#define SPAWNY_CAMERA_TUTORIAL 11
#define SPAWNX_CAMERA_HADES 10
#define SPAWNY_CAMERA_HADES 11

#define SPAWNX_TUTORIAL 29
#define SPAWNY_TUTORIAL 7
#define SPAWNX_HADES000_IN 10
#define SPAWNY_HADES000_IN 15
#define SPAWNX_HADES000_OUT 10
#define SPAWNY_HADES000_OUT 5
#define SPAWNX_HADES001_IN 4
#define SPAWNY_HADES001_IN 4
#define SPAWNX_HADES001_OUT 16
#define SPAWNY_HADES001_OUT 13
#define SPAWNX_HADES002_IN 8
#define SPAWNY_HADES002_IN 3
#define SPAWNX_HADES002_OUT 5
#define SPAWNY_HADES002_OUT 13
#define SPAWNX_HADES003_IN 4
#define SPAWNY_HADES003_IN 4
#define SPAWNX_HADES003_OUT 15
#define SPAWNY_HADES003_OUT 4
#define SPAWNX_HADES004_IN 4
#define SPAWNY_HADES004_IN 4
#define SPAWNX_HADES007_IN 3
#define SPAWNY_HADES007_IN 4
#define SPAWNX_HADES008_IN 15
#define SPAWNY_HADES008_IN 4
#define SPAWNX_HADES009_IN 4
#define SPAWNY_HADES009_IN 11
#define SPAWNX_HADES010_IN 1
#define SPAWNY_HADES010_IN 13
#define SPAWNX_HADES011_IN 8
#define SPAWNY_HADES011_IN 3
#define SPAWNX_HADES012_IN 15
#define SPAWNY_HADES012_IN 12
#define SPAWNX_HADES013_IN 6
#define SPAWNY_HADES013_IN 13
#define SPAWNX_HADES014_IN 15
#define SPAWNY_HADES014_IN 3
#define SPAWNX_HADES015_IN 2
#define SPAWNY_HADES015_IN 3
#define SPAWNX_HADES016_IN 8
#define SPAWNY_HADES016_IN 3
#define SPAWNX_HADES017_IN 16
#define SPAWNY_HADES017_IN 12
#define SPAWNX_HADES018_IN 3
#define SPAWNY_HADES018_IN 3
#define SPAWNX_HADES019_IN 6
#define SPAWNY_HADES019_IN 11
#define SPAWNX_HADES020_IN 15
#define SPAWNY_HADES020_IN 12

#define SPAWNX_HADES004_OUT 6
#define SPAWNY_HADES004_OUT 13
#define SPAWNX_HADES006_OUT 16
#define SPAWNY_HADES006_OUT 12
#define SPAWNX_HADES007_OUT 14
#define SPAWNY_HADES007_OUT 3
#define SPAWNX_HADES008_OUT 10
#define SPAWNY_HADES008_OUT 3
#define SPAWNX_HADES009_OUT 9
#define SPAWNY_HADES009_OUT 3
#define SPAWNX_HADES010_OUT 14
#define SPAWNY_HADES010_OUT 3
#define SPAWNX_HADES011_OUT 4
#define SPAWNY_HADES011_OUT 13
#define SPAWNX_HADES012_OUT 2
#define SPAWNY_HADES012_OUT 3
#define SPAWNX_HADES013_OUT 15
#define SPAWNY_HADES013_OUT 3
#define SPAWNX_HADES014_OUT 2
#define SPAWNY_HADES014_OUT 13
#define SPAWNX_HADES016_OUT 10
#define SPAWNY_HADES016_OUT 13
#define SPAWNX_HADES017_OUT 16
#define SPAWNY_HADES017_OUT 3
#define SPAWNX_HADES018_OUT 14
#define SPAWNY_HADES018_OUT 3
#define SPAWNX_HADES019_OUT 14
#define SPAWNY_HADES019_OUT 3
#define SPAWNX_HADES020_OUT 8
#define SPAWNY_HADES020_OUT 3
#define SPAWNX_HADES021_IN 2
#define SPAWNY_HADES021_IN 13
#define SPAWNX_BOSSCHARON_IN 9
#define SPAWNY_BOSSCHARON_IN 15
#define SPAWNX_BOSSAEACUS_IN 4
#define SPAWNY_BOSSAEACUS_IN 15
#define SPAWNX_BOSSHADES_IN 9
#define SPAWNY_BOSSHADES_IN 15

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
UINT8 button_pressed = 0u;
UINT8 orpheus_haskey = 0u;
UINT8 in_dialog = 0u;
UINT8 init_block_button = 0u;
UINT8 anim_counter = 0u;
UINT8 area_enemy_counter = 0u;
UINT8 changing_map = 0u;
UINT8 restart_current_map = 0u;
INT8 boss_hp_max = 5;
INT8 boss_hp_current = 5;
UINT8 spikes_countdown = 255u;
UINT8 spikes_hit_flag = 0u;
//MACROMAP trap_button_pressed = HADES_00;
UINT8 evaluate_button = 1u;//0 normal, 1 init, 2 force pressed
UINT8 flag_button_repushable = 0u;
UINT16 repushable_button_cooldown = REPUSHABLE_BUTTON_COOLDOWN_MAX;
UINT8 flag_button_pushable = 1u;
UINT8 flag_paused = 0u;
UINT8 song_selection_cooldown = 0u;

UINT8 paused_first_line[20];
UINT8 paused_second_line[20];

UINT8 camera_shake_wait = 0u;
UINT8 flag_camera_shake_v = 0u;
UINT8 flag_camera_shake_h = 0u;
UINT8 camera_shake_frmskip = 0u;
UINT8 camera_shake_frmskip_max = CAMERA_SHAKE_FRMSKIP_MAX_INIT;

extern UINT8 has_lyre;
extern UINT16 orpheus_spawnx;
extern UINT16 orpheus_spawny;
extern UINT16 camera_spawnx;
extern UINT16 camera_spawny;
extern MACROMAP solved_map;
extern MACROMAP current_map;
extern MACROMAP next_map;
extern MACROMAP prev_map;
extern MACROMAP max_map;
extern struct OrpheusInfo* orpheus_info;
extern INT8 a_walk_counter_x;
extern INT8 a_walk_counter_y;
extern INT8 orpheus_hp_max;
extern INT8 orpheus_hp;
extern INT8 countdown;
extern UINT8 tutorial_go;
extern UINT8 J_INT;
extern UINT8 J_ATK;
extern unsigned char EMPTY_STRING_20[];
extern SPRITE_STATES new_state;
extern UINT8 show_cartel;
extern UINT8 spawned_ball;
extern PUSHING orpheus_pushing;
extern UINT8 colliding_block;
extern UINT8 dialog_paused;
extern uint8_t sgb_checked;
extern UINT8 hades_music_started;
extern UINT8 boss_intro;

void write_dialog() BANKED;
void level_common_start() BANKED;
void level_common_update_play() BANKED;
void move_camera() BANKED;
void UpdateHUD() BANKED;
void fill_bar_idx(UINT8 i, UINT8 r) BANKED;
void show_next_character() BANKED;
void init_write_dialog(UINT8 nlines) BANKED;
void press_release_button(UINT16 x, UINT16 y, UINT8 t) BANKED;
void go_to_next_map() BANKED;
void go_to_prev_map() BANKED;
void solve_current_map() BANKED;
void reset_maps() BANKED;
void camera_shake_v() BANKED;


extern void draw_button(UINT16 x, UINT16 y, UINT8 t) BANKED;
extern void spawn_ball(UINT8 arg_type, UINT16 arg_spawnfireball_x, UINT16 arg_spawnfireball_y, UINT8 arg_direction) BANKED;
extern unsigned char get_char(UINT8 arg_writing_line, UINT8 counter_char) BANKED;
extern void my_play_fx(UINT8 c, UINT8 mute_frames, UINT8 s0, UINT8 s1, UINT8 s2, UINT8 s3, UINT8 s4) BANKED;
extern UINT8 is_level_on_boss() BANKED;
extern UINT8 is_level_with_button() BANKED;
extern UINT8 is_level_with_enemies() BANKED;
extern void manage_sgb_border() BANKED;
extern void manage_sgb_palette() BANKED;

void camera_shake_v() BANKED{
	camera_shake_frmskip++;
	if(camera_shake_frmskip >= camera_shake_frmskip_max){
		camera_shake_frmskip = 0;
		camera_shake_wait++;
		if(camera_shake_wait < CAMERA_SHAKE_DURATION){
			if(camera_shake_wait < 6){
				camera_shake_frmskip_max = camera_shake_wait;
			}
			if(camera_shake_wait % 2){
				scroll_target->y -= (camera_shake_wait >> 1);
			}else{
				scroll_target->y += (camera_shake_wait >> 1);
			}
		}else{
			scroll_target->y = camera_spawny;
			flag_camera_shake_v = 0u;
			camera_shake_wait = 0;
			camera_shake_frmskip = 0u;
			camera_shake_frmskip_max = CAMERA_SHAKE_FRMSKIP_MAX_INIT;
		}
	}
}

void camera_shake_h() BANKED{
	camera_shake_frmskip++;
	if(camera_shake_frmskip >= camera_shake_frmskip_max){
		camera_shake_frmskip = 0;
		camera_shake_wait++;
		if(camera_shake_wait < CAMERA_SHAKE_DURATION){
			if(camera_shake_wait < 6){
				camera_shake_frmskip_max = camera_shake_wait;
			}
			if(camera_shake_wait % 2){
				scroll_bkg(2,0);
			}else{
				scroll_bkg(-2,0);
			}
		}else{
			scroll_target->x = camera_spawnx;
			flag_camera_shake_h = 0u;
			camera_shake_wait = 0;
			camera_shake_frmskip = 0u;
			camera_shake_frmskip_max = CAMERA_SHAKE_FRMSKIP_MAX_INIT;
		}
	}
}

void level_common_start() BANKED{
	//SGB
		if(sgb_checked){
			if(current_map == TUTORIAL || current_map == BOSS_HADES){
				manage_sgb_border();
			}
			manage_sgb_palette();
		}
	//CAMERA SHAKE
		flag_camera_shake_v = 0u;
		flag_camera_shake_h = 0u;
		camera_shake_wait = 0u;
		camera_shake_frmskip = 0u;
		camera_shake_frmskip_max = CAMERA_SHAKE_FRMSKIP_MAX_INIT;
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
		init_block_button = 0;
		changing_map = 0u;
		restart_current_map = 0u;
		anim_counter = 0u;
		show_cartel = 0u;
		spikes_countdown = 0u;
		spikes_hit_flag = 0u;
		evaluate_button = 1u;
		flag_button_repushable = 0u;
		repushable_button_cooldown = REPUSHABLE_BUTTON_COOLDOWN_MAX;
		flag_button_pushable = 1u;
		flag_paused = 0u;
		song_selection_cooldown = 0u;
}

void reset_maps() BANKED{
	hades_music_started = 0;
	new_state = GENERIC_IDLE;
	if(current_map <= BOSS_CHARON){
		solved_map = TUTORIAL;
		current_map = HADES_00;
		next_map = HADES_01;
		prev_map = HADES_00;
		max_map = HADES_00;
		orpheus_spawnx = ((UINT16) SPAWNX_HADES000_IN << 3);
		orpheus_spawny = ((UINT16) SPAWNY_HADES000_IN << 3);
	}else if(current_map <= BOSS_CERBERUS){
		solved_map = BOSS_CHARON;
		current_map = HADES_06;
		next_map = HADES_07;
		prev_map = HADES_06;
		max_map = HADES_06;
		orpheus_spawnx = ((UINT16) SPAWNX_HADES004_IN << 3);
		orpheus_spawny = ((UINT16) SPAWNY_HADES004_IN << 3);
	}else if(current_map <= BOSS_MINOS){
		solved_map = BOSS_CERBERUS;
		current_map = HADES_11;
		next_map = HADES_12;
		prev_map = HADES_11;
		max_map = HADES_11;
		orpheus_spawnx = ((UINT16) SPAWNX_HADES004_IN << 3);
		orpheus_spawny = ((UINT16) SPAWNY_HADES004_IN << 3);
	}else if(current_map <= BOSS_AEACUS){
		solved_map = BOSS_MINOS;
		current_map = HADES_16;
		next_map = HADES_17;
		prev_map = BOSS_MINOS;
		max_map = HADES_16;
		orpheus_spawnx = ((UINT16) SPAWNX_HADES004_IN << 3);
		orpheus_spawny = ((UINT16) SPAWNY_HADES004_IN << 3);
	}else{
		solved_map = BOSS_AEACUS;
		current_map = HADES_21;
		next_map = HADES_22;
		prev_map = BOSS_AEACUS;
		max_map = HADES_21;
		orpheus_spawnx = ((UINT16) SPAWNX_HADES004_IN << 3);
		orpheus_spawny = ((UINT16) SPAWNY_HADES004_IN << 3);
	}
}


void level_common_update_play() BANKED{
	// camera shake
		if(flag_camera_shake_v){
			camera_shake_v();
		}
		if(flag_camera_shake_h){
			camera_shake_h();
		}
	// pausedè'a	
		if(current_map > TUTORIAL && !is_level_on_boss()){
			if(KEY_TICKED(J_START) && orpheus_info->ow_state != ATTACK && orpheus_info->ow_state != HIT){
				if(flag_paused == 0){
					PauseMusic;
					flag_paused = 1u;
					paused_first_line[0] = GetScrollTile(0, 11);
					paused_first_line[1] = GetScrollTile(1, 11);
					paused_first_line[2] = GetScrollTile(2, 11);
					paused_first_line[3] = GetScrollTile(3, 11);
					paused_first_line[4] = GetScrollTile(4, 11);
					paused_first_line[5] = GetScrollTile(5, 11);
					paused_first_line[6] = GetScrollTile(6, 11);
					paused_first_line[7] = GetScrollTile(7, 11);
					paused_first_line[8] = GetScrollTile(8, 11);
					paused_first_line[9] = GetScrollTile(9, 11);
					paused_first_line[10] = GetScrollTile(10, 11);
					paused_first_line[11] = GetScrollTile(11, 11);
					paused_first_line[12] = GetScrollTile(12, 11);
					paused_first_line[13] = GetScrollTile(13, 11);
					paused_first_line[14] = GetScrollTile(14, 11);
					paused_first_line[15] = GetScrollTile(15, 11);
					paused_first_line[16] = GetScrollTile(16, 11);
					paused_first_line[17] = GetScrollTile(17, 11);
					paused_first_line[18] = GetScrollTile(18, 11);
					paused_first_line[19] = GetScrollTile(19, 11);
					paused_second_line[0] = GetScrollTile(0, 12);
					paused_second_line[1] = GetScrollTile(1, 12);
					paused_second_line[2] = GetScrollTile(2, 12);
					paused_second_line[3] = GetScrollTile(3, 12);
					paused_second_line[4] = GetScrollTile(4, 12);
					paused_second_line[5] = GetScrollTile(5, 12);
					paused_second_line[6] = GetScrollTile(6, 12);
					paused_second_line[7] = GetScrollTile(7, 12);
					paused_second_line[8] = GetScrollTile(8, 12);
					paused_second_line[9] = GetScrollTile(9, 12);
					paused_second_line[10] = GetScrollTile(10, 12);
					paused_second_line[11] = GetScrollTile(11, 12);
					paused_second_line[12] = GetScrollTile(12, 12);
					paused_second_line[13] = GetScrollTile(13, 12);
					paused_second_line[14] = GetScrollTile(14, 12);
					paused_second_line[15] = GetScrollTile(15, 12);
					paused_second_line[16] = GetScrollTile(16, 12);
					paused_second_line[17] = GetScrollTile(17, 12);
					paused_second_line[18] = GetScrollTile(18, 12);
					paused_second_line[19] = GetScrollTile(19, 12);
					UpdateMapTile(0, 0, 11, 0, 0, 0);
					UpdateMapTile(0, 1, 11, 0, 0, 0);
					UpdateMapTile(0, 2, 11, 0, 0, 0);
					UpdateMapTile(0, 3, 11, 0, 0, 0);
					UpdateMapTile(0, 4, 11, 0, 0, 0);
					UpdateMapTile(0, 5, 11, 0, 0, 0);
					UpdateMapTile(0, 6, 11, 0, 49, 0);
					UpdateMapTile(0, 7, 11, 0, 0, 0);
					UpdateMapTile(0, 8, 11, 0, 106, 0);
					UpdateMapTile(0, 9, 11, 0, 108, 0);
					UpdateMapTile(0, 10, 11, 0, 110, 0);
					UpdateMapTile(0, 11, 11, 0, 112, 0);
					UpdateMapTile(0, 12, 11, 0, 114, 0);
					UpdateMapTile(0, 13, 11, 0, 120, 0);
					UpdateMapTile(0, 14, 11, 0, 49, 0);
					UpdateMapTile(0, 15, 11, 0, 0, 0);
					UpdateMapTile(0, 16, 11, 0, 0, 0);
					UpdateMapTile(0, 17, 11, 0, 0, 0);
					UpdateMapTile(0, 18, 11, 0, 0, 0);
					UpdateMapTile(0, 19, 11, 0, 0, 0);
					UpdateMapTile(0, 0, 12, 0, 0, 0);
					UpdateMapTile(0, 1, 12, 0, 0, 0);
					UpdateMapTile(0, 2, 12, 0, 0, 0);
					UpdateMapTile(0, 3, 12, 0, 0, 0);
					UpdateMapTile(0, 4, 12, 0, 0, 0);
					UpdateMapTile(0, 5, 12, 0, 0, 0);
					UpdateMapTile(0, 6, 12, 0, 11, 0);
					UpdateMapTile(0, 7, 12, 0, 0, 0);
					UpdateMapTile(0, 8, 12, 0, 107, 0);
					UpdateMapTile(0, 9, 12, 0, 109, 0);
					UpdateMapTile(0, 10, 12, 0, 111, 0);
					UpdateMapTile(0, 11, 12, 0, 113, 0);
					UpdateMapTile(0, 12, 12, 0, 115, 0);
					UpdateMapTile(0, 13, 12, 0, 121, 0);
					UpdateMapTile(0, 14, 12, 0, 11, 0);
					UpdateMapTile(0, 15, 12, 0, 0, 0);
					UpdateMapTile(0, 16, 12, 0, 0, 0);
					UpdateMapTile(0, 17, 12, 0, 0, 0);
					UpdateMapTile(0, 18, 12, 0, 0, 0);
					UpdateMapTile(0, 19, 12, 0, 0, 0);
				}else{
					ResumeMusic;
					flag_paused = 0u;
					UpdateMapTile(0, 0, 11, 0, paused_first_line[0], 0);
					UpdateMapTile(0, 1, 11, 0, paused_first_line[1], 0);
					UpdateMapTile(0, 2, 11, 0, paused_first_line[2], 0);
					UpdateMapTile(0, 3, 11, 0, paused_first_line[3], 0);
					UpdateMapTile(0, 4, 11, 0, paused_first_line[4], 0);
					UpdateMapTile(0, 5, 11, 0, paused_first_line[5], 0);
					UpdateMapTile(0, 6, 11, 0, paused_first_line[6], 0);
					UpdateMapTile(0, 7, 11, 0, paused_first_line[7], 0);
					UpdateMapTile(0, 8, 11, 0, paused_first_line[8], 0);
					UpdateMapTile(0, 9, 11, 0, paused_first_line[9], 0);
					UpdateMapTile(0, 10, 11, 0, paused_first_line[10], 0);
					UpdateMapTile(0, 11, 11, 0, paused_first_line[11], 0);
					UpdateMapTile(0, 12, 11, 0, paused_first_line[12], 0);
					UpdateMapTile(0, 13, 11, 0, paused_first_line[13], 0);
					UpdateMapTile(0, 14, 11, 0, paused_first_line[14], 0);
					UpdateMapTile(0, 15, 11, 0, paused_first_line[15], 0);
					UpdateMapTile(0, 16, 11, 0, paused_first_line[16], 0);
					UpdateMapTile(0, 17, 11, 0, paused_first_line[17], 0);
					UpdateMapTile(0, 18, 11, 0, paused_first_line[18], 0);
					UpdateMapTile(0, 19, 11, 0, paused_first_line[19], 0);

					UpdateMapTile(0, 0, 12, 0, paused_second_line[0], 0);
					UpdateMapTile(0, 1, 12, 0, paused_second_line[1], 0);
					UpdateMapTile(0, 2, 12, 0, paused_second_line[2], 0);
					UpdateMapTile(0, 3, 12, 0, paused_second_line[3], 0);
					UpdateMapTile(0, 4, 12, 0, paused_second_line[4], 0);
					UpdateMapTile(0, 5, 12, 0, paused_second_line[5], 0);
					UpdateMapTile(0, 6, 12, 0, paused_second_line[6], 0);
					UpdateMapTile(0, 7, 12, 0, paused_second_line[7], 0);
					UpdateMapTile(0, 8, 12, 0, paused_second_line[8], 0);
					UpdateMapTile(0, 9, 12, 0, paused_second_line[9], 0);
					UpdateMapTile(0, 10, 12, 0, paused_second_line[10], 0);
					UpdateMapTile(0, 11, 12, 0, paused_second_line[11], 0);
					UpdateMapTile(0, 12, 12, 0, paused_second_line[12], 0);
					UpdateMapTile(0, 13, 12, 0, paused_second_line[13], 0);
					UpdateMapTile(0, 14, 12, 0, paused_second_line[14], 0);
					UpdateMapTile(0, 15, 12, 0, paused_second_line[15], 0);
					UpdateMapTile(0, 16, 12, 0, paused_second_line[16], 0);
					UpdateMapTile(0, 17, 12, 0, paused_second_line[17], 0);
					UpdateMapTile(0, 18, 12, 0, paused_second_line[18], 0);
					UpdateMapTile(0, 19, 12, 0, paused_second_line[19], 0);
				}
			}
			if(flag_paused){ return; }
		}
	// check button draw
		if(evaluate_button){
			if(is_level_with_button()){
				if(flag_button_pushable || 
					(flag_button_repushable && repushable_button_cooldown == REPUSHABLE_BUTTON_COOLDOWN_MAX)
				){//SET IT PUSHABLE
					flag_button_pushable = 1u;
					repushable_button_cooldown--;
					switch(current_map){
						case HADES_06:
							draw_button(12, 12, 67u);
						break;
						case HADES_09:
							draw_button(17, 11, 67u);
						break;
						case HADES_14:
							draw_button(14, 11, 67u);
						break;
						case HADES_17:
							draw_button(6, 7, 67u);
						break;
						case HADES_19:
							draw_button(3, 13, 67u);
						break;
						case BOSS_AEACUS:
							draw_button(16, 14, 67u);
						break;
					}
				}else{//SET IT PUSHED
					switch(current_map){
						case HADES_06:
							draw_button(12, 12, 71u);
						break;
						case HADES_09:
							draw_button(17, 11, 71u);
						break;
						case HADES_14:
							draw_button(14, 11, 71u);
						break;
						case HADES_17:
							draw_button(6, 7, 71u);
						break;
						case HADES_19:
							draw_button(3, 13, 71u);
						break;
						case BOSS_AEACUS:
							draw_button(16, 14, 71u);
						break;
					}
				}
			}
			evaluate_button = 0u;
		}
		UINT8 tile = GetScrollTile((s_orpheus->x + 4) >> 3, (s_orpheus->y+12) >> 3);
		if(tile == 71u || tile == 72u || tile == 73u || tile == 74u){
			evaluate_button = 1u;
			/*if(trap_button_pressed < current_map){
				trap_button_pressed = current_map;
			}*/
			if(flag_button_pushable == 1){
				flag_button_pushable = 0;
				switch(current_map){
					case HADES_06:
						spawn_ball(SpriteStone, 56u, 28u, J_DOWN);
					break;
					case HADES_14:
						spawn_ball(SpriteFireball, 72u, 24u, J_DOWN);
					break;
					case HADES_19:
						spawn_ball(SpriteStone, 88u, 24u, J_DOWN);
					break;
					case BOSS_AEACUS:
						spawn_ball(SpriteFireball, 96u, 24u, J_DOWN);
					break;
				}
			}
		}
		if(flag_button_repushable){
			if(repushable_button_cooldown < REPUSHABLE_BUTTON_COOLDOWN_MAX){
				repushable_button_cooldown--;
				if(repushable_button_cooldown == 0){
					flag_button_pushable = 1u;
					repushable_button_cooldown = REPUSHABLE_BUTTON_COOLDOWN_MAX;
				}
			}else{
				evaluate_button = 1u;
			}
		}
	// restart current map
		if(restart_current_map > 0u){
			restart_current_map++;
			if(restart_current_map >= 250u){
				orpheus_hp = 4;
				a_walk_counter_y = 0;
				restart_current_map = 0u;
				reset_maps();
				SetState(StateHades00);
				//TODO Perché non SetState(StateStart) ?
			}
			return;
		}
	// move camera
		if(move_camera_up || move_camera_down || move_camera_left || move_camera_right){
			move_camera();
			return;
		}
	// orpheus_scroll_deltay
		if(flag_camera_shake_v == 0 && flag_camera_shake_h == 0){
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
	// song selection
		if(song_selection_cooldown){
			song_selection_cooldown--;
		}
		if(song_selection_cooldown == 0){
			if((KEY_TICKED(J_INT) || KEY_TICKED(J_SELECT)) && has_lyre && show_cartel == 0 && orpheus_pushing == PUSH_NONE && colliding_block == 0 && !in_dialog){
			//TODO per evitare overpowerment avevo inserito in and questa condizione orpheus_info->charming == 0 ma molti tester me l'hanno cassata
				song_selection++;
				if(song_selection == 3){
					song_selection = ATTRACT;
				}
				redraw_hud = 1;
			}
		}
	// update HUD
		if(redraw_hud){
			UpdateHUD();
		}
	// spikes animation
		if(current_map >= HADES_06){
			spikes_countdown++;
			if(spikes_countdown > 180u){
				Anim_Spike_0();
			}else if(spikes_countdown > 160u){
				Anim_Spike_1();
			}else if(spikes_countdown > 140u){
				spikes_hit_flag = 0u;
				Anim_Spike_2();
			}else if(spikes_countdown < 6u){
				Anim_Spike_1();
			}else{
				spikes_hit_flag = 1u;
				Anim_Spike_3();
			}
		}
	// solve current map
		if(is_level_with_enemies()){
			if(changing_map == 0u && solved_map < current_map && area_enemy_counter == 0){
				solve_current_map();
			}
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
	INT8 idx = 0;
	UINT8 is_on_boss = is_level_on_boss();
	//STRUCTURE
		if(is_on_boss == 0){
			UPDATE_HUD_TILE(0,0,57);
			UPDATE_HUD_TILE(1,0,57);
			UPDATE_HUD_TILE(2,0,57);
			UPDATE_HUD_TILE(3,0,57);
			UPDATE_HUD_TILE(4,0,57);
			UPDATE_HUD_TILE(5,0,57);
			UPDATE_HUD_TILE(6,0,57);
			UPDATE_HUD_TILE(7,0,57);
			UPDATE_HUD_TILE(8,0,57);
			UPDATE_HUD_TILE(9,0,57);
			UPDATE_HUD_TILE(10,0,57);
			UPDATE_HUD_TILE(11,0,57);
			UPDATE_HUD_TILE(12,0,57);
			UPDATE_HUD_TILE(13,0,57);
			UPDATE_HUD_TILE(14,0,57);
			UPDATE_HUD_TILE(15,0,57);
			UPDATE_HUD_TILE(16,0,57);
			UPDATE_HUD_TILE(17,0,57);
			UPDATE_HUD_TILE(18,0,57);
			UPDATE_HUD_TILE(19,0,57);
		}
		UPDATE_HUD_TILE(0,1,25);
		UPDATE_HUD_TILE(0,2,26);
		UPDATE_HUD_TILE(5,1,47);
		UPDATE_HUD_TILE(5,2,52);
		UPDATE_HUD_TILE(6,1,55);
		UPDATE_HUD_TILE(6,2,56);
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
		if(orpheus_hp == 0){//sono morto, deseleziono tutto
			UPDATE_HUD_TILE(7,1,9);
			UPDATE_HUD_TILE(7,2,10);
			UPDATE_HUD_TILE(8,1,11);
			UPDATE_HUD_TILE(8,2,12);
			UPDATE_HUD_TILE(9,1,17);
			UPDATE_HUD_TILE(9,2,18);
			UPDATE_HUD_TILE(10,1,19);
			UPDATE_HUD_TILE(10,2,20);
			UPDATE_HUD_TILE(11,1,21);
			UPDATE_HUD_TILE(11,2,22);
			UPDATE_HUD_TILE(12,1,23);
			UPDATE_HUD_TILE(12,2,24);
		}
	//BAR
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
		if(orpheus_hp == 0){
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
	//KEY
		if(orpheus_haskey == 1){
			UPDATE_HUD_TILE(6,1,53);
			UPDATE_HUD_TILE(6,2,54);
		}
	//BOSS HP
		if(is_on_boss){
			INT8 idx_bosshp = 0;
			switch(boss_hp_max){
				case 5:{
					UPDATE_HUD_TILE(6,0,0);
					for(idx_bosshp = 0; idx_bosshp < boss_hp_current; idx_bosshp++){
						UPDATE_HUD_TILE(7+idx_bosshp,0,59);
					}
					for(;idx_bosshp < boss_hp_max; idx_bosshp++){
						UPDATE_HUD_TILE(7+idx_bosshp,0,60);
					}
					UPDATE_HUD_TILE(7+boss_hp_max,0,0);
				}break;
				case 8:{
					UPDATE_HUD_TILE(5,0,0);
					for(idx_bosshp = 0; idx_bosshp < boss_hp_current; idx_bosshp++){
						UPDATE_HUD_TILE(6+idx_bosshp,0,59);
					}
					for(;idx_bosshp < boss_hp_max; idx_bosshp++){
						UPDATE_HUD_TILE(6+idx_bosshp,0,60);
					}
					UPDATE_HUD_TILE(6+boss_hp_max,0,0);
				}break;
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
	print_target = PRINT_WIN;
	PRINT(0, 0, EMPTY_STRING_20);
	PRINT(0, 1, EMPTY_STRING_20);
	PRINT(0, 2, EMPTY_STRING_20);
}

void write_dialog() BANKED{	
    if(KEY_TICKED(J_SELECT)){init_write_dialog(n_lines);}
    switch(dialog_ready){
		case 0u:{
			dialog_ready = 1;
			print_target = PRINT_WIN;
			PRINT(0, 0, EMPTY_STRING_20);
			PRINT(0, 1, EMPTY_STRING_20);
			PRINT(0, 2, EMPTY_STRING_20);
		}break;
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
					if(KEY_TICKED(J_SELECT)){
						init_write_dialog(n_lines);
					}else if(KEY_TICKED(J_ATK) || KEY_TICKED(J_INT) || KEY_TICKED(J_UP) || KEY_TICKED(J_DOWN) || KEY_TICKED(J_LEFT) || KEY_TICKED(J_RIGHT) || KEY_RELEASED(J_INT) || KEY_RELEASED(J_ATK) || KEY_RELEASED(J_UP) || KEY_RELEASED(J_DOWN) || KEY_RELEASED(J_LEFT) || KEY_RELEASED(J_RIGHT) || KEY_RELEASED(J_START)){
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
	if(counter_char == 20u){
		dialog_paused = 40u;
	}
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
	if(button_pressed == 0 && solved_map < current_map){
		button_pressed = 1;
		solve_current_map();
	}else if(button_pressed == 1){
		button_pressed = 0;
	}
}

void go_to_next_map() BANKED{
	changing_map = 1u;
	SpriteManagerRemoveSprite(s_orpheus);
	if(next_map > max_map){
		max_map = next_map;
		if(solved_map < next_map){
			button_pressed = 0;
			orpheus_haskey = 0;
		}
	}
	UINT8 next_state = StateTutorial;
	a_walk_counter_x = 0;
	a_walk_counter_y = 0;
	current_map = next_map;
	if(!is_level_on_boss()){
		a_walk_counter_y = 8;
	}
	switch(next_map){
		case HADES_00:
			prev_map = HADES_00;
			next_map = HADES_01;
			camera_spawnx = ((UINT16) SPAWNX_CAMERA_HADES << 3);
			camera_spawny = ((UINT16) SPAWNY_CAMERA_HADES << 3) + 4u;
			orpheus_spawnx = ((UINT16) SPAWNX_HADES000_IN << 3);
			orpheus_spawny = ((UINT16) SPAWNY_HADES000_IN << 3);
			new_state = IDLE_UP;
			next_state = StateHades00;
		break;
		case HADES_01:
			prev_map = HADES_00;
			next_map = HADES_02;
			orpheus_spawnx = ((UINT16) SPAWNX_HADES001_IN << 3);
			orpheus_spawny = ((UINT16) SPAWNY_HADES001_IN << 3) + 2u;
			new_state = IDLE_DOWN;
			next_state = StateHades00;
		break;
		case HADES_02:
			prev_map = HADES_01;
			next_map = HADES_03;
			orpheus_spawnx = ((UINT16) SPAWNX_HADES002_IN << 3);
			orpheus_spawny = ((UINT16) SPAWNY_HADES002_IN << 3) + 4u;
			new_state = IDLE_DOWN;
			next_state = StateHades00;
		break;
		case HADES_03:
			prev_map = HADES_02;
			next_map = HADES_04;
			orpheus_spawnx = ((UINT16) SPAWNX_HADES003_IN << 3);
			orpheus_spawny = ((UINT16) SPAWNY_HADES003_IN << 3) + 4u;
			new_state = IDLE_DOWN;
			next_state = StateHades00;
		break;
		case HADES_04:
			prev_map = HADES_03;
			next_map = HADES_05;
			orpheus_spawnx = ((UINT16) SPAWNX_HADES004_IN << 3);
			orpheus_spawny = ((UINT16) SPAWNY_HADES004_IN << 3) + 4u;
			new_state = IDLE_DOWN;
			next_state = StateHades00;
		break;
		case HADES_05:
			prev_map = HADES_04;
			next_map = BOSS_CHARON;
			orpheus_spawnx = ((UINT16) SPAWNX_HADES004_IN << 3);
			orpheus_spawny = ((UINT16) SPAWNY_HADES004_IN << 3) + 4u;
			new_state = IDLE_DOWN;
			next_state = StateHades00;
		break;
		case BOSS_CHARON:
			prev_map = HADES_05;
			next_map = HADES_06;
			orpheus_spawnx = ((UINT16) SPAWNX_BOSSCHARON_IN << 3);
			orpheus_spawny = ((UINT16) SPAWNY_BOSSCHARON_IN << 3);
			a_walk_counter_y = -16;
            boss_intro = 0;
			next_state = StateBoss00;
		break;
		case HADES_06:
			prev_map = HADES_05;
			next_map = HADES_07;
			orpheus_spawnx = ((UINT16) SPAWNX_HADES004_IN << 3);
			orpheus_spawny = ((UINT16) SPAWNY_HADES004_IN << 3) + 4u;
			new_state = IDLE_DOWN;
			next_state = StateHades00;
		break;
		case HADES_07:
			prev_map = HADES_06;
			next_map = HADES_08;
			orpheus_spawnx = ((UINT16) SPAWNX_HADES007_IN << 3) + 4u;
			orpheus_spawny = ((UINT16) SPAWNY_HADES007_IN << 3) + 4u;
			new_state = IDLE_DOWN;
			next_state = StateHades00;
		break;
		case HADES_08:
			prev_map = HADES_07;
			next_map = HADES_09;
			orpheus_spawnx = ((UINT16) SPAWNX_HADES008_IN << 3) + 4u;
			orpheus_spawny = ((UINT16) SPAWNY_HADES008_IN << 3) + 4u;
			new_state = IDLE_DOWN;
			next_state = StateHades00;
		break;
		case HADES_09:
			prev_map = HADES_08;
			next_map = HADES_10;
			orpheus_spawnx = ((UINT16) SPAWNX_HADES009_IN << 3);
			orpheus_spawny = ((UINT16) SPAWNY_HADES009_IN << 3) + 4u;
			new_state = IDLE_DOWN;
			next_state = StateHades00;
		break;
		case HADES_10:
			prev_map = HADES_09;
			next_map = BOSS_CERBERUS;
			orpheus_spawnx = ((UINT16) SPAWNX_HADES010_IN << 3) + 2u;
			orpheus_spawny = ((UINT16) SPAWNY_HADES010_IN << 3) + 4u;
			new_state = IDLE_DOWN;
			next_state = StateHades00;
		break;
		case BOSS_CERBERUS:
			prev_map = HADES_10;
			next_map = HADES_11;
			orpheus_spawnx = ((UINT16) SPAWNX_BOSSCHARON_IN << 3);
			orpheus_spawny = ((UINT16) SPAWNY_BOSSCHARON_IN << 3) + 4u;
			new_state = IDLE_UP;
			a_walk_counter_y = -18;
            boss_intro = 0;
			next_state = StateBoss00;
		break;
		case HADES_11:
			prev_map = BOSS_CERBERUS;
			next_map = HADES_12;
			orpheus_spawnx = ((UINT16) SPAWNX_HADES011_IN << 3) + 2u;
			orpheus_spawny = ((UINT16) SPAWNY_HADES011_IN << 3) + 4u;
			next_state = StateHades00;
		break;
		case HADES_12:
			prev_map = HADES_11;
			next_map = HADES_13;
			orpheus_spawnx = ((UINT16) SPAWNX_HADES012_IN << 3) + 2u;
			orpheus_spawny = ((UINT16) SPAWNY_HADES012_IN << 3) + 4u;
			next_state = StateHades00;
			new_state = IDLE_DOWN;
		break;
		case HADES_13:
			prev_map = HADES_12;
			next_map = HADES_14;
			orpheus_spawnx = ((UINT16) SPAWNX_HADES013_IN << 3) + 2u;
			orpheus_spawny = ((UINT16) SPAWNY_HADES013_IN << 3) + 4u;
			next_state = StateHades00;
			new_state = IDLE_DOWN;
		break;
		case HADES_14:
			prev_map = HADES_13;
			next_map = HADES_15;
			orpheus_spawnx = ((UINT16) SPAWNX_HADES014_IN << 3) + 2u;
			orpheus_spawny = ((UINT16) SPAWNY_HADES014_IN << 3) + 4u;
			next_state = StateHades00;
			new_state = IDLE_DOWN;
		break;
		case HADES_15:
			prev_map = HADES_14;
			next_map = BOSS_MINOS;
			orpheus_spawnx = ((UINT16) SPAWNX_HADES015_IN << 3) + 4u;
			orpheus_spawny = ((UINT16) SPAWNY_HADES015_IN << 3) + 4u;
			next_state = StateHades00;
			new_state = IDLE_RIGHT;
		break;
		case BOSS_MINOS:
			prev_map = HADES_15;
			next_map = HADES_16;
			orpheus_spawnx = ((UINT16) SPAWNX_BOSSCHARON_IN << 3);
			orpheus_spawny = ((UINT16) SPAWNY_BOSSCHARON_IN << 3) + 2u;
            boss_intro = 0;
			new_state = IDLE_UP;
			a_walk_counter_y = -8;
			next_state = StateBoss00;
		break;
		case HADES_16:
			prev_map = BOSS_MINOS;
			next_map = HADES_17;
			orpheus_spawnx = ((UINT16) SPAWNX_HADES016_IN << 3) + 4u;
			orpheus_spawny = ((UINT16) SPAWNY_HADES016_IN << 3) + 4u;
			next_state = StateHades00;
			new_state = IDLE_UP;
		break;
		case HADES_17:
			prev_map = HADES_16;
			next_map = HADES_18;
			orpheus_spawnx = ((UINT16) SPAWNX_HADES017_IN << 3) + 4u;
			orpheus_spawny = ((UINT16) SPAWNY_HADES017_IN << 3) + 4u;
			next_state = StateHades00;
			new_state = IDLE_UP;
		break;
		case HADES_18:
			prev_map = HADES_17;
			next_map = HADES_19;
			orpheus_spawnx = ((UINT16) SPAWNX_HADES018_IN << 3) + 4u;
			orpheus_spawny = ((UINT16) SPAWNY_HADES018_IN << 3) + 4u;
			next_state = StateHades00;
			new_state = IDLE_UP;
		break;
		case HADES_19:
			prev_map = HADES_18;
			next_map = HADES_20;
			orpheus_spawnx = ((UINT16) SPAWNX_HADES019_IN << 3) + 4u;
			orpheus_spawny = ((UINT16) SPAWNY_HADES019_IN << 3) + 2u;
			next_state = StateHades00;
			new_state = IDLE_UP;
		break;
		case HADES_20:
			prev_map = HADES_19;
			next_map = BOSS_AEACUS;
			orpheus_spawnx = ((UINT16) SPAWNX_HADES020_IN << 3) + 4u;
			orpheus_spawny = ((UINT16) SPAWNY_HADES020_IN << 3) + 2u;
			next_state = StateHades00;
			new_state = IDLE_RIGHT;
		break;
		case BOSS_AEACUS:
			prev_map = HADES_20;
			next_map = HADES_21;
			orpheus_spawnx = ((UINT16) SPAWNX_BOSSAEACUS_IN << 3);
			orpheus_spawny = ((UINT16) SPAWNY_BOSSAEACUS_IN << 3);
            boss_intro = 0;
			new_state = IDLE_UP;
			a_walk_counter_y = -16;
			next_state = StateBoss00;
		break;
		case HADES_21:{
			prev_map = BOSS_AEACUS;
			next_map = HADES_22;
			orpheus_spawnx = ((UINT16) SPAWNX_HADES021_IN << 3);
			orpheus_spawny = ((UINT16) SPAWNY_HADES021_IN << 3) + 4u;
			next_state = StateHades00;
			new_state = IDLE_DOWN;
		}break;
		case HADES_22:{
			prev_map = HADES_21;
			next_map = HADES_23;
			orpheus_spawnx = ((UINT16) SPAWNX_HADES004_IN << 3);
			orpheus_spawny = ((UINT16) SPAWNY_HADES004_IN << 3) + 4u;
			next_state = StateHades00;
			new_state = IDLE_DOWN;
		}break;
		case HADES_23:{
			prev_map = HADES_22;
			next_map = HADES_24;
			orpheus_spawnx = ((UINT16) SPAWNX_HADES004_IN << 3);
			orpheus_spawny = ((UINT16) SPAWNY_HADES004_IN << 3) + 4u;
			next_state = StateHades00;
			new_state = IDLE_DOWN;
		}break;
		case HADES_24:{
			prev_map = HADES_23;
			next_map = HADES_25;
			orpheus_spawnx = ((UINT16) SPAWNX_HADES004_IN << 3);
			orpheus_spawny = ((UINT16) SPAWNY_HADES004_IN << 3) + 4u;
			next_state = StateHades00;
			new_state = IDLE_DOWN;
		}break;
		case HADES_25:{
			prev_map = HADES_24;
			next_map = HADES_26;
			orpheus_spawnx = ((UINT16) SPAWNX_HADES004_IN << 3);
			orpheus_spawny = ((UINT16) SPAWNY_HADES004_IN << 3) + 4u;
			next_state = StateHades00;
			new_state = IDLE_DOWN;
		}break;
		case HADES_26:{//RADAMANTHUS
			prev_map = HADES_25;
			next_map = HADES_27;
			orpheus_spawnx = ((UINT16) SPAWNX_HADES004_IN << 3);
			orpheus_spawny = ((UINT16) SPAWNY_HADES004_IN << 3) + 4u;
			new_state = IDLE_DOWN;
			next_state = StateHades00;
		}break;
		case HADES_27:{
			prev_map = HADES_26;
			next_map = BOSS_HADES;
			orpheus_spawnx = ((UINT16) SPAWNX_HADES004_IN << 3);
			orpheus_spawny = ((UINT16) SPAWNY_HADES004_IN << 3) + 4u;
			new_state = IDLE_DOWN;
			next_state = StateHades00;
		}break;
		case BOSS_HADES:
			prev_map = HADES_27;
			next_map = END_GAME;
			orpheus_spawnx = ((UINT16) SPAWNX_BOSSHADES_IN << 3);
			orpheus_spawny = ((UINT16) SPAWNY_BOSSHADES_IN << 3);
            boss_intro = 0;
			new_state = IDLE_UP;
			a_walk_counter_y = -10;
			next_state = StateBoss00;
		break;
	}
	SetState(next_state);
}

void go_to_prev_map() BANKED{
	changing_map = 1u;
	SpriteManagerRemoveSprite(s_orpheus);
	current_map = prev_map;
	UINT8 next_state = StateTutorial;
	a_walk_counter_x = 0;
	a_walk_counter_y = 0;
	if(!is_level_on_boss()){
		a_walk_counter_y = 8;
	}
	switch(prev_map){
		case TUTORIAL:
			prev_map = TUTORIAL;
			next_map = HADES_00;
			orpheus_spawnx = ((UINT16) SPAWNX_TUTORIAL << 3) + 4u;
			orpheus_spawny = ((UINT16) SPAWNY_TUTORIAL << 3);
			camera_spawnx = ((UINT16) SPAWNX_CAMERA_TUTORIAL << 3);
			camera_spawny = ((UINT16) SPAWNY_CAMERA_TUTORIAL << 3) + 6u;
		break;
		case HADES_00:
			prev_map = TUTORIAL;
			next_map = HADES_01;
			orpheus_spawnx = ((UINT16) SPAWNX_HADES000_OUT << 3);
			orpheus_spawny = ((UINT16) SPAWNY_HADES000_OUT << 3);
			camera_spawnx = ((UINT16) SPAWNX_CAMERA_HADES << 3);
			camera_spawny = ((UINT16) SPAWNY_CAMERA_HADES << 3) + 4;
			new_state = IDLE_DOWN;
			next_state = StateHades00;
		break;
		case HADES_01:
			prev_map = HADES_00;
			next_map = HADES_02;
			orpheus_spawnx = ((UINT16) SPAWNX_HADES001_OUT << 3);
			orpheus_spawny = ((UINT16) SPAWNY_HADES001_OUT << 3) + 4u;
			next_state = StateHades00;
		break;
		case HADES_02:
			prev_map = HADES_01;
			next_map = HADES_03;
			orpheus_spawnx = ((UINT16) SPAWNX_HADES002_OUT << 3);
			orpheus_spawny = ((UINT16) SPAWNY_HADES002_OUT << 3);
			next_state = StateHades00;
		break;
		case HADES_03:
			prev_map = HADES_02;
			next_map = HADES_04;
			orpheus_spawnx = ((UINT16) SPAWNX_HADES003_OUT << 3) + 4u;
			orpheus_spawny = ((UINT16) SPAWNY_HADES003_OUT << 3) + 2u;
			next_state = StateHades00;
		break;
		case HADES_04:
			prev_map = HADES_03;
			next_map = HADES_05;
			orpheus_spawnx = ((UINT16) SPAWNX_HADES004_OUT << 3) + 4u;
			orpheus_spawny = ((UINT16) SPAWNY_HADES004_OUT << 3) + 2u;
			next_state = StateHades00;
		break;
		case HADES_05:
			prev_map = HADES_04;
			next_map = BOSS_CHARON;
			orpheus_spawnx = ((UINT16) SPAWNX_HADES004_OUT << 3) + 4u;
			orpheus_spawny = ((UINT16) SPAWNY_HADES004_OUT << 3) + 2u;
			next_state = StateHades00;
		break;
		case HADES_06:
			prev_map = HADES_06;
			next_map = HADES_07;
			orpheus_spawnx = ((UINT16) SPAWNX_HADES006_OUT << 3);
			orpheus_spawny = ((UINT16) SPAWNY_HADES006_OUT << 3);
			new_state = IDLE_DOWN;
			next_state = StateHades00;
		break;
		case HADES_07:
			prev_map = HADES_06;
			next_map = HADES_08;
			new_state = IDLE_DOWN;
			orpheus_spawnx = ((UINT16) SPAWNX_HADES007_OUT << 3);
			orpheus_spawny = ((UINT16) SPAWNY_HADES007_OUT << 3) + 4u;
			next_state = StateHades00;
		break;
		case HADES_08:
			prev_map = HADES_07;
			next_map = HADES_09;
			orpheus_spawnx = ((UINT16) SPAWNX_HADES008_OUT << 3) + 4u;
			orpheus_spawny = ((UINT16) SPAWNY_HADES008_OUT << 3) + 2u;
			next_state = StateHades00;
		break;
		case HADES_09:
			prev_map = HADES_08;
			next_map = HADES_10;
			orpheus_spawnx = ((UINT16) SPAWNX_HADES009_OUT << 3) + 4u;
			orpheus_spawny = ((UINT16) SPAWNY_HADES009_OUT << 3) + 2u;
			next_state = StateHades00;
		break;
		case HADES_10:
			prev_map = HADES_09;
			next_map = BOSS_CERBERUS;
			orpheus_spawnx = ((UINT16) SPAWNX_HADES010_OUT << 3) + 4u;
			orpheus_spawny = ((UINT16) SPAWNY_HADES010_OUT << 3) + 2u;
			next_state = StateHades00;
		break;
		case HADES_11:
			prev_map = HADES_11;
			next_map = HADES_12;
			orpheus_spawnx = ((UINT16) SPAWNX_HADES011_OUT << 3) + 4u;
			orpheus_spawny = ((UINT16) SPAWNY_HADES011_OUT << 3) + 2u;
			next_state = StateHades00;
		break;
		case HADES_12:
			prev_map = HADES_11;
			next_map = HADES_13;
			orpheus_spawnx = ((UINT16) SPAWNX_HADES012_OUT << 3) + 4u;
			orpheus_spawny = ((UINT16) SPAWNY_HADES012_OUT << 3) + 2u;
			next_state = StateHades00;
		break;
		case HADES_13:
			prev_map = HADES_12;
			next_map = HADES_14;
			orpheus_spawnx = ((UINT16) SPAWNX_HADES013_OUT << 3) + 4u;
			orpheus_spawny = ((UINT16) SPAWNY_HADES013_OUT << 3) + 2u;
			next_state = StateHades00;
		break;
		case HADES_14:
			prev_map = HADES_13;
			next_map = HADES_15;
			orpheus_spawnx = ((UINT16) SPAWNX_HADES014_OUT << 3) + 4u;
			orpheus_spawny = ((UINT16) SPAWNY_HADES014_OUT << 3) + 2u;
			next_state = StateHades00;
		break;
		case HADES_15:
			prev_map = HADES_14;
			next_map = BOSS_MINOS;
			orpheus_spawnx = ((UINT16) SPAWNX_HADES004_OUT << 3) + 4u;
			orpheus_spawny = ((UINT16) SPAWNY_HADES004_OUT << 3) + 2u;
			next_state = StateHades00;
		break;
		case HADES_16:
			prev_map = HADES_16;
			next_map = HADES_17;
			orpheus_spawnx = ((UINT16) SPAWNX_HADES016_OUT << 3) + 4u;
			orpheus_spawny = ((UINT16) SPAWNY_HADES016_OUT << 3) + 2u;
			next_state = StateHades00;
		break;
		case HADES_17:
			prev_map = HADES_16;
			next_map = HADES_18;
			orpheus_spawnx = ((UINT16) SPAWNX_HADES017_OUT << 3) + 4u;
			orpheus_spawny = ((UINT16) SPAWNY_HADES017_OUT << 3) + 2u;
			next_state = StateHades00;
		break;
		case HADES_18:
			prev_map = HADES_17;
			next_map = HADES_19;
			orpheus_spawnx = ((UINT16) SPAWNX_HADES018_OUT << 3) + 4u;
			orpheus_spawny = ((UINT16) SPAWNY_HADES018_OUT << 3) + 2u;
			next_state = StateHades00;
		break;
		case HADES_19:
			prev_map = HADES_19;
			next_map = HADES_20;
			orpheus_spawnx = ((UINT16) SPAWNX_HADES019_OUT << 3) + 4u;
			orpheus_spawny = ((UINT16) SPAWNY_HADES019_OUT << 3) + 2u;
			next_state = StateHades00;
		break;
		case HADES_20:
			prev_map = HADES_19;
			next_map = BOSS_AEACUS;
			orpheus_spawnx = ((UINT16) SPAWNX_HADES020_OUT << 3) + 4u;
			orpheus_spawny = ((UINT16) SPAWNY_HADES020_OUT << 3) + 2u;
			next_state = StateHades00;
		break;
		case HADES_21:
			prev_map = HADES_21;
			next_map = HADES_22;
			orpheus_spawnx = ((UINT16) SPAWNX_HADES004_OUT << 3) + 4u;
			orpheus_spawny = ((UINT16) SPAWNY_HADES004_OUT << 3) + 2u;
			next_state = StateHades00;
		break;
		case HADES_22:
			prev_map = HADES_21;
			next_map = HADES_23;
			orpheus_spawnx = ((UINT16) SPAWNX_HADES004_OUT << 3) + 4u;
			orpheus_spawny = ((UINT16) SPAWNY_HADES004_OUT << 3) + 2u;
			next_state = StateHades00;
		break;
		case HADES_23:
			prev_map = HADES_22;
			next_map = HADES_24;
			orpheus_spawnx = ((UINT16) SPAWNX_HADES004_OUT << 3) + 4u;
			orpheus_spawny = ((UINT16) SPAWNY_HADES004_OUT << 3) + 2u;
			next_state = StateHades00;
		break;
		case HADES_24:
			prev_map = HADES_23;
			next_map = HADES_25;
			orpheus_spawnx = ((UINT16) SPAWNX_HADES004_OUT << 3) + 4u;
			orpheus_spawny = ((UINT16) SPAWNY_HADES004_OUT << 3) + 2u;
			next_state = StateHades00;
		break;
		case HADES_25:
			prev_map = HADES_24;
			next_map = HADES_26;
			orpheus_spawnx = ((UINT16) SPAWNX_HADES004_OUT << 3) + 4u;
			orpheus_spawny = ((UINT16) SPAWNY_HADES004_OUT << 3) + 2u;
			next_state = StateHades00;
		break;
		case HADES_26://RADAMANTHUS
			prev_map = HADES_25;
			next_map = HADES_27;
			orpheus_spawnx = ((UINT16) SPAWNX_HADES004_OUT << 3) + 4u;
			orpheus_spawny = ((UINT16) SPAWNY_HADES004_OUT << 3) + 2u;
			next_state = StateHades00;
		break;
		case HADES_27:
			prev_map = HADES_26;
			next_map = BOSS_HADES;
			orpheus_spawnx = ((UINT16) SPAWNX_HADES004_OUT << 3) + 4u;
			orpheus_spawny = ((UINT16) SPAWNY_HADES004_OUT << 3) + 2u;
			next_state = StateHades00;
		break;
		case BOSS_HADES:
			prev_map = HADES_27;
			next_map = END_GAME;
			orpheus_spawnx = ((UINT16) SPAWNX_HADES004_OUT << 3) + 4u;
			orpheus_spawny = ((UINT16) SPAWNY_HADES004_OUT << 3) + 2u;
			next_state = StateHades00;
		break;
	}
	SetState(next_state);
}

void solve_current_map() BANKED{
	if(solved_map < current_map){
		solved_map = current_map;
		my_play_fx(4u, 20, 0x3f, 0xe8, 0x4d, 0xc0, 0x00);
	}
	Anim_Opendoors();
}
