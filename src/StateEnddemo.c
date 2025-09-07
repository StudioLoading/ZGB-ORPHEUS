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

IMPORT_MAP(mapenddemo);
IMPORT_TILES(font);
IMPORT_TILES(fontj);
DECLARE_MUSIC(intro);

extern CHOSEN_LANGUAGE chosen_language;

void START() {
	//INITSCROLL
        SetWindowY(144);//TO HIDE THE OLD HUD
		InitScroll(BANK(mapenddemo), &mapenddemo, 0, 0);
	//MAP
        switch(chosen_language){
            case ENG:{
                INIT_FONT(font, PRINT_BKG);
                PRINT(0, 1, "  CONGRATULATIONS!  ");
                PRINT(0, 8, "YOU COMPLETED THIS  ");
                PRINT(0, 9, "DEMO. SO THANK YOU!");
                PRINT(0, 11, "FOLLOW THE  ");
                PRINT(0, 12, "KICKSTARTER ");
                PRINT(0, 13, "CAMPAIGN TO ");
                PRINT(0, 14, "GET GAME    ");
                PRINT(0, 15, "UPDATES!    ");
            }break;
            case JAP:{
                INIT_FONT(fontj, PRINT_BKG);
                PRINT(0, 1, "E8ST_E[BKL KYY T_8 -");
                PRINT(0, 8, "F(A LS H,S A,G T_   ");
                PRINT(0, 9, "5UK8 AP(L_B EL(LN  ");
                PRINT(0, 11, "- 8,C P7V   ");
                PRINT(0, 12, "T_CK ?PLQL  ");
                PRINT(0, 13, "- LDV       ");
                PRINT(0, 14, "LQSASB.     ");
                PRINT(0, 15, "            ");
            }break;
        }
    PlayMusic(intro, 1);
}

void UPDATE() {
	
}
