#include "Banks/SetAutoBank.h"

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

extern CHOSEN_LANGUAGE chosen_language;

const UINT8 a_flag_en[] = {1, 2};
const UINT8 a_flag_en_chosen[] = {2, 2,4};
const UINT8 a_flag_jp[] = {1, 1};
const UINT8 a_flag_jp_chosen[] = {2, 1,3};

void START() {
    THIS->lim_x = 500;
}

void UPDATE() {
    struct FlagInfo* flag_info = (struct FlagInfo*)THIS->custom_data;
    if(flag_info->configured == 1){
        switch(flag_info->type){
            case ENG:
                if(flag_info->type == chosen_language){
                    SetSpriteAnim(THIS, a_flag_en_chosen, 12);
                }else{
                    SetSpriteAnim(THIS, a_flag_en, 1);
                }
            break;
            case JAP:
                if(flag_info->type == chosen_language){
                    SetSpriteAnim(THIS, a_flag_jp_chosen, 12);
                }else{
                    SetSpriteAnim(THIS, a_flag_jp, 1);
                }
            break;
        }
    }
}

void DESTROY() {
}