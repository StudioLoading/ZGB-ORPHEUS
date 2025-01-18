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
108u, 109u, 110, 111, 114u,115u,
//here the hit tiles
//exit
11u, 12u,
0};
const UINT8 coll_surface_intro[] = {1u, 66u, 67u,69u,70u, 97u, 98u, 0};

UINT8 gate_pushed = 0u;
UINT8 tutorial_push_button = 0u;
Sprite* s_gate = 0;
Sprite* s_gate_other = 0;
Sprite* s_butt3 = 0;

extern UINT8 tutorial_go;
extern UINT8 tutorial_hades_entrance;
extern UINT8 tutorial_get_lyre;
extern UINT8 in_dialog;
extern Sprite* s_orpheus;
extern INT8 a_walk_counter_y;
extern UINT8 button_pressed;
extern UINT16 orpheus_spawnx;
extern UINT16 orpheus_spawny;
extern UINT8 has_lyre;
extern MACROMAP solved_map;
extern MACROMAP current_map;
extern UINT8 other_gate_created;

extern void e_configure(Sprite* s_enemy, UINT8 sprite_type) BANKED;
extern void level_common_start() BANKED;
extern void level_common_update_play() BANKED;
extern void init_write_dialog(UINT8 nlines) BANKED;
extern void write_dialog() BANKED;
extern UINT8 prepare_dialog(WHOSTALKING arg_whostalking) BANKED;
extern void press_release_button(UINT16 x, UINT16 y, UINT8 t) BANKED;
extern void draw_button(UINT16 x, UINT16 y, UINT8 t) BANKED;
extern void solve_current_map() BANKED;

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
		other_gate_created = 0u;
		if(gate_pushed == 1u){
			s_gate = SpriteManagerAdd(SpriteGate, ((UINT16) 28u << 3), ((UINT16) 21u << 3)+3);
			draw_button(32u, 24u, 124u);
		}else{
			s_gate = SpriteManagerAdd(SpriteGate, ((UINT16) 29u << 3) + 3u, ((UINT16) 21u << 3) +3);
		}
		if(has_lyre == 0){
			SpriteManagerAdd(SpriteLyre, ((UINT16) 7u << 3), ((UINT16) 39u << 3) +1);
		}
		Sprite* s_butt1 = SpriteManagerAdd(SpriteButterfly, ((UINT16) 25u << 3), ((UINT16) 60u << 3));
		struct EnemyInfo* butt1_data = (struct EnemyInfo*) s_butt1->custom_data;
		butt1_data->e_configured = 1;
		Sprite* s_butt2 = SpriteManagerAdd(SpriteButterfly, ((UINT16) 35u << 3), ((UINT16) 58u << 3));
		struct EnemyInfo* butt2_data = (struct EnemyInfo*) s_butt2->custom_data;
		butt2_data->e_configured = 2;
		Sprite* s_dog = SpriteManagerAdd(SpriteDog, ((UINT16) 30u << 3), ((UINT16) 60u << 3));
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
	if(s_butt3 == 0 && s_orpheus->x < ((UINT16) 15u << 3)){
		s_butt3 = SpriteManagerAdd(SpriteButterfly, ((UINT16) 7u << 3), ((UINT16) 44u << 3));
		struct EnemyInfo* butt3_data = (struct EnemyInfo*) s_butt3->custom_data;
		butt3_data->e_configured = 1;
	}
	//DIALOGS INTERRUPTS
		if(s_orpheus->y < ((UINT16) 29u << 3)){
			if(has_lyre == 0){
				s_orpheus->y += 4u;
				init_write_dialog(prepare_dialog(MISSING_LYRE));
			}else if(gate_pushed == 0 && tutorial_push_button == 0u){
				s_orpheus->y -= 2u;
				tutorial_push_button = 1u;
				init_write_dialog(prepare_dialog(PUSH_BUTTON));
			}
		}
		if(s_orpheus->y < ((UINT16) 8u << 3)){
			if(tutorial_hades_entrance == 0){
				init_write_dialog(prepare_dialog(HADES_ENTRANCE));
				tutorial_hades_entrance = 1u;
			}
		}
	//GATES
		if(button_pressed == 0u && gate_pushed == 0){
			UINT8 tile = GetScrollTile((s_orpheus->x + 4) >> 3, (s_orpheus->y+12) >> 3);
			if(tile == 120u || tile == 121u || tile == 122u || tile == 123u){
				button_pressed = 1u;
				gate_pushed = 1u;
				struct EnemyInfo* g_data = (struct EnemyInfo*) s_gate->custom_data;
				g_data->e_configured = 1u;
				struct EnemyInfo* g_data_other = (struct EnemyInfo*) s_gate_other->custom_data;
				g_data_other->e_configured = 2u;
				solved_map = current_map;
				draw_button(32u, 24u, 124u);
			}
		}else{
			if(scroll_target->y > ((UINT16) 25u << 3) && scroll_target->y < ((UINT16) 35u << 3)){
				draw_button(32u, 24u, 124u);
			}
		}
}
