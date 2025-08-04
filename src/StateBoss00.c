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

#define ANIM_COUNTER_MAX 84
#define ANIMFIRE_COUNTER_MAX 32
#define BOSS_BREATH_MAX 24
#define BOSS_BREATH_MED 16
#define BOSS_BREATH_MIN 10
#define BOSS_BREATH_MAX_RIGHT 20
#define BOSS_BREATH_MED_RIGHT 14
#define BOSS_BREATH_MIN_RIGHT 8

IMPORT_MAP(mapbosscharon);
IMPORT_MAP(mapbosscerberus);
IMPORT_MAP(mapbossminos);
IMPORT_MAP(mapbossaeacus);
IMPORT_MAP(hudmap);
//IMPORT_TILES(font);
DECLARE_MUSIC(battle);


const UINT8 coll_t_hades005[] = {1,3,4,5,9,10,11,13,14,17,18,19,66,
75,76,
//here the hit tiles

//prev
6,7,8,2,
//next
88,90,92,94,96,98,100,102,104,
0};
const UINT8 coll_s_hades005[] = {0};

Sprite* s_charon = 0;
Sprite* s_cerberus_headleft = 0;
Sprite* s_cerberus_headright = 0;
Sprite* s_minosscale = 0;
Sprite* s_aeacus_wing_left = 0;
Sprite* s_aeacus_wing_right = 0;
Sprite* s_awacus_body = 0;
UINT16 end_demo_counter = 600u;
UINT8 boss_intro = 0u;//0 init; 1 make Orpheus move up; 2 stop Orpheus and show a cutscene; 3 play; 4 boss dead
UINT16 spawn_common_wait = 0u;
UINT16 spawn_common_wait_max = 0u;
UINT8 spawned_enemy_counter = 0u;
UINT8 river_verse = 0u;//0 left;1 right
INT8 boss_breath_counter = 0;
INT8 boss_breath_counter_max = 0;
INT8 boss_breath_verse = 1;//1 low, 2 low, -1 up, -2up
UINT8 boss_breath_flag = 0u;
UINT8 bossminos_breath_flag = 0u;
INT8 boss_breath_counter_right = 0;
INT8 boss_breath_counter_max_right = 0;
INT8 boss_breath_verse_right = 1;//1 low, 2 low, -1 up, -2up
UINT8 boss_breath_flag_right = 0u;
Sprite* s_skeletoncerberus = 0;
Sprite* s_impminos = 0;
UINT8 flag_impminos_alive = 0u;
UINT16 boss_cerberus_startpos_x_left = ((UINT16) 7u << 3);
UINT16 boss_cerberus_startpos_y_left =((UINT16) 3u << 3) + 4u;
UINT16 boss_cerberus_startpos_x_right = ((UINT16) 10u << 3);
UINT16 boss_cerberus_startpos_y_right =((UINT16) 3u << 3) + 4u;
UINT16 boss_cerberus_startpos_x_center = ((UINT16) 8u << 3);
UINT16 boss_cerberus_startpos_y_center = ((UINT16) 3u << 3) + 1;
UINT8 animfire_counter = 0u;
UINT8 animboss_hit_flag = 0u;
UINT8 animboss_hit_counter = 0u;
INT8 animboss_hit = 0u;
INT8 animboss_hit_max = 10;

void boss_manage_death_charon() BANKED;
void boss_manage_death_cerberus() BANKED;
void boss_manage_death_minos() BANKED;
void boss_manage_death_aeacus() BANKED;
void boss_manage_death_radamanthus() BANKED;
void boss_invert_river_verse() BANKED;
void boss_update_breath_verse_and_max() BANKED;
void boss_hit() BANKED;

extern UINT8 dialog_block_interact;
extern UINT8 in_dialog;
extern UINT8 init_block_button;
extern Sprite* s_orpheus;
extern UINT16 orpheus_spawnx;
extern UINT16 orpheus_spawny;
extern UINT8 tutorial_go;
extern UINT8 current_map;
extern UINT8 orpheus_haskey;
extern MACROMAP max_map;
extern MACROMAP solved_map;
extern UINT16 idle_countdown;
extern UINT8 area_enemy_counter;
extern UINT8 anim_counter;
extern Sprite* s_charon_boat;
extern Sprite* s_charon_hand_left;
extern Sprite* s_charon_hand_right;
extern INT8 a_walk_counter_y;
extern UINT8 death_countdown;
extern INT8 boss_hp_current;
extern INT8 boss_hp_max;
extern UINT8 redraw_hud;
extern UINT8 flag_button_repushable;

