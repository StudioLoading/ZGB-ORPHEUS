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
#include "UtilsLoadSave.h"


IMPORT_MAP(maphades000);
IMPORT_MAP(maphades001);
IMPORT_MAP(maphades002);
IMPORT_MAP(maphades003);
IMPORT_MAP(maphades004);
IMPORT_MAP(maphades006);
IMPORT_MAP(hudmap);
DECLARE_MUSIC(danger);


const UINT8 coll_t_hades001[] = {1,3,4,5,9,10,11,13,14,17,18,19,20,
60, 61,63,64,66,
75,76, 107, 108, 111, 112,
//here the hit tiles
//84,85,86,87,
//prev
6,7,8,2,
//next
88,90,92,94,96,98,100,102,104,
//cartel
116, 118,
0};
const UINT8 coll_s_hades001[] = {0};

UINT8 dialog_block_interact = 0u;
UINT8 dialog_skeleton_lyre = 0u;
Sprite* s_block_00;
Sprite* s_block_01;
Sprite* s_blade;
UINT8 hades_music_started = 0u;
UINT8 show_cartel = 0u;
UINT8 death_countdown = 0u;

extern UINT8 in_dialog;
extern UINT8 init_block_button;
extern Sprite* s_orpheus;
extern UINT8 button_pressed;
extern UINT16 orpheus_spawnx;
extern UINT16 orpheus_spawny;
extern UINT8 tutorial_go;
extern UINT8 current_map;
extern UINT8 orpheus_haskey;
extern MACROMAP max_map;
extern MACROMAP solved_map;
extern UINT16 idle_countdown;
extern UINT8 area_enemy_counter;
extern UINT8 changing_map;
extern UINT8 sprite_stack_top;
extern UINT8 flag_button_repushable;

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
		if(sprite_stack_top > 0){
			RestoreSprites();
		}else if(solved_map < current_map){
			s_orpheus = SpriteManagerAdd(SpriteOrpheus, orpheus_spawnx, orpheus_spawny);
			switch(current_map){
				case HADES_ONE:{
					s_block_00 = SpriteManagerAdd(SpriteBlock, ((UINT16) 5u << 3), ((UINT16) 8u << 3) + 3u);
					struct ItemInfo* block00_data = (struct ItemInfo*) s_block_00->custom_data;
					block00_data->item_type = BLOCK;
					block00_data->i_configured = 1u;
				}break;
				case HADES_TWO:{
					if(orpheus_haskey == 0 || (orpheus_haskey == 1 && solved_map > current_map)){
						Sprite* s_key = SpriteManagerAdd(SpriteItem, ((UINT16) 17u << 3), ((UINT16) 15u << 3) - 3u);
						struct ItemInfo* key_data = (struct ItemInfo*) s_key->custom_data;
						key_data->item_type = KEY;
						key_data->i_configured = 1u;
					}
				}break;
				case HADES_THREE:{
					area_enemy_counter = 1;
					Sprite* e_enemy = SpriteManagerAdd(SpriteSkeleton, ((UINT16) 14u << 3), ((UINT16) 7u << 3));
					e_configure(e_enemy, SKELETON);
				}break;
				case HADES_FOUR:{
					area_enemy_counter = 3;
					Sprite* e_skeleton1 = SpriteManagerAdd(SpriteSkeleton, ((UINT16) 12u << 3), ((UINT16) 8u << 3));
					e_configure(e_skeleton1, SKELETON);
					
					Sprite* e_skeleton2 = SpriteManagerAdd(SpriteSkeleton, ((UINT16) 14u << 3), ((UINT16) 7u << 3));
					e_configure(e_skeleton2, SKELETON);

					Sprite* e_skeleton3 = SpriteManagerAdd(SpriteSkeleton, ((UINT16) 4u << 3), ((UINT16) 15u << 3) - 3u);
					e_configure(e_skeleton3, SKELETON);
				}break;
				case HADES_FIVE:{
					area_enemy_counter = 1;
					Sprite* e_dog = SpriteManagerAdd(SpriteDog, ((UINT16) 7u << 3), ((UINT16) 14u << 3) +3);
					e_configure(e_dog, DOG);
				}break;
				case HADES_SIX:{
					area_enemy_counter = 1;
					/*Sprite* e_skeleton1 = SpriteManagerAdd(SpriteSkeletonshield, ((UINT16) 12u << 3), ((UINT16) 8u << 3));
					e_configure(e_skeleton1, SKELETON_SHIELD);*/
					/*Sprite* e_infernalimp1 = SpriteManagerAdd(SpriteInfernalimp, ((UINT16) 4u << 3), ((UINT16) 10u << 3));
					e_configure(e_infernalimp1, INFERNALIMP);*/
					/*Sprite* e_lostsoul1 = SpriteManagerAdd(SpriteLostsoul, ((UINT16) 12u << 3), ((UINT16) 8u << 3));
					e_configure(e_lostsoul1, LOSTSOUL);*/
					/*s_blade = SpriteManagerAdd(SpriteBlade,((UINT16) 13u << 3), ((UINT16) 6u << 3));
					Sprite* e_skeleton1 = SpriteManagerAdd(SpriteSentinel, ((UINT16) 12u << 3), ((UINT16) 8u << 3));
					e_configure(e_skeleton1, SENTINEL);*/
					/*Sprite* e_skeleton2 = SpriteManagerAdd(SpriteOoze, ((UINT16) 13u << 3), ((UINT16) 10u << 3));
					e_configure(e_skeleton2, OOZE);*/
					Sprite* e_skeleton2 = SpriteManagerAdd(SpriteShadow, ((UINT16) 13u << 3), ((UINT16) 7u << 3));
					e_configure(e_skeleton2, SHADOW);
				}break;
			}
		}else{
			s_orpheus = SpriteManagerAdd(SpriteOrpheus, orpheus_spawnx, orpheus_spawny);
		}
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
			case HADES_THREE: 
				InitScroll(BANK(maphades003), &maphades003, coll_t_hades001, coll_s_hades001);
			break;
			case HADES_FOUR:
				InitScroll(BANK(maphades004), &maphades004, coll_t_hades001, coll_s_hades001);
			break;
			case HADES_FIVE:
				InitScroll(BANK(maphades004), &maphades004, coll_t_hades001, coll_s_hades001);
			break;
			case HADES_SIX:
				InitScroll(BANK(maphades006), &maphades006, coll_t_hades001, coll_s_hades001);
			break;
		}
	//HUD
        //INIT_FONT(font, PRINT_WIN);
        INIT_HUD(hudmap);
	//EXIT DOORS OPEN
		if(solved_map >= current_map){
			Anim_Opendoors();
		}
	//VARS & MUSIC
		if(hades_music_started == 0){
			PlayMusic(danger, 1);
			hades_music_started = 1;
		}
		if(current_map == HADES_SIX){
			flag_button_repushable = 1u;
		}
}

