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


IMPORT_MAP(mapendgame);
IMPORT_MAP(hudmap);
IMPORT_TILES(font);
IMPORT_TILES(fontj);
DECLARE_MUSIC(danger2);

const UINT8 coll_tiles_endgame[] = {
0};
const UINT8 coll_surface_endgame[] = { 0};

Sprite* s_eg_orpheus = 0;
Sprite* s_eg_euridyce = 0;

extern UINT8 dialog_paused;
extern UINT8 in_dialog;
extern CHOSEN_LANGUAGE chosen_language;
extern UINT16 camera_spawnx;
extern UINT16 camera_spawny;
extern unsigned char EMPTY_STRING_20[];
extern UINT8 tutorial_go;
extern MACROMAP current_map;
extern UINT8 anim_counter;

extern void level_common_start() BANKED;
extern void level_common_update_play() BANKED;
extern void init_write_dialog(UINT8 nlines) BANKED;
extern void write_dialog() BANKED;
extern void my_play_fx(UINT8 c, UINT8 mute_frames, UINT8 s0, UINT8 s1, UINT8 s2, UINT8 s3, UINT8 s4) BANKED;
extern UINT8 prepare_dialog(WHOSTALKING arg_whostalking) BANKED;
extern void spawn_item(ITEM_TYPE arg_item_type, UINT16 arg_spawnx, UINT16 arg_spawny, UINT8 arg_hp_max) BANKED;

void endgame_anim() BANKED;

void START() {
	in_dialog = 0;
	camera_spawnx = 68u << 3;
	camera_spawny = 11u << 3;
	tutorial_go = 1;
	current_map = END_GAME;
	level_common_start();
		
	//SPRITES
		s_eg_orpheus = SpriteManagerAdd(SpriteEndgameorpheus, ((UINT16) 71u << 3), ((UINT16) 7u << 3) + 2);
		s_eg_euridyce = SpriteManagerAdd(SpriteEndgameeuridyce, ((UINT16) 73u << 3), ((UINT16) 8u << 3));
		
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
	if(tutorial_go > 0){
		level_common_update_play();
	}
	endgame_anim();
	//DIALOGS INTERRUPTS
		if(s_eg_orpheus->x < ((UINT16) 68u << 3)){
			init_write_dialog(prepare_dialog(MISSING_LYRE));
		}
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