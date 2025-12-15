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
IMPORT_TILES(fontjhades01moveblock);
IMPORT_TILES(fontjhades02usekey);
IMPORT_TILES(fontjhades03kill);
IMPORT_TILES(fontjhades04guards);
IMPORT_TILES(fontjhades05rolling);
IMPORT_TILES(fontjhades06owlsaving);
IMPORT_TILES(fontjhades07guardsawaken);
IMPORT_TILES(fontjhades08death);
IMPORT_TILES(fontjhades09charonintro);
IMPORT_TILES(fontjhades09charonbeated);
IMPORT_TILES(fontjhades10cerberusintro);
IMPORT_TILES(fontjhades10cerberusbeated);
IMPORT_TILES(fontjhades11minosintro);
IMPORT_TILES(fontjhades11minosbeated);
IMPORT_TILES(fontjhades12aeacusintro);
IMPORT_TILES(fontjhades12aeacusbeated);
IMPORT_TILES(fontjhades13hadesintro);
IMPORT_TILES(fontjhades13hadesbeated);
IMPORT_TILES(fontjendgame01);
IMPORT_TILES(fontjendgame02);
IMPORT_TILES(fontjendgame03);
IMPORT_TILES(fontjendgame04);
IMPORT_TILES(fontjendgame05);

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
    [HADES_WELCOME]=   {BANK(fontjhades00welcome), &fontjhades00welcome},
    [HADES_MOVE_BLOCK]=   {BANK(fontjhades01moveblock), &fontjhades01moveblock},
    [HADES_USE_KEY]=   {BANK(fontjhades02usekey), &fontjhades02usekey},
    [HADES_KILL_ENEMY]=   {BANK(fontjhades03kill), &fontjhades03kill},
    [HADES_GUARDS]=   {BANK(fontjhades04guards), &fontjhades04guards},
    [HADES_ROLLING_STONES]=   {BANK(fontjhades05rolling), &fontjhades05rolling},
    [HADES_OWL_SAVING]=   {BANK(fontjhades06owlsaving), &fontjhades06owlsaving},
    [HADES_GUARDS_AWAKENED]=   {BANK(fontjhades07guardsawaken), &fontjhades07guardsawaken},
    [HADES_DEATH]=   {BANK(fontjhades08death), &fontjhades08death},
    [BOSS_CHARON_INTRO]=   {BANK(fontjhades09charonintro), &fontjhades09charonintro},
    [BOSS_CHARON_BEATED]=   {BANK(fontjhades09charonbeated), &fontjhades09charonbeated},
    [BOSS_CERBERUS_INTRO]=   {BANK(fontjhades10cerberusintro), &fontjhades10cerberusintro},
    [BOSS_CERBERUS_BEATED]=   {BANK(fontjhades10cerberusbeated), &fontjhades10cerberusbeated},
    [BOSS_MINOS_INTRO]=   {BANK(fontjhades11minosintro), &fontjhades11minosintro},
    [BOSS_MINOS_BEATED]=   {BANK(fontjhades11minosbeated), &fontjhades11minosbeated},
    [BOSS_AEACUS_INTRO]=   {BANK(fontjhades12aeacusintro), &fontjhades12aeacusintro},
    [BOSS_AEACUS_BEATED]=   {BANK(fontjhades12aeacusbeated), &fontjhades12aeacusbeated},
    [BOSS_HADES_INTRO]=   {BANK(fontjhades13hadesintro), &fontjhades13hadesintro},
    [BOSS_HADES_BEATED]=   {BANK(fontjhades13hadesbeated), &fontjhades13hadesbeated},
    [END_ORPHEUS_FOLLOW]=   {BANK(fontjendgame01), &fontjendgame01},
    [END_ORPHEUS_EURIDYCE]=   {BANK(fontjendgame02), &fontjendgame02},
    [END_EURIDYCE_NOOO]=   {BANK(fontjendgame03), &fontjendgame03},
    [END_EURIDYCE_BOX]=   {BANK(fontjendgame04), &fontjendgame04},
    [ENDSCREEN_SEEYOUIN2027]=   {BANK(fontjendgame05), &fontjendgame05},

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