#include "Banks/SetAutoBank.h"

#include "ZGBMain.h"
#include "custom_datas.h"

IMPORT_TILES(maphades002t);
IMPORT_TILES(maphades002ta1);
IMPORT_TILES(maphades002ta2);
IMPORT_TILES(maphades002ta3);
IMPORT_TILES(maphades002ta4);
IMPORT_TILES(maphades002ta5);
IMPORT_TILES(maphades002ta6);
IMPORT_TILES(maphades002ta7);
IMPORT_TILES(maphades003t);

IMPORT_TILES(mapbosscerberust);
IMPORT_TILES(mapbossminost);
IMPORT_TILES(mapbossminost01);
IMPORT_TILES(mapbossminost02);
IMPORT_TILES(mapbossminost03);
IMPORT_TILES(mapbossminost04);


void set_banked_bkg_data(UINT8 first_tile, UINT8 nb_tiles, struct TilesInfo* t, UINT8 bank) NONBANKED {
    uint8_t save = _current_bank;
    SWITCH_ROM(bank);
    set_bkg_data(first_tile, nb_tiles, t->data+((16u) * first_tile));
	SWITCH_ROM(save);
}

void Anim_Breath_Minos_0() BANKED{
	set_banked_bkg_data(96u, 15u, &mapbossminost, BANK(mapbossminost));//minos breath
}
void Anim_Breath_Minos_1() BANKED{
	set_banked_bkg_data(96u, 15u, &mapbossminost01, BANK(mapbossminost01));//minos breath
}
void Anim_Breath_Minos_2() BANKED{
	set_banked_bkg_data(96u, 15u, &mapbossminost02, BANK(mapbossminost02));//minos breath
}

void Anim_Hit_Minos_0() BANKED{
	set_banked_bkg_data(96u, 15u, &mapbossminost04, BANK(mapbossminost04));//minos hit
}

void Anim_Hit_Minos_1() BANKED{
	set_banked_bkg_data(96u, 15u, &mapbossminost03, BANK(mapbossminost03));//minos hit
}

void AnimFire_0() BANKED{
	set_banked_bkg_data(84u, 4u, &maphades002t, BANK(maphades002t));//fire
}
void AnimFire_Minos0() BANKED{
	set_banked_bkg_data(84u, 4u, &mapbossminost, BANK(mapbossminost));//fire
}
void AnimFire_1() BANKED{
	set_banked_bkg_data(84u, 4u, &maphades002ta1, BANK(maphades002ta1));//fire
}
void AnimFire_2() BANKED{
	set_banked_bkg_data(84u, 4u, &maphades002ta2, BANK(maphades002ta2));//fire
}
void AnimFire_3() BANKED{
	set_banked_bkg_data(84u, 4u, &maphades002ta3, BANK(maphades002ta3));//fire
}


void Anim_Spike_0() BANKED{
	set_banked_bkg_data(50u, 1u, &maphades003t, BANK(maphades003t));//spike
}
void Anim_Spike_1() BANKED{
	set_banked_bkg_data(50u, 1u, &maphades002ta1, BANK(maphades002ta1));//spike
}
void Anim_Spike_2() BANKED{
	set_banked_bkg_data(50u, 1u, &maphades002ta2, BANK(maphades002ta2));//spike
}
void Anim_Spike_3() BANKED{
	set_banked_bkg_data(50u, 1u, &maphades002ta3, BANK(maphades002ta3));//spike
}

void Anim_Opendoors() BANKED{
	set_banked_bkg_data(88u, 18u, &maphades002ta1, BANK(maphades002ta1));//exit door tiles of all types
}

void Anim_Minos_0() BANKED{
	set_banked_bkg_data(106u, 7u, &mapbossminost, BANK(mapbossminost));//
}
void Anim_Cerberus_0() BANKED{
	set_banked_bkg_data(106u, 7u, &mapbosscerberust, BANK(mapbosscerberust));//river
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
void Anim_Charon_4() BANKED{
	set_banked_bkg_data(106u, 7u, &maphades002ta4, BANK(maphades002ta4));//river
}
void Anim_Charon_5() BANKED{
	set_banked_bkg_data(106u, 7u, &maphades002ta5, BANK(maphades002ta5));//river
}
void Anim_Charon_6() BANKED{
	set_banked_bkg_data(106u, 7u, &maphades002ta6, BANK(maphades002ta6));//river
}
void Anim_Charon_7() BANKED{
	set_banked_bkg_data(106u, 7u, &maphades002ta7, BANK(maphades002ta7));//river
}