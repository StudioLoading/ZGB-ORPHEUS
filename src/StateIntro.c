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
#include "Dialog.h"

#define TEXT_TIMEOUT 40
#define NOTE_COUNT_MAX 105

IMPORT_MAP(mapintro);
IMPORT_MAP(intro0);
IMPORT_MAP(intro1);
IMPORT_MAP(intro2);
IMPORT_MAP(intro3);
IMPORT_MAP(intro4);
IMPORT_TILES(font);

extern UINT8 J_INT;
extern UINT8 J_ATK;

extern unsigned char EMPTY_STRING_20[];
extern UINT8 note_countdown;
extern UINT8 rndm;
extern UINT8 note_configured;
UINT8 intro_page_counter = 0u;
UINT8 text_wait = 0u;
UINT8 text_shown = 0u;

void START(){
    text_shown = 0u;
    switch(intro_page_counter){
        case 0u:
        case 1u:
	        InitScroll(BANK(intro0), &intro0, 0, 0);
        break;
        case 2u:
	        InitScroll(BANK(intro2), &intro2, 0, 0);
        break;
        case 3u:
	        InitScroll(BANK(intro3), &intro3, 0, 0);
        break;
        case 4u:
        case 5u:
	        InitScroll(BANK(intro4), &intro4, 0, 0);
        break;
        default:
            InitScroll(BANK(mapintro), &mapintro, 0, 0);
        break;
    }
    INIT_FONT(font, PRINT_BKG);
    print_target = PRINT_BKG;
    note_countdown = NOTE_COUNT_MAX - 20;
    note_configured = 0;
    rndm = 1;
}

void UPDATE(){
    if(text_wait < TEXT_TIMEOUT){
        text_wait++;
        return;
    }
    if(intro_page_counter == 1){
        note_countdown++;
        rndm++;
        if(note_countdown >= NOTE_COUNT_MAX){
            note_countdown = 0;
            note_configured++;
            if(note_configured > 3){
                note_configured = 1;
            }
            Sprite* s_note = SpriteManagerAdd(SpriteNote, 40u, 55u + (note_configured << 1));
            struct EnemyInfo* note_data = (struct EnemyInfo*) s_note->custom_data;
            if(rndm | 0){
                note_data->e_configured = note_configured+1;
            }else{
                note_data->e_configured = note_configured;
            }
        }
    }
    if(text_shown == 0u){
        switch(intro_page_counter){
            case 0u:
                PRINT(0,11, "A LONG TIME AGO, IN ");
                PRINT(0,12, "ANCIENT GREECE, A HE");
                PRINT(0,13, "RO AND A NYMPH WERE ");
                PRINT(0,14, "DEEPLY IN LOVE WITH ");
                PRINT(0,15, "EACH OTHER. THEIR NA");
                PRINT(0,16, "MES WERE            ");
                PRINT(0,17, "ORPHEUS AND EURYDICE");
            break;
            case 1u:
                PRINT(0,11, "THEY LIVED HAPPILY  ");
                PRINT(0,12, "AND THEIR DAYS ACCOM");
                PRINT(0,13, "PANIED BY THE SWEET ");
                PRINT(0,14, "MUSIC ORPHEUS COMPO ");
                PRINT(0,15, "SED WITH HIS LYRE.  ");
                PRINT(0,16, "                    ");
                PRINT(0,17, "                    ");
            break;
            case 2u:
                PRINT(0,11, "UNFORTUNATELY ONE   ");
                PRINT(0,12, "DAY EURYDICE STEPPED");
                PRINT(0,13, "ON A SNAKE. IN DEFEN");
                PRINT(0,14, "SE IT BIT HER, POISO");
                PRINT(0,15, "NING HER IMMEDIATELY");
                PRINT(0,16, "                    ");
                PRINT(0,17, "                    ");
            break;
            case 3u:
                PRINT(0,11, "THE POOR NYMPH SUD  ");
                PRINT(0,12, "DENLY DIED, LEAVING ");
                PRINT(0,13, "ORPHEUS ALONE WITH  ");
                PRINT(0,14, "HIS GRIEF.          ");
                PRINT(0,15, "                    ");
                PRINT(0,16, "                    ");
                PRINT(0,17, "                    ");
            break;
            case 4u:
                PRINT(0,11, "HOWEVER, THE YOUNG  ");
                PRINT(0,12, "HERO DID NOT GIVE UP");
                PRINT(0,13, "BECAUSE HE KNEW     ");
                PRINT(0,14, "THAT EVERY SOUL OF  ");
                PRINT(0,15, "THE DEPARTED ENDED  ");
                PRINT(0,16, "DOWN IN THE         ");
                PRINT(0,17, "UNDERWORLD.         ");
            break;
            case 5u:
                PRINT(0,11, "DETERMINED TO BRING ");
                PRINT(0,12, "EURYDICE BACK TO LI ");
                PRINT(0,13, "FE, ORPHEUS GATHERED");
                PRINT(0,14, "HIS COURAGE AND DECI");
                PRINT(0,15, "DED TO FACE THE GOD ");
                PRINT(0,16, "OF THE UNDERWORLD   ");
                PRINT(0,17, "HIMSELF.            ");
            break;
        }

        text_shown = 1u;
    }

    if(KEY_TICKED(J_START) || KEY_TICKED(J_ATK) || KEY_TICKED(J_INT)){
        intro_page_counter++;
        if(intro_page_counter < 6){
            SetState(StateIntro);
        }else{
            SetState(StateStart);
        }
    }

}