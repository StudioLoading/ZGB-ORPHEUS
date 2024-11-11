#include "Banks/SetAutoBank.h"

#include "ZGBMain.h"
#include "Palette.h"
#include "Scroll.h"
#include "Sprite.h"
#include "SpriteManager.h"

#include "custom_datas.h"

void START() {
    THIS->lim_x = 1000u;
    THIS->lim_y = 1000u;
    struct ItemInfo* i_data = (struct ItemInfo*) THIS->custom_data;
    i_data->item_type = LYRE;
    i_data->i_configured = 2;
}

void UPDATE() {
}

void DESTROY() {
}