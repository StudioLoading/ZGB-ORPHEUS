#include "Banks/SetAutoBank.h"

#include "ZGBMain.h"
#include "custom_datas.h"

IMPORT_TILES(maphades002t);
IMPORT_TILES(maphades002ta1);
IMPORT_TILES(maphades002ta2);
IMPORT_TILES(maphades002ta3);



void set_banked_bkg_data(UINT8 first_tile, UINT8 nb_tiles, struct TilesInfo* t, UINT8 bank) NONBANKED {
    uint8_t save = _current_bank;
    SWITCH_ROM(bank);
    set_bkg_data(first_tile, nb_tiles, t->data+((16u) * first_tile));
	SWITCH_ROM(save);
}

void Anim_0() BANKED{
	set_banked_bkg_data(84u, 4u, &maphades002t, BANK(maphades002t));//fire
}
void Anim_1() BANKED{
	set_banked_bkg_data(84u, 4u, &maphades002ta1, BANK(maphades002ta1));//fire
}
void Anim_2() BANKED{
	set_banked_bkg_data(84u, 4u, &maphades002ta2, BANK(maphades002ta2));//fire
}
void Anim_3() BANKED{
	set_banked_bkg_data(84u, 4u, &maphades002ta3, BANK(maphades002ta3));//fire
}

void Anim_Opendoors() BANKED{
	set_banked_bkg_data(88u, 18u, &maphades002ta1, BANK(maphades002ta1));//exit door tiles of all types
}

void Anim_Charon_0() BANKED{
	set_banked_bkg_data(106u, 7u, &maphades002t, BANK(maphades002t));//river
}
void Anim_Charon_1() BANKED{
	set_banked_bkg_data(106u, 7u, &maphades002ta1, BANK(maphades002ta1));//river
}
void Anim_Charon_2() BANKED{
	set_banked_bkg_data(106u, 7u, &maphades002ta2, BANK(maphades002ta2));//river
}
void Anim_Charon_3() BANKED{
	set_banked_bkg_data(106u, 7u, &maphades002ta3, BANK(maphades002ta3));//river
}