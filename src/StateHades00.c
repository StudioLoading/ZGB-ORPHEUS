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
IMPORT_MAP(maphades001);
IMPORT_MAP(maphades002);
IMPORT_MAP(hudmap);
IMPORT_TILES(font);


const UINT8 coll_t_hades001[] = {1,3,4,5,9,10,11,13,14,17,18,19,20,66,
75,76,77,
//here the hit tiles
//prev
6,7,8,2,
//next
44,45,46,
0};
const UINT8 coll_s_hades001[] = {0};

UINT8 dialog_block_interact = 0u;

extern UINT8 in_dialog;
extern UINT8 init_block_button;
extern Sprite* s_block_00;
extern Sprite* s_block_01;
extern Sprite* s_door;
extern Sprite* s_key;
extern Sprite* s_orpheus;
extern INT8 a_walk_counter_y;
extern UINT8 button_pressed;
extern UINT16 orpheus_spawnx;
extern UINT16 orpheus_spawny;
extern UINT8 tutorial_go;
extern UINT8 current_map;
extern UINT8 orpheus_haskey;

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
		if(button_pressed == 0){
			switch(current_map){
				case HADES_ONE:{
					s_block_00 = SpriteManagerAdd(SpriteBlock, ((UINT16) 5u << 3), ((UINT16) 8u << 3) + 3u);
					struct ItemInfo* block00_data = (struct ItemInfo*) s_block_00->custom_data;
					block00_data->item_type = BLOCK;
					block00_data->i_configured = 1u;
					s_door = SpriteManagerAdd(SpriteBlock, ((UINT16) 15u << 3) + 5u, ((UINT16) 13u << 3) + 3u);
					struct ItemInfo* door_data = (struct ItemInfo*) s_door->custom_data;
					door_data->item_type = DOOR;
					door_data->i_configured = 1u;
				}break;
				case HADES_TWO:{
					s_door = SpriteManagerAdd(SpriteBlock, ((UINT16) 4u << 3) + 5u, ((UINT16) 12u << 3) + 1u);
					struct ItemInfo* door_data = (struct ItemInfo*) s_door->custom_data;
					door_data->item_type = DOOR_KEY;
					door_data->i_configured = 1u;
					if(orpheus_haskey == 0){
						s_key = SpriteManagerAdd(SpriteItem, ((UINT16) 17u << 3), ((UINT16) 15u << 3) - 3u);
						struct ItemInfo* key_data = (struct ItemInfo*) s_key->custom_data;
						key_data->item_type = KEY;
						key_data->i_configured = 1u;
					}
				}break;
			}
		}
		//ENEMIES
		/*
		Sprite* e_enemy = SpriteManagerAdd(SpriteSkeleton, ((UINT16) 28u << 3), ((UINT16) 60u << 3));
		e_configure(e_enemy, SKELETON);
		*/
	//INITSCROLL
		switch(current_map){
			case HADES_ZERO: 
				InitScroll(BANK(maphades000), &maphades000, coll_t_hades001, coll_s_hades001);
			break;
			case HADES_ONE: 
				InitScroll(BANK(maphades001), &maphades001, coll_t_hades001, coll_s_hades001);
			break;
			case HADES_TWO: 
				InitScroll(BANK(maphades002), &maphades002, coll_t_hades001, coll_s_hades001);
			break;
		}
	//HUD
        INIT_FONT(font, PRINT_WIN);
        INIT_HUD(hudmap);
	//VARS
}

void UPDATE() {
	if(in_dialog){
		write_dialog();
	}
	if(tutorial_go > 0){
		level_common_update_play();
	}
	//DIALOGS
		if(current_map == HADES_ONE){
			if(s_orpheus->y > ((UINT16) 6u << 3)){
				if(dialog_block_interact == 0u){
					init_write_dialog(prepare_dialog(TUTORIAL_BLOCKS));
					dialog_block_interact = 1u;
				}
			}
		}
	//BLOCK MANAGEMENT
		if(current_map == HADES_ONE){
			if(init_block_button == 0){
				if(button_pressed == 1){
					draw_button(1u, 15u, 71u);
				}else{
					s_block_01->x = (UINT16) 3u << 3;
					s_block_01->y = ((UINT16) 8u << 3) - 1u;
				}
				init_block_button = 1u;
			}
			if(button_pressed == 0){
				UINT8 tile = GetScrollTile((s_block_00->x + 8) >> 3, (s_block_00->y+8) >> 3);
				if(tile == 67u || tile == 68u || tile == 69u || tile == 70u){
					press_release_button(1u, 15u, 71u);
					struct ItemInfo* block00_data = (struct ItemInfo*) s_block_00->custom_data;
					block00_data->i_configured = 3;
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
