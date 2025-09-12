#pragma bank 10

#include <gb/gb.h>
#include <gb/sgb.h>

#include "sgb_palette.h"

struct SgbPalettePacket {
    UINT8 command;
    UINT16 pal0[4];
    UINT16 pal1[3];
    UINT8 padding;
    // Aggiungi altri campi se vuoi salvare più stato
};
struct SgbLinePacket {
        UINT8 command;
        UINT8 xcoo;
        UINT8 ycoo;
		UINT16 ndata;
		UINT8 style;
        UINT8 ds[10];
};

void set_sgb_palette(UINT16 c0, UINT16 c1, UINT16 c2, UINT16 c3) __banked { 
    struct SgbPalettePacket SGB_PALETTE_PACKET = {
        .command = (SGB_PAL_01 << 3) | 1,
        .pal0 = {c0, c1, c2, c3},
        .pal1 = {0, 0, 0},
        .padding = 0 
    };
    sgb_transfer((void *)&SGB_PALETTE_PACKET);
}

void set_sgb_pal0pal1(UINT16 c0, UINT16 c1, UINT16 c2, UINT16 c3, UINT16 c11, UINT16 c12, UINT16 c13) __banked {
    struct SgbPalettePacket SGB_PALETTE_PACKET = {
        .command = (SGB_PAL_01 << 3) | 1,
        .pal0 = {c0, c1, c2, c3},
        .pal1 = {c11, c12, c13},
        .padding = 0 
    };
    sgb_transfer((void *)&SGB_PALETTE_PACKET);
}

void set_sgb_pal2pal3(UINT16 c0, UINT16 c1, UINT16 c2, UINT16 c3, UINT16 c11, UINT16 c12, UINT16 c13) __banked {
    struct SgbPalettePacket SGB_PALETTE_PACKET = {
        .command = (SGB_PAL_23 << 3) | 1,
        .pal0 = {c0, c1, c2, c3},
        .pal1 = {c11, c12, c13},
        .padding = 0 
    };
    sgb_transfer((void *)&SGB_PALETTE_PACKET);
}

void set_sgb_palette2(UINT16 c0, UINT16 c1, UINT16 c2, UINT16 c3, UINT16 c11, UINT16 c12, UINT16 c13) __banked {
    struct SgbPalettePacket SGB_PALETTE_PACKET = {
        .command = (SGB_PAL_01 << 3) | 1,
        .pal0 = {c0, c1, c2, c3},
        .pal1 = {c11, c12, c13},
        .padding = 0 
    };
    
	struct SgbLinePacket SGB_LINE11_PACKET = {
        .command = (SGB_ATTR_CHR << 3) | 1,
        .xcoo = 0,
        .ycoo = 11u,
        .ndata = 20u,
		.style = 0,
		.ds = {0b01010101,0b01010101,0b01010101,0b01010101,
        0b01010101,0b01010101,0b01010101,0b01010101,
        0b01010101,0b01010101}
    };
    
	struct SgbLinePacket SGB_LINE12_PACKET = {
        .command = (SGB_ATTR_CHR << 3) | 1,
        .xcoo = 0,
        .ycoo = 12u,
        .ndata = 20u,
		.style = 0,
		.ds = {0b01010101,0b01010101,0b01010101,0b01010101,
        0b01010101,0b01010101,0b01010101,0b01010101,
        0b01010101,0b01010101}
    };
    
	struct SgbLinePacket SGB_LINE13_PACKET = {
        .command = (SGB_ATTR_CHR << 3) | 1,
        .xcoo = 0,
        .ycoo = 13u,
        .ndata = 20u,
		.style = 0,
		.ds = {0b01010101,0b01010101,0b01010101,0b01010101,
        0b01010101,0b01010101,0b01010101,0b01010101,
        0b01010101,0b01010101}
    };
	struct SgbLinePacket SGB_LINE14_PACKET = {
        .command = (SGB_ATTR_CHR << 3) | 1,
        .xcoo = 0,
        .ycoo = 14u,
        .ndata = 20u,
		.style = 0,
		.ds = {0b01010101,0b01010101,0b01010101,0b01010101,
        0b01010101,0b01010101,0b01010101,0b01010101,
        0b01010101,0b01010101}
    };
	struct SgbLinePacket  SGB_LINE15_PACKET = {
        .command = (SGB_ATTR_CHR << 3) | 1,
        .xcoo = 0,
        .ycoo = 15u,
        .ndata = 20u,
		.style = 0,
		.ds = {0b01010101,0b01010101,0b01010101,0b01010101,
        0b01010101,0b01010101,0b01010101,0b01010101,
        0b01010101,0b01010101}
    };
	struct SgbLinePacket SGB_LINE16_PACKET = {
        .command = (SGB_ATTR_CHR << 3) | 1,
        .xcoo = 0,
        .ycoo = 16u,
        .ndata = 20u,
		.style = 0,
		.ds = {0b01010101,0b01010101,0b01010101,0b01010101,
        0b01010101,0b01010101,0b01010101,0b01010101,
        0b01010101,0b01010101}
    };
    sgb_transfer((void *)&SGB_PALETTE_PACKET);
    sgb_transfer((void *)&SGB_LINE11_PACKET);
    sgb_transfer((void *)&SGB_LINE12_PACKET);
    sgb_transfer((void *)&SGB_LINE13_PACKET);
    sgb_transfer((void *)&SGB_LINE14_PACKET);
    sgb_transfer((void *)&SGB_LINE15_PACKET);
    sgb_transfer((void *)&SGB_LINE16_PACKET);
}

