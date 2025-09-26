#include "Banks/SetAutoBank.h"

#include "BankManager.h"
#include "ZGBMain.h"
#include "Palette.h"
#include "Scroll.h"
#include "Sprite.h"
#include "SpriteManager.h"

#include "custom_datas.h"

#define SPAWNX_CAMERA_HADES 10
#define SPAWNY_CAMERA_HADES 11

IMPORT_MAP(inbetweenmap);

// START FROM OTHER POSITION - TEST ONLY

#define SPAWNX_HADES_IN 4
#define SPAWNY_HADES_IN 4
#define SPAWNX_BOSS_IN 9
#define SPAWNY_BOSS_IN 15

MACROMAP solved_map = BOSS_CERBERUS; // NONE
MACROMAP current_map = HADES_11; // TUTORIAL
MACROMAP next_map = HADES_12; // HADES_00
MACROMAP prev_map = BOSS_CERBERUS; // NONE
MACROMAP max_map = HADES_11; // TUTORIAL

UINT16 orpheus_spawnx = ((UINT16) SPAWNX_HADES_IN << 3) + 4u;//((UINT16) 28u << 3) - 4u;
UINT16 orpheus_spawny = ((UINT16) SPAWNY_HADES_IN << 3) + 2u;//((UINT16) 79u << 3);
UINT16 camera_spawnx = ((UINT16) 30 << 3) + 4u; // ((UINT16) 30 << 3) + 4u;
UINT16 camera_spawny = ((UINT16) 64 << 3) + 4u;//  ((UINT16) 64 << 3) + 4u;

UINT8 has_lyre = 1; // 0
UINT8 tutorial_go = 1u; // 0
UINT8 tutorial_hades_entrance = 1u; //  0
UINT8 tutorial_get_lyre = 1u; //  0

// END FROM OTHER POSITION - TEST ONLY

//START FROM TUTORIAL
/*
UINT8 tutorial_go = 0;
UINT8 tutorial_hades_entrance = 0;
UINT8 tutorial_get_lyre = 0;

MACROMAP solved_map = MAP_NONE;
MACROMAP current_map = TUTORIAL;
MACROMAP next_map = HADES_00;
MACROMAP prev_map = MAP_NONE;
MACROMAP max_map = TUTORIAL;
UINT8 has_lyre = 0;

UINT16 orpheus_spawnx = ((UINT16) 28u << 3) - 4u;
UINT16 orpheus_spawny = ((UINT16) 79u << 3);
UINT16 camera_spawnx = ((UINT16) 30 << 3) + 4u;
UINT16 camera_spawny = ((UINT16) 64 << 3) + 4u;
*/
//END FROM TUTORIAL

extern UINT8 current_map;
extern INT8 a_walk_counter_y;

void START(){
	InitScroll(BANK(inbetweenmap), &inbetweenmap, 0, 0);
    switch(current_map){
        case TUTORIAL:
            SetState(StateTutorial);
        break;
        case BOSS_CHARON:
        case BOSS_CERBERUS:
        case BOSS_MINOS:
        case BOSS_AEACUS:
        case BOSS_HADES:
			camera_spawnx = ((UINT16) SPAWNX_CAMERA_HADES << 3);
			camera_spawny = ((UINT16) SPAWNY_CAMERA_HADES << 3) + 4;
            SetState(StateBoss00);
        break;
        default://all stages
			camera_spawnx = ((UINT16) SPAWNX_CAMERA_HADES << 3);
			camera_spawny = ((UINT16) SPAWNY_CAMERA_HADES << 3) + 4;
            a_walk_counter_y = 0;
            SetState(StateHades00);
        break;
    }

}

void UPDATE(){

}