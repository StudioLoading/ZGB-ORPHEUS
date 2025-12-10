#include "Banks/SetAutoBank.h"

#include "BankManager.h"
#include "ZGBMain.h"
#include "string.h"

#include "UtilJP.h"

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
    Anim_JP(arg_whostalking);
    switch(arg_whostalking){
        case FIRSTEVER:
            memcpy(d1, "     KNF2DWRH     ", 21);
            memcpy(d2, "     IOMVA...     ", 21);
            memcpy(d3, "  LXF,S['YJ037ZHF.", 21);
            memcpy(d4, " HHD15689BFQDUE4P ", 21);
            memcpy(d5, "     DQCTAGHXF    ", 21);
            memcpy(d6, "    ...?U,AM(F!   ", 21);
            return 6u;
        break;
        case MISSING_LYRE:
            memcpy(d1, "   LEBCDQIHTBSVA.   ", 21);
            memcpy(d2, "   LXB F['G J03VAI! ", 21);
            memcpy(d3, "                    ", 21);
            return 3u;
        break;
        case FOUND_LYRE:
            memcpy(d1, "   D['F BCUNHC,     ", 21);
            memcpy(d2, "  QIVGKA:TC,TSJ     ", 21);
            memcpy(d3, "      LS37E4,       ", 21);
            memcpy(d4, "                    ", 21);
            memcpy(d5, " Q5BCZME4XGQIWTCSG. ", 21);
            memcpy(d6, "                    ", 21);
            return 6u;
        break;
        case PUSH_BUTTON:
            memcpy(d1, "       DF2QEZH,     ", 21);
            memcpy(d2, "    XSKW84PI0EA1.   ", 21);
            memcpy(d3, "                    ", 21);
            return 3u;
        break;
        case PRESS_INTERACT:
            memcpy(d1, "                    ", 21);
            memcpy(d2, "     B['CJTPANG     ", 21);
            memcpy(d3, "                    ", 21);
            return 3u;
        break;
        case HADES_ENTRANCE:
            memcpy(d1, "K['LJTPANG3AP3AEMC..", 21);
            memcpy(d2, "      OHC2DWR!      ", 21);
            memcpy(d3, "                    ", 21);
            memcpy(d4, "        SYHC0,      ", 21);
            memcpy(d5, "     BVZXCEX7T1G!   ", 21);
            memcpy(d6, "  ICRVQRVRBCU:FIW!  ", 21);
            return 6u;
        break;
        case HADES_WELCOME:
            memcpy(d0, "                  ", 21);
            memcpy(d1, "                  ", 21);
            memcpy(d2, "3KPD,FSQ3.        ", 21);
            memcpy(d3, "GINLRX7EYBVH      ", 21);
            memcpy(d4, "ZMJTKT            ", 21);
            memcpy(d5, "OEKEWA0E'BEVK     ", 21);
            memcpy(d6, "VCSH4AJSKUH       ", 21);
            memcpy(d7, "                  ", 21);
            memcpy(d8, "                  ", 21);
            memcpy(d9, "                  ", 21);
            memcpy(d10, "                  ", 21);
        break;
        case HADES_MOVE_BLOCK:
            memcpy(d0, "                  ", 21);
            memcpy(d1, "CFOA0WBA:(BAMOCRS.", 21);
            memcpy(d2, "                  ", 21);
            memcpy(d3, "CFJEQABFO,7-GKJ   ", 21);
            memcpy(d4, "INLA41BAP2XH3EDA. ", 21);
            memcpy(d5, "                  ", 21);
            memcpy(d6, "                  ", 21);
            memcpy(d7, "                  ", 21);
            memcpy(d8, "                  ", 21);
            memcpy(d9, "                  ", 21);
            memcpy(d10, "                  ", 21);
        break; 
        case HADES_USE_KEY:
            memcpy(d0, "                  ", 21);
            memcpy(d1, "CFOA0WBA:(BAMOCRS.", 21);
            memcpy(d2, "                  ", 21);
            memcpy(d3, "                  ", 21);
            memcpy(d4, "CFJEQABFO,7-GKJ   ", 21);
            memcpy(d5, "                  ", 21);
            memcpy(d6, "INLA41BAP2XH3EDA. ", 21);
            memcpy(d7, "                  ", 21);
            memcpy(d8, "                  ", 21);
            memcpy(d9, "                  ", 21);
            memcpy(d10, "                  ", 21);
        break;
        case HADES_KILL_ENEMY:
            memcpy(d0, "                  ", 21);
            memcpy(d1, "BC:FYDWBFPUD2     ", 21);
            memcpy(d2, "                  ", 21);
            memcpy(d3, "41BFVK            ", 21);
            memcpy(d4, "                  ", 21);
            memcpy(d5, "GAIJHE5NYBU       ", 21);
            memcpy(d6, "                  ", 21);
            memcpy(d7, "SMFOABC:FYNQBFPKTL", 21);
            memcpy(d8, "                  ", 21);
            memcpy(d9, " BPF2ZC           ", 21);
            memcpy(d10, "                  ", 21);
        break;
        case HADES_GUARDS:
            memcpy(d0, "                  ", 21);
            memcpy(d1, "FGQIFJL00BPQUZC   ", 21);
            memcpy(d2, "                  ", 21);
            memcpy(d3, "BM2AFBCNWGECF[    ", 21);
            memcpy(d4, "                  ", 21);
            memcpy(d5, "ZNB0D2            ", 21);
            memcpy(d6, "                  ", 21);
            memcpy(d7, "BM2LVYR]OKH       ", 21);
            memcpy(d8, "                  ", 21);
            memcpy(d9, "                  ", 21);
            memcpy(d10, "                 ", 21);
        break;
        case HADES_ROLLING_STONES:
            memcpy(d0, "                  ", 21);
            memcpy(d1, "JBAKGD1BGI(MHT    ", 21);
            memcpy(d2, "                  ", 21);
            memcpy(d3, "C6BGQ[BG5LFG8H    ", 21);
            memcpy(d4, "                  ", 21);
            memcpy(d5, "C6ATI]DVTNL       ", 21);
            memcpy(d6, "                  ", 21);
            memcpy(d7, "ZN4AQ2ZCDG[E      ", 21);
            memcpy(d8, "                  ", 21);
            memcpy(d9, "                  ", 21);
            memcpy(d10, "                  ", 21);
        break;
        case HADES_OWL_SAVING:
            memcpy(d0, "                  ", 21);
            memcpy(d1, "IEHLNOPGU7A       ", 21);
            memcpy(d2, "B1FMDG            ", 21);
            memcpy(d3, "Y3CDRFCDGXBG      ", 21);
            memcpy(d4, ":G[]KJEQGBVH      ", 21);
            memcpy(d5, "T5JBCWESHT,       ", 21);
            memcpy(d6, "FMQGFZBG8J(RS     ", 21);
            memcpy(d7, "                  ", 21);
            memcpy(d8, "                  ", 21);
            memcpy(d9, "                  ", 21);
            memcpy(d10, "                  ", 21);
        break;
        case HADES_GUARDS_AWAKENED:
            memcpy(d0, "                  ", 21);
            memcpy(d1, "                  ", 21);
            memcpy(d2, "                  ", 21);
            memcpy(d3, "                  ", 21);
            memcpy(d4, "FEQAFGBAXCBCFOCH! ", 21);
            memcpy(d5, "                  ", 21);
            memcpy(d6, "JA-LMDWBAIN]OKH!! ", 21);
            memcpy(d7, "                  ", 21);
            memcpy(d8, "                  ", 21);
            memcpy(d9, "                  ", 21);
            memcpy(d10, "                  ", 21);
        break;
        case HADES_DEATH:
            memcpy(d0, "                  ", 21);
            memcpy(d1, "IRUADJGL          ", 21);
            memcpy(d2, "                  ", 21);
            memcpy(d3, "I65FGK  ZC.       ", 21);
            memcpy(d4, "                  ", 21);
            memcpy(d5, "IRULDIMDBG,       ", 21);
            memcpy(d6, "                  ", 21);
            memcpy(d7, "IRUANC[L          ", 21);
            memcpy(d8, "                  ", 21);
            memcpy(d9, ":DDJGDWVBGHDG[E.  ", 21);
            memcpy(d10, "                  ", 21);
        break;
        case BOSS_CHARON_INTRO:
            memcpy(d0, "                  ", 21);
            memcpy(d1, "QMLIRS.           ", 21);
            memcpy(d2, "                  ", 21);
            memcpy(d3, "U-'VOD:GJ         ", 21);
            memcpy(d4, "                  ", 21);
            memcpy(d5, "CFN:DYX3E         ", 21);
            memcpy(d6, "                  ", 21);
            memcpy(d7, "BMAOEQDKTP,       ", 21);
            memcpy(d8, "                  ", 21);
            memcpy(d9, ":GLBMAFLC(MH      ", 21);
            memcpy(d10, "                  ", 21);
        break;
        case BOSS_CHARON_BEATED:
            memcpy(d0, "                  ", 21);
            memcpy(d1, "IRUAWB2OC         ", 21);
            memcpy(d2, "                  ", 21);
            memcpy(d3, "6DFA:ELQ6MD.      ", 21);
            memcpy(d4, "                  ", 21);
            memcpy(d5, "QQOCA6DFAGK8L     ", 21);
            memcpy(d6, "                  ", 21);
            memcpy(d7, "I6]D.             ", 21);
            memcpy(d8, "                  ", 21);
            memcpy(d9, "SS8,FAKNH         ", 21);
            memcpy(d10, "                  ", 21);
        break;
        case BOSS_CERBERUS_INTRO:
            memcpy(d0, "TLFVBJ CJMJO DT0D ", 21);
            memcpy(d1, "HF(WOKZ8JI.       ", 21);
            memcpy(d2, "0ZO]JD5LF8S       ", 21);
            memcpy(d3, "YN1JN3            ", 21);
            memcpy(d4, "BJF2QF2RAI.       ", 21);
            memcpy(d5, "                  ", 21);
            memcpy(d6, "7D9G]R,X2RAI!     ", 21);
            memcpy(d7, "8XDDFE8JK]4B:IE9Q,", 21);
            memcpy(d8, "'J[)?DRCEHJXKB6Q  ", 21);
            memcpy(d9, "UBJ-U8PGJ!        ", 21);
            memcpy(d10, "                  ", 21);
        break;
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