void set_sgb_structure_hades() __banked{
	struct SgbLinePacket SGB_LINE15_PACKET = {
        .command = (SGB_ATTR_CHR << 3) | 1,
        .xcoo = 0,
        .ycoo = 15u,
        .ndata = 20u,
		.style = 0,
		.ds = {0b10101010,0b10101111,0b11111111,0b11111111,
        0b11111111,0b11111111,0b11111111,0b11111111,
        0b11111111,0b11111111}
    };
	struct SgbLinePacket SGB_LINE16_PACKET = {
        .command = (SGB_ATTR_CHR << 3) | 1,
        .xcoo = 0,
        .ycoo = 16u,
        .ndata = 20u,
		.style = 0,
		.ds = {0b10101010,0b10101111,0b11111111,0b11111111,
        0b11111111,0b11111111,0b11111111,0b11111111,
        0b11111111,0b11111111}
    };
	struct SgbLinePacket SGB_LINE17_PACKET = {
        .command = (SGB_ATTR_CHR << 3) | 1,
        .xcoo = 0,
        .ycoo = 17u,
        .ndata = 20u,
		.style = 0,
		.ds = {0b10101010,0b10101111,0b11111111,0b11111111,
        0b11111111,0b11111111,0b11111111,0b11111111,
        0b11111111,0b11111111}
    };
    
    sgb_transfer((void *)&SGB_LINE15_PACKET);
    sgb_transfer((void *)&SGB_LINE16_PACKET);
    sgb_transfer((void *)&SGB_LINE17_PACKET);
}

