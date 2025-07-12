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

// START FROM OTHER POSITION 

#define SPAWNX_HADES000_IN 10
#define SPAWNY_HADES000_IN 15
#define SPAWNX_HADES001_IN 4
#define SPAWNY_HADES001_IN 5
#define SPAWNX_HADES002_IN 8
#define SPAWNY_HADES002_IN 3
#define SPAWNX_HADES003_IN 4
#define SPAWNY_HADES003_IN 4
#define SPAWNX_HADES004_IN 4
#define SPAWNY_HADES004_IN 4
#define SPAWNX_BOSSCHARON_IN 11
#define SPAWNY_BOSSCHARON_IN 15

UINT8 tutorial_go = 1u; //TODO 0
UINT8 tutorial_hades_entrance = 1u; // TODO 0
UINT8 tutorial_get_lyre = 1u; // TODO 0

MACROMAP solved_map = BOSS_CHARON; //TODO NONE
MACROMAP current_map = HADES_SIX; //TODO TUTORIAL
MACROMAP next_map = HADES_SEVEN; //TODO HADES_ZERO
MACROMAP prev_map = BOSS_CHARON; //TODO NONE
MACROMAP max_map = HADES_SIX; //TODO TUTORIAL
UINT8 has_lyre = 1; //TODO 0

UINT16 orpheus_spawnx = ((UINT16) SPAWNX_BOSSCHARON_IN << 3);//((UINT16) 28u << 3) - 4u;
UINT16 orpheus_spawny = ((UINT16) SPAWNY_BOSSCHARON_IN << 3);//((UINT16) 79u << 3);
UINT16 camera_spawnx = ((UINT16) 30 << 3) + 4u; //todo ((UINT16) 30 << 3) + 4u;
UINT16 camera_spawny = ((UINT16) 64 << 3) + 4u;// TODO ((UINT16) 64 << 3) + 4u;

//START FROM TUTORIAL
/*
UINT8 tutorial_go = 0;
UINT8 tutorial_hades_entrance = 0;
UINT8 tutorial_get_lyre = 0;

MACROMAP solved_map = MAP_NONE;
MACROMAP current_map = TUTORIAL;
MACROMAP next_map = HADES_ZERO;
MACROMAP prev_map = MAP_NONE;
MACROMAP max_map = TUTORIAL;
UINT8 has_lyre = 0;

UINT16 orpheus_spawnx = ((UINT16) 28u << 3) - 4u;
UINT16 orpheus_spawny = ((UINT16) 79u << 3);
UINT16 camera_spawnx = ((UINT16) 30 << 3) + 4u;
UINT16 camera_spawny = ((UINT16) 64 << 3) + 4u;
*/

extern UINT8 current_map;
extern INT8 a_walk_counter_y;

void START(){
	InitScroll(BANK(inbetweenmap), &inbetweenmap, 0, 0);
    switch(current_map){
        case TUTORIAL:
            SetState(StateTutorial);
        break;
        case HADES_ZERO:
        case HADES_ONE:
        case HADES_TWO:
        case HADES_THREE:
        case HADES_FOUR:
        case HADES_FIVE:
        case HADES_SIX:
			camera_spawnx = ((UINT16) SPAWNX_CAMERA_HADES << 3);
			camera_spawny = ((UINT16) SPAWNY_CAMERA_HADES << 3) + 4;
            a_walk_counter_y = 0;
            SetState(StateHades00);
        break;
        case BOSS_CHARON:
			camera_spawnx = ((UINT16) SPAWNX_CAMERA_HADES << 3);
			camera_spawny = ((UINT16) SPAWNY_CAMERA_HADES << 3) + 4;
            SetState(StateBoss00);
        break;
    }

}

void UPDATE(){

}