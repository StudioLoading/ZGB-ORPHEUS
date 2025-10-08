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
IMPORT_MAP(maphades005);
IMPORT_MAP(maphades006);
IMPORT_MAP(maphades007);
IMPORT_MAP(maphades008);
IMPORT_MAP(maphades009);
IMPORT_MAP(maphades010);
IMPORT_MAP(maphades011);
IMPORT_MAP(maphades012);
IMPORT_MAP(maphades013);
IMPORT_MAP(maphades014);
IMPORT_MAP(maphades015);
IMPORT_MAP(maphades016);
IMPORT_MAP(maphades017);
IMPORT_MAP(maphades018);
IMPORT_MAP(maphades019);
IMPORT_MAP(maphades020);
IMPORT_MAP(maphades021);
IMPORT_MAP(maphades022);
IMPORT_MAP(maphades023);
IMPORT_MAP(maphades024);
IMPORT_MAP(maphades025);
IMPORT_MAP(maphades026);
IMPORT_MAP(hudmap);
DECLARE_MUSIC(danger);
DECLARE_MUSIC(danger2);
DECLARE_MUSIC(death);


const UINT8 coll_t_hades001[] = {1,3,4,5,9,10,11,13,14,17,18,19,
60,61,63,64,
75,76, 107, 108, 111, 112,
//prev
6,7,8,
//next
88,90,92,94,96,98,100,102,104,
//cartel
116, 118,
0};
const UINT8 coll_t_hades003[] = {1,3,4,5,9,10,11,13,14,17,18,19,
60,61,63,64,
75,76, 107, 108, 111, 112,
//prev
6,7,8,
//next
88,90,92,94,96,98,100,102,104,
//cartel
116, 118,
//column
34, 38, 33, 37,
0};
const UINT8 coll_s_hades001[] = {0};

UINT8 dialog_block_interact = 0u;
UINT8 dialog_skeleton_lyre = 0u;
Sprite* s_block_00;
Sprite* s_blade;
Sprite* s_radamanthusshadow = 0;
UINT8 hades_music_started = 0u;
UINT8 show_cartel = 0u;
UINT8 death_countdown = 0u;
struct ItemSpawnedByCommon item_spawned_by_common = {
		.e_unique_id = 0,
        .sprite_type = 0,
        .item_type = ITEM_NONE,
        .spawned = 0
};

void play_death_music() BANKED;

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
extern UINT8 sprite_stack_top;
extern UINT8 flag_button_repushable;
extern UINT8 flag_paused;

extern void e_configure(Sprite* s_enemy) BANKED;
extern void level_common_start() BANKED;
extern void level_common_update_play() BANKED;
extern void level_common_anim() BANKED;
extern UINT8 prepare_dialog(WHOSTALKING arg_whostalking) BANKED;
extern void press_release_button(UINT16 x, UINT16 y, UINT8 t) BANKED;
extern void draw_button(UINT16 x, UINT16 y, UINT8 t) BANKED;
extern void solve_current_map() BANKED;
extern UINT8 is_level_with_repushable_button() BANKED;
extern void spawn_item(ITEM_TYPE arg_item_type, UINT16 arg_spawnx, UINT16 arg_spawny, UINT8 arg_hp_max) BANKED;

