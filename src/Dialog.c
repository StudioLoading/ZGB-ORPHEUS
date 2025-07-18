#include "Banks/SetAutoBank.h"

#include "BankManager.h"
#include "ZGBMain.h"
#include "string.h"

#include "Dialog.h"

unsigned char d0[22];
unsigned char d1[22];
unsigned char d2[22];
unsigned char d3[22];
unsigned char d4[22];
unsigned char d5[22];
unsigned char d6[22];
unsigned char d7[22];
unsigned char d8[22];
unsigned char d9[22];
unsigned char d10[22];
unsigned char d11[22];
unsigned char d12[22];
unsigned char d13[22];
unsigned char d14[22];
unsigned char d15[22];
unsigned char d16[22];
unsigned char d17[22];
unsigned char d18[22];
unsigned char d19[22];
unsigned char d20[22];
unsigned char d21[22];
unsigned char d22[22];
unsigned char d23[22];
unsigned char EMPTY_STRING_20[] = "                    ";

UINT8 prepare_dialog(WHOSTALKING arg_whostalking) BANKED;
unsigned char get_char(UINT8 arg_writing_line, UINT8 arg_counter_char) BANKED;

UINT8 prepare_dialog(WHOSTALKING arg_whostalking) BANKED{
    switch(arg_whostalking){
        case FIRSTEVER:
            memcpy(d1, "THE GATES OF HADES  ", 21);
            memcpy(d2, "ARE NOT FAR...      ", 21);
            memcpy(d3, "I NEED TO FIND MY   ", 21);
            memcpy(d4, "LYRE FIRST! I THINK ", 21);
            memcpy(d5, "MY MOTHER CALLIOPE  ", 21);
            memcpy(d6, "LEFT IT AROUND HERE.", 21);
            memcpy(d7, EMPTY_STRING_20, 21);
            memcpy(d8, "   ...LET'S GO!     ", 21);
            memcpy(d9, EMPTY_STRING_20, 21);
            return 9u;
        break;
        case MISSING_LYRE:
            memcpy(d1, "I CAN'T PROCEED, I  ", 21);
            memcpy(d2, "NEED TO FIND MY LYRE", 21);
            memcpy(d3, "FIRST!              ", 21);
            return 3u;
        break;
        case FOUND_LYRE:
            memcpy(d1, "GREAT! WITH MY LYRE ", 21);
            memcpy(d2, "I CAN PLAY DIFFERENT", 21);
            memcpy(d3, "SONGS TO SCARE,     ", 21);
            memcpy(d4, "ATTRACT OR REPEL MY ", 21);
            memcpy(d5, "ENEMIES.            ", 21);
            memcpy(d6, EMPTY_STRING_20, 21);
            return 6u;
        break;
        case PUSH_BUTTON:
            memcpy(d1, "I CAN OPEN THE GATE ", 21);
            memcpy(d2, "BY STANDING OVER    ", 21);
            memcpy(d3, "THAT BUTTON.        ", 21);
            return 3u;
        break;
        case PRESS_INTERACT:
            memcpy(d1, "PRESS THE INTERACT  ", 21);
            memcpy(d2, "BUTTON TO GET THE   ", 21);
            memcpy(d3, "LYRE!               ", 21);
            return 3u;
        break;
        case TUTORIAL_BLOCKS:
            memcpy(d1, "I AM ABLE TO PUSH   ", 21);
            memcpy(d2, "HEAVY BLOCKS  (PRESS", 21);
            memcpy(d3, "INTERACT BUTTON)    ", 21);
            memcpy(d4, "TO OPEN THIS GATE I ", 21);
            memcpy(d5, "NEED TO PUSH THAT   ", 21);
            memcpy(d6, "BLOCK ON THE BUTTON.", 21);
            return 6u;
        break;
        case HADES_ENTRANCE:
            memcpy(d1, "HERE I AM... THE    ", 21);
            memcpy(d2, "GATES OF HADES!     ", 21);
            memcpy(d3, "I WILL SAVE YOU,    ", 21);
            memcpy(d4, "EURYDICE! NO MATTER ", 21);
            memcpy(d5, "HOW MANY CHALLENGES ", 21);
            memcpy(d6, "I FACE!             ", 21);
            return 6u;
        break;
        case TUTORIAL_PLAY:
            memcpy(d1, "BY PLAYING MY LYRE  ", 21);
            memcpy(d2, "I WILL MOVE MY ENEMI", 21);
            memcpy(d3, "ES AROUND... LET ME ", 21);
            memcpy(d4, "PUSH THAT SKELETON  ", 21);
            memcpy(d5, "INTO THOSE FLAMES!  ", 21);
            memcpy(d6, EMPTY_STRING_20, 21);
            return 6u;
        break;
        case TUTORIAL_CARTEL:
            memcpy(d0, "WELCOME YOU BASTAR", 21);
            memcpy(d1, "WELCOME YOU BASTAR", 21);
            memcpy(d2, "GATES OF HADES!   ", 21);
            memcpy(d3, "I WILL SAVE YOU,  ", 21);
            memcpy(d4, "EURYDICE! NO MATTE", 21);
            memcpy(d5, "HOW MANY CHALLENGE", 21);
            memcpy(d6, "I FACE!           ", 21);
            memcpy(d7, "I FACE!           ", 21);
            memcpy(d8, "I FACE!           ", 21);
            memcpy(d9, "I FACE!           ", 21);
            memcpy(d10, "I FACE!           ", 21);
            memcpy(d11, "I FACE!           ", 21);
            memcpy(d12, "I FACE!           ", 21);
        break;
        case HADES_WELCOME:
            memcpy(d0, "WELCOME YOU BASTAR", 21);
            memcpy(d1, "WELCOME YOU BASTAR", 21);
            memcpy(d2, "GATES OF HADES!   ", 21);
            memcpy(d3, "I WILL SAVE YOU,  ", 21);
            memcpy(d4, "EURYDICE! NO MATTE", 21);
            memcpy(d5, "HOW MANY CHALLENGE", 21);
            memcpy(d6, "I FACE!           ", 21);
            memcpy(d7, "I FACE!           ", 21);
            memcpy(d8, "I FACE!           ", 21);
            memcpy(d9, "I FACE!           ", 21);
            memcpy(d10, "I FACE!           ", 21);
            memcpy(d11, "I FACE!           ", 21);
            memcpy(d12, "I FACE!           ", 21);
        break;
        case HADES_MOVE_BLOCK:
            memcpy(d1, "BY PRESSING THE IN  ", 21);
            memcpy(d2, "TERACT BUTTON YOU   ", 21);
            memcpy(d3, "ARE ABLE TO PUSH    ", 21);
            memcpy(d4, "HEAVY BLOCKS.       ", 21);
            //memcpy(d5, "TO OPEN GATES AS THE", 21);
            memcpy(d6, "TO OPEN GATES AS THE", 21);
            memcpy(d7, "EXIT OF THIS ROOM   ", 21);
            memcpy(d8, "THE BUTTON MUST BE  ", 21);
            memcpy(d9, "PUSHED TO THE FLOOR ", 21);
            memcpy(d10, "BY MOVING AN HEAVY  ", 21);
            memcpy(d11, "BLOCK OVER IT.      ", 21);
        break;
        case HADES_USE_KEY:
            memcpy(d1, "YOU WILL FIND OLD ", 21);
            memcpy(d2, "LOCKED DOORS ON   ", 21);
            memcpy(d3, "YOUR PATH.        ", 21);
            memcpy(d5, "THOSE CAN BE      ", 21);
            memcpy(d6, "UNLOCKED WITH A   ", 21);
            memcpy(d7, "KEY.              ", 21);
            //memcpy(d5, "TO OPEN GATES AS THE", 21);
            memcpy(d8, "GRAB IT AND INTER-", 21);
            memcpy(d9, "ACT WITH THE DOOR ", 21);
            memcpy(d10, "TO USE IT.       ", 21);
        break;
        case HADES_KILL_ENEMY:
            memcpy(d1, "SOME GATES OPEN IF", 21);
            memcpy(d2, "AND ONLY IF THERE ", 21);
            memcpy(d3, "ARE NO HADES CREA,", 21);
            memcpy(d4, "TURES AROUND.     ", 21);
            //memcpy(d5, "TO OPEN GATES AS THE", 21);
            memcpy(d6, "USE THE FATUOUS   ", 21);
            memcpy(d7, "FIRE AT YOUR ADVAN", 21);
            memcpy(d8, "TAGE.             ", 21);
        break;
        case HADES_DEATH:
            memcpy(d0, "HADES DEATH!      ", 21);
            memcpy(d1, "                  ", 21);
            memcpy(d2, "YOU DIE!          ", 21);
            memcpy(d3, "                  ", 21);
            memcpy(d4, "TURES AROUND.     ", 21);
            memcpy(d5, "??????????????????", 21);
            memcpy(d6, "USE THE FATUOUS   ", 21);
            memcpy(d7, "FIRE AT YOUR ADVAN", 21);
            memcpy(d8, "TAGE.             ", 21);
            memcpy(d9, "TAGE.             ", 21);
            memcpy(d10, "TAGE.             ", 21);
            memcpy(d11, "TAGE.             ", 21);
            memcpy(d12, "TAGE.             ", 21);
        break;
        case BOSS_CHARON_INTRO:
            memcpy(d0, "CHARON:           ", 21);
            memcpy(d1, "YOUR LYRE CAN CON,", 21);
            memcpy(d2, "TROL HIS BOAT FOR ", 21);
            memcpy(d3, "A LIMITED PERIOD  ", 21);
            memcpy(d4, "OF TIME. PUSH HIM ", 21);
            memcpy(d5, "AGAINST THOSE     ", 21);
            memcpy(d6, "STONES!           ", 21);
            memcpy(d7, "                  ", 21);
            memcpy(d8, "WHEN HIS HANDS    ", 21);
            memcpy(d9, "MOVE IN CIRCLES   ", 21);
            memcpy(d10, "THE BOAT GETS    ", 21);
            memcpy(d11, "UNDER HIS FULL   ", 21);
            memcpy(d12, "CONTROL.         ", 21);
        break;
        case BOSS_CHARON_BEATED:
            memcpy(d0, "CHARON:           ", 21);
            memcpy(d1, "YOU BEATED ME     ", 21);
            memcpy(d2, "                  ", 21);
            memcpy(d3, "                  ", 21);
            memcpy(d4, "                  ", 21);
            memcpy(d5, "                  ", 21);
            memcpy(d6, "                  ", 21);
            memcpy(d7, "                  ", 21);
            memcpy(d8, "                  ", 21);
            memcpy(d9, "                  ", 21);
            memcpy(d10, "                  ", 21);
            memcpy(d11, "                  ", 21);
            memcpy(d12, "                  ", 21);
        break;
        case BOSS_CERBERUS_INTRO:
            memcpy(d0, "CERBERUS:         ", 21);
            memcpy(d1, "                  ", 21);
            memcpy(d2, "                  ", 21);
            memcpy(d3, "                  ", 21);
            memcpy(d4, "OF TIME. PUSH HIM ", 21);
            memcpy(d5, "AGAINST THOSE     ", 21);
            memcpy(d6, "STONES!           ", 21);
            memcpy(d7, "                  ", 21);
            memcpy(d8, "WHEN HIS HANDS    ", 21);
            memcpy(d9, "MOVE IN CIRCLES   ", 21);
            memcpy(d10, "THE BOAT GETS    ", 21);
            memcpy(d11, "UNDER HIS FULL   ", 21);
            memcpy(d12, "CONTROL.         ", 21);
        break;
        case BOSS_CERBERUS_BEATED:
            memcpy(d0, "CERBERUS:         ", 21);
            memcpy(d1, "YOU BEATED ME     ", 21);
            memcpy(d2, "                  ", 21);
            memcpy(d3, "                  ", 21);
            memcpy(d4, "                  ", 21);
            memcpy(d5, "                  ", 21);
            memcpy(d6, "                  ", 21);
            memcpy(d7, "                  ", 21);
            memcpy(d8, "                  ", 21);
            memcpy(d9, "                  ", 21);
            memcpy(d10, "                  ", 21);
            memcpy(d11, "                  ", 21);
            memcpy(d12, "                  ", 21);
        break;
        case BOSS_MINOS_INTRO:
            memcpy(d0, "MINOS:            ", 21);
            memcpy(d1, "                  ", 21);
            memcpy(d2, "                  ", 21);
            memcpy(d3, "                  ", 21);
            memcpy(d4, "OF TIME. PUSH HIM ", 21);
            memcpy(d5, "AGAINST THOSE     ", 21);
            memcpy(d6, "STONES!           ", 21);
            memcpy(d7, "                  ", 21);
            memcpy(d8, "WHEN HIS HANDS    ", 21);
            memcpy(d9, "MOVE IN CIRCLES   ", 21);
            memcpy(d10, "THE BOAT GETS    ", 21);
            memcpy(d11, "UNDER HIS FULL   ", 21);
            memcpy(d12, "CONTROL.         ", 21);
        break;
        case BOSS_MINOS_BEATED:
            memcpy(d0, "MINOS:            ", 21);
            memcpy(d1, "YOU BEATED ME     ", 21);
            memcpy(d2, "                  ", 21);
            memcpy(d3, "                  ", 21);
            memcpy(d4, "                  ", 21);
            memcpy(d5, "                  ", 21);
            memcpy(d6, "                  ", 21);
            memcpy(d7, "                  ", 21);
            memcpy(d8, "                  ", 21);
            memcpy(d9, "                  ", 21);
            memcpy(d10, "                  ", 21);
            memcpy(d11, "                  ", 21);
            memcpy(d12, "                  ", 21);
        break;
    }
    return 0u;
}

