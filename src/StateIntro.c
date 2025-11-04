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
IMPORT_TILES(fontj);
IMPORT_TILES(fontjintro0);
IMPORT_TILES(fontjintro1);

extern UINT8 J_INT;
extern UINT8 J_ATK;

extern UINT8 note_countdown;
extern UINT8 rndm;
extern UINT8 note_configured;
extern CHOSEN_LANGUAGE chosen_language;

UINT8 intro_page_counter = 0u;
UINT8 text_wait = 0u;
UINT8 text_shown = 0u;

void print_intro_en() BANKED;
void print_intro_jp() BANKED;

extern void manage_sgb_border() BANKED;
extern void manage_sgb_palette() BANKED;


void START(){
    text_shown = 0u;
    switch(intro_page_counter){
        case 0u:
            manage_sgb_border();
            manage_sgb_palette();
        case 1u:
	        InitScroll(BANK(intro0), &intro0, 0, 0);
        break;
        case 2u:
	        InitScroll(BANK(intro2), &intro2, 0, 0);
        break;
        case 3u:
            InitScroll(BANK(intro1), &intro1, 0, 0);
        break;
        case 4u:
            InitScroll(BANK(intro3), &intro3, 0, 0);
        break;
        case 5u:
        case 6u:
	        InitScroll(BANK(intro4), &intro4, 0, 0);
        break;
        default:
            InitScroll(BANK(mapintro), &mapintro, 0, 0);
        break;
    }
    switch(chosen_language){
        case ENG: INIT_FONT(font, PRINT_BKG); break;
        case JAP: {
            switch(intro_page_counter){
                case 0: INIT_FONT(fontjintro0, PRINT_BKG); break;
                case 1: INIT_FONT(fontjintro1, PRINT_BKG); break;
            }
            //INIT_FONT(fontj, PRINT_BKG); 
        }break;
    }
    
    print_target = PRINT_BKG;
    note_countdown = NOTE_COUNT_MAX - 20;
    note_configured = 0;
    rndm = 1;
}

void print_intro_en() BANKED{
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
            PRINT(0,11, "                    ");
            PRINT(0,12, "ORPHEUS BRAVELY     ");
            PRINT(0,13, "DEFEATED THE SNAKE, ");
            PRINT(0,14, "TRYING TO PROTECT   ");
            PRINT(0,15, "HIS BELOVED NYMPH   ");
            PRINT(0,16, "FROM DANGER.        ");
            PRINT(0,17, "                    ");
        break;
        case 4u:
            PRINT(0,11, "THE POOR NYMPH SUD  ");
            PRINT(0,12, "DENLY DIED, LEAVING ");
            PRINT(0,13, "ORPHEUS ALONE WITH  ");
            PRINT(0,14, "HIS GRIEF.          ");
            PRINT(0,15, "                    ");
            PRINT(0,16, "                    ");
            PRINT(0,17, "                    ");
        break;
        case 5u:
            PRINT(0,11, "HOWEVER, THE YOUNG  ");
            PRINT(0,12, "HERO DID NOT GIVE UP");
            PRINT(0,13, "BECAUSE HE KNEW     ");
            PRINT(0,14, "THAT EVERY SOUL OF  ");
            PRINT(0,15, "THE DEPARTED FOUND  ");
            PRINT(0,16, "THEIR WAY TO THE    ");
            PRINT(0,17, "UNDERWORLD.         ");
        break;
        case 6u:
            PRINT(0,11, "DETERMINED TO BRING ");
            PRINT(0,12, "EURYDICE BACK TO LI ");
            PRINT(0,13, "FE, ORPHEUS GATHERED");
            PRINT(0,14, "HIS COURAGE AND DECI");
            PRINT(0,15, "DED TO FACE THE GOD ");
            PRINT(0,16, "OF THE UNDERWORLD   ");
            PRINT(0,17, "HIMSELF.            ");
        break;
    }
}

void print_intro_jp() BANKED{
    switch(intro_page_counter){
        case 0u:
            PRINT(0,11, "                    ");
            PRINT(0,12, "    QDG9QDGVWXYM9   ");
            PRINT(0,13, "   Z01234LBCPCGTL   ");
            PRINT(0,14, "    5W67LBCL'CHB    ");
            PRINT(0,15, "  FODEABGA8KBPGI.   ");
            PRINT(0,16, "                    ");
            PRINT(0,17, "                    ");
        break;
        case 1u:
            PRINT(0,11, "                    ");
            PRINT(0,12, "  QDGB4QDGBWXXYZXM4 ");
            PRINT(0,13, "  Z01234XKCCPKGUL   ");
            PRINT(0,14, "    0X12LBCLSCHB    ");
            PRINT(0,15, "  FODEABGA3KBPGI5   ");
            PRINT(0,16, "                    ");
            PRINT(0,17, "                    ");
        break;
        case 2u:
            PRINT(0,11, "       1JC V 8      ");
            PRINT(0,12, "     DC)!SBN Z A,   ");
            PRINT(0,13, "     0 20 - 1CP     ");
            PRINT(0,14, "     20 Z 5 - 48,   ");
            PRINT(0,15, "    P7 V FYO - F5   ");
            PRINT(0,16, "      PPQ V TH F    ");
            PRINT(0,17, "         4?RP       ");
        break;
        case 3u:
            PRINT(0,11, "       E,2CM        ");
            PRINT(0,12, "       Z ABM        ");
            PRINT(0,13, "      , VC1 -       ");
            PRINT(0,14, "       GI Y F(      ");
            PRINT(0,15, "      48:C T LS     ");
            PRINT(0,16, "      !CF V OY      ");
            PRINT(0,17, "      20 - PELP     ");
        break;
        case 4u:
            PRINT(0,11, "       FULB VC1     ");
            PRINT(0,12, "       Z PPQ V      ");
            PRINT(0,13, "      LV E,2CM -    ");
            PRINT(0,14, "        FUL5        ");
            PRINT(0,15, "       Y UF V       ");
            PRINT(0,16, "      0T) YJLP      ");
            PRINT(0,17, "                    ");
        break;
        case 5u:
            PRINT(0,11, "      LFL ?FG       ");
            PRINT(0,12, "       DB! Z        ");
            PRINT(0,13, "     AG(7UFRP       ");
            PRINT(0,14, "    UNU( UH URP     ");
            PRINT(0,15, "    M2S Y P4LB      ");
            PRINT(0,16, "F 8BFB 2 Y 5Q - 5RI ");
            PRINT(0,17, " , JT - LRSB P F( P ");
        break;
        case 6u:
            PRINT(0,11, "     DC)!SBN - '5   ");
            PRINT(0,12, "  FD( N , IRB - LP  ");
            PRINT(0,13, " E,2CM Z !CG - AR7  ");
            PRINT(0,14, "   8BFB Y F5 LLW    ");
            PRINT(0,15, "    V PPQ V PQ      ");
            PRINT(0,16, "     6F C JT -      ");
            PRINT(0,17, "       IRB LP       ");
        break;
    }
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
        switch(chosen_language){
            case ENG: print_intro_en(); break;
            case JAP: print_intro_jp(); break;
        }
        text_shown = 1u;
    }

    if(KEY_TICKED(J_START) || KEY_TICKED(J_ATK) || KEY_TICKED(J_INT)){
        intro_page_counter++;
        if(intro_page_counter < 7){
            SetState(StateIntro);
        }else{
            SetState(StateStart);
        }
    }

}