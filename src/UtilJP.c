#include "Banks/SetAutoBank.h"

#include "Print.h" 
#include "Scroll.h" 
#include "ZGBMain.h"

#include "Dialog.h"

extern UINT16 font_offset;

IMPORT_TILES(fontjtutorial0);
IMPORT_TILES(fontjtutorial1);
IMPORT_TILES(fontjtutorial2);
IMPORT_TILES(fontjtutorial3);
IMPORT_TILES(fontjtutorial4);
IMPORT_TILES(fontjtutorial5);
IMPORT_TILES(fontjhades00welcome);

typedef struct {
    UINT8 bank;
    void *ptr;
} far_ptr_t;

const far_ptr_t state_fonts[] = {
    [FIRSTEVER]    = { BANK(fontjtutorial0), &fontjtutorial0 },
    [MISSING_LYRE] = { BANK(fontjtutorial1), &fontjtutorial1 },
    [FOUND_LYRE]   = { BANK(fontjtutorial2), &fontjtutorial2 },
    [PUSH_BUTTON]  = { BANK(fontjtutorial3), &fontjtutorial3 },
    [PRESS_INTERACT]= {BANK(fontjtutorial4), &fontjtutorial4},
    [HADES_ENTRANCE]= {BANK(fontjtutorial5), &fontjtutorial5},
    [HADES_WELCOME]=   {BANK(fontjhades00welcome), &fontjhades00welcome}
};

void jp_set_banked_win_data(WHOSTALKING arg_whostalking) NONBANKED {
    uint8_t save = _current_bank;
    SWITCH_ROM(state_fonts[arg_whostalking].bank);
    UINT8 __save = last_tile_loaded;
    ScrollSetTiles(font_offset, state_fonts[arg_whostalking].bank, state_fonts[arg_whostalking].ptr);
    last_tile_loaded = __save;
	SWITCH_ROM(save);
}

void Anim_JP(WHOSTALKING arg_whostalking) BANKED{
    jp_set_banked_win_data(arg_whostalking);
}