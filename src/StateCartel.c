#include "Banks/SetAutoBank.h"

#include "BankManager.h"
#include "ZGBMain.h"
#include "Palette.h"
#include "Keys.h"
#include "Music.h"
#include "Scroll.h"
#include "Sprite.h"
#include "SpriteManager.h"
#include "string.h"
#include "Print.h"

#include "custom_datas.h"
#include "UtilsLoadSave.h"

IMPORT_MAP(mapcartel);
IMPORT_MAP(hudmap);
IMPORT_TILES(fontbw);

extern unsigned char d0[];
extern unsigned char d1[];
extern unsigned char d2[];
extern unsigned char d3[];
extern unsigned char d4[];
extern unsigned char d5[];
extern unsigned char d6[];
extern unsigned char d7[];
extern unsigned char d8[];
extern unsigned char d9[];
extern unsigned char d10[];

extern MACROMAP current_map;

void START(){
    InitScroll(BANK(mapcartel), &mapcartel, 0, 0);
    INIT_FONT(fontbw, PRINT_BKG);
    INIT_HUD(hudmap);
    PRINT(1,2, d0);
    PRINT(1,3, d1);
    PRINT(1,4, d2);
    PRINT(1,5, d3);
    PRINT(1,6, d4);
    PRINT(1,7, d5);
    PRINT(1,8, d6);
    PRINT(1,9, d7);
    PRINT(1,10, d8);
    PRINT(1,11, d9);
    PRINT(1,12, d10);
}

void UPDATE(){
    if(KEY_TICKED(J_A)){
        SetState(StateHades00);
    }
}