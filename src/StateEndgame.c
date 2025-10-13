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

#define TIME_INTRO 100
#define GHOST_TIMER_MAX 40
#define GHOST_TIMER_ENDSCREEN 120

IMPORT_MAP(mapendgame);
IMPORT_MAP(hudmap);
IMPORT_TILES(font);
IMPORT_TILES(fontj);
DECLARE_MUSIC(danger2);
DECLARE_MUSIC(battle);
DECLARE_MUSIC(tutorial);

const UINT8 coll_tiles_endgame[] = {
0};
const UINT8 coll_surface_endgame[] = { 0};

typedef enum{
	INTRO_PAUSE,
	INTRO_DIALOG,
	INTRO_DIALOG_END,
	ORPHEUS_GO_LEFT,
	WAIT_CAMERA_MOVEMENT,
	ORPHEUS_GO_UP,
	TREMBLE,
	FALLING_BRICKS,
	ORPHEUS_TURN,
	ORPHEUS_DISAPPEAR,
	HADESCLAW_INTRO,
	HADESCLAW_APPEAR,
	HADESCLAW_UP,
	HADESCLAW_LEFT,
	HADESCLAW_DEPOSIT,
	EURIDYCE_GO_DOWN,
	EURIDYCE_GO_LEFT,
	EURIDYCE_MEET_BOX,
	OVER
}CUTSCENE_PHASE;

CUTSCENE_PHASE cutscene_phase = INTRO_PAUSE;
UINT8 cutscene_timer = 0u;
UINT16 orpheus_limx_first = 52u << 3;
UINT8 ghost_counter = 0u;
UINT8 ghost_timer = 0u;
UINT8 cutscene_frmskip = 0;
INT8 cutscene_frmskip_max = 0;
Sprite* s_eg_shadow = 0;
Sprite* s_eg_orpheus = 0;
Sprite* s_eg_euridyce = 0;
Sprite* s_eg_hadesclaw = 0;
Sprite* s_eg_box = 0;
UINT8 flag_eg_brick_crashed = 0u;

extern UINT8 dialog_paused;
extern UINT8 in_dialog;
extern CHOSEN_LANGUAGE chosen_language;
extern UINT16 camera_spawnx;
extern UINT16 camera_spawny;
extern unsigned char EMPTY_STRING_20[];
extern UINT8 tutorial_go;
extern MACROMAP current_map;
extern UINT8 anim_counter;
extern UINT8 move_camera_left;
extern UINT16 move_camera_destx;
extern UINT8 flag_camera_shake_v;
extern INT8 boss_hp_current;
extern INT16 shadow_blinking_hp;

extern void level_common_start() BANKED;
extern void level_common_update_play() BANKED;
extern void init_write_dialog(UINT8 nlines) BANKED;
extern void write_dialog() BANKED;
extern void my_play_fx(UINT8 c, UINT8 mute_frames, UINT8 s0, UINT8 s1, UINT8 s2, UINT8 s3, UINT8 s4) BANKED;
extern UINT8 prepare_dialog(WHOSTALKING arg_whostalking) BANKED;
extern void spawn_item(ITEM_TYPE arg_item_type, UINT16 arg_spawnx, UINT16 arg_spawny, UINT8 arg_hp_max) BANKED;
extern void move_camera() BANKED;
extern void eg_orpheus_go_up(Sprite* arg_s_eg_orpheus) BANKED;
extern void eg_orpheus_idle_up(Sprite* arg_s_eg_orpheus) BANKED;
extern void eg_orpheus_go_down(Sprite* arg_s_eg_orpheus) BANKED;
extern void eg_orpheus_blinking(Sprite* arg_s_eg_orpheus) BANKED;
extern void eg_euridyce_idleup(Sprite* arg_s_eg_euridyce) BANKED;
extern void eg_euridyce_idledown(Sprite* arg_s_eg_euridyce) BANKED;
extern void eg_euridyce_walkdown(Sprite* arg_s_eg_euridyce) BANKED;
extern void eg_euridyce_walkh(Sprite* arg_s_eg_euridyce) BANKED;
extern void eg_euridyce_idleh(Sprite* arg_s_eg_euridyce) BANKED;
extern void eg_euridyce_champion(Sprite* arg_s_eg_euridyce) BANKED;
extern void eg_hadesclaw_appear(Sprite* arg_s_eg_hadesclaw) BANKED;
extern void eg_box_absorb(Sprite* arg_s_box) BANKED;
extern void camera_shake_v() BANKED;

void endgame_anim() BANKED;
void spawn_ghost() BANKED;