extern void level_common_start() BANKED;
extern void level_common_update_play() BANKED;
extern void init_write_dialog(UINT8 nlines) BANKED;
extern void write_dialog() BANKED;
extern UINT8 prepare_dialog(WHOSTALKING arg_whostalking) BANKED;
extern void press_release_button(UINT16 x, UINT16 y, UINT8 t) BANKED;
extern void spawn_death_animation(UINT16 spawnx, UINT16 spawny) BANKED;
extern void e_configure(Sprite* s_enemy) BANKED;
extern void e_change_state(Sprite* s_enemy, SPRITE_STATES new_state) BANKED;
extern void UpdateHUD() BANKED;

void START() {
	level_common_start();
	//SPRITES & VARS per boss
		s_orpheus = SpriteManagerAdd(SpriteOrpheus, orpheus_spawnx, orpheus_spawny);
		if(solved_map < current_map){
			switch(current_map){
				case BOSS_CHARON:{
					area_enemy_counter = 2;
				}break;
				case BOSS_CERBERUS:{
					river_verse = 1;
				}break;
			}
		}
	//INITSCROLL & BOSS SPRITES
		switch(current_map){
			case BOSS_CHARON:{
				InitScroll(BANK(mapbosscharon), &mapbosscharon, coll_t_hades005, coll_s_hades005);
				s_charon = SpriteManagerAdd(SpriteCharon, ((UINT16) 11u << 3), ((UINT16) 5u << 3));
				Sprite* s_heart = SpriteManagerAdd(SpriteItem, ((UINT16) 16u << 3), ((UINT16) 14u << 3) - 3u);
				struct ItemInfo* heart_data = (struct ItemInfo*) s_heart->custom_data;
				heart_data->item_type = HEART;
				heart_data->i_configured = 1u;
			}break;
			case BOSS_CERBERUS:{
				InitScroll(BANK(mapbosscerberus), &mapbosscerberus, coll_t_hades005, coll_s_hades005);
				s_cerberus_headright = SpriteManagerAdd(SpriteCerberushead, ((UINT16) 8u << 3), ((UINT16) 3u << 3) + 1);
					struct CerberusInfo* headcenter_info = (struct CerberusInfo*)s_cerberus_headright->custom_data;
					headcenter_info->head_config = 2;
				s_cerberus_headleft = SpriteManagerAdd(SpriteCerberushead, ((UINT16) 7u << 3), ((UINT16) 3u << 3) + 4);
				struct CerberusInfo* headleft_info = (struct CerberusInfo*)s_cerberus_headleft->custom_data;
				headleft_info->head_config = 1;
			}break;
			case BOSS_MINOS:{
				InitScroll(BANK(mapbossminos), &mapbossminos, coll_t_hades005, coll_s_hades005);
				s_minosscale = SpriteManagerAdd(SpriteMinosscale, ((UINT16) 7u << 3) + 4u, ((UINT16) 4u << 3) - 4u);
				bossminos_breath_flag = 0u;
				boss_breath_flag = 0u;
				boss_breath_counter = 0;
				boss_breath_counter_max = BOSS_BREATH_MAX;
			}break;
			case BOSS_AEACUS:{
				InitScroll(BANK(mapbossaeacus), &mapbossaeacus, coll_t_hades005, coll_s_hades005);
				s_aeacus_wing_left = SpriteManagerAdd(SpriteAeacuswing, 8u, 18u);
				s_aeacus_wing_right = SpriteManagerAdd(SpriteAeacuswing, 40u, 18u);
				s_awacus_body = SpriteManagerAdd(SpriteAeacusbody, 32u, 18u);			    struct EnemyInfo* aeacuswing_left_data = (struct EnemyInfo*)s_aeacus_wing_left->custom_data;
				aeacuswing_left_data->e_configured = 1u;
				struct EnemyInfo* aeacuswing_right_data = (struct EnemyInfo*)s_aeacus_wing_right->custom_data;
				aeacuswing_right_data->e_configured = 2u;
			}break;
		}
	//HUD
        INIT_HUD(hudmap);
	//VARS
		spawn_common_wait = 0u;
		spawn_common_wait_max = 300u;
		spawned_enemy_counter = 0u;
		PlayMusic(battle, 1);
		boss_hp_max = 5;
		boss_hp_current = 1;//TODO 5
		boss_breath_counter = 0;
		boss_breath_counter_max = BOSS_BREATH_MAX;
		boss_breath_verse = 1;
		boss_breath_flag = 0u;
		boss_breath_counter_right = 0;
		boss_breath_counter_max_right = BOSS_BREATH_MAX_RIGHT;
		boss_breath_verse_right = 1;
		boss_breath_flag_right = 0u;
		animboss_hit_flag = 0;
		flag_button_repushable = 1u;
	//PER STAGE
		if(boss_intro == 0){
			boss_intro = 1;
			a_walk_counter_y = -52;
		}
}

