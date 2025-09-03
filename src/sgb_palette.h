#include <gb/gb.h>

#define myRGB(r, g, b) (((UINT16)((b) >> 3) << 10) | ((UINT16)((g) >> 3) << 5) | ((UINT16)((r) >> 3) << 0))


#define SGB_CREDIT0_LIGHTER 	myRGB(255, 250, 255)
#define SGB_CREDIT0_LIGHT 	    myRGB(233, 226, 93)
#define SGB_CREDIT0_DARK		myRGB(112, 81, 158)
#define SGB_CREDIT0_DARKER 	    myRGB(0, 0, 0)

#define SGB_CREDIT1_LIGHTER 	myRGB(224, 224, 224)
#define SGB_CREDIT1_LIGHT 	    myRGB(240, 136, 240)
#define SGB_CREDIT1_DARK		myRGB(120, 0, 184)
#define SGB_CREDIT1_DARKER 	    myRGB(0, 0, 0)
#define SGB_CREDIT11_LIGHT 	    myRGB(112, 248, 200)
#define SGB_CREDIT11_DARK		myRGB(0, 48, 200)
#define SGB_CREDIT11_DARKER 	myRGB(0, 0, 0)

#define SGB_TITLE_LIGHTER 	myRGB(255, 250, 238)
#define SGB_TITLE_LIGHT 	myRGB(253, 234, 162)
#define SGB_TITLE_DARK		myRGB(112, 64, 8)
#define SGB_TITLE_DARKER 	myRGB(0, 0, 0)


void set_sgb_palette(UINT16 c0, UINT16 c1, UINT16 c2, UINT16 c3) __banked;
void set_sgb_palette2(UINT16 c0, UINT16 c1, UINT16 c2, UINT16 c3, UINT16 c11, UINT16 c12, UINT16 c13) __banked;

void set_sgb_palette_credits_slkibou() __banked;
void set_sgb_palette_credits_misusloopy() __banked;

void set_sbg_titlescreen() __banked;

/*
void set_sgb_palette_statusbar() __banked;
void reset_sgb_palette_statusbar() __banked;
*/