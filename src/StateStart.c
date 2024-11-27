#include "Banks/SetAutoBank.h"

#include "BankManager.h"
#include "ZGBMain.h"
#include "Palette.h"
#include "Scroll.h"
#include "Sprite.h"
#include "SpriteManager.h"

#include "custom_datas.h"

#define SPAWNX_HADES_TUTORIAL 10
#define SPAWNY_HADES_TUTORIAL 11
#define SPAWNX_HADES003_IN 4
#define SPAWNY_HADES003_IN 4
#define SPAWNX_BOSSCHARON_IN 9
#define SPAWNY_BOSSCHARON_IN 15

IMPORT_MAP(inbetweenmap);

// START FROM OTHER POSITION 
/*/
UINT8 tutorial_go = 1u; //TODO 0
UINT8 tutorial_hades_entrance =1u; // TODO 0
UINT8 tutorial_get_lyre = 1u; // TODO 0

MACROMAP solved_map = HADES_FOUR; //TODO NONE
MACROMAP current_map = BOSS_CHARON; //TODO TUTORIAL
MACROMAP next_map = BOSS_CHARON; //TODO HADES_ZERO
MACROMAP prev_map = HADES_FOUR; //TODO NONE
MACROMAP max_map = BOSS_CHARON; //TODO TUTORIAL
UINT8 has_lyre = 1; //TODO 0

UINT16 orpheus_spawnx = ((UINT16) SPAWNX_BOSSCHARON_IN << 3);//((UINT16) 28u << 3) - 4u;
UINT16 orpheus_spawny = ((UINT16) SPAWNY_BOSSCHARON_IN << 3);//((UINT16) 79u << 3);
UINT16 camera_spawnx = ((UINT16) SPAWNX_HADES_TUTORIAL << 3); //todo ((UINT16) 30 << 3) + 4u;
UINT16 camera_spawny = ((UINT16) SPAWNY_HADES_TUTORIAL << 3) + 4u;// TODO ((UINT16) 64 << 3) + 4u;
*/


//START FROM TUTORIAL

UINT8 tutorial_go = 0;
UINT8 tutorial_hades_entrance = 0;
UINT8 tutorial_get_lyre = 0;

MACROMAP solved_map = NONE;
MACROMAP current_map = TUTORIAL;
MACROMAP next_map = HADES_ZERO;
MACROMAP prev_map = NONE;
MACROMAP max_map = TUTORIAL;
UINT8 has_lyre = 0;

UINT16 orpheus_spawnx = ((UINT16) 28u << 3) - 4u;
UINT16 orpheus_spawny = ((UINT16) 79u << 3);
UINT16 camera_spawnx = ((UINT16) 30 << 3) + 4u;
UINT16 camera_spawny = ((UINT16) 64 << 3) + 4u;



extern UINT8 current_map;

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
            SetState(StateHades00);
        break;
        case BOSS_CHARON:
            SetState(StateBoss00);
        break;
    }

}

void UPDATE(){

}