void UPDATE() {	
	if(a_walk_counter_y == 0 && boss_intro == 1){
		boss_intro = 2;
	}
	switch(boss_intro){
		case 2:{
			switch(current_map){
				case BOSS_CHARON: 
					prepare_dialog(BOSS_CHARON_INTRO);
				break;
				case BOSS_CERBERUS: 
					prepare_dialog(BOSS_CERBERUS_INTRO);
				break;
				case BOSS_MINOS: 
					prepare_dialog(BOSS_MINOS_INTRO);
				break;
				case BOSS_AEACUS: 
					prepare_dialog(BOSS_AEACUS_INTRO);
				break;
				case BOSS_HADES: 
					prepare_dialog(BOSS_HADES_INTRO);
				break;
			}
			boss_intro = 3;
			SetState(StateCartel);
		}break;
		case 0://on Orpheus death!
		case 3:
			level_common_update_play();
		break;
		case 4:	//DEATH COOLDOWN BEFORE CHANGING SCREEN
			if(redraw_hud){
				UpdateHUD();
			}
			if(boss_hp_current){
			    boss_hp_current = 0;
			}
			if(death_countdown){
				death_countdown--;
				switch(current_map){
					case BOSS_CHARON: 
						boss_manage_death_charon();
					break;
					case BOSS_CERBERUS: 
						boss_manage_death_cerberus();
					break;
					case BOSS_MINOS: 
						boss_manage_death_minos();
					break;
					case BOSS_AEACUS: 
						boss_manage_death_aeacus();
					break;
				}
			}
		break;
	}
	//BOSS HIT
		if(animboss_hit_flag || boss_hp_current == 0){
			animboss_hit++;
			if(animboss_hit >= animboss_hit_max){
				animboss_hit = 0;
				animboss_hit_counter++;
				switch(animboss_hit_counter){
					case 1:
					case 3:
						switch(current_map){
							case BOSS_MINOS:
								Anim_Hit_Minos_1();
							break;
						}
					break;
					case 2:
					case 4:
						switch(current_map){
							case BOSS_MINOS:
								Anim_Hit_Minos_0();
							break;
						}
					break;
					case 5:
						if(boss_hp_current == 0){
							animboss_hit_counter = 0;
						}else{
							switch(current_map){
								case BOSS_MINOS:
									Anim_Breath_Minos_0();
								break;
							}
							animboss_hit_flag = 0u;
						}
					break;
				}
			}
		}
	//BREATH BOSS
		switch(current_map){
			case BOSS_CERBERUS:{
				//BREATHS COUNTER LEFT
					if(boss_breath_flag == 0){
						boss_breath_counter++;
						if(boss_breath_counter >= boss_breath_counter_max){
							boss_breath_counter = 0;
							boss_update_breath_verse_and_max();
							boss_breath_flag = 1u;
						}
					}
				//BREATHS COUNTER RIGHT
					if(boss_breath_flag_right == 0){
						boss_breath_counter_right++;
						if(boss_breath_counter_right >= boss_breath_counter_max_right){
							boss_breath_counter_right = 0;
							if(boss_breath_verse_right == 1){
								boss_breath_verse_right = 2;
							}else if(boss_breath_verse_right == 2){
								boss_breath_verse_right = -2;
							}else if(boss_breath_verse_right == -2){
								boss_breath_verse_right = -1;
							}else if(boss_breath_verse_right == -1){
								boss_breath_verse_right = 0;
							}else if(boss_breath_verse_right == 0){
								boss_breath_verse_right = 1;
							}
							boss_breath_flag_right = 1u;
							switch(boss_hp_current){
								case 1: case 2:
									if(boss_breath_counter_max_right != BOSS_BREATH_MIN_RIGHT){
										boss_breath_counter_max_right = BOSS_BREATH_MIN_RIGHT;
									}
								break;
								case 3: case 4:
									if(boss_breath_counter_max_right != BOSS_BREATH_MED_RIGHT){
										boss_breath_counter_max_right = BOSS_BREATH_MED_RIGHT;
									}
								break;
							}
						}
					}
			}break;
			case BOSS_MINOS:
				boss_breath_counter++;
				if(animboss_hit_flag == 0 && boss_hp_current && boss_breath_counter >= boss_breath_counter_max){
					boss_breath_counter = 0;
					boss_update_breath_verse_and_max();
					struct EnemyInfo* minosscale_data = (struct EnemyInfo*) s_minosscale->custom_data;
					switch(boss_breath_flag){
						case 0u:
							boss_breath_flag = 1u;
						break;
						case 1u:
							boss_breath_flag = 0u;
						break;
					}
					//se minosscale GENERIC_IDLE molleggia
					if(minosscale_data->e_state == GENERIC_IDLE){
						switch(bossminos_breath_flag){
							case 0u: //goes down
								Anim_Breath_Minos_1();
								bossminos_breath_flag = 1u;
							break;
							case 1u: //back up
								Anim_Breath_Minos_0();
								bossminos_breath_flag = 0u;
							break;
						}
					}else{//altrimenti spalanca gli occhi
						Anim_Breath_Minos_2();
					}
				}
			break;			
			case BOSS_AEACUS:
				boss_breath_counter++;
				if(animboss_hit_flag == 0 && boss_hp_current && boss_breath_counter >= boss_breath_counter_max){
					boss_breath_counter = 0;
					boss_update_breath_verse_and_max();
					switch(boss_breath_flag){
						case 0u:
							boss_breath_flag = 1u;
						break;
						case 1u:
							boss_breath_flag = 0u;
						break;
					}
					//struct EnemyInfo* minosscale_data = (struct EnemyInfo*) s_minosscale->custom_data;
					//se minosscale GENERIC_IDLE molleggia
					//if(minosscale_data->e_state == GENERIC_IDLE){
						switch(bossminos_breath_flag){
							case 0u: //goes down
								Anim_Breath_Aeacus_1();
								bossminos_breath_flag = 1u;
							break;
							case 1u: //back up
								Anim_Breath_Aeacus_0();
								bossminos_breath_flag = 0u;
							break;
						}
					//}else{//altrimenti spalanca gli occhi
					//	Anim_Breath_Minos_2();
					//}
				}
			break;
		}
	

	//COMMON SPAWNING
		if(boss_intro < 4){
			if(spawned_enemy_counter == 0 || spawned_enemy_counter > 20){
				spawned_enemy_counter = 0;
				spawn_common_wait++;
				if(spawn_common_wait >= spawn_common_wait_max){
					spawn_common_wait = 0u;
					switch(current_map){
						case BOSS_CERBERUS:{
							UINT16 spawn_skeletoncerberus_posx = 5u;
							UINT16 spawn_skeletoncerberus_posy = 12u;
							switch(boss_hp_current){
								case 4: case 2:
									spawn_skeletoncerberus_posx = 12u;
								break;
							}
							s_skeletoncerberus = SpriteManagerAdd(SpriteSkeletoncerberus, (spawn_skeletoncerberus_posx << 3) + 3u, (spawn_skeletoncerberus_posy << 3));
							e_configure(s_skeletoncerberus);
							e_change_state(s_skeletoncerberus, IDLE_DOWN);
						}break;
						case BOSS_MINOS:{
							UINT16 spawn_impminos_posx = 3u;
							UINT16 spawn_impminos_posy = 4u;
							switch(boss_hp_current){
								case 4:
								case 2:
									spawn_impminos_posx = 16u;
								break;
							}
							if(flag_impminos_alive == 0){
 								s_impminos = SpriteManagerAdd(SpriteImpminos, (spawn_impminos_posx << 3), (spawn_impminos_posy << 3));
								e_configure(s_impminos);
								e_change_state(s_impminos, WALK_DOWN);
							}
						}break;
					}
					//change max interval according to boss hp
						switch(boss_hp_current){
							case 1: spawn_common_wait_max = 160u; break;
							case 2: spawn_common_wait_max = 250u; break;
							case 3: spawn_common_wait_max = 400u; break;
							default: spawn_common_wait_max = 700u; break;
						}
				}
			}
		}
	//GHOSTS
	/*	if(current_map == HADES_03){
			if(idle_countdown < 10 && idle_countdown > 0){
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
	*/
	//ANIM FIRE
		if(current_map == BOSS_MINOS || current_map == BOSS_AEACUS){
			animfire_counter++;
			if(animfire_counter >= ANIMFIRE_COUNTER_MAX){
				animfire_counter = 0u;
			}
			switch(animfire_counter){
				case 0u:
					if(current_map == BOSS_MINOS){
						AnimFire_Minos0();
					}else if(current_map == BOSS_AEACUS){
						AnimFire_Aeacus0();
					}
				break;
				case 8u: AnimFire_1();
				break;
				case 16u: AnimFire_2();
				break;
				case 24u: AnimFire_3();
				break;
			}
		}
	//ANIMS RIVER
		if(current_map != BOSS_MINOS && current_map != BOSS_AEACUS){
			anim_counter++;
			if(anim_counter >= (ANIM_COUNTER_MAX + 12)){
				anim_counter = 0u;
			}
			if(river_verse == 0){//to the left
				switch(anim_counter){
					case 0u:{
						switch(current_map){
							case BOSS_CHARON:
								Anim_Charon_0();
							break;
							case BOSS_CERBERUS:
								Anim_Cerberus_0();
							break; 
							case BOSS_MINOS:
								Anim_Minos_0();
							break;
						}
					}break;
					case 12u: Anim_Charon_1(); break;
					case 24u: Anim_Charon_2(); break;
					case 36u: Anim_Charon_3(); break;
					case 48u: Anim_Charon_4(); break;
					case 60u: Anim_Charon_5(); break;
					case 72u: Anim_Charon_6(); break;
					case 84u: Anim_Charon_7(); break;
				}
			}else{
				switch(anim_counter){
					case 0u: 
						switch(current_map){
							case BOSS_CHARON:
								Anim_Charon_0();
							break;
							case BOSS_CERBERUS:
								Anim_Cerberus_0();
							break; 
							case BOSS_MINOS:
								Anim_Minos_0();
							break;
						}
					break;
					case 12u: Anim_Charon_7(); break;
					case 24u: Anim_Charon_6(); break;
					case 36u: Anim_Charon_5(); break;
					case 48u: Anim_Charon_4(); break;
					case 60u: Anim_Charon_3(); break;
					case 72u: Anim_Charon_2(); break;
					case 84u: Anim_Charon_1(); break;
				}
			}
		}
}

