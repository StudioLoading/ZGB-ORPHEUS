#include "Banks/SetAutoBank.h"

#include "SGB.h"
#include "BankManager.h"
#include "ZGBMain.h"
#include "Palette.h"
#include "Keys.h"
#include "Scroll.h"
#include "Sprite.h"
#include "SpriteManager.h"
#include "string.h"
#include "Print.h"

#include "custom_datas.h"

IMPORT_MAP(bordersky);
IMPORT_MAP(borderflame);

extern uint8_t sgb_checked;
CURRENT_BORDER current_border = BORDER_FLAMES;
void manage_sgb_border() BANKED;

void manage_sgb_border() BANKED{
    if(current_state != StateBoss00 && current_border != BORDER_SKY){
        current_border = BORDER_SKY;
    }else if(current_state == StateHades00 && current_border != BORDER_FLAMES){
        current_border = BORDER_FLAMES;
    }
    if(sgb_checked){
        switch(current_border){
            case BORDER_SKY: LOAD_SGB_BORDER(bordersky); break;
            case BORDER_FLAMES: LOAD_SGB_BORDER(borderflame); break;
        }
    }
}

void START() {}

void UPDATE() {}