void START() {
	level_common_start();
	//SPRITES
		if(sprite_stack_top > 0){
			RestoreSprites();
		}else if(solved_map < current_map){
			item_spawned_by_common.e_unique_id = 0;
			item_spawned_by_common.sprite_type = 0;
			item_spawned_by_common.item_type = 0;
			item_spawned_by_common.spawned = 0;
			s_orpheus = SpriteManagerAdd(SpriteOrpheus, orpheus_spawnx, orpheus_spawny);
			switch(current_map){
				case HADES_00:{
					Sprite* s_carteltext = SpriteManagerAdd(SpriteCarteltext, 6u << 3, 13u << 3);
				}break;
				case HADES_01:{
					s_block_00 = SpriteManagerAdd(SpriteBlock, ((UINT16) 5u << 3), ((UINT16) 8u << 3) + 3u);
					struct ItemInfo* block00_data = (struct ItemInfo*) s_block_00->custom_data;
					block00_data->item_type = BLOCK;
					block00_data->i_configured = 1u;
					Sprite* s_carteltext = SpriteManagerAdd(SpriteCarteltext, 1u << 3, 4u << 3);
				}break;
				case HADES_02:{
					if(orpheus_haskey == 0 || (orpheus_haskey == 1 && solved_map > current_map)){
						spawn_item(KEY,  ((UINT16) 17u << 3), ((UINT16) 15u << 3) - 3u, 0);
					}
					Sprite* s_carteltext = SpriteManagerAdd(SpriteCarteltext, 5u << 3, 4u << 3);
				}break;
				case HADES_03:{
					area_enemy_counter = 1;
					Sprite* e_enemy = SpriteManagerAdd(SpriteSkeleton, ((UINT16) 14u << 3), ((UINT16) 7u << 3));
					e_configure(e_enemy);
					Sprite* s_carteltext = SpriteManagerAdd(SpriteCarteltext, 6u << 3, 4u << 3);
				}break;
				case HADES_04:{
					area_enemy_counter = 2;
					Sprite* e_skeleton1 = SpriteManagerAdd(SpriteInfernalimp, ((UINT16) 13u << 3), ((UINT16) 7u << 3));
					e_configure(e_skeleton1);
					Sprite* e_skeleton2 = SpriteManagerAdd(SpriteInfernalimp, ((UINT16) 14u << 3), ((UINT16) 14u << 3) - 3u);
					e_configure(e_skeleton2);
				}break;
				case HADES_05:{
					area_enemy_counter = 1;
					Sprite* e_dog = SpriteManagerAdd(SpriteDog, ((UINT16) 7u << 3), ((UINT16) 14u << 3) +3);
					e_configure(e_dog);
					if(orpheus_haskey == 0 || (orpheus_haskey == 1 && solved_map > current_map)){
						item_spawned_by_common.e_unique_id = e_dog->unique_id;
						item_spawned_by_common.sprite_type = SpriteDog;
						item_spawned_by_common.item_type = KEY;
						item_spawned_by_common.spawned = 0;
					}
					Sprite* s_carteltext = SpriteManagerAdd(SpriteCarteltext, 1u << 3, 4u << 3);
				}break;
				//BOSS CHARON
				case HADES_06:{
					area_enemy_counter = 2;
					Sprite* e_skeleton1 = SpriteManagerAdd(SpriteSkeletonshield, ((UINT16) 14u << 3), ((UINT16) 7u << 3));
					e_configure(e_skeleton1);
					Sprite* e_skeleton2 = SpriteManagerAdd(SpriteSkeletonshield, ((UINT16) 8u << 3), ((UINT16) 14u << 3));
					e_configure(e_skeleton2);
					Sprite* s_carteltext = SpriteManagerAdd(SpriteCarteltext, 16u << 3, 4u << 3);
				}break;
				case HADES_07:{
					area_enemy_counter = 2;
					Sprite* e_skeleton1 = SpriteManagerAdd(SpriteLostsoul, ((UINT16) 17u << 3), ((UINT16) 6u << 3));
					e_configure(e_skeleton1);
					Sprite* e_skeleton2 = SpriteManagerAdd(SpriteLostsoul, ((UINT16) 1u << 3), ((UINT16) 10u << 3));
					e_configure(e_skeleton2);
				}break;
				case HADES_08:{
					area_enemy_counter = 2;
					Sprite* e_skeleton1 = SpriteManagerAdd(SpriteRevenant, ((UINT16) 2u << 3), ((UINT16) 9u << 3));
					e_configure(e_skeleton1);
					Sprite* e_skeleton2 = SpriteManagerAdd(SpriteRevenant, ((UINT16) 17u << 3), ((UINT16) 16u << 3));
					e_configure(e_skeleton2);
					if(orpheus_haskey == 0 || (orpheus_haskey == 1 && solved_map > current_map)){
						spawn_item(KEY,  ((UINT16) 12u << 3), ((UINT16) 15u << 3) - 3u, 0);
					}
					Sprite* s_carteltext = SpriteManagerAdd(SpriteCarteltext, 1u << 3, 4u << 3);
				}break;
				case HADES_09:{
					Sprite* e_skeleton1 = SpriteManagerAdd(SpriteInfernalimp, ((UINT16) 17u << 3), ((UINT16) 15u << 3));
					e_configure(e_skeleton1);
					Sprite* e_skeleton2 = SpriteManagerAdd(SpriteInfernalimp, ((UINT16) 1u << 3), ((UINT16) 5u << 3));
					e_configure(e_skeleton2);
					s_block_00 = SpriteManagerAdd(SpriteBlock, ((UINT16) 8u << 3) + 5u, ((UINT16) 12u << 3));
					struct ItemInfo* block00_data = (struct ItemInfo*) s_block_00->custom_data;
					block00_data->item_type = BLOCK;
					block00_data->i_configured = 1u;
					item_spawned_by_common.e_unique_id = e_skeleton2->unique_id;
					item_spawned_by_common.sprite_type = SpriteInfernalimp;
					item_spawned_by_common.item_type = HEART;
					item_spawned_by_common.spawned = 0;
				}break;
				case HADES_10:{
					area_enemy_counter = 3;
					Sprite* e_skeleton1 = SpriteManagerAdd(SpriteSkeleton, ((UINT16) 2u << 3), ((UINT16) 5u << 3));
					e_configure(e_skeleton1);
					Sprite* e_skeleton2 = SpriteManagerAdd(SpriteSkeleton, ((UINT16) 14u << 3), ((UINT16) 15u << 3));
					e_configure(e_skeleton2);
					Sprite* e_skeleton3 = SpriteManagerAdd(SpriteSkeleton, ((UINT16) 11u << 3), ((UINT16) 8u << 3));
					e_configure(e_skeleton3);
					item_spawned_by_common.e_unique_id = e_skeleton3->unique_id;
					item_spawned_by_common.sprite_type = SpriteSkeleton;
					item_spawned_by_common.item_type = HEART;
					item_spawned_by_common.spawned = 0;
				}break;
				//BOSS CERBERUS
				case HADES_11:{
					area_enemy_counter = 3;
					Sprite* e_skeleton1 = SpriteManagerAdd(SpriteSentinel, ((UINT16) 17u << 3), ((UINT16) 7u << 3));
					e_configure(e_skeleton1);
					Sprite* e_skeleton2 = SpriteManagerAdd(SpriteSentinel, ((UINT16) 12u << 3), ((UINT16) 5u << 3));
					e_configure(e_skeleton2);
					Sprite* e_skeleton3 = SpriteManagerAdd(SpriteSentinel, ((UINT16) 12u << 3), ((UINT16) 15u << 3));
					e_configure(e_skeleton3);
				}break;
				case HADES_12:{
					Sprite* e_skeleton1 = SpriteManagerAdd(SpriteSentinel, ((UINT16) 13u << 3), ((UINT16) 7u << 3));
					e_configure(e_skeleton1);
					s_block_00 = SpriteManagerAdd(SpriteBlock, ((UINT16) 4u << 3) + 5u, ((UINT16) 13u << 3));
					struct ItemInfo* block00_data = (struct ItemInfo*) s_block_00->custom_data;
					block00_data->item_type = BLOCK;
					block00_data->i_configured = 1u;
				}break;
				case HADES_13:{
					if(orpheus_haskey == 0 || (orpheus_haskey == 1 && solved_map > current_map)){
						spawn_item(KEY,  ((UINT16) 1u << 3), ((UINT16) 5u << 3), 0);
					}
					Sprite* e_skeleton1 = SpriteManagerAdd(SpriteShadow, ((UINT16) 16u << 3), ((UINT16) 14u << 3));
					e_configure(e_skeleton1);
					Sprite* e_skeleton2 = SpriteManagerAdd(SpriteShadow, ((UINT16) 11u << 3), ((UINT16) 6u << 3));
					e_configure(e_skeleton2);
					item_spawned_by_common.e_unique_id = e_skeleton2->unique_id;
					item_spawned_by_common.sprite_type = SpriteShadow;
					item_spawned_by_common.item_type = HEART;
					item_spawned_by_common.spawned = 0;
				}break;
				case HADES_14:{
					area_enemy_counter = 3;
					Sprite* e_skeleton1 = SpriteManagerAdd(SpriteSiren, ((UINT16) 8u << 3), ((UINT16) 6u << 3));
					e_configure(e_skeleton1);
					Sprite* e_skeleton2 = SpriteManagerAdd(SpriteSiren, ((UINT16) 17u << 3), ((UINT16) 12u << 3));
					e_configure(e_skeleton2);
					Sprite* e_skeleton3 = SpriteManagerAdd(SpriteSiren, ((UINT16) 6u << 3), ((UINT16) 15u << 3));
					e_configure(e_skeleton3);
					item_spawned_by_common.e_unique_id = e_skeleton3->unique_id;
					item_spawned_by_common.sprite_type = SpriteSiren;
					item_spawned_by_common.item_type = HEART;
					item_spawned_by_common.spawned = 0;
				}break;
				case HADES_15:{
					Sprite* e_skeleton1 = SpriteManagerAdd(SpriteTartarus, ((UINT16) 14u << 3), ((UINT16) 5u << 3));
					e_configure(e_skeleton1);
					Sprite* e_skeleton2 = SpriteManagerAdd(SpriteTartarus, ((UINT16) 17u << 3), ((UINT16) 12u << 3));
					e_configure(e_skeleton2);
					Sprite* e_skeleton3 = SpriteManagerAdd(SpriteTartarus, ((UINT16) 2u << 3), ((UINT16) 15u << 3));
					e_configure(e_skeleton3);
					if(orpheus_haskey == 0 || (orpheus_haskey == 1 && solved_map > current_map)){
						item_spawned_by_common.e_unique_id = e_skeleton1->unique_id;
						item_spawned_by_common.sprite_type = SpriteTartarus;
						item_spawned_by_common.item_type = KEY;
						item_spawned_by_common.spawned = 0;
					}
				}break;
				//BOSS MINOS
				case HADES_16:{
					area_enemy_counter = 3;
					Sprite* e_skeleton1 = SpriteManagerAdd(SpriteBanshee, ((UINT16) 3u << 3), ((UINT16) 6u << 3));
					e_configure(e_skeleton1);
					Sprite* e_skeleton2 = SpriteManagerAdd(SpriteBanshee, ((UINT16) 6u << 3), ((UINT16) 14u << 3));
					e_configure(e_skeleton2);
					Sprite* e_skeleton3 = SpriteManagerAdd(SpriteBanshee, ((UINT16) 16u << 3), ((UINT16) 9u << 3));
					e_configure(e_skeleton3);
					item_spawned_by_common.e_unique_id = e_skeleton2->unique_id;
					item_spawned_by_common.sprite_type = SpriteBanshee;
					item_spawned_by_common.item_type = HEART;
					item_spawned_by_common.spawned = 0;
				}break;
				case HADES_17:{
					s_block_00 = SpriteManagerAdd(SpriteBlock, ((UINT16) 8u << 3) + 4u, ((UINT16) 14u << 3));
					struct ItemInfo* block00_data = (struct ItemInfo*) s_block_00->custom_data;
					block00_data->item_type = BLOCK;
					block00_data->i_configured = 1u;
					Sprite* e_skeleton1 = SpriteManagerAdd(SpriteMagma, ((UINT16) 8u << 3), ((UINT16) 10u << 3));
					e_configure(e_skeleton1);
					Sprite* e_skeleton2 = SpriteManagerAdd(SpriteMagma, ((UINT16) 3u << 3), ((UINT16) 14u << 3));
					e_configure(e_skeleton2);
					item_spawned_by_common.e_unique_id = e_skeleton1->unique_id;
					item_spawned_by_common.sprite_type = SpriteMagma;
					item_spawned_by_common.item_type = HEART;
					item_spawned_by_common.spawned = 0;
				}break;
				case HADES_18:{
					if(orpheus_haskey == 0 || (orpheus_haskey == 1 && solved_map > current_map)){
						spawn_item(KEY,  ((UINT16) 3u << 3), ((UINT16) 15u << 3), 0);
					}
					spawn_item(HEART,  ((UINT16) 15u << 3), ((UINT16) 15u << 3), 2);
					s_blade = SpriteManagerAdd(SpriteBlade, ((UINT16) 7u << 3), ((UINT16) 14u << 3));
				}break;
				case HADES_19:{
					//area_enemy_counter = 3;
					Sprite* e_skeleton1 = SpriteManagerAdd(SpriteSiren, ((UINT16) 2u << 3), ((UINT16) 5u << 3));
					e_configure(e_skeleton1);
					Sprite* e_skeleton2 = SpriteManagerAdd(SpriteSiren, ((UINT16) 9u << 3), ((UINT16) 7u << 3));
					e_configure(e_skeleton2);
					Sprite* e_skeleton3 = SpriteManagerAdd(SpriteSiren, ((UINT16) 14u << 3), ((UINT16) 13u << 3));
					e_configure(e_skeleton3);
					if(orpheus_haskey == 0 || (orpheus_haskey == 1 && solved_map > current_map)){
						item_spawned_by_common.e_unique_id = e_skeleton1->unique_id;
						item_spawned_by_common.sprite_type = SpriteSiren;
						item_spawned_by_common.item_type = KEY;
						item_spawned_by_common.spawned = 0;
					}
				}break;
				case HADES_20:{
					area_enemy_counter = 4;
					Sprite* e_skeleton1 = SpriteManagerAdd(SpriteOoze, ((UINT16) 2u << 3), ((UINT16) 6u << 3));
					e_configure(e_skeleton1);
					Sprite* e_skeleton2 = SpriteManagerAdd(SpriteOoze, ((UINT16) 7u << 3), ((UINT16) 7u << 3));
					e_configure(e_skeleton2);
					Sprite* e_skeleton3 = SpriteManagerAdd(SpriteOoze, ((UINT16) 11u << 3), ((UINT16) 8u << 3));
					e_configure(e_skeleton3);
					Sprite* e_skeleton4 = SpriteManagerAdd(SpriteOoze, ((UINT16) 4u << 3), ((UINT16) 11u << 3));
					e_configure(e_skeleton4);
					item_spawned_by_common.e_unique_id = e_skeleton1->unique_id;
					item_spawned_by_common.sprite_type = SpriteOoze;
					item_spawned_by_common.item_type = HEART;
					item_spawned_by_common.spawned = 0;
				}break;
				//BOSS AEACUS
				case HADES_21:{
					area_enemy_counter = 2;
					Sprite* e_skeleton1 = SpriteManagerAdd(SpriteSerpent, ((UINT16) 6u << 3), ((UINT16) 7u << 3));
					e_configure(e_skeleton1);
					Sprite* e_skeleton2 = SpriteManagerAdd(SpriteSerpent, ((UINT16) 17u << 3), ((UINT16) 12u << 3));
					e_configure(e_skeleton2);
					s_blade = SpriteManagerAdd(SpriteBlade, ((UINT16) 10u << 3), ((UINT16) 14u << 3));
					item_spawned_by_common.e_unique_id = e_skeleton2->unique_id;
					item_spawned_by_common.sprite_type = SpriteSerpent;
					item_spawned_by_common.item_type = HEART;
					item_spawned_by_common.spawned = 0;
				}break;
				case HADES_22:{
					Sprite* e_skeleton1 = SpriteManagerAdd(SpriteFrost, ((UINT16) 1u << 3), ((UINT16) 10u << 3));
					e_configure(e_skeleton1);
					Sprite* e_skeleton2 = SpriteManagerAdd(SpriteFrost, ((UINT16) 11u << 3), ((UINT16) 8u << 3));
					e_configure(e_skeleton2);
					item_spawned_by_common.e_unique_id = e_skeleton2->unique_id;
					item_spawned_by_common.sprite_type = SpriteFrost;
					item_spawned_by_common.item_type = HEART;
					item_spawned_by_common.spawned = 0;
					Sprite* e_skeleton3 = SpriteManagerAdd(SpriteFrost, ((UINT16) 7u << 3), ((UINT16) 13u << 3));
					e_configure(e_skeleton3);
					s_block_00 = SpriteManagerAdd(SpriteBlock, ((UINT16) 11u << 3), ((UINT16) 12u << 3));
					struct ItemInfo* block00_data = (struct ItemInfo*) s_block_00->custom_data;
					block00_data->item_type = BLOCK;
					block00_data->i_configured = 1u;
				}break;
				case HADES_23:{
					Sprite* e_skeleton1 = SpriteManagerAdd(SpriteMinion, ((UINT16) 6u << 3), ((UINT16) 12u << 3));
					e_configure(e_skeleton1);
					Sprite* e_skeleton2 = SpriteManagerAdd(SpriteMinion, ((UINT16) 10u << 3), ((UINT16) 9u << 3));
					e_configure(e_skeleton2);
					Sprite* e_skeleton3 = SpriteManagerAdd(SpriteMinion, ((UINT16) 16u << 3), ((UINT16) 13u << 3));
					e_configure(e_skeleton3);
					s_block_00 = SpriteManagerAdd(SpriteBlock, ((UINT16) 3u << 3), ((UINT16) 13u << 3));
					struct ItemInfo* block00_data = (struct ItemInfo*) s_block_00->custom_data;
					block00_data->item_type = BLOCK;
					block00_data->i_configured = 1u;
					spawn_item(HEART,  ((UINT16) 3u << 3), ((UINT16) 7u << 3), 2);
				}break;
				case HADES_24:{
					area_enemy_counter = 3;
					Sprite* e_skeleton1 = SpriteManagerAdd(SpriteDevourer, ((UINT16) 2u << 3), ((UINT16) 15u << 3));
					e_configure(e_skeleton1);
					Sprite* e_skeleton2 = SpriteManagerAdd(SpriteDevourer, ((UINT16) 1u << 3), ((UINT16) 6u << 3));
					e_configure(e_skeleton2);
					Sprite* e_skeleton3 = SpriteManagerAdd(SpriteDevourer, ((UINT16) 8u << 3), ((UINT16) 5u << 3));
					e_configure(e_skeleton3);
					if(orpheus_haskey == 0 || (orpheus_haskey == 1 && solved_map > current_map)){
						item_spawned_by_common.e_unique_id = e_skeleton2->unique_id;
						item_spawned_by_common.sprite_type = SpriteDevourer;
						item_spawned_by_common.item_type = KEY;
						item_spawned_by_common.spawned = 0;
					}
					spawn_item(HEART,  ((UINT16) 11u << 3), ((UINT16) 15u << 3), 0);
				}break;
				case HADES_25:{
					spawn_item(KEY,  ((UINT16) 9u << 3), ((UINT16) 9u << 3) - 3u, 0);
				}break;
				case HADES_26:{//BOSS RADAMANTHUS
					area_enemy_counter = 1;
					Sprite* s_radamanthus = SpriteManagerAdd(SpriteRadamanthus, ((UINT16) 13u << 3), ((UINT16) 7u << 3));
					e_configure(s_radamanthus);
					s_radamanthusshadow = SpriteManagerAdd(SpriteRadamanthusshadow,((UINT16) 13u << 3), ((UINT16) 7u << 3));
					struct EnemyInfo* shadow_data = (struct EnemyInfo*) s_radamanthusshadow->custom_data;
					shadow_data->tile_collision = MOVEMENT_DIAGONAL_NWSE;
					shadow_data->e_configured = 1;
				}break;
				//BOSS HADES
				//END GAME
			}
		}else{
			s_orpheus = SpriteManagerAdd(SpriteOrpheus, orpheus_spawnx, orpheus_spawny);
		}
	//INITSCROLL
		switch(current_map){
			case HADES_00: //ponte
				InitScroll(BANK(maphades000), &maphades000, coll_t_hades001, coll_s_hades001);
			break;
			case HADES_01: //blocco
				InitScroll(BANK(maphades001), &maphades001, coll_t_hades001, coll_s_hades001);
			break;
			case HADES_02: //chiave
				InitScroll(BANK(maphades002), &maphades002, coll_t_hades001, coll_s_hades001);
			break;
			case HADES_03: //skeleton
				InitScroll(BANK(maphades003), &maphades003, coll_t_hades001, coll_s_hades001);
			break;
			case HADES_04: //infernal imp
				InitScroll(BANK(maphades004), &maphades004, coll_t_hades001, coll_s_hades001);
			break;
			case HADES_05: //puppy
				InitScroll(BANK(maphades005), &maphades005, coll_t_hades001, coll_s_hades001);
			break;
			case HADES_06:
				InitScroll(BANK(maphades006), &maphades006, coll_t_hades001, coll_s_hades001);
			break;
			case HADES_07:
				InitScroll(BANK(maphades007), &maphades007, coll_t_hades001, coll_s_hades001);
			break;
			case HADES_08:
				InitScroll(BANK(maphades008), &maphades008, coll_t_hades001, coll_s_hades001);
			break;
			case HADES_09:
				InitScroll(BANK(maphades009), &maphades009, coll_t_hades001, coll_s_hades001);
			break;
			case HADES_10:
				InitScroll(BANK(maphades010), &maphades010, coll_t_hades001, coll_s_hades001);
			break;
			case HADES_11:
				InitScroll(BANK(maphades011), &maphades011, coll_t_hades001, coll_s_hades001);
			break;
			case HADES_12:
				InitScroll(BANK(maphades012), &maphades012, coll_t_hades001, coll_s_hades001);
			break;
			case HADES_13:
				InitScroll(BANK(maphades013), &maphades013, coll_t_hades001, coll_s_hades001);
			break;
			case HADES_14:
				InitScroll(BANK(maphades014), &maphades014, coll_t_hades001, coll_s_hades001);
			break;
			case HADES_15:
				InitScroll(BANK(maphades015), &maphades015, coll_t_hades001, coll_s_hades001);
			break;
			case HADES_16:
				InitScroll(BANK(maphades016), &maphades016, coll_t_hades003, coll_s_hades001);
			break;
			case HADES_17:
				InitScroll(BANK(maphades017), &maphades017, coll_t_hades003, coll_s_hades001);
			break;
			case HADES_18:
				InitScroll(BANK(maphades018), &maphades018, coll_t_hades003, coll_s_hades001);
			break;
			case HADES_19:
				InitScroll(BANK(maphades019), &maphades019, coll_t_hades003, coll_s_hades001);
			break;
			case HADES_20:
				InitScroll(BANK(maphades020), &maphades020, coll_t_hades003, coll_s_hades001);
			break;
			case HADES_21:
				InitScroll(BANK(maphades021), &maphades021, coll_t_hades003, coll_s_hades001);
			break;
			case HADES_22:
				InitScroll(BANK(maphades022), &maphades022, coll_t_hades003, coll_s_hades001);
			break;
			case HADES_23:
				InitScroll(BANK(maphades023), &maphades023, coll_t_hades003, coll_s_hades001);
			break;
			case HADES_24:
				InitScroll(BANK(maphades024), &maphades024, coll_t_hades003, coll_s_hades001);
			break;
			case HADES_25:
				InitScroll(BANK(maphades025), &maphades025, coll_t_hades003, coll_s_hades001);
			break;
			case HADES_26:
				InitScroll(BANK(maphades026), &maphades026, coll_t_hades001, coll_s_hades001);
			break;
		}
	//HUD
        INIT_HUD(hudmap);
	//EXIT DOORS OPEN
		if(solved_map >= current_map){
			Anim_Opendoors();
		}
	//VARS & MUSIC
		if(current_map == HADES_25){
			StopMusic;
			hades_music_started = 0;
		}else if(hades_music_started == 0){
			if(current_map < BOSS_CHARON){
				PlayMusic(danger, 1);
			}else if(current_map < BOSS_CERBERUS){
				PlayMusic(danger2, 1);
			}else if(current_map < BOSS_MINOS){
				PlayMusic(danger, 1);
			}else if(current_map < BOSS_AEACUS){
				PlayMusic(danger2, 1);
			}else{
				PlayMusic(danger, 1);
			}
			hades_music_started = 1;
		}
	//SET REPUSHABLE
		if(is_level_with_repushable_button()){
			flag_button_repushable = 1u;
		}
}