void boss_hit() BANKED{
	animboss_hit_flag = 1u;
	boss_hp_current--;
	redraw_hud = 1;
	if(boss_hp_current <= 0){
		boss_hp_current = 0;
		if(boss_intro < 4 && current_map != HADES_26){
			boss_intro = 4;
			death_countdown = 160u;
		}
	}
}

void boss_update_breath_verse_and_max() BANKED{
	if(boss_breath_verse == 1){
		boss_breath_verse = 2;
	}else if(boss_breath_verse == 2){
		boss_breath_verse = -2;
	}else if(boss_breath_verse == -2){
		boss_breath_verse = -1;
	}else if(boss_breath_verse == -1){
		boss_breath_verse = 0;
	}else if(boss_breath_verse == 0){
		boss_breath_verse = 1;
	}
	switch(boss_hp_current){
		case 1: case 2:
			if(boss_breath_counter_max != BOSS_BREATH_MIN){
				boss_breath_counter_max = BOSS_BREATH_MIN;
			}
		break;
		case 3: case 4:
			if(boss_breath_counter_max != BOSS_BREATH_MED){
				boss_breath_counter_max = BOSS_BREATH_MED;
			}
		break;
	}
}

void boss_manage_death_charon() BANKED{
	switch(death_countdown){
		case 100u:
			SpriteManagerRemoveSprite(s_charon_hand_left);
			SpriteManagerRemoveSprite(s_charon_hand_right);
		break;
		case 60u:
			spawn_death_animation(s_charon->x + 4u, s_charon->y + 12u);
		break;
		case 50u:
			SpriteManagerRemoveSprite(s_charon);
		break;
		case 0u:{
			boss_intro = 0;//reset
			prepare_dialog(BOSS_CHARON_BEATED);
			SetState(StateCartel);
		}break;
	}
}

