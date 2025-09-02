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


IMPORT_MAP(mapenddemo);
IMPORT_TILES(font);
DECLARE_MUSIC(intro);

void START() {
	//INITSCROLL
        SetWindowY(144);//TO HIDE THE OLD HUD
		InitScroll(BANK(mapenddemo), &mapenddemo, 0, 0);
	//MAP
        INIT_FONT(font, PRINT_BKG);
    PRINT(0, 1, "  CONGRATULATIONS!  ");
    PRINT(0, 8, "YOU COMPLETED THIS  ");
    PRINT(0, 9, "DEMO. SO THANK YOU!");
    PRINT(0, 11, "FOLLOW THE  ");
    PRINT(0, 12, "KICKSTARTER ");
    PRINT(0, 13, "CAMPAIGN TO ");
    PRINT(0, 14, "GET GAME    ");
    PRINT(0, 15, "UPDATES!    ");
    //PlayMusic(intro, 1);
}

void UPDATE() {
	
}
