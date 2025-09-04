#include "Banks/SetAutoBank.h"

#include "SGB.h"
#include "BankManager.h"
#include "ZGBMain.h"
#include "Palette.h"
#include "Scroll.h"
#include "Sprite.h"
#include "SpriteManager.h"
#include "string.h"
#include "Print.h"

#include "custom_datas.h"
#include "sgb_palette.h"

IMPORT_MAP(bordersky);
IMPORT_MAP(borderflame);

CURRENT_BORDER current_border = BORDER_NO;

extern UINT8 credit_page_counter;
extern UINT8 intro_page_counter;
extern MACROMAP current_map;

void manage_sgb_border() BANKED;
void manage_sgb_palette() BANKED;

void manage_sgb_border() BANKED{
    CURRENT_BORDER old_border = current_border;
    if(current_state == StateCredit && current_border != BORDER_FLAMES){
        current_border = BORDER_FLAMES;
    }else if(current_state == StateIntro && current_border != BORDER_SKY){
        current_border = BORDER_SKY;
    //}else if(current_state == StateHades00 && current_border != BORDER_FLAMES){
    }else if(current_state == StateTutorial && current_border != BORDER_FLAMES){
        current_border = BORDER_FLAMES;
    }
    if(old_border != current_border){
        switch(current_border){
            case BORDER_SKY:{ LOAD_SGB_BORDER(bordersky); }break;
            case BORDER_FLAMES:{ LOAD_SGB_BORDER(borderflame); }break;
        }
    }
}

void manage_sgb_palette() BANKED{
    switch(current_state){
        case StateCredit:{
            switch(credit_page_counter){
                case 0://Studio Loading & Kibou
                    set_sgb_palette_credits_slkibou();
                break;
                case 1://Misu & Sloopy
                    set_sgb_palette_credits_misusloopy();
                break;
                case 2://FAult & Studio Loading
                    set_sgb_palette_credits_faultsl();
                break;
                case 3://ZGB
                    set_sgb_palette_credits_zgb();
                break;
                case 4://Titlescreen
                    set_sbg_titlescreen();
                break;
            }
        }break;
        case StateIntro:{
            switch(intro_page_counter){
                case 0:
                    set_sbg_intro();
                break;
            }
        }break;
        case StateTutorial:
            set_sbg_palette_tutorial();
        break;
        case StateHades00:{
            if(current_map <= BOSS_CHARON){
                set_sbg_palette_hades_charon();
            }
        }break;
    }
}

void START() {}

void UPDATE() {}