void boss_manage_death_cerberus() BANKED{
	switch(death_countdown){
		case 140u:
			spawn_death_animation(70u, 46u);
		break;
		case 130u:
			spawn_death_animation(63u, 48u);
		break;
		case 100u:
			spawn_death_animation(52u, 46u);
		break;
		case 80u:
			spawn_death_animation(78u, 47u);
		break;
		case 60u:
			spawn_death_animation(68u, 44u);
		break;
		case 45u:
			spawn_death_animation(63u, 44u);
		break;
		case 30u:
			spawn_death_animation(52u, 42u);
		break;
		case 0u:{
			boss_intro = 0;//reset
			prepare_dialog(BOSS_CERBERUS_BEATED);
			SetState(StateCartel);
		}break;
	}
}

void boss_manage_death_minos() BANKED{
	switch(death_countdown){
		case 140u:
			spawn_death_animation(76u, 47u);
		break;
		case 130u:
			spawn_death_animation(68u, 49u);
		break;
		case 100u:
			spawn_death_animation(58u, 47u);
		break;
		case 80u:
			spawn_death_animation(83u, 48u);
		break;
		case 60u:
			spawn_death_animation(74u, 45u);
		break;
		case 45u:
			spawn_death_animation(69u, 45u);
		break;
		case 30u:
			spawn_death_animation(59u, 44u);
		break;
		case 0u:{
			boss_intro = 0;//reset
			prepare_dialog(BOSS_MINOS_BEATED);
			SetState(StateCartel);
		}break;
	}
}