void set_sgb_palette_credits_reset() __banked{
    struct SgbPalettePacket  SGB_PALETTE_PACKET = {
        .command = (SGB_PAL_01 << 3) | 1,
        .pal0 = {SGB_POCKET_LIGHTER, SGB_POCKET_LIGHT, SGB_POCKET_DARK, SGB_POCKET_DARKER},
        .pal1 = {SGB_POCKET_LIGHT, SGB_POCKET_DARK, SGB_POCKET_DARKER},
        .padding = 0 
    };
	struct SgbLinePacket SGB_LINE11_PACKET = {
        .command = (SGB_ATTR_CHR << 3) | 1,
        .xcoo = 0,
        .ycoo = 11u,
        .ndata = 20u,
		.style = 0,
		.ds = {0b00000000,0b00000000,0b00000000,0b00000000,
        0b00000000,0b00000000,0b00000000,0b00000000,
        0b00000000,0b00000000}
    };
	struct SgbLinePacket SGB_LINE12_PACKET = {
        .command = (SGB_ATTR_CHR << 3) | 1,
        .xcoo = 0,
        .ycoo = 12u,
        .ndata = 20u,
		.style = 0,
		.ds = {0b00000000,0b00000000,0b00000000,0b00000000,
        0b00000000,0b00000000,0b00000000,0b00000000,
        0b00000000,0b00000000}
    };    
	struct SgbLinePacket SGB_LINE13_PACKET = {
        .command = (SGB_ATTR_CHR << 3) | 1,
        .xcoo = 0,
        .ycoo = 13u,
        .ndata = 20u,
		.style = 0,
		.ds = {0b00000000,0b00000000,0b00000000,0b00000000,
        0b00000000,0b00000000,0b00000000,0b00000000,
        0b00000000,0b00000000}
    };
	struct SgbLinePacket SGB_LINE14_PACKET = {
        .command = (SGB_ATTR_CHR << 3) | 1,
        .xcoo = 0,
        .ycoo = 14u,
        .ndata = 20u,
		.style = 0,
		.ds = {0b00000000,0b00000000,0b00000000,0b00000000,
        0b00000000,0b00000000,0b00000000,0b00000000,
        0b00000000,0b00000000}
    };
	struct SgbLinePacket SGB_LINE15_PACKET = {
        .command = (SGB_ATTR_CHR << 3) | 1,
        .xcoo = 0,
        .ycoo = 15u,
        .ndata = 20u,
		.style = 0,
		.ds = {0b00000000,0b00000000,0b00000000,0b00000000,
        0b00000000,0b00000000,0b00000000,0b00000000,
        0b00000000,0b00000000}
    };
	struct SgbLinePacket SGB_LINE16_PACKET = {
        .command = (SGB_ATTR_CHR << 3) | 1,
        .xcoo = 0,
        .ycoo = 16u,
        .ndata = 20u,
		.style = 0,
		.ds = {0b00000000,0b00000000,0b00000000,0b00000000,
        0b00000000,0b00000000,0b00000000,0b00000000,
        0b00000000,0b00000000}
    };
    sgb_transfer((void *)&SGB_PALETTE_PACKET);
    sgb_transfer((void *)&SGB_LINE11_PACKET);
    sgb_transfer((void *)&SGB_LINE12_PACKET);
    sgb_transfer((void *)&SGB_LINE13_PACKET);
    sgb_transfer((void *)&SGB_LINE14_PACKET);
    sgb_transfer((void *)&SGB_LINE15_PACKET);
    sgb_transfer((void *)&SGB_LINE16_PACKET);
}

void set_sgb_palette_credits_slkibou() __banked {	
    set_sgb_palette(SGB_CREDIT0_LIGHTER, SGB_CREDIT0_DARK, SGB_CREDIT0_LIGHT, SGB_CREDIT0_DARKER);
}

void set_sgb_palette_credits_misusloopy() __banked {	
    set_sgb_palette2(SGB_CREDIT1_LIGHTER, SGB_CREDIT1_LIGHT, SGB_CREDIT1_DARK, SGB_CREDIT1_DARKER, SGB_CREDIT11_LIGHT, SGB_CREDIT11_DARK, SGB_CREDIT11_DARKER);
}

void set_sgb_palette_credits_faultsl() __banked {	
    set_sgb_palette2(SGB_CREDIT2_LIGHTER, SGB_CREDIT2_LIGHT, SGB_CREDIT2_DARK, SGB_CREDIT2_DARKER, myRGB(200, 200, 200), myRGB(80, 80, 80), SGB_CREDIT0_DARKER);
}

void set_sgb_palette_credits_zgb() __banked{
    set_sgb_palette_credits_reset();
}


void set_sbg_titlescreen() __banked{
    set_sgb_palette2(SGB_TITLE_LIGHTER, SGB_TITLE_LIGHT, SGB_TITLE_DARK, SGB_TITLE_DARKER, myRGB(200, 200, 200), myRGB(80, 80, 80), SGB_CREDIT0_DARKER);
}

