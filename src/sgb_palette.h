#include <gb/gb.h>

#define myRGB(r, g, b) (((UINT16)((b) >> 3) << 10) | ((UINT16)((g) >> 3) << 5) | ((UINT16)((r) >> 3) << 0))

#define SGB_POCKET_LIGHTER      myRGB(255, 255, 255)
#define SGB_POCKET_LIGHT        myRGB(180, 180, 180)
#define SGB_POCKET_DARK         myRGB(80, 80, 80)
#define SGB_POCKET_DARKER       myRGB(0, 0, 0)

#define SGB_CREDIT0_LIGHTER 	myRGB(255, 250, 255)
#define SGB_CREDIT0_LIGHT 	    myRGB(233, 226, 93)
#define SGB_CREDIT0_DARK		myRGB(0, 62, 155)
#define SGB_CREDIT0_DARKER 	    myRGB(0, 0, 0)

#define SGB_CREDIT1_LIGHTER 	myRGB(224, 224, 224)
#define SGB_CREDIT1_LIGHT 	    myRGB(240, 136, 240)
#define SGB_CREDIT1_DARK		myRGB(120, 0, 184)
#define SGB_CREDIT1_DARKER 	    myRGB(0, 0, 0)
#define SGB_CREDIT11_LIGHT 	    myRGB(112, 248, 200)
#define SGB_CREDIT11_DARK		myRGB(0, 48, 200)
#define SGB_CREDIT11_DARKER 	myRGB(0, 0, 0)

#define SGB_CREDIT2_LIGHTER 	myRGB(255, 250, 255)
#define SGB_CREDIT2_LIGHT 	    myRGB(248, 224, 224)
#define SGB_CREDIT2_DARK		myRGB(64, 184, 184)
#define SGB_CREDIT2_DARKER 	    myRGB(0, 0, 0)

#define SGB_TITLE_LIGHTER 	myRGB(255, 250, 238)
#define SGB_TITLE_LIGHT 	myRGB(253, 234, 162)
#define SGB_TITLE_DARK		myRGB(112, 64, 8)
#define SGB_TITLE_DARKER 	myRGB(0, 0, 0)

#define SGB_INTRO_LIGHTER 	myRGB(240, 240, 216)
#define SGB_INTRO_LIGHT 	myRGB(240, 208, 128)
#define SGB_INTRO_DARK		myRGB(0, 72, 200)
#define SGB_INTRO_DARKER 	myRGB(0, 0, 0)
#define SGB_INTRO1_LIGHT 	myRGB(240, 208, 128)
#define SGB_INTRO1_DARK		myRGB(72, 160, 0)
#define SGB_INTRO1_DARKER 	myRGB(0, 0, 0)

#define SGB_TUTORIAL_LIGHTER 	myRGB(216, 216, 216)
#define SGB_TUTORIAL_LIGHT 	    myRGB(240, 240, 160)
#define SGB_TUTORIAL_DARK		myRGB(0, 176, 80)
#define SGB_TUTORIAL_DARKER 	myRGB(0, 0, 0)

#define SGB_STYX_LIGHTER 	myRGB(216, 216, 216)
#define SGB_STYX_LIGHT 	myRGB(240, 216, 136)
#define SGB_STYX_DARK		myRGB(104, 128, 248)
#define SGB_STYX_DARKER 	myRGB(0, 0, 0)
#define SGB_STATUS_LIGHTER 	myRGB(255, 255, 255)
#define SGB_STATUS_LIGHT 	myRGB(232, 248, 72)
#define SGB_STATUS_DARK		myRGB(248, 40, 24)
#define SGB_STATUS_DARKER 	myRGB(0, 0, 0)
#define SGB_STATUS2_LIGHT 	myRGB(210, 220, 229)
#define SGB_STATUS2_DARK	myRGB(61, 142, 197)
#define SGB_STATUS2_DARKER 	myRGB(0, 0, 0)

#define SGB_BOSSCHARON_LIGHTER 	myRGB(216, 216, 216)
#define SGB_BOSSCHARON_LIGHT 	myRGB(239, 187, 170)
#define SGB_BOSSCHARON_DARK		myRGB(198, 0, 13)
#define SGB_BOSSCHARON_DARKER 	myRGB(0, 0, 0)

#define SGB_ACHERON_LIGHTER	myRGB(216, 216, 216)
#define SGB_ACHERON_LIGHT   myRGB(255, 209, 228)
#define SGB_ACHERON_DARK    myRGB(255, 59, 56)
#define SGB_ACHERON_DARKER 	myRGB(0, 0, 0)

void set_sgb_palette(UINT16 c0, UINT16 c1, UINT16 c2, UINT16 c3) __banked;
void set_sgb_palette2(UINT16 c0, UINT16 c1, UINT16 c2, UINT16 c3, UINT16 c11, UINT16 c12, UINT16 c13) __banked;
void set_sgb_palette_intro(UINT16 c0, UINT16 c1, UINT16 c2, UINT16 c3, UINT16 c11, UINT16 c12, UINT16 c13) __banked;

void set_sgb_palette_credits_slkibou() __banked;
void set_sgb_palette_credits_misusloopy() __banked;
void set_sgb_palette_credits_faultsl() __banked;
void set_sgb_palette_credits_zgb() __banked;
void set_sbg_titlescreen() __banked;
void set_sbg_palette_tutorial() __banked;
void set_sbg_palette_styx() __banked;
void set_sbg_palette_boss_charon() __banked;
void set_sbg_palette_acheron() __banked;

void set_sbg_intro() __banked;
/*
void set_sgb_palette_statusbar() __banked;
void reset_sgb_palette_statusbar() __banked;
*/