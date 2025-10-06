#include "Banks/SetAutoBank.h"

#include "BankManager.h"
#include "ZGBMain.h"
#include "Palette.h"
#include "Keys.h"
#include "Music.h"
#include "Scroll.h"
#include "Sprite.h"
#include "SpriteManager.h"
#include "string.h"
#include "Print.h"

#include "custom_datas.h"
#include "UtilsLoadSave.h"

IMPORT_MAP(mapcartel);
IMPORT_MAP(hudmap);
IMPORT_TILES(fontbw);
IMPORT_TILES(fontjbw);
DECLARE_MUSIC(intro);

extern unsigned char d0[];
extern unsigned char d1[];
extern unsigned char d2[];
extern unsigned char d3[];
extern unsigned char d4[];
extern unsigned char d5[];
extern unsigned char d6[];
extern unsigned char d7[];
extern unsigned char d8[];
extern unsigned char d9[];
extern unsigned char d10[];

extern MACROMAP current_map;
extern UINT8 J_ATK;
extern UINT8 J_INT;
extern UINT8 song_selection_cooldown;
extern INT8 boss_hp_current;
extern UINT8 boss_intro;
extern UINT8 show_cartel;
extern CHOSEN_LANGUAGE chosen_language;
extern UINT8 hades_music_started;

extern UINT8 is_level_on_boss() BANKED;
extern void go_to_next_map() BANKED;


void START(){
    InitScroll(BANK(mapcartel), &mapcartel, 0, 0);
    switch(chosen_language){
        case ENG:
            INIT_FONT(fontbw, PRINT_BKG);
        break;
        case JAP:
            INIT_FONT(fontjbw, PRINT_BKG);
        break;
    }
    INIT_HUD(hudmap);
    PRINT(1,2, d0);
    PRINT(1,3, d1);
    PRINT(1,4, d2);
    PRINT(1,5, d3);
    PRINT(1,6, d4);
    PRINT(1,7, d5);
    PRINT(1,8, d6);
    PRINT(1,9, d7);
    PRINT(1,10, d8);
    PRINT(1,11, d9);
    PRINT(1,12, d10);
    show_cartel = 0u;
    if(boss_intro == 4 && is_level_on_boss()){
        PlayMusic(intro, 1);
    }
}

void UPDATE(){
    if(KEY_TICKED(J_ATK) || KEY_TICKED(J_INT)){
        song_selection_cooldown = 40u;
        if(is_level_on_boss() && current_map != HADES_26){
            if(boss_intro == 4){
                boss_intro = 0;//reset
                StopMusic;
			    hades_music_started = 0;
                go_to_next_map();
                //TODO nuovo State di presentazione Nuovo Bioma
                //dal quale chiamare la go_to_next_map()
            }else{
                SetState(StateBoss00);
            }
        }else{
            SetState(StateHades00);
        }
    }
}