void START() {
	in_dialog = 0;
	ghost_counter = 0u;
	ghost_timer = 0u;
	camera_spawnx = 68u << 3;
	camera_spawny = (11u << 3) - 2u;
	tutorial_go = 1;
	current_map = END_GAME;
	cutscene_timer = 0u;
	move_camera_destx = 0;
	move_camera_left = 0;
	cutscene_frmskip = 0u;
	cutscene_frmskip_max = 0u;
	flag_eg_brick_crashed = 0u;
	level_common_start();		
	//SPRITES
		s_eg_shadow = 0;
		s_eg_hadesclaw = 0;
		s_eg_orpheus = SpriteManagerAdd(SpriteEndgameorpheus, ((UINT16) 71u << 3), ((UINT16) 8u << 3) + 2u);
		s_eg_euridyce = SpriteManagerAdd(SpriteEndgameeuridyce, ((UINT16) 73u << 3), ((UINT16) 9u << 3) + 6u);

	//INITSCROLL
		InitScroll(BANK(mapendgame), &mapendgame, 0, 0);
	//HUD
		switch(chosen_language){
			case ENG: INIT_FONT(font, PRINT_BKG); break;
			case JAP: INIT_FONT(fontj, PRINT_BKG); break;
		}
		INIT_HUD(hudmap);		
		print_target = PRINT_WIN;
		PRINT(0, 0, EMPTY_STRING_20);
		PRINT(0, 1, EMPTY_STRING_20);
		PRINT(0, 2, EMPTY_STRING_20);
	//MUSIC
    	PlayMusic(danger2, 1);
}


