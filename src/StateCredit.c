#include "Banks/SetAutoBank.h"

#include "BankManager.h"
#include "ZGBMain.h"
#include "Palette.h"
#include "Keys.h"
#include "Scroll.h"
#include "Sprite.h"
#include "SpriteManager.h"

#include "custom_datas.h"

#define NOTE_COUNT_MAX 80

IMPORT_MAP(mapcredit0);

UINT8 note_countdown = 0;
UINT8 note_configured = 1;
UINT8 rndm = 0u;


void START(){
	InitScroll(BANK(mapcredit0), &mapcredit0, 0, 0);
    Sprite* s_note0 = SpriteManagerAdd(SpriteNote, 0, 40u);
    struct EnemyInfo* note_data = (struct EnemyInfo*) s_note0->custom_data;
    note_data->e_configured = 3;
}

void UPDATE(){
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
    if(KEY_TICKED(J_START)){
        SetState(StateStart);
    }
}