void set_sbg_intro() __banked{
    set_sgb_palette(SGB_INTRO_LIGHTER, SGB_INTRO_LIGHT, SGB_INTRO_DARK, SGB_INTRO_DARKER);
}

void set_sbg_palette_tutorial() __banked{
    set_sgb_palette_credits_reset();
    set_sgb_pal0pal1(SGB_TUTORIAL_LIGHTER, SGB_TUTORIAL_LIGHT, SGB_TUTORIAL_DARK, SGB_TUTORIAL_DARKER, SGB_STATUS_LIGHT, SGB_STATUS_DARK, SGB_STATUS_DARKER);
    set_sgb_pal2pal3(SGB_STATUS_LIGHTER, SGB_STATUS_LIGHT, SGB_STATUS_DARK, SGB_STATUS_DARKER, SGB_STATUS2_LIGHT, SGB_STATUS2_DARK, SGB_STATUS2_DARKER);
    set_sgb_structure_hades();
}

void set_sbg_palette_styx() __banked{
    set_sgb_palette_credits_reset();
    set_sgb_pal0pal1(SGB_STYX_LIGHTER, SGB_STYX_LIGHT, SGB_STYX_DARK, SGB_STYX_DARKER, SGB_STATUS_LIGHT, SGB_STATUS_DARK, SGB_STATUS_DARKER);
    set_sgb_pal2pal3(SGB_STYX_LIGHTER, SGB_STATUS_LIGHT, SGB_STATUS_DARK, SGB_STATUS_DARKER, SGB_STATUS2_LIGHT, SGB_STATUS2_DARK, SGB_STATUS2_DARKER);
    set_sgb_structure_hades();
}

void set_sbg_palette_boss_charon() __banked{
    set_sgb_palette_credits_reset();
    set_sgb_pal0pal1(SGB_BOSSCHARON_LIGHTER, SGB_BOSSCHARON_LIGHT, SGB_BOSSCHARON_DARK, SGB_BOSSCHARON_DARKER, SGB_STATUS_LIGHT, SGB_STATUS_DARK, SGB_STATUS_DARKER);
    set_sgb_pal2pal3(SGB_BOSSCHARON_LIGHTER, SGB_STATUS_LIGHT, SGB_STATUS_DARK, SGB_STATUS_DARKER, SGB_STATUS2_LIGHT, SGB_STATUS2_DARK, SGB_STATUS2_DARKER);
    set_sgb_structure_hades();
}

void set_sbg_palette_acheron() __banked{
    set_sgb_palette_credits_reset();
    set_sgb_pal0pal1(SGB_ACHERON_LIGHTER, SGB_ACHERON_LIGHT, SGB_ACHERON_DARK, SGB_ACHERON_DARKER, SGB_STATUS_LIGHT, SGB_STATUS_DARK, SGB_STATUS_DARKER);
    set_sgb_pal2pal3(SGB_ACHERON_LIGHTER, SGB_STATUS_LIGHT, SGB_STATUS_DARK, SGB_STATUS_DARKER, SGB_STATUS2_LIGHT, SGB_STATUS2_DARK, SGB_STATUS2_DARKER);
    set_sgb_structure_hades();
}

void set_sbg_palette_boss_cherberus() __banked{
    set_sgb_palette_credits_reset();
    set_sgb_pal0pal1(SGB_BOSSCERBERUS_LIGHTER, SGB_BOSSCERBERUS_LIGHT, SGB_BOSSCERBERUS_DARK, SGB_BOSSCERBERUS_DARKER, SGB_STATUS_LIGHT, SGB_STATUS_DARK, SGB_STATUS_DARKER);
    set_sgb_pal2pal3(SGB_BOSSCERBERUS_LIGHTER, SGB_STATUS_LIGHT, SGB_STATUS_DARK, SGB_STATUS_DARKER, SGB_STATUS2_LIGHT, SGB_STATUS2_DARK, SGB_STATUS2_DARKER);
    set_sgb_structure_hades();
}