void UPDATE() {
	if(in_dialog){
		if(dialog_paused){
			dialog_paused--;
		}else{
			write_dialog();
		}
	}
	ghost_timer++;
	if(cutscene_phase < OVER){
		if(ghost_timer > GHOST_TIMER_MAX){
			spawn_ghost();
		}
	}else{
		if(ghost_timer > GHOST_TIMER_ENDSCREEN){
			spawn_ghost();
		}
	}
	endgame_anim();
	switch(cutscene_phase){
		case INTRO_PAUSE:{
			if(cutscene_timer < TIME_INTRO){
				cutscene_timer++;
			}else{
				init_write_dialog(prepare_dialog(END_ORPHEUS_FOLLOW));
				cutscene_phase = INTRO_DIALOG;
			}
		}break;
		case INTRO_DIALOG:{
			if(in_dialog){ return; }
			else{
				PRINT(0, 0, EMPTY_STRING_20);
				PRINT(0, 1, EMPTY_STRING_20);
				PRINT(0, 2, EMPTY_STRING_20);
				cutscene_phase = ORPHEUS_GO_LEFT;
			}
		}break;
		case ORPHEUS_GO_LEFT:{
			UINT8 move_phase = 0u;
			if(scroll_target->x > ((31u << 3) + 3u)){
				scroll_target->x--;
			}else{
				move_phase++;
			}
			if(s_eg_orpheus->x > (((UINT16) 24u << 3) - 3u)){
				if(cutscene_frmskip < cutscene_frmskip_max){
					cutscene_frmskip++;
					return;
				}else{
					cutscene_frmskip = 0u;
				}
				if(scroll_target->x > ((31u << 3) + 3u)){
					if(s_eg_orpheus->x > (scroll_target->x - 40u)){
						cutscene_frmskip_max = 0;
					}else{
						cutscene_frmskip_max = 1;
					}
				}
				TranslateSprite(s_eg_orpheus, -1 << delta_time, 0);
				TranslateSprite(s_eg_euridyce, -1 << delta_time, 0);
			}else{
				move_phase++;
			}
			if(move_phase == 2){
				cutscene_frmskip = 0;
				cutscene_frmskip_max = 3;
				s_eg_euridyce->x += 2u;
				eg_orpheus_go_up(s_eg_orpheus);
				cutscene_phase = ORPHEUS_GO_UP;
			}
		}break;
		case ORPHEUS_GO_UP:{
			UINT8 move_phase = 0u;
			if(cutscene_frmskip < cutscene_frmskip_max){
				cutscene_frmskip++;
				return;
			}else{
				cutscene_frmskip = 0u;
			}
			if(s_eg_orpheus->y > 24u){
				TranslateSprite(s_eg_orpheus, 0, -1 << delta_time);
			}else{
				move_phase++;
			}
			if(s_eg_euridyce->x > 186u){
				TranslateSprite(s_eg_euridyce, -1 << delta_time, 0);
			}else{
				eg_euridyce_idleup(s_eg_euridyce);
				move_phase++;
			}
			if(move_phase == 2){
				eg_orpheus_idle_up(s_eg_orpheus);
				flag_camera_shake_v = 1;
				cutscene_timer = 0;
    			PlayMusic(battle, 1);
				cutscene_phase = TREMBLE;
			}
		}break;
		case TREMBLE:{
			if(cutscene_timer < TIME_INTRO){
				cutscene_timer++;
				camera_shake_v();
			}else{
				cutscene_timer = 0;
				init_write_dialog(prepare_dialog(END_ORPHEUS_EURIDYCE));
				s_eg_shadow = SpriteManagerAdd(SpriteRadamanthusshadow, s_eg_euridyce->x, s_eg_euridyce->y - 18u);
				struct EnemyInfo* shadow_data = (struct EnemyInfo*) s_eg_shadow->custom_data;
				shadow_data->tile_collision = MOVEMENT_NONE;
				shadow_data->e_configured = 1;
				shadow_blinking_hp = 40;
				cutscene_phase = FALLING_BRICKS;
				flag_camera_shake_v = 0;
			}
		}break;
		case FALLING_BRICKS:{
			camera_shake_v();
			if(flag_eg_brick_crashed){
				flag_eg_brick_crashed = 0;
				SpriteManagerRemoveSprite(s_eg_shadow);
				SpriteManagerAdd(SpriteEndgamehole, s_eg_euridyce->x, s_eg_euridyce->y - 16u);
				SpriteManagerAdd(SpriteEndgamehole, s_eg_euridyce->x + 6, s_eg_euridyce->y - 14u);
				eg_orpheus_go_down(s_eg_orpheus);
				cutscene_timer = 0;
			}
			if(in_dialog){ return; }
			else if(cutscene_timer == 0){
				PRINT(0, 0, EMPTY_STRING_20);
				PRINT(0, 1, EMPTY_STRING_20);
				PRINT(0, 2, EMPTY_STRING_20);
				cutscene_phase = ORPHEUS_TURN;
			}
		}break;
		case ORPHEUS_TURN:{
			if(cutscene_timer < TIME_INTRO){
				cutscene_timer++;
			}else{
				cutscene_timer = 0;
				eg_orpheus_blinking(s_eg_orpheus);
				init_write_dialog(prepare_dialog(END_EURIDYCE_NOOO));
				cutscene_phase = ORPHEUS_DISAPPEAR;
			}
		}break;
		case ORPHEUS_DISAPPEAR:{
			if(cutscene_timer < TIME_INTRO){
				cutscene_timer++;
			}else{
				if(in_dialog){ return; }
				PRINT(0, 0, EMPTY_STRING_20);
				PRINT(0, 1, EMPTY_STRING_20);
				PRINT(0, 2, EMPTY_STRING_20);
				cutscene_timer = 0;
				SpriteManagerRemoveSprite(s_eg_orpheus);
				s_eg_hadesclaw = SpriteManagerAdd(SpriteEndgamehadesclaw, s_eg_euridyce->x - 16u, s_eg_euridyce->y + 18u);
				cutscene_phase = HADESCLAW_APPEAR;
			}
		}break;
		case HADESCLAW_APPEAR:{
			if(cutscene_timer < TIME_INTRO){
				cutscene_timer++;
			}else{
				cutscene_timer = 0;
				eg_hadesclaw_appear(s_eg_hadesclaw);
				cutscene_phase = HADESCLAW_UP;
			}
		}break;
		case HADESCLAW_UP:{
			cutscene_frmskip++;
			if(cutscene_frmskip > cutscene_frmskip_max){
				cutscene_frmskip = 0;
				TranslateSprite(s_eg_hadesclaw, 0, -1 << delta_time);
			}
			s_eg_euridyce->x = s_eg_hadesclaw->x + 10u;
			s_eg_euridyce->y = s_eg_hadesclaw->y - 8u;
			if(s_eg_hadesclaw->y < 48u){
				cutscene_timer = 0;
				cutscene_phase = HADESCLAW_LEFT;
			}
		}break;
		case HADESCLAW_LEFT:{
			TranslateSprite(s_eg_hadesclaw, -1 << delta_time, 0);
			s_eg_euridyce->x = s_eg_hadesclaw->x + 10u;
			s_eg_euridyce->y = s_eg_hadesclaw->y - 8u;
			if(s_eg_hadesclaw->x < 104u){
				cutscene_timer = 0;
				eg_euridyce_idledown(s_eg_euridyce);
				SpriteManagerRemoveSprite(s_eg_hadesclaw);
				cutscene_phase = HADESCLAW_DEPOSIT;
			}
		}break;
		case HADESCLAW_DEPOSIT:{
			if(scroll_target->x > 80u){
				TranslateSprite(scroll_target, -1 << delta_time, 0);
			}else{
				if(cutscene_timer < TIME_INTRO){
					cutscene_timer++;
				}else{
					s_eg_box = SpriteManagerAdd(SpriteEndgamebox, 80u, 104u);
					cutscene_timer = 0;
					eg_euridyce_walkdown(s_eg_euridyce);
					cutscene_frmskip = 0;
					cutscene_frmskip_max = 3;
					PlayMusic(tutorial, 1);
					cutscene_phase = EURIDYCE_GO_DOWN;
				}
			}
		}break;
		case EURIDYCE_GO_DOWN:{
			if(s_eg_euridyce->y < s_eg_box->y){
				cutscene_frmskip++;
				if(cutscene_frmskip > cutscene_frmskip_max){
					cutscene_frmskip = 0;
					TranslateSprite(s_eg_euridyce, 0, 1 << delta_time);
				}
			}else if(s_eg_euridyce->x > (s_eg_box->x + 16u)){
				eg_euridyce_walkh(s_eg_euridyce);
				cutscene_frmskip++;
				if(cutscene_frmskip > cutscene_frmskip_max){
					cutscene_frmskip = 0;
					TranslateSprite(s_eg_euridyce, -1 << delta_time, 0);
				}
			}else{
				eg_euridyce_idleh(s_eg_euridyce);
				init_write_dialog(prepare_dialog(END_EURIDYCE_BOX));
				cutscene_timer = 0;
				cutscene_phase = EURIDYCE_MEET_BOX;
			}
		}break;
		case EURIDYCE_MEET_BOX:{
				if(cutscene_timer < TIME_INTRO){
					cutscene_timer++;
				}else{
					if(in_dialog){ return; }
					PRINT(0, 0, EMPTY_STRING_20);
					PRINT(0, 1, EMPTY_STRING_20);
					PRINT(0, 2, EMPTY_STRING_20);
					cutscene_timer = 0;
					s_eg_euridyce->x = 80u;
					s_eg_box->x = s_eg_euridyce->x - 4u;
					s_eg_box->y = s_eg_euridyce->y - 20u;
					eg_euridyce_champion(s_eg_euridyce);
					eg_box_absorb(s_eg_box);
					init_write_dialog(prepare_dialog(ENDSCREEN_SEEYOUIN2027));
					cutscene_phase = OVER;
				}
		}break;
	}
}