void play_death_music() BANKED{
	PlayMusic(death, 0);
}

void UPDATE() {
	if(tutorial_go > 0){
		level_common_update_play();
	}
	if(flag_paused){ return; }
	level_common_anim();
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
				case HADES_00:
					solve_current_map();
					prepare_dialog(HADES_WELCOME);
				break;
				case HADES_01:
					prepare_dialog(HADES_MOVE_BLOCK);
				break;
				case HADES_02:
					prepare_dialog(HADES_USE_KEY);
				break;
				case HADES_03:
					prepare_dialog(HADES_KILL_ENEMY);
				break;
				case HADES_05:
					prepare_dialog(HADES_GUARDS);
				break;
				case HADES_06:
					prepare_dialog(HADES_ROLLING_STONES);
				break;
			}
			SaveSprites();
			SetState(StateCartel);
		}
	//BLOCK MANAGEMENT
		UINT16 button_posx = 0u;
		UINT16 button_posy = 0u;
		switch(current_map){
			case HADES_01:{
				button_posx = 1u;
				button_posy = 15u;
			}break;
			case HADES_09:{
				button_posx = 17u;
				button_posy = 11u;
			}break;
			case HADES_12:{
				button_posx = 2u;
				button_posy = 8u;
			}break;
			case HADES_14:{
				button_posx = 14u;
				button_posy = 11u;
			}break;
			case HADES_17:{
				button_posx = 6u;
				button_posy = 7u;
			}break;
			case HADES_22:{
				button_posx = 1u;
				button_posy = 15u;
			}break;
			case HADES_23:{
				button_posx = 16u;
				button_posy = 15u;
			}break;
		}
		if(button_posx && button_posy){
			if(init_block_button == 0){
				if(button_pressed == 1 || solved_map >= current_map){
					draw_button(button_posx, button_posy, 71u);
				}
				init_block_button = 1u;
			}
			if(button_pressed == 0){
				UINT8 tile = GetScrollTile((s_block_00->x + 8) >> 3, (s_block_00->y+8) >> 3);
				if(tile == 67u || tile == 68u || tile == 69u || tile == 70u){
					press_release_button(button_posx, button_posy, 71u);
					struct ItemInfo* block00_data = (struct ItemInfo*) s_block_00->custom_data;
					block00_data->i_configured = 3;
				}
			}
		}
	//GHOSTS
		if(current_map > HADES_02 && current_map < BOSS_HADES){
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
