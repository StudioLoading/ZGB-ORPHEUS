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

IMPORT_MAP(inbetweenmap);

UINT8 tutorial_go = 1u; //TODO 0
UINT8 tutorial_hades_entrance = 1u; // TODO 0
UINT8 tutorial_get_lyre = 1u; // TODO 0

MACROMAP solved_map = HADES_TWO;
MACROMAP current_map = HADES_THREE; //TODO TUTORIAL
MACROMAP next_map = HADES_FOUR; //TODO HADES_ZERO
MACROMAP prev_map = HADES_TWO; //TODO TUTORIAL
MACROMAP max_map = HADES_TWO;
UINT8 has_lyre = 1u;//TODO 0

UINT16 orpheus_spawnx = ((UINT16) SPAWNX_HADES003_IN << 3);//((UINT16) 28u << 3) - 4u;
UINT16 orpheus_spawny = ((UINT16) SPAWNX_HADES003_IN << 3);//((UINT16) 79u << 3);
UINT16 camera_spawnx = ((UINT16) SPAWNX_HADES_TUTORIAL << 3); //todo 30
UINT16 camera_spawny = ((UINT16) SPAWNY_HADES_TUTORIAL << 3) + 4u; //todo 64

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
            SetState(StateHades00);
        break;
    }

}

void UPDATE(){

}