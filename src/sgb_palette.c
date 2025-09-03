#pragma bank 10

#include <gb/gb.h>
#include <gb/sgb.h>

#include "sgb_palette.h"


void set_sgb_palette(UINT16 c0, UINT16 c1, UINT16 c2, UINT16 c3) __banked {
    struct {
        UINT8 command;
        UINT16 pal0[4];
        UINT16 pal1[3];
        UINT8 padding;
    } SGB_PALETTE_PACKET = {
        .command = (SGB_PAL_01 << 3) | 1,
        .pal0 = {c0, c1, c2, c3},
        .pal1 = {0, 0, 0},
        .padding = 0 
    };
    sgb_transfer((void *)&SGB_PALETTE_PACKET);
}

void set_sgb_palette2(UINT16 c0, UINT16 c1, UINT16 c2, UINT16 c3, UINT16 c11, UINT16 c12, UINT16 c13) __banked {
    struct {
        UINT8 command;
        UINT16 pal0[4];
        UINT16 pal1[3];
        UINT8 padding;
    } SGB_PALETTE_PACKET = {
        .command = (SGB_PAL_01 << 3) | 1,
        .pal0 = {c0, c1, c2, c3},
        .pal1 = {c11, c12, c13},
        .padding = 0 
    };
    
	struct {
        UINT8 command;
        UINT8 xcoo;
        UINT8 ycoo;
		UINT16 ndata;
		UINT8 style;
        UINT8 ds[10];
    } SGB_LINE11_PACKET = {
        .command = (SGB_ATTR_CHR << 3) | 1,
        .xcoo = 0,
        .ycoo = 11u,
        .ndata = 20u,
		.style = 0,
		.ds = {0b10101010,0b10101010,0b10101010,0b10101010,
        0b10101010,0b10101010,0b10101010,0b10101010,
        0b10101010,0b10101010}
    };
    sgb_transfer((void *)&SGB_PALETTE_PACKET);
    sgb_transfer((void *)&SGB_LINE11_PACKET);
}

void set_sgb_palette_credits_slkibou() __banked {	
    set_sgb_palette(SGB_CREDIT0_LIGHTER, SGB_CREDIT0_DARK, SGB_CREDIT0_LIGHT, SGB_CREDIT0_DARKER);
}

void set_sgb_palette_credits_misusloopy() __banked {	
    set_sgb_palette2(SGB_CREDIT1_LIGHTER, SGB_CREDIT1_LIGHT, SGB_CREDIT1_DARK, SGB_CREDIT1_DARKER, SGB_CREDIT11_LIGHT, SGB_CREDIT11_DARK, SGB_CREDIT11_DARKER);
}