void boss_manage_death_aeacus() BANKED{
	UINT8 scroll_aea_tile;
	Sprite* iaeaspr;
	SPRITEMANAGER_ITERATE(scroll_aea_tile, iaeaspr) {
		if(iaeaspr->type == SpriteAeacusblade){
			SpriteManagerRemoveSprite(iaeaspr);
		}
	}
	switch(death_countdown){
		case 140u:
			spawn_death_animation(s_awacus_body->x, s_awacus_body->y + 16);
		break;
		case 130u:
			//spawn_death_animation(20u, 30u);
		break;
		case 100u:
			spawn_death_animation(s_awacus_body->x - 3, s_awacus_body->y + 12);
		break;
		case 80u:
			//spawn_death_animation(28u, 28u);
		break;
		case 60u:
			spawn_death_animation(s_awacus_body->x - 4, s_awacus_body->y + 28);
		break;
		case 45u:
			spawn_death_animation(s_awacus_body->x - 6u, s_awacus_body->y + 12);
		break;
		case 30u:
			spawn_death_animation(s_awacus_body->x + 2u, s_awacus_body->y + 16);
		break;
		case 0u:{
			boss_intro = 0;//reset
			prepare_dialog(BOSS_AEACUS_BEATED);
			SetState(StateCartel);
		}break;
	}
}

void boss_invert_river_verse() BANKED{
	if(river_verse == 0){
		river_verse = 1;
	}else{
		river_verse = 0;
	}
}