void UPDATE() {
	/*if(in_dialog){
		write_dialog();
	}*/
	if(tutorial_go > 0){
		level_common_update_play();
	}
	//DEATH COOLDOWN BEFORE CHANGING SCREEN
		if(death_countdown){
			death_countdown--;
			if(death_countdown == 0){
				prepare_dialog(HADES_DEATH);
				SetState(StateCartel);
			}
			return;
		}
	//DIALOGS
		if(show_cartel){
			switch(current_map){
				case HADES_ZERO:
					prepare_dialog(HADES_WELCOME);
				break;
				case HADES_ONE:
					prepare_dialog(HADES_MOVE_BLOCK);
				break;
				case HADES_TWO:
					prepare_dialog(HADES_USE_KEY);
				break;
				case HADES_THREE:
					prepare_dialog(HADES_KILL_ENEMY);
				break;
			}
			SaveSprites();
			SetState(StateCartel);
		}
	//BLOCK MANAGEMENT
		if(current_map == HADES_ONE){
			if(init_block_button == 0){
				if(button_pressed == 1 || solved_map >= current_map){
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
				}
			}
		}
		if(s_orpheus->y > ((UINT16) 16u << 3)){
			if(init_block_button == 1){
				init_block_button = 0;
			}
		}
	//GHOSTS
		if(current_map > HADES_TWO && current_map < BOSS_CHARON){
			if(in_dialog == 0 && idle_countdown < 10 && idle_countdown > 0){
				UINT16 ghost_spawnx = ((UINT16) 19u << 3);
				INT8 ghost_vx = -1;
				MirroMode ghost_mirror = NO_MIRROR;
				if(s_orpheus->x > scroll_target->x){
					ghost_spawnx = ((UINT16) 1u << 3);
					ghost_vx = 1;
					ghost_mirror = V_MIRROR;
				}
				Sprite* s_ghost = SpriteManagerAdd(SpriteGhost, ghost_spawnx, s_orpheus->y + 4u);
				struct EnemyInfo* ghost_data = (struct EnemyInfo*) s_ghost->custom_data;
				ghost_data->vx = ghost_vx;
				s_ghost->mirror = ghost_mirror;
				idle_countdown = 0;
			}
		}
}
