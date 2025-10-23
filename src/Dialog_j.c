#include "Banks/SetAutoBank.h"

#include "BankManager.h"
#include "ZGBMain.h"
#include "string.h"

#include "Dialog.h"

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
extern unsigned char d11[];
extern unsigned char d12[];
extern unsigned char d13[];
extern unsigned char d14[];
extern unsigned char d15[];
extern unsigned char d16[];
extern unsigned char d17[];
extern unsigned char d18[];
extern unsigned char d19[];
extern unsigned char d20[];
extern unsigned char d21[];
extern unsigned char d22[];
extern unsigned char d23[];


UINT8 prepare_dialog_jp(WHOSTALKING arg_whostalking) BANKED;

UINT8 prepare_dialog_jp(WHOSTALKING arg_whostalking) BANKED{
    switch(arg_whostalking){
        // Dialog Case: FIRSTEVER
        case FIRSTEVER:
            memcpy(d1, "8B1 Y 8 Y         ", 21);
            memcpy(d2, "Z TE H UB         ", 21);
            memcpy(d3, "4M PS]T - 5RI     ", 21);
            memcpy(d4, "UI. Z ZZ F)E2     ", 21);
            memcpy(d5, "F JY AP) V EB     ", 21);
            memcpy(d6, "S BRP T E8 C      ", 21);
            memcpy(d7, "BJC               ", 21);
            memcpy(d8, "                  ", 21);
            memcpy(d9, "                  ", 21);
            return 9u;
        break;

// Dialog Case: MISSING_LYRE
        case MISSING_LYRE:
            memcpy(d1, "       MM 7 UB      ", 21);
            memcpy(d2, "      4M PS]T -     ", 21);
            memcpy(d3, "      5RI UI. Z     ", 21);
            return 3u;
        break;

// Dialog Case: FOUND_LYRE
        case FOUND_LYRE:
            memcpy(d1, "      MJB PS]T S    ", 21);
            memcpy(d2, "     SG - 0GR IP)   ", 21);
            memcpy(d3, "      E0D KKP)G     ", 21);
            memcpy(d4, "      EBZ(RP) M     ", 21);
            memcpy(d5, "     , K4K4 U CP    ", 21);
            memcpy(d6, "      - FUS(. ,     ", 21);
            return 6u;
        break;

// Dialog Case: PUSH_BUTTON
        case PUSH_BUTTON:
            memcpy(d1, "     AY 3PW Y CD    ", 21);
            memcpy(d2, "     V PR JT S 8    ", 21);
            memcpy(d3, "      Y - AI(. ,    ", 21);
            return 3u;
        break;

// Dialog Case: PRESS_INTERACT
        case PRESS_INTERACT:
            memcpy(d1, "    1.M Y BWP(HT    ", 21);
            memcpy(d2, "   3PW - EL S PS]T  ", 21);
            memcpy(d3, "     - S V B. :     ", 21);
            return 3u;
        break;

    // Dialog Case: HADES_ENTRANCE
        case HADES_ENTRANCE:
            memcpy(d1, " GP O 8B1 Y 8       ", 21);
            memcpy(d2, " Y P DC)!SBN G5 -   ", 21);
            memcpy(d3, " MHB PM TW U        ", 21);
            memcpy(d4, " L.W V Q'H 7W       ", 21);
            memcpy(d5, " L'C T 8            ", 21);
            memcpy(d6, "                  ", 21);
            return 6u;
        break;

// Dialog Case: HADES_WELCOME
        case HADES_WELCOME:
            memcpy(d0, "'CJO ?F 6MJ ' J.( ", 21);
            memcpy(d1, "Y 8L S FP) FI ,   ", 21);
            memcpy(d2, "O.O. Y 29 V Z ZM ,", 21);
            memcpy(d3, "F A , O. - TB S   ", 21);
            memcpy(d4, "SHQ Y T0( - AI ,  ", 21);
            memcpy(d5, "YP FLJH A . KM.   ", 21);
            memcpy(d6, "Z KBAB Y 8 Y      ", 21);
            memcpy(d7, "- T) 8TN ,        ", 21);
            memcpy(d8, "P: C              ", 21);
            memcpy(d9, "                  ", 21);
            memcpy(d10, "                  ", 21);
        break;

// Dialog Case: HADES_MOVE_BLOCK
        case HADES_MOVE_BLOCK:
            memcpy(d0, "BHR F Y 5Q Z      ", 21);
            memcpy(d1, "BL S 1KF .        ", 21);
            memcpy(d2, "S B , F           ", 21);
            memcpy(d3, "CJF M JT F SG ,   ", 21);
            memcpy(d4, "BL - !F Y 3PW Y   ", 21);
            memcpy(d5, "CD V EL S         ", 21);
            memcpy(d6, "8 Y - AI :        ", 21);
            memcpy(d7, "                  ", 21);
            memcpy(d8, "                  ", 21);
            memcpy(d9, "                  ", 21);
            memcpy(d10, "                  ", 21);
            break;

// Dialog Case: HADES_USE_KEY
        case HADES_USE_KEY:
            memcpy(d0, "TCQ!C             ", 21);
            memcpy(d1, "1,B FG Y FFRP     ", 21);
            memcpy(d2, "T0( - 5RI , P: C  ", 21);
            memcpy(d3, "AI (. ,           ", 21);
            memcpy(d4, "FG - S V B.       ", 21);
            memcpy(d5, "CP - FD, Y T EU L ", 21);
            memcpy(d6, "3C3C S T0( V      ", 21);
            memcpy(d7, "BWP(HT LS RF C YP ", 21);
            memcpy(d8, "                  ", 21);
            memcpy(d9, "                  ", 21);
            memcpy(d10, "                  ", 21);
            break;

// Dialog Case: HADES_KILL_ENEMY
        case HADES_KILL_ENEMY:
            memcpy(d0, "BHR F Y 8 Y Z     ", 21);
            memcpy(d1, "L!C B V 8B1 Y     ", 21);
            memcpy(d2, "NB1R F YJR S B    ", 21);
            memcpy(d3, "UB ZA B V Y5 AH   ", 21);
            memcpy(d4, "1ATCAM 1ABA -     ", 21);
            memcpy(d5, "!C) V )'C N'      ", 21);
            memcpy(d6, "LFL M2S Y         ", 21);
            memcpy(d7, "NB1R F 3YE S      ", 21);
            memcpy(d8, "GM RH ?I S Z UB   ", 21);
            memcpy(d9, "YS Q!C B N'       ", 21);
            memcpy(d10, "                  ", 21);
        break;

// Dialog Case: HADES_GUARDS
        case HADES_GUARDS:
            memcpy(d0, "'H GI ?F 6MJ '    ", 21);
            memcpy(d1, "JY )'C B G Y ZW   ", 21);
            memcpy(d2, "VW Z 55 F GJD     ", 21);
            memcpy(d3, "UB F.( Z 29 -     ", 21);
            memcpy(d4, "MG9W L L!C B -    ", 21);
            memcpy(d5, "FW L LS B , F.(   ", 21);
            memcpy(d6, "F TJ - 5S B ,     ", 21);
            memcpy(d7, "F V Q!C B N' UN   ", 21);
            memcpy(d8, "U( UVF BOC - 5.   ", 21);
            memcpy(d9, "Z OJ 2 ZL R S H   ", 21);
            memcpy(d10, ", P: C F(         ", 21);
        break;

// Dialog Case: HADES_ROLLING_STONES
        case HADES_ROLLING_STONES:
            memcpy(d0, "8B1 Z Q7BSG U ?U S", 21);
            memcpy(d1, "BRZB P            ", 21);
            memcpy(d2, "OY 0T R F :C)WH   ", 21);
            memcpy(d3, "MTCW P            ", 21);
            memcpy(d4, "!F Y 3PW F EK . , ", 21);
            memcpy(d5, "T MH V J:F)       ", 21);
            memcpy(d6, "ZL 7 , FPB BL Z   ", 21);
            memcpy(d7, "OY IB:OC Y M2S -  ", 21);
            memcpy(d8, "GM RI ,           ", 21);
            memcpy(d9, "                  ", 21);
            memcpy(d10, "                  ", 21);
        break;

// Dialog Case: HADES_OWL_SAVING
        case HADES_OWL_SAVING:
            memcpy(d0, "3CH               ", 21);
            memcpy(d1, "1H:C Z I,2:M Y    ", 21);
            memcpy(d2, "R'B P4LB PI F     ", 21);
            memcpy(d3, "1:RH - CJF N ,    ", 21);
            memcpy(d4, "T) - FB3C M , T   ", 21);
            memcpy(d5, "ZW VW F 7K 7 ,    ", 21);
            memcpy(d6, "R G V 5R H0 Y     ", 21);
            memcpy(d7, "ZW VW V PQ 6F C   ", 21);
            memcpy(d8, "L!W 0 - N'        ", 21);
            memcpy(d9, "                  ", 21);
            memcpy(d10, "                  ", 21);
            break;

// Dialog Case: HADES_GUARDS_AWAKENED
        case HADES_GUARDS_AWAKENED:
            memcpy(d0, "                  ", 21);
            memcpy(d1, "                  ", 21);
            memcpy(d2, "                  ", 21);
            memcpy(d3, "                  ", 21);
            memcpy(d4, "ZW VW F IBFB LP   ", 21);
            memcpy(d5, "G5 Y 4?) V Z      ", 21);
            memcpy(d6, "MI, T W PI P      ", 21);
            memcpy(d7, "                  ", 21);
            memcpy(d8, "                  ", 21);
            memcpy(d9, "                  ", 21);
            memcpy(d10, "                  ", 21);
            break;

// Dialog Case: HADES_DEATH
        case HADES_DEATH:
            memcpy(d0, "6MJ '             ", 21);
            memcpy(d1, "G5 Y P0 Z E?R S B ", 21);
            memcpy(d2, "UB PE. P F        ", 21);
            memcpy(d3, "G5 Y EW FH Z 1PP0 ", 21);
            memcpy(d4, "PQ AF , P: C      ", 21);
            memcpy(d5, "JY )'C B G Y ZL 4)", 21);
            memcpy(d6, "V 8T. Z           ", 21);
            memcpy(d7, "G5 Y QF( Z FB1H M ", 21);
            memcpy(d8, ", P: C            ", 21);
            memcpy(d9, "DC)!SBN F 4R S B ,", 21);
            memcpy(d10, "                  ", 21);
        break;

// Dialog Case: BOSS_CHARON_INTRO
        case BOSS_CHARON_INTRO:
            memcpy(d0, "F:W P             ", 21);
            memcpy(d1, "G5 Y PS]T Z FG    ", 21);
            memcpy(d2, "(. P LFW PI       ", 21);
            memcpy(d3, "F. Y 1X - OCK SG ,", 21);
            memcpy(d4, "F. - AY BL V EL   ", 21);
            memcpy(d5, "RI : F. Y S F DW  ", 21);
            memcpy(d6, "- DFB S           ", 21);
            memcpy(d7, "CJ H T 1X Z       ", 21);
            memcpy(d8, "F. Y NBJ F V 8T , ", 21);
            memcpy(d9, "                  ", 21);
            memcpy(d10, "                  ", 21);
        break;

// Dialog Case: BOSS_CHARON_BEATED
        case BOSS_CHARON_BEATED:
            memcpy(d0, "G5 V Z OY QF(     ", 21);
            memcpy(d1, "F A ,             ", 21);
            memcpy(d2, "?PL Y 1X Z J?.    ", 21);
            memcpy(d3, "P JJ S Y ?PL Y    ", 21);
            memcpy(d4, "9H7 Z E?R P       ", 21);
            memcpy(d5, "MM 7 L Y HV Y     ", 21);
            memcpy(d6, "8 Y F B4 AH       ", 21);
            memcpy(d7, "                  ", 21);
            memcpy(d8, "                  ", 21);
            memcpy(d9, "                  ", 21);
            memcpy(d10, "                  ", 21);
            break;

// Dialog Case: BOSS_CERBERUS_INTRO
        case BOSS_CERBERUS_INTRO:
            memcpy(d0, "G'C 1 F AI : W    ", 21);
            memcpy(d1, "F? 2 Y G5 Y       ", 21);
            memcpy(d2, "TCQ9H - RI , 5R   ", 21);
            memcpy(d3, "H0 Y )'C IW I,2:M ", 21);
            memcpy(d4, "Z CD S B ,        ", 21);
            memcpy(d5, "OY 7 Z 3YE S 8D   ", 21);
            memcpy(d6, "S B , OY I8Y F    ", 21);
            memcpy(d7, "G'C DW M , P7 V   ", 21);
            memcpy(d8, "MI, T W Y SLP - F?", 21);
            memcpy(d9, "V ELJ4 UI. Z U( UB", 21);
            memcpy(d10, "                  ", 21);
        break;

// Dialog Case: BOSS_CERBERUS_BEATED
        case BOSS_CERBERUS_BEATED:
            memcpy(d0, "G5 Z J PB Y MI,   ", 21);
            memcpy(d1, "T W - RFR S       ", 21);
            memcpy(d2, "G' PB U I,2:M     ", 21);
            memcpy(d3, "- PE LP G5 Y      ", 21);
            memcpy(d4, "KBAB Y DC)!SBN    ", 21);
            memcpy(d5, "Z BL P(I Y        ", 21);
            memcpy(d6, "1.ITW F? Y 6JC    ", 21);
            memcpy(d7, "S 4R S B , B4M    ", 21);
            memcpy(d8, "H LL9 Y HV 2 MM 7 ", 21);
            memcpy(d9, "                  ", 21);
            memcpy(d10, "                  ", 21);
            break;

// Dialog Case: BOSS_MINOS_INTRO
        case BOSS_MINOS_INTRO:
            memcpy(d0, "G5 Z KZG S 5YM Y  ", 21);
            memcpy(d1, "4D V PR S B , SW0W", 21);
            memcpy(d2, "- RF 7 G5 Y BGP E8", 21);
            memcpy(d3, "K F AH4 V PQ 6F   ", 21);
            memcpy(d4, "? UI. Z U( UB F.  ", 21);
            memcpy(d5, "Y KZG Z HPI Q,    ", 21);
            memcpy(d6, "FB1R F F. - CR    ", 21);
            memcpy(d7, "B4M H PE. P       ", 21);
            memcpy(d8, "KZG S - CS        ", 21);
            memcpy(d9, "                  ", 21);
            memcpy(d10, "                  ", 21);
        break;

// Dialog Case: BOSS_MINOS_BEATED
        case BOSS_MINOS_BEATED:
            memcpy(d0, "G5 Y JJ: Y LWLR F ", 21);
            memcpy(d1, "5YM - CQ 91,      ", 21);
            memcpy(d2, "B4 U5P Y JG!TM F  ", 21);
            memcpy(d3, "G5 - EL 8TOC T M ,", 21);
            memcpy(d4, "FWPW S Z UB O     ", 21);
            memcpy(d5, "6MJ '             ", 21);
            memcpy(d6, "G5 Y PS]T T 0WL'C ", 21);
            memcpy(d7, "K - LWL:          ", 21);
            memcpy(d8, "E?) 2 T RM H 5Q - ", 21);
            memcpy(d9, "G) 0( I           ", 21);
            memcpy(d10, "                  ", 21);
            break;

// Dialog Case: BOSS_AEACUS_INTRO
        case BOSS_AEACUS_INTRO:
            memcpy(d0, "JG!TM Y E?) V     ", 21);
            memcpy(d1, "A B A JM F 4R     ", 21);
            memcpy(d2, "S B , LFL F. Z    ", 21);
            memcpy(d3, "55 F GJD UB YS    ", 21);
            memcpy(d4, "G5 Y A4B PS]T Z   ", 21);
            memcpy(d5, "RC 'C L UB        ", 21);
            memcpy(d6, "F. Y NBKH - )'C N'", 21);
            memcpy(d7, "FHK . P ?U - RF D ", 21);
            memcpy(d8, "F. F PE . , 4S    ", 21);
            memcpy(d9, "FWG'C S F. - CS   ", 21);
            memcpy(d10, "                  ", 21);
            break;

// Dialog Case: BOSS_AEACUS_BEATED
        case BOSS_AEACUS_BEATED:
            memcpy(d0, "A B A JM F PE. P  ", 21);
            memcpy(d1, "G5 Z QL Y .S F?   ", 21);
            memcpy(d2, "V B , JJ V ZSM LLW", 21);
            memcpy(d3, "F MW S B , 8R T   ", 21);
            memcpy(d4, "8 TC 8C U SG F    ", 21);
            memcpy(d5, "AR4) F. Y L!JL9   ", 21);
            memcpy(d6, "Y T8 F 4R S B ,   ", 21);
            memcpy(d7, "MM 7 6MJ '        ", 21);
            memcpy(d8, "F.( M2S - PEN     ", 21);
            memcpy(d9, "DC)!SBN Y P7 V    ", 21);
            memcpy(d10, "                  ", 21);
            break;

// Dialog Case: BOSS_HADES_INTRO
        case BOSS_HADES_INTRO:
            memcpy(d0, "(P4WS!M F PE. P   ", 21);
            memcpy(d1, "ZSM Y 4 Z Q7BSG U ", 21);
            memcpy(d2, "3YE S 5PK . S B , ", 21);
            memcpy(d3, "'I :              ", 21);
            memcpy(d4, "G5 Y LW Y CP F    ", 21);
            memcpy(d5, "F. Y BL - HP H    ", 21);
            memcpy(d6, "PS]T - RFR S F.   ", 21);
            memcpy(d7, "V BT 7            ", 21);
            memcpy(d8, "B4M H DC)!SBN -   ", 21);
            memcpy(d9, "T) 8TN            ", 21);
            memcpy(d10, "                  ", 21);
        break;

// Dialog Case: BOSS_HADES_BEATED
        case BOSS_HADES_BEATED:
            memcpy(d0, "ZSM Z PEK . P     ", 21);
            memcpy(d1, "5Q Z 0(F . P F    ", 21);
            memcpy(d2, "J. - GI           ", 21);
            memcpy(d3, "PB'C Y 0F) - 5, 4S", 21);
            memcpy(d4, "1)6BP) ZULP) LS Z ", 21);
            memcpy(d5, "U( UB JY GOH      ", 21);
            memcpy(d6, "- 91. Z FYL' Z    ", 21);
            memcpy(d7, "DBDW V CLU?. ,    ", 21);
            memcpy(d8, "E,1DCM MM 7       ", 21);
            memcpy(d9, "DC)!SBN RM I      ", 21);
            memcpy(d10, "                  ", 21);
        break;

// Dialog Case: END_ORPHEUS_FOLLOW
        case END_ORPHEUS_FOLLOW:
            memcpy(d1, "  8B1 Y 8 Y Z TE    ", 21);
            memcpy(d2, "  H UB ?PL Y BTL B  ", 21);
            memcpy(d3, "  0T ' ?PL Y CL:    ", 21);
            memcpy(d4, "  V RBS G S         ", 21);
            memcpy(d5, "  ?.?. Z L!C 4S     ", 21);
            memcpy(d6, "  AT MC 3 P         ", 21);
            memcpy(d7, "  G5 Y AL ET F GJD  ", 21);
            memcpy(d8, "  , FG) ?PL Z EP9F  ", 21);
            memcpy(d9, "  S B(. , P: C      ", 21);
            return 9u;
        break;

// Dialog Case: END_ORPHEUS_EURIDYCE
        case END_ORPHEUS_EURIDYCE:
            memcpy(d1, "                    ", 21);
            memcpy(d2, "      DC)!SBN       ", 21);
            memcpy(d3, "                    ", 21);
            return 3u;
        break;

// Dialog Case: END_EURIDYCE_NOOO
        case END_EURIDYCE_NOOO:
            memcpy(d1, "                    ", 21);
            memcpy(d2, "       WYCCCCC      ", 21);
            memcpy(d3, "                    ", 21);
            return 3u;
        break;

// Dialog Case: END_EURIDYCE_BOX
        case END_EURIDYCE_BOX:
            memcpy(d1, "  J. Z U U D?       ", 21);
            memcpy(d2, "  Z J F? J. Z...    ", 21);
            memcpy(d3, "  P U Y ( Y Z J F?  ", 21);
            memcpy(d4, "  ?PKV Z O, -       ", 21);
            memcpy(d5, "  R K P S 8 T ,,.   ", 21);
            memcpy(d6, "  K A,' A P L Y     ", 21);
            memcpy(d7, "  B M ,, 0 P        ", 21);
            memcpy(d8, "  '. E ) 1 D M...   ", 21);
            memcpy(d9, "  T J V B), Y?      ", 21);
            return 9u;
        break;

// Dialog Case: ENDSCREEN_SEEYOUIN2027
        case ENDSCREEN_SEEYOUIN2027:
            memcpy(d1, "     E 7 S ' T!     ", 21);
            memcpy(d2, "                    ", 21);
            memcpy(d3, "  P ) B A ( G ' T!  ", 21);
            return 3u;
        break;
    }
    return 0u;
}