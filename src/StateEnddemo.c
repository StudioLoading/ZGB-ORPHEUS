#include "Banks/SetAutoBank.h"

#include "BankManager.h"
#include "ZGBMain.h"
#include "Palette.h"
#include "Scroll.h"
#include "Sprite.h"
#include "SpriteManager.h"
#include "string.h"
#include "Print.h"


IMPORT_MAP(mapenddemo);
IMPORT_TILES(font);

extern unsigned char EMPTY_STRING_20[];

void START() {
	//INITSCROLL
        SetWindowY(144);//TO HIDE THE OLD HUD
		InitScroll(BANK(mapenddemo), &mapenddemo, 0, 0);
	//MAP
        INIT_FONT(font, PRINT_BKG);
    PRINT(0, 1, "  CONGRATULATIONS!  ");
    PRINT(0, 8, "YOU COMPLETED THE   ");
    PRINT(0, 9, "DEMO OF ORPHEUS.    ");
    PRINT(0, 10, "FOLLOW THE KICKSTART");
    PRINT(0, 11, "ER PAGE OF THIS     ");
    PRINT(0, 12, "PROJECT TO STAY UP  ");
    PRINT(0, 13, "DATED ON ITS DEVELOP");
    PRINT(0, 14, "MENT!               ");
}

void UPDATE() {
	
}