unsigned char get_char(UINT8 arg_writing_line, UINT8 arg_counter_char) BANKED{
    unsigned char result = 0;
    switch(arg_writing_line){
        case 1u:result = d1[arg_counter_char];break;
        case 2u:result = d2[arg_counter_char];break;
        case 3u:result = d3[arg_counter_char];break;
        case 4u:result = d4[arg_counter_char];break;
        case 5u:result = d5[arg_counter_char];break;
        case 6u:result = d6[arg_counter_char];break;
        case 7u:result = d7[arg_counter_char];break;
        case 8u:result = d8[arg_counter_char];break;
        case 9u:result = d9[arg_counter_char];break;
        case 10u:result = d10[arg_counter_char];break;
        case 11u:result = d11[arg_counter_char];break;
        case 12u:result = d12[arg_counter_char];break;
        case 13u:result = d13[arg_counter_char];break;
        case 14u:result = d14[arg_counter_char];break;
        case 15u:result = d15[arg_counter_char];break;
        case 16u:result = d16[arg_counter_char];break;
        case 17u:result = d17[arg_counter_char];break;
        case 18u:result = d18[arg_counter_char];break;
        case 19u:result = d19[arg_counter_char];break;
        case 20u:result = d20[arg_counter_char];break;
        case 21u:result = d21[arg_counter_char];break;
        case 22u:result = d22[arg_counter_char];break;
    }
    return result;
}