void spawn_ghost() BANKED{
	boss_hp_current = 2;
	ghost_timer = 0u;
	ghost_counter++;
	UINT16 spawn_ghostx = 0u;
	UINT16 spawn_ghosty = 0u;
	if(cutscene_phase <= ORPHEUS_DISAPPEAR){
		if(ghost_counter | 0){
			spawn_ghostx = s_eg_orpheus->x - 90u;
			spawn_ghosty = 24u;
		}else{
			spawn_ghostx = s_eg_orpheus->x - 80u;
			spawn_ghosty = 60u;
		}
	}else{
		if(ghost_counter | 0){
			spawn_ghostx = 12u;
			spawn_ghosty = 16u;
		}else{
			spawn_ghostx = 30u;
			spawn_ghosty = 40u;
		}
	}
	Sprite* s_ghost1 = SpriteManagerAdd(SpriteGhost, spawn_ghostx, spawn_ghosty);
	s_ghost1->lim_x = 80u;
	struct EnemyInfo* ghost1_data = (struct EnemyInfo*) s_ghost1->custom_data;
	s_ghost1->mirror = V_MIRROR;
	if(ghost_counter | 0){
		ghost1_data->vx = 4;
	}else{
		ghost1_data->vx = 3;
	}
	if(ghost_counter & 3){
		s_ghost1->y += 20u;
	}
	if(ghost_counter & 5){
		ghost1_data->vx = 6;
	}
	ghost1_data->vy = 4;
	if(cutscene_phase == OVER){
		ghost1_data->e_configured = 2;
	}
	s_ghost1 = 0;
}

void endgame_anim() BANKED{
	//ANIMS RIVER
		anim_counter+=4;
		if(anim_counter >= 96u){
			anim_counter = 0u;
		}
		switch(anim_counter){
			case 0u:{
				Anim_Cerberus_0();
			}break;
			case 12u: Anim_Charon_7(); break;
			case 24u: Anim_Charon_6(); break;
			case 36u: Anim_Charon_5(); break;
			case 48u: Anim_Charon_4(); break;
			case 60u: Anim_Charon_3(); break;
			case 72u: Anim_Charon_2(); break;
			case 84u: Anim_Charon_1(); break;
		}
}