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

UINT8 prepare_dialog_en(WHOSTALKING arg_whostalking) BANKED;
unsigned char get_char(UINT8 arg_writing_line, UINT8 arg_counter_char) BANKED;


UINT8 prepare_dialog_en(WHOSTALKING arg_whostalking) BANKED{
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
            memcpy(d3, "SONGS TO ATTRACT,   ", 21);
            memcpy(d4, "SCARE OR REPEL MY   ", 21);
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
        case HADES_ENTRANCE:
            memcpy(d1, "HERE I AM... THE    ", 21);
            memcpy(d2, "GATES OF HADES!     ", 21);
            memcpy(d3, "I WILL SAVE YOU,    ", 21);
            memcpy(d4, "EURYDICE! NO MATTER ", 21);
            memcpy(d5, "HOW MANY CHALLENGES ", 21);
            memcpy(d6, "MAY I FACE!         ", 21);
            return 6u;
        break;
        case HADES_WELCOME:
            memcpy(d0, "WELCOME, MY SON. I", 21);
            memcpy(d1, "TALK TO YOU WITH  ", 21);
            memcpy(d2, "THESE WRITINGS.   ", 21);
            memcpy(d3, "                  ", 21);
            memcpy(d4, "EACH ROOM HAS A   ", 21);
            memcpy(d5, "PUZZLE. SOLVE IT  ", 21);
            memcpy(d6, "TO OPEN THE EXIT  ", 21);
            memcpy(d7, "DOOR.             ", 21);
            memcpy(d8, "BE WISE, AND YOU  ", 21);
            memcpy(d9, "WILL BRING BACK   ", 21);
            memcpy(d10, "YOUR BELOVED.     ", 21);
        break;
        case HADES_MOVE_BLOCK:
            memcpy(d0, "SOME PATHS ARE    ", 21);
            memcpy(d1, "BLOCKED BY STONES ", 21);
            memcpy(d2, "BUT YOU CAN MOVE  ", 21);
            memcpy(d3, "THEM. PUSH A      ", 21);
            memcpy(d4, "STONE ONTO THE    ", 21);
            memcpy(d5, "BUTTON THE GROUND ", 21);
            memcpy(d6, "TO OPEN THE GATE. ", 21);
            memcpy(d7, "                  ", 21);
            memcpy(d8, "                  ", 21);
            memcpy(d9, "                  ", 21);
            memcpy(d10, "                  ", 21);
        break;
        case HADES_USE_KEY:
            memcpy(d0, "YOU WILL FIND OLD ", 21);
            memcpy(d1, "LOCKED DOORS ON   ", 21);
            memcpy(d2, "YOUR PATH.        ", 21);
            memcpy(d3, "THOSE CAN BE      ", 21);
            memcpy(d4, "UNLOCKED WITH A   ", 21);
            memcpy(d5, "KEY. SO GRAB IT   ", 21);
            memcpy(d6, "AND INTERACT      ", 21);
            memcpy(d7, "WITH THE DOOR     ", 21);
            memcpy(d8, "TO USE IT IN THE  ", 21);
            memcpy(d9, "SAME WAY YOU CHAN ", 21);
            memcpy(d10, "GE SONGS.         ", 21);
        break;
        case HADES_KILL_ENEMY:
            memcpy(d0, "SOME GATES OPEN   ", 21);
            memcpy(d1, "IF AND ONLY IF    ", 21);
            memcpy(d2, "THERE ARE NO      ", 21);
            memcpy(d3, "HADES CREATURES   ", 21);
            memcpy(d4, "LEFT AROUND.      ", 21);
            memcpy(d5, "USE THE FATUOUS   ", 21);
            memcpy(d6, "FIRE AT YOUR ADVAN", 21);
            memcpy(d7, "TAGE. BUT BE CARE(", 21);
            memcpy(d8, "FUL BECAUSE NOT   ", 21);
            memcpy(d9, "ALL CREATURES GET ", 21);
            memcpy(d10, "HARMED BY FIRE.  ", 21);
        break;
        case HADES_GUARDS:
            memcpy(d0, "LISTEN CLOSELY,   ", 21);
            memcpy(d1, "MY SON.           ", 21);
            memcpy(d2, "GUARDS IN THIS    ", 21);
            memcpy(d3, "REALM ARE DEAF.   ", 21);
            memcpy(d4, "THEY SCAN THE ROOM", 21);
            memcpy(d5, "WATCHING AROUND.  ", 21);
            memcpy(d6, "NOTICE WHERE THEY ", 21);
            memcpy(d7, "LOOK AT BECAUSE IF", 21);
            memcpy(d8, "THEY SEE SOMETHING", 21);
            memcpy(d9, "WRONG THEY WILL RUN", 21);
            memcpy(d10, "AT IT.             ", 21);
        break;
        case HADES_ROLLING_STONES:
            memcpy(d0, "HADES IS FULL OF  ", 21);
            memcpy(d1, "DEADLY TRAPS. ONE ", 21);
            memcpy(d2, "OF THEM ARE THE   ", 21);
            memcpy(d3, "ROLLING STONES.   ", 21);
            memcpy(d4, "THEY START ROLLING", 21);
            memcpy(d5, "DOWN AS SOON AS A ", 21);
            memcpy(d6, "BUTTON ON THE     ", 21);
            memcpy(d7, "GROUND IS PRESSED.", 21);
            memcpy(d8, "THE HARD STONES   ", 21);
            memcpy(d9, "HARM EVERYTHING ON", 21);
            memcpy(d10, "ITS PATH.         ", 21);
        break;
        case HADES_OWL_SAVING:
            memcpy(d0, "HAWK! THE OWL IS  ", 21);
            memcpy(d1, "CERBERUS PRISONER.", 21);
            memcpy(d2, "ONLY A STRONG SOUL", 21);
            memcpy(d3, "MOVES THE BLOCK.  ", 21);
            memcpy(d4, "FREEING THE BIRD  ", 21);
            memcpy(d5, "AWAKENS ITS GUARD.", 21);
            memcpy(d6, "PREPARE TO FACE   ", 21);
            memcpy(d7, "THE TRIPLE HEADED ", 21);
            memcpy(d8, "GUARDIAN  NEXT!   ", 21);
            memcpy(d9, "                  ", 21);
            memcpy(d10, "                  ", 21);
        break;
        case HADES_GUARDS_AWAKENED:
            memcpy(d0, "                  ", 21);
            memcpy(d1, "                  ", 21);
            memcpy(d2, "GUARDS HAVE BEEN  ", 21);
            memcpy(d3, "ALERTED!          ", 21);
            memcpy(d4, "                  ", 21);
            memcpy(d5, "THERE ARE         ", 21);
            memcpy(d6, "SKELETONS ALL     ", 21);
            memcpy(d7, "AROUND YOU!!      ", 21);
            memcpy(d8, "                  ", 21);
            memcpy(d9, "                  ", 21);
            memcpy(d10, "                  ", 21);
        break;
        case HADES_DEATH:
            memcpy(d0, "SON O MINE YOUR   ", 21);
            memcpy(d1, "JOURNEY IS NOT    ", 21);
            memcpy(d2, "OVER. YOU VE FAL( ", 21);
            memcpy(d3, "LEN BUT YOUR MUSIC", 21);
            memcpy(d4, "WILL RISE AGAIN.  ", 21);
            memcpy(d5, "BACK TO THE BEGIN(", 21);
            memcpy(d6, "NING OF THIS REALM", 21);
            memcpy(d7, "YOUR STRENGTH WILL", 21);
            memcpy(d8, "BE RESTORED.      ", 21);
            memcpy(d9, "                   ", 21);
            memcpy(d10, "EURIDYCE IS WAITING", 21);
        break;
        case BOSS_CHARON_INTRO:
            memcpy(d0, "THIS IS CHARON:   ", 21);
            memcpy(d1, "YOUR LYRE CAN CON,", 21);
            memcpy(d2, "TROL HIS BOAT FOR ", 21);
            memcpy(d3, "A LIMITED PERIOD  ", 21);
            memcpy(d4, "OF TIME. PUSH HIM ", 21);
            memcpy(d5, "AGAINST THOSE     ", 21);
            memcpy(d6, "STONES!           ", 21);
            memcpy(d7, "WHEN HIS HANDS    ", 21);
            memcpy(d8, "MOVE IN CIRCLES   ", 21);
            memcpy(d9, "THE BOAT GETS     ", 21);
            memcpy(d10, "UNDER HIS CONTROL", 21);
        break;
        case BOSS_CHARON_BEATED:
            memcpy(d0, "YOU HAVE THAT     ", 21);
            memcpy(d1, "STRENGTH!         ", 21);
            memcpy(d2, "MY BOAT HAS BEEN  ", 21);
            memcpy(d3, "BROKEN. MY DUTY   ", 21);
            memcpy(d4, "HERE IS DONE.     ", 21);
            memcpy(d5, "GO ON.  THE GATES ", 21);
            memcpy(d6, "TO THE LAND OF    ", 21);
            memcpy(d7, "DEATH ARE         ", 21);
            memcpy(d8, " OPENING NOW.     ", 21);
            memcpy(d9, "                  ", 21);
            memcpy(d10, "                  ", 21);
        break;
        case BOSS_CERBERUS_INTRO:
            memcpy(d0, "DREAD HERALDS YOUR", 21);
            memcpy(d1, "ARRIVAL AT THE    ", 21);
            memcpy(d2, "ACHERON. CERBERUS,", 21);
            memcpy(d3, "THE THREE-HEADED  ", 21);
            memcpy(d4, "HOUND, HUNGERS.   ", 21);
            memcpy(d5, "ITS EYES BURN WITH", 21);
            memcpy(d6, "FIRE!             ", 21);
            memcpy(d7, "SKELETAL MINIONS  ", 21);
            memcpy(d8, "MUST BE PUSHED IN ", 21);
            memcpy(d9, "THE RIVER FOR THE", 21);
            memcpy(d10, "BEAST TO FEAST!  ", 21);
        break;
        case BOSS_CERBERUS_BEATED:
            memcpy(d0, "YOU DEFEATED THE  ", 21);
            memcpy(d1, "THE GIANT CERBERUS", 21);
            memcpy(d2, "USING FIVE SKELE  ", 21);
            memcpy(d3, "TONS! YOUR BELOVED", 21);
            memcpy(d4, "EURYDICE WAITS    ", 21);
            memcpy(d5, "BEYOND THE STONY  ", 21);
            memcpy(d6, "PHLEGETHON.ADVANCE", 21);
            memcpy(d7, "NOW TO THE LAND OF", 21);
            memcpy(d8, "THE DEAD.         ", 21);
            memcpy(d9, "                  ", 21);
            memcpy(d10, "                  ", 21);
        break;
        case BOSS_MINOS_INTRO:
            memcpy(d0, "YOU STAND BEFORE  ", 21);
            memcpy(d1, "MINOS THE JUDGE!  ", 21);
            memcpy(d2, "GRASP THE SCALE,  ", 21);
            memcpy(d3, "FOR YOUR LIVING   ", 21);
            memcpy(d4, "WEIGHT MUST FALL  ", 21);
            memcpy(d5, "AGAINST THE IMP!  ", 21);
            memcpy(d6, "HIS JUDGMENT      ", 21);
            memcpy(d7, "SHATTERS; THE     ", 21);
            memcpy(d8, "CREATURE STRIKES  ", 21);
            memcpy(d9, "HIM! STRIKE THE   ", 21);
            memcpy(d10, "FALLEN JUDGE NOW! ", 21);
        break;
        case BOSS_MINOS_BEATED:
            memcpy(d0, "YOUR HEART'S TRUTH", 21);
            memcpy(d1, "CONQUERS MINOS!   ", 21);
            memcpy(d2, "NOW, THE TEARFUL  ", 21);
            memcpy(d3, "COCYTUS SEEKS TO  ", 21);
            memcpy(d4, "PUSH YOU BACK! IT ", 21);
            memcpy(d5, "WON'T BE EASY,    ", 21);
            memcpy(d6, "SON. TRUST YOUR   ", 21);
            memcpy(d7, "LYRE AND YOUR     ", 21);
            memcpy(d8, "AGILITY! BLAZE A  ", 21);
            memcpy(d9, " PATH TO THE END! ", 21);
            memcpy(d10, "                  ", 21);
        break;
        case BOSS_AEACUS_INTRO:
            memcpy(d0, "AT THE COCYTUS'S  ", 21);
            memcpy(d1, "END, AEACUS AWAITS", 21);
            memcpy(d2, "BUT HE IS DEAF SO ", 21);
            memcpy(d3, "YOUR SWEET LYRE   ", 21);
            memcpy(d4, "WILL FAIL! EXPLOIT", 21);
            memcpy(d5, " HIS SILENCE! USE ", 21);
            memcpy(d6, "THE HIDDEN TRAPS! ", 21);
            memcpy(d7, "STRIKE HIM WITH   ", 21);
            memcpy(d8, "THE ENVIRONMENT   ", 21);
            memcpy(d9, "UNTIL HE FALLS!   ", 21);
            memcpy(d10, "                  ", 21);
        break;
        case BOSS_AEACUS_BEATED:
            memcpy(d0, "AEACUS FALLS! YOU ", 21);
            memcpy(d1, "ARE AT THE LETHAL ", 21);
            memcpy(d2, "LETHE! HERE, HADES", 21);
            memcpy(d3, "HIMSELF DWELLS!   ", 21);
            memcpy(d4, "THE FIERCEST FOES ", 21);
            memcpy(d5, "GATHER, AND HIS   ", 21);
            memcpy(d6, "GUARDIAN FRIEND   ", 21);
            memcpy(d7, "AWAITS! MOVE ON,  ", 21);
            memcpy(d8, "SON, DEFEAT THEM  ", 21);
            memcpy(d9, "ALL! FOR EURYDICE!", 21);
            memcpy(d10, "                  ", 21);
        break;
        case BOSS_HADES_INTRO:
            memcpy(d0, "RHADAMANTHUS      ", 21);
            memcpy(d1, "FALLS! HADES'     ", 21);
            memcpy(d2, "CHAMBER IS FILLED ", 21);
            memcpy(d3, "WITH FATAL FLAMES ", 21);
            memcpy(d4, "DODGE THEM!       ", 21);
            memcpy(d5, "YOUR TRUE SONG    ", 21);
            memcpy(d6, "BREAKS HIS WILL!  ", 21);
            memcpy(d7, "USE YOUR LYRE     ", 21);
            memcpy(d8, "TO CHALLENGE      ", 21);
            memcpy(d9, "HIM! RECLAIM      ", 21);
            memcpy(d10, "EURYDICE NOW!     ", 21);
        break;
        case BOSS_HADES_BEATED:
            memcpy(d0, "HADES IS DEFEATED!", 21);
            memcpy(d1, "THE PATH IS OPEN, ", 21);
            memcpy(d2, "BUT HEAR THIS:    ", 21);
            memcpy(d3, "YOU MUST NOT TURN ", 21);
            memcpy(d4, "OR SPEAK UNTIL THE", 21);
            memcpy(d5, "SUN'S LIGHT! BREAK", 21);
            memcpy(d6, "THIS RULE, AND    ", 21);
            memcpy(d7, "SHE IS LOST       ", 21);
            memcpy(d8, "FOREVER.          ", 21);
            memcpy(d9, "ORPHEUS, PROCEED! ", 21);
            memcpy(d10, "EURIDYCE, FOLLOW!", 21);
        break;
        case END_ORPHEUS_FOLLOW:
            memcpy(d1, "THE GATES OF HADES  ", 21);
            memcpy(d2, "ARE NOT FAR...      ", 21);
            memcpy(d3, "STAY BEHIND ME MY   ", 21);
            memcpy(d4, "BELOVED. WE ARE JUST", 21);
            memcpy(d5, "A FEW STEPS AWAY    ", 21);
            memcpy(d6, "FROM OUR FREEDOM.   ", 21);
            memcpy(d7, "AS LONG AS I HEAR   ", 21);
            memcpy(d8, "YOUR STEPS BEHIND ME", 21);
            memcpy(d9, "I WILL BE CALM.     ", 21);
            return 9u;
        break;
        case END_ORPHEUS_EURIDYCE:
            memcpy(d1, "                    ", 21);
            memcpy(d2, "     EURIDYCE!      ", 21);
            memcpy(d3, "                    ", 21);
            return 3u;
        break;
        case END_EURIDYCE_NOOO:
            memcpy(d1, "                    ", 21);
            memcpy(d2, "     NNOOOOOO!      ", 21);
            memcpy(d3, "                    ", 21);
            return 3u;
        break;
        case END_EURIDYCE_BOX:
            memcpy(d1, "WHAT IS THIS? A BOX?", 21);
            memcpy(d2, "CAN IT BE... THE    ", 21);
            memcpy(d3, "PANDORA'S BOX?      ", 21);
            memcpy(d4, "I COULD USE IT TO   ", 21);
            memcpy(d5, "GET MY WAY BACK. NOW", 21);
            memcpy(d6, "IT IS TIME FOR ME TO", 21);
            memcpy(d7, "GET YOU MY BELOVED. ", 21);
            memcpy(d8, "ORPHEUS....         ", 21);
            memcpy(d9, "WHERE ARE YOU?      ", 21);
            return 9u;
        break;
        case ENDSCREEN_SEEYOUIN2027:
            memcpy(d1, "  CONGRATULATIONS!  ", 21);
            memcpy(d2, "                    ", 21);
            memcpy(d3, "THANK U FOR PLAYING!", 21);
            return 3u;
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
