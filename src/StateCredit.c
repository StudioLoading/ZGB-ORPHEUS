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

#define NOTE_COUNT_MAX 80
#define PRESSSTART_COUNT_MAX 20

IMPORT_MAP(mapcredit0);
IMPORT_MAP(mapcredit1);
IMPORT_MAP(mapcredit2);
IMPORT_MAP(mapcredit3);
IMPORT_MAP(maptitlescreen);
IMPORT_TILES(font);

UINT8 note_countdown = 0;
UINT8 note_configured = 1;
UINT8 rndm = 0u;
UINT8 credit_page_counter = 0u;

void START(){
    switch(credit_page_counter){
        case 0u:
            Sprite* s_note0 = SpriteManagerAdd(SpriteNote, 0, 40u);
            struct EnemyInfo* note_data = (struct EnemyInfo*) s_note0->custom_data;
            note_data->e_configured = 3;
            InitScroll(BANK(mapcredit0), &mapcredit0, 0, 0);
        break;
        case 1u:
            InitScroll(BANK(mapcredit1), &mapcredit1, 0, 0);
        break;
        case 2u:
            InitScroll(BANK(mapcredit2), &mapcredit2, 0, 0);
        break;
        case 3u:
            InitScroll(BANK(mapcredit3), &mapcredit3, 0, 0);
        break;
        case 4u:
            InitScroll(BANK(maptitlescreen), &maptitlescreen, 0, 0);
        break;
    }
    INIT_FONT(font, PRINT_BKG);
    PRINT(12, 17, "VO.O.XV");
}

void UPDATE(){
    if(credit_page_counter == 1){//misu & sloopygoop
        note_countdown++;
        rndm++;
        if(note_countdown >= NOTE_COUNT_MAX){
            note_countdown = 0;
            note_configured++;
            if(note_configured > 3){
                note_configured = 1;
            }
            Sprite* s_note = SpriteManagerAdd(SpriteNote, 0, 35u * note_configured);
            struct EnemyInfo* note_data = (struct EnemyInfo*) s_note->custom_data;
            if(rndm | 0){
                note_data->e_configured = note_configured+1;
            }else{
                note_data->e_configured = note_configured;
            }
        }
    }
    if(credit_page_counter == 4){//titlescreen
        note_countdown++;
        if(note_countdown >= PRESSSTART_COUNT_MAX){
            note_countdown = 0;
            if(rndm == 0){rndm = 1;}
            else{rndm = 0;}
            switch(rndm){
                case 0u: PRINT(5, 14, "PRESS START");
                break;
                case 1u: PRINT(5, 14, "           ");
                break;
            }
        }
    }
    if(KEY_TICKED(J_START)){
        credit_page_counter++;
        note_countdown = 0;
        rndm = 0;
        switch(credit_page_counter){
            case 1u://misu & sloopygoop
            case 2u://faultbox & studioloading
            case 3u://zgb engine
            case 4u://titlescreen
                SetState(StateCredit);
            break;
            case 5u://intro + tutorial
                SetState(StateIntro);
            break;
        }
    }
}