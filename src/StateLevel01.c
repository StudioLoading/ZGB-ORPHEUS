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


IMPORT_MAP(maphades000);
IMPORT_MAP(hudmap);
IMPORT_TILES(font);

const UINT8 coll_t_hades000[] = {1,2,3,4,5,6,7,8,9,10,13,14,15,
 20,21,26,27,32,33,38,51,64,65,66,67,68,70,71,72,73,74,
//here the hit tiles
//exit
11,12,
0};
const UINT8 coll_s_hades000[] = {0};

extern UINT8 in_dialog;
extern UINT8 init_block_button;
extern Sprite* s_block_00;
extern Sprite* s_block_01;
extern Sprite* s_door;
extern UINT8 tutorial_block_interact;
extern UINT8 tutorial_hades_entrance;
extern Sprite* s_orpheus;
extern INT8 a_walk_counter_y;
extern UINT8 button_pressed;
extern UINT16 orpheus_spawnx;
extern UINT16 orpheus_spawny;
extern UINT8 has_lyre;
extern UINT8 tutorial_go;

extern void e_configure(Sprite* s_enemy, UINT8 sprite_type) BANKED;
extern void level_common_start() BANKED;
extern void level_common_update_play() BANKED;
extern void init_write_dialog(UINT8 nlines) BANKED;
extern void write_dialog() BANKED;
extern UINT8 prepare_dialog(WHOSTALKING arg_whostalking) BANKED;
extern void press_release_button(UINT16 x, UINT16 y, UINT8 t) BANKED;

void START() {
	level_common_start();
	//SPRITES
		s_orpheus = SpriteManagerAdd(SpriteOrpheus, orpheus_spawnx, orpheus_spawny);
		/*Sprite* s_item_heart = SpriteManagerAdd(SpriteItem, ((UINT16) 27u << 3), ((UINT16) 84u << 3));
		struct ItemInfo* heart_data = (struct ItemInfo*) s_item_heart->custom_data; 
		heart_data->item_type = HEART;
		heart_data->i_configured = 1;*/
		/*s_block_00 = SpriteManagerAdd(SpriteBlock, ((UINT16) 30u << 3), ((UINT16) 23u << 3) + 2u);
		struct ItemInfo* block00_data = (struct ItemInfo*) s_block_00->custom_data;
		block00_data->item_type = BLOCK;
		block00_data->i_configured = 1u;*/
		/*if(button_pressed == 0){
			s_door = SpriteManagerAdd(SpriteBlock, ((UINT16) 29u << 3), ((UINT16) 5u << 3) + 3u);
			struct ItemInfo* door_data = (struct ItemInfo*) s_door->custom_data;
			door_data->item_type = DOOR;
			door_data->i_configured = 1u;
		}*/
		//ENEMIES
		/*
		Sprite* e_enemy = SpriteManagerAdd(SpriteSkeleton, ((UINT16) 28u << 3), ((UINT16) 60u << 3));
		e_configure(e_enemy, SKELETON);
		*/
	//INITSCROLL
		InitScroll(BANK(maphades000), &maphades000, coll_t_hades000, coll_s_hades000);
	//HUD
        INIT_FONT(font, PRINT_BKG);
        INIT_HUD(hudmap);
	//TUTORIAL INIT OPRHEUS MOVEMENT
		if(tutorial_go == 0){
			a_walk_counter_y = -108;
		}
}

void UPDATE() {
	if(in_dialog){
		write_dialog();
	}
	if(tutorial_go > 0){
		level_common_update_play();
	}
	//DIALOGS INTERRUPTS
		/*if(s_orpheus->y < ((UINT16) 30u << 3)){
			if(has_lyre == 1 && tutorial_block_interact == 0u){
				init_write_dialog(prepare_dialog(TUTORIAL_BLOCKS));
				tutorial_block_interact = 1u;
			}
		}
		if(s_orpheus->y < ((UINT16) 10u << 3) && tutorial_hades_entrance == 0 && button_pressed == 1){
			init_write_dialog(prepare_dialog(HADES_ENTRANCE));
			tutorial_hades_entrance = 1u;
		}*/
	//BLOCK MANAGEMENT
		/*if(s_orpheus->y < ((UINT16) 28u << 3)){
			if(init_block_button == 0){
				s_block_01 = SpriteManagerAdd(SpriteBlock, ((UINT16) 25u << 3), ((UINT16) 9u << 3) + 2u);
				struct ItemInfo* block01_data = (struct ItemInfo*) s_block_01->custom_data;
				block01_data->item_type = BLOCK;
				block01_data->i_configured = 1u;
				init_block_button = 1u;
			}
			UINT8 tile = GetScrollTile((s_block_01->x + 8) >> 3, (s_block_01->y+8) >> 3);
			if(tile == 120u || tile == 121u || tile == 122u || tile == 123u){
				if(button_pressed == 0){
					press_release_button(27u, 12u, 124u);
					SpriteManagerRemoveSprite(s_door);
				}
			}else{
				if(button_pressed == 1){
					press_release_button(27u, 12u, 120u);
				}
			}
		}else{
			if(init_block_button == 1u){
				if(button_pressed == 0){
					s_block_01->x = ((UINT16) 25u << 3);
					s_block_01->y = ((UINT16) 9u << 3) + 2u;
				}
			}
		}*/
}
