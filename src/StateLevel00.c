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

const UINT8 coll_tiles_intro[] = {4u, 15u, 16u, 17u, 18u ,19u, 20u, 21u, 22u, 23u, 24u, 25u, 32u, 33u, 34u, 35u, 36u, 40u, 41u, 51u, 53u, 60u, 61u, 62u, 63u, 64u, 65u, 80u,
82u, 87u, 88u, 89u, 90u, 91u, 92u, 93u, 94u, 95u, 96u, 106u,
108u, 109u, 110, 111, 114u,
//here the hit tiles
38u,
//exit
11u, 12u,
0};
const UINT8 coll_surface_intro[] = {1u, 66u, 67u,69u,70u, 97u, 98u, 0};

UINT8 tutorial_go = 0u;
UINT8 init_block_button = 0u;
Sprite* s_block_00 = 0;
Sprite* s_block_01 = 0;
Sprite* s_door = 0;
UINT8 tutorial_block_interact = 0u;
UINT8 tutorial_hades_entrance = 0u;
extern UINT8 in_dialog;
extern Sprite* s_orpheus;
extern INT8 a_walk_counter_y;
extern UINT8 button_pressed;
extern UINT16 orpheus_spawnx;
extern UINT16 orpheus_spawny;
extern UINT8 has_lyre;

extern void e_configure(Sprite* s_enemy, UINT8 sprite_type) BANKED;
extern void level_common_start() BANKED;
extern void level_common_update_play() BANKED;
extern void init_write_dialog(UINT8 nlines) BANKED;
extern void write_dialog() BANKED;
extern UINT8 prepare_dialog(WHOSTALKING arg_whostalking) BANKED;
extern void press_release_button(UINT16 x, UINT16 y, UINT8 t) BANKED;
extern void draw_button(UINT16 x, UINT16 y, UINT8 t) BANKED;

void START() {
	level_common_start();
	//SPRITES
		s_orpheus = SpriteManagerAdd(SpriteOrpheus, orpheus_spawnx, orpheus_spawny);
		if(tutorial_go == 0){
			scroll_target->y = s_orpheus->y - 16u;
			Sprite* s_item_heart = SpriteManagerAdd(SpriteItem, ((UINT16) 27u << 3), ((UINT16) 84u << 3));
			struct ItemInfo* heart_data = (struct ItemInfo*) s_item_heart->custom_data; 
			heart_data->item_type = HEART;
			heart_data->i_configured = 1;
		}
		if(has_lyre == 0){
			SpriteManagerAdd(SpriteLyre, ((UINT16) 7u << 3), ((UINT16) 39u << 3) +1);
		}
		if(button_pressed == 0){
			s_block_00 = SpriteManagerAdd(SpriteBlock, ((UINT16) 30u << 3), ((UINT16) 23u << 3) + 2u);
			struct ItemInfo* block00_data = (struct ItemInfo*) s_block_00->custom_data;
			block00_data->item_type = BLOCK;
			block00_data->i_configured = 1u;
			s_door = SpriteManagerAdd(SpriteBlock, ((UINT16) 29u << 3), ((UINT16) 5u << 3) + 2u);
			struct ItemInfo* door_data = (struct ItemInfo*) s_door->custom_data;
			door_data->item_type = DOOR;
			door_data->i_configured = 1u;
			s_block_01 = SpriteManagerAdd(SpriteBlock, ((UINT16) 25u << 3), ((UINT16) 9u << 3) + 2u);
			struct ItemInfo* block01_data = (struct ItemInfo*) s_block_01->custom_data;
			block01_data->item_type = BLOCK;
			block01_data->i_configured = 1u;
		}
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
	init_block_button = 0;
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
	//DIALOGS INTERRUPTS
		if(s_orpheus->y < ((UINT16) 30u << 3)){
			if(has_lyre == 1 && tutorial_block_interact == 0u){
				init_write_dialog(prepare_dialog(TUTORIAL_BLOCKS));
				tutorial_block_interact = 1u;
			}
		}
		if(s_orpheus->y < ((UINT16) 10u << 3)){
			if(tutorial_hades_entrance == 0 && button_pressed == 1){
				init_write_dialog(prepare_dialog(HADES_ENTRANCE));
				tutorial_hades_entrance = 1u;
			}
		}
	//BLOCK MANAGEMENT
		if(s_orpheus->y < ((UINT16) 28u << 3)){
			if(init_block_button == 0){
				if(button_pressed == 1){
					draw_button(27u, 12u, 124u);
				}else{
					s_block_01->x = (UINT16) 25u << 3;
					s_block_01->y = ((UINT16) 9u << 3) + 2u;
				}
				init_block_button = 1u;
			}
			if(button_pressed == 0){
				UINT8 tile = GetScrollTile((s_block_01->x + 8) >> 3, (s_block_01->y+8) >> 3);
				if(tile == 120u || tile == 121u || tile == 122u || tile == 123u){
					press_release_button(27u, 12u, 124u);
					struct ItemInfo* block01_data = (struct ItemInfo*) s_block_01->custom_data;
					block01_data->i_configured = 3;
					SpriteManagerRemoveSprite(s_door);
				}
			}
		}
		if(s_orpheus->y > ((UINT16) 16u << 3)){
			if(init_block_button == 1){
				init_block_button = 0;
			}
		}
}
