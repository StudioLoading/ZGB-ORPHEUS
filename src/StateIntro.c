#include "Banks/SetAutoBank.h"

#include "BankManager.h"
#include "ZGBMain.h"
#include "Palette.h"
#include "Keys.h"
#include "Scroll.h"
#include "Sprite.h"
#include "SpriteManager.h"
#include "string.h"
#include "Print.h"

#include "custom_datas.h"
#include "Dialog.h"

#define TEXT_TIMEOUT 40

IMPORT_MAP(mapintro);
IMPORT_TILES(font);

extern UINT8 J_INT;
extern UINT8 J_ATK;

extern unsigned char EMPTY_STRING_20[];
UINT8 intro_page_counter = 0u;
UINT8 text_wait = 0u;
UINT8 text_shown = 0u;

void START(){
	InitScroll(BANK(mapintro), &mapintro, 0, 0);
    INIT_FONT(font, PRINT_BKG);
    text_shown = 0u;
}

void UPDATE(){
    if(text_wait < TEXT_TIMEOUT){
        text_wait++;
        return;
    }
    if(text_shown == 0u){
        switch(intro_page_counter){
            case 0u:
                PRINT(0,14, "FIRST LINE OF TEXT !");
                PRINT(0,15, EMPTY_STRING_20);
                PRINT(0,16, EMPTY_STRING_20);
                PRINT(0,17, "LAST LINE OF TEXT !!");
            break;
            case 1u:
                PRINT(0,14, "FIRST LINE OF TEXT !");
                PRINT(0,15, EMPTY_STRING_20);
                PRINT(0,16, EMPTY_STRING_20);
                PRINT(0,17, "LAST LINE OF TEXT !!");
            break;
            case 2u:
                PRINT(0,14, "FIRST LINE OF TEXT !");
                PRINT(0,15, EMPTY_STRING_20);
                PRINT(0,16, EMPTY_STRING_20);
                PRINT(0,17, "LAST LINE OF TEXT !!");
            break;
            case 3u:
                PRINT(0,14, "FIRST LINE OF TEXT !");
                PRINT(0,15, EMPTY_STRING_20);
                PRINT(0,16, EMPTY_STRING_20);
                PRINT(0,17, "LAST LINE OF TEXT !!");
            break;
        }

        text_shown = 1u;
    }

    if(KEY_TICKED(J_START) || KEY_TICKED(J_ATK) || KEY_TICKED(J_INT)){
        intro_page_counter++;
        if(intro_page_counter < 4){
            SetState(StateIntro);
        }else{
            SetState(StateStart);
        }
    }

}