void set_sbg_titlescreen() __banked{
    set_sgb_palette(SGB_TITLE_LIGHTER, SGB_TITLE_LIGHT, SGB_TITLE_DARK, SGB_TITLE_DARKER);
}
/*
void set_sgb_palette_statusbar() __banked {	
	struct {
        UINT8 command;
        UINT16 pal1[4];
        UINT16 pal2[3];
        UINT8 padding;
    } SGB_PALETTE2_PACKET = {
        .command = (SGB_PAL_12 << 3) | 1,
        .pal1 = {myRGB(255, 255, 255), SGB_STATUS_LIGHT, SGB_STATUS_RED, SGB_STATUS_DARKER},
        .pal2 = {SGB_PAL2_LIGHT, SGB_STATUS_LIGHT, SGB_STATUS_DARKER},
        .padding = 0 
    };
	struct {
        UINT8 command;
        UINT8 xcoo;
        UINT8 ycoo;
		UINT16 ndata;
		UINT8 style;
        UINT8 ds[10];
    } SGB_PALETTE_STATUS_PACKET_0 = {
        .command = (SGB_ATTR_CHR << 3) | 1,
        .xcoo = 0,
        .ycoo = 15u,
        .ndata = 20u,
		.style = 0,
		.ds = {0b10101010,0b10101010,0b10101010,0b10101010,
        0b10101010,0b10101010,0b10101010,0b10101010,
        0b10101010,0b10101010}
    };
	struct {
        UINT8 command;
        UINT8 xcoo;
        UINT8 ycoo;
		UINT16 ndata;
		UINT8 style;
        UINT8 ds[10];
    } SGB_PALETTE_STATUS_PACKET_1 = {
        .command = (SGB_ATTR_CHR << 3) | 1,
        .xcoo = 0,
        .ycoo = 16u,
        .ndata = 20u,
		.style = 0,
		.ds = {0b10101010,0b10010101,0b01010101,0b01010110,
        0b10101010,0b10101010,0b10101010,0b10101010,
        0b10101010,0b10101010}
    };
	struct {
        UINT8 command;
        UINT8 xcoo;
        UINT8 ycoo;
		UINT16 ndata;
		UINT8 style;
        UINT8 ds[10];
    } SGB_PALETTE_STATUS_PACKET_2 = {
        .command = (SGB_ATTR_CHR << 3) | 1,
        .xcoo = 0,
        .ycoo = 17u,
        .ndata = 20u,
		.style = 0,
		.ds = {0b10101010,0b10010101,0b01010101,0b01010110,
        0b10101010,0b10101010,0b10101010,0b10101010,
        0b10101010,0b10101010}
    };
    sgb_transfer((void *)&SGB_PALETTE2_PACKET);
    sgb_transfer((void *)&SGB_PALETTE_STATUS_PACKET_0);
    sgb_transfer((void *)&SGB_PALETTE_STATUS_PACKET_1);
    sgb_transfer((void *)&SGB_PALETTE_STATUS_PACKET_2);
}

void reset_sgb_palette_statusbar() __banked{	
	struct {
        UINT8 command;
        UINT8 xcoo;
        UINT8 ycoo;
		UINT16 ndata;
		UINT8 style;
        UINT8 ds[10];
    } SGB_PALETTE_STATUS_PACKET_0 = {
        .command = (SGB_ATTR_CHR << 3) | 1,
        .xcoo = 0,
        .ycoo = 15u,
        .ndata = 20u,
		.style = 0,
		.ds = {0b00000000,0b00000000,0b00000000,0b00000000,
                0b00000000,0b00000000,0b00000000,0b00000000,
                0b00000000,0b00000000}
    };	
	struct {
        UINT8 command;
        UINT8 xcoo;
        UINT8 ycoo;
		UINT16 ndata;
		UINT8 style;
        UINT8 ds[10];
    } SGB_PALETTE_STATUS_PACKET_1 = {
        .command = (SGB_ATTR_CHR << 3) | 1,
        .xcoo = 0,
        .ycoo = 16u,
        .ndata = 20u,
		.style = 0,
		.ds = {0b00000000,0b00000000,0b00000000,0b00000000,
        0b00000000,0b00000000,0b00000000,0b00000000,
        0b00000000,0b00000000}
    };
	struct {
        UINT8 command;
        UINT8 xcoo;
        UINT8 ycoo;
		UINT16 ndata;
		UINT8 style;
        UINT8 ds[10];
    } SGB_PALETTE_STATUS_PACKET_2 = {
        .command = (SGB_ATTR_CHR << 3) | 1,
        .xcoo = 0,
        .ycoo = 17u,
        .ndata = 20u,
		.style = 0,
		.ds = {0b00000000,0b00000000,0b00000000,0b00000000,
        0b00000000,0b00000000,0b00000000,0b00000000,
        0b00000000,0b00000000}
    };
    sgb_transfer((void *)&SGB_PALETTE_STATUS_PACKET_0);	
    sgb_transfer((void *)&SGB_PALETTE_STATUS_PACKET_1);	
    sgb_transfer((void *)&SGB_PALETTE_STATUS_PACKET_2);	
}

void set_sgb_palette_overworldsw() __banked{
    set_sgb_palette(SGB_PAL7_LIGHTER, SGB_PAL7_LIGHT, SGB_PAL7_DARK, SGB_PAL7_DARKER);
}
    */