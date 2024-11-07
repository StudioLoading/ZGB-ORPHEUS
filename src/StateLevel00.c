#include "Banks/SetAutoBank.h"

#include "BankManager.h"
#include "ZGBMain.h"
#include "Palette.h"
#include "Scroll.h"
#include "Sprite.h"
#include "SpriteManager.h"
#include "string.h"
#include "Print.h"

#include "custom_datas.h"
#include "Dialog.h"


IMPORT_MAP(omapintro);
IMPORT_MAP(hudmap);
IMPORT_TILES(font);

const UINT8 coll_tiles_intro[] = {4u, 15u, 16u, 17u, 18u ,19u, 20u, 21u, 22u, 23u, 24u, 25u, 32u, 33u, 34u, 35u, 36u, 40u, 41u, 51u, 53u, 60u, 61u, 62u, 63u, 64u, 65u, 
82u, 87u, 88u, 89u, 90u, 91u, 92u, 93u, 94u, 95u, 96u, 105u, 106u,
108u, 109u,
//here the hit tiles
120, 121, 122, 123, 124, 125, 126, 127,
0};
const UINT8 coll_surface_intro[] = {1u, 66u, 67u,69u,70u, 97u, 98u, 0};

UINT8 tutorial_go = 0u;
UINT8 in_dialog = 0u;
extern Sprite* s_orpheus;
extern INT8 a_walk_counter_y;

void UpdateHUD() BANKED;
void fill_bar_idx(UINT8 i, UINT8 r);

extern void e_configure(Sprite* s_enemy, UINT8 sprite_type) BANKED;
extern void level_common_start() BANKED;
extern void level_common_update_play() BANKED;
extern void init_write_dialog(UINT8 nlines) BANKED;
extern void write_dialog() BANKED;
extern UINT8 prepare_dialog(WHOSTALKING arg_whostalking) BANKED;

void START() {
	level_common_start();
	//SPRITES
		s_orpheus = SpriteManagerAdd(SpriteOrpheus, ((UINT16) 28u << 3) - 4u, ((UINT16) 79u << 3));
		scroll_target->y = s_orpheus->y - 16u;
		Sprite* s_item_heart = SpriteManagerAdd(SpriteItem, ((UINT16) 27u << 3), ((UINT16) 84u << 3));
		struct ItemInfo* heart_data = (struct ItemInfo*) s_item_heart->custom_data; 
		heart_data->item_type = HEART;
		heart_data->i_configured = 1;
		Sprite* lyre = SpriteManagerAdd(SpriteLyre, ((UINT16) 7u << 3), ((UINT16) 39u << 3) +1);
		Sprite* s_block = SpriteManagerAdd(SpriteBlock, ((UINT16) 30u << 3), ((UINT16) 23u << 3) + 6u);
		//ENEMIES
		/*
		Sprite* e_enemy = SpriteManagerAdd(SpriteSkeleton, ((UINT16) 28u << 3), ((UINT16) 60u << 3));
		e_configure(e_enemy, SKELETON);
		*/
	//INITSCROLL
		InitScroll(BANK(omapintro), &omapintro, coll_tiles_intro, coll_surface_intro);
	//HUD
        INIT_FONT(font, PRINT_BKG);
        INIT_HUD(hudmap);
	//TUTORIAL INIT OPRHEUS MOVEMENT
		if(tutorial_go == 0){
			a_walk_counter_y = -108;
		}
}

void UPDATE() {
	if(tutorial_go == 0){
		scroll_target->y = s_orpheus->y - 16u;
		if(s_orpheus->y <= ((UINT16) 66u << 3)){
			s_orpheus->y = (UINT16) 66u << 3;
			scroll_target->y = (UINT16) 64u << 3;
			tutorial_go = 1;
			//show first dialog
			init_write_dialog(prepare_dialog(FIRSTEVER));
		}
	}
	if(in_dialog){
		write_dialog();
	}
	if(tutorial_go > 0){
		level_common_update_play();
	}
}
