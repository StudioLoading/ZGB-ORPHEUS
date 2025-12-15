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
            memcpy(d1, "     4N)5GJHK     ", 21);
            memcpy(d2, "     B[6CA...     ", 21);
            memcpy(d3, "                  ", 21);
            memcpy(d4, " Y?),OPQRLZIS7K). ", 21);
            memcpy(d5, " KKG]9TWX1)DGME0U ", 21);
            memcpy(d6, "                  ", 21);
            memcpy(d7, "    GD2VAFK?)     ", 21);
            memcpy(d8, "   ...3M,A68)!    ", 21);
            memcpy(d9, "                  ", 21);
            return 9u;
        break;
        case MISSING_LYRE:
            memcpy(d1, "   YE)FGDBKV)WCA.   ", 21);
            memcpy(d2, "  Y?) OPQR LZICAB!  ", 21);
            memcpy(d3, "                    ", 21);
            return 3u;
        break;
        case FOUND_LYRE:
            memcpy(d1, "   OPQR G)M2K),     ", 21);
            memcpy(d2, "   DBCF7A:V),VWL    ", 21);
            memcpy(d3, "                    ", 21);
            memcpy(d4, "      HWISE0,       ", 21);
            memcpy(d5, " DNG)3TE0?FDBJV)WF. ", 21);
            memcpy(d6, "                    ", 21);
            return 6u;
        break;
        case PUSH_BUTTON:
            memcpy(d1, "    C)DKG-NUEIB,    ", 21);
            memcpy(d2, "    JHLMS32FZEAE).  ", 21);
            memcpy(d3, "                    ", 21);
            return 3u;
        break;
        case PRESS_INTERACT:
            memcpy(d1, "                    ", 21);
            memcpy(d2, "     OPQRLVUA2F     ", 21);
            memcpy(d3, "                    ", 21);
            return 3u;
        break;
        case HADES_ENTRANCE:
            memcpy(d1, "     IAUIAET)..     ", 21);
            memcpy(d2, "      4K)5GJH!      ", 21);
            memcpy(d3, "                    ", 21);
            memcpy(d4, "       W9K)X,       ", 21);
            memcpy(d5, "    NC3?)E?SVYF!    ", 21);
            memcpy(d6, "  B)HCDHCHN)M:-BJ!  ", 21);
            return 6u;
        break;
        case HADES_WELCOME:
            memcpy(d0, "                  ", 21);
            memcpy(d1, "2MRD,FSP2.        ", 21);
            memcpy(d2, "                  ", 21);
            memcpy(d3, "GINKQW7EXBVH      ", 21);
            memcpy(d4, "                  ", 21);
            memcpy(d5, "[LJUMU            ", 21);
            memcpy(d6, "                  ", 21);
            memcpy(d7, "OEMEYAZE'BEVM     ", 21);
            memcpy(d8, "                  ", 21);
            memcpy(d9, "VCSH3AJSMTH       ", 21);
            memcpy(d10, "                  ", 21);
        break;
        case HADES_MOVE_BLOCK:
            memcpy(d0, "                  ", 21);
            memcpy(d1, "CEOA4YBA[(BALOCQS.", 21);
            memcpy(d2, "                  ", 21);
            memcpy(d3, "CEJFPABEO,7:GMJ   ", 21);
            memcpy(d4, "                  ", 21);
            memcpy(d5, "INKA3ZBAR0WH2FDA. ", 21);
            memcpy(d6, "                  ", 21);
            memcpy(d7, "                  ", 21);
            memcpy(d8, "                  ", 21);
            memcpy(d9, "                  ", 21);
            memcpy(d10, "                  ", 21);
        break; 
        case HADES_USE_KEY:
            memcpy(d0, "                  ", 21);
            memcpy(d1, "]HCBRAVLKA,       ", 21);
            memcpy(d2, "                  ", 21);
            memcpy(d3, "DA'JVWHPUBAOARH.  ", 21);
            memcpy(d4, "                  ", 21);
            memcpy(d5, "GC?JBTH2FNDA'J    ", 21);
            memcpy(d6, "                  ", 21);
            memcpy(d7, "[F(EO42F.         ", 21);
            memcpy(d8, "                  ", 21);
            memcpy(d9, "                  ", 21);
            memcpy(d10, "                  ", 21);
        break;
        case HADES_KILL_ENEMY:
            memcpy(d0, "                  ", 21);
            memcpy(d1, "BC]E1DYBERTD0     ", 21);
            memcpy(d2, "                  ", 21);
            memcpy(d3, "3ZBEVM            ", 21);
            memcpy(d4, "                  ", 21);
            memcpy(d5, "GAIJHF5N1BT       ", 21);
            memcpy(d6, "                  ", 21);
            memcpy(d7, "SLEOABC]E1NPBERMUK", 21);
            memcpy(d8, "                  ", 21);
            memcpy(d9, "BRE0XC            ", 21);
            memcpy(d10, "                  ", 21);
        break;
        case HADES_GUARDS:
            memcpy(d0, "                  ", 21);
            memcpy(d1, "EGPIEJK44BRPTXC   ", 21);
            memcpy(d2, "                  ", 21);
            memcpy(d3, "BL0AEBCNYGFCE?    ", 21);
            memcpy(d4, "                  ", 21);
            memcpy(d5, "XNB4D0            ", 21);
            memcpy(d6, "                  ", 21);
            memcpy(d7, "BL0KV1Q-OMH       ", 21);
            memcpy(d8, "                  ", 21);
            memcpy(d9, "                  ", 21);
            memcpy(d10, "                 ", 21);
        break;
        case HADES_ROLLING_STONES:
            memcpy(d0, "                  ", 21);
            memcpy(d1, "JBAMGDZBGI(LHU    ", 21);
            memcpy(d2, "                  ", 21);
            memcpy(d3, "C6BGP?BG5KEG8H    ", 21);
            memcpy(d4, "                  ", 21);
            memcpy(d5, "C6AUI-DVUNK       ", 21);
            memcpy(d6, "                  ", 21);
            memcpy(d7, "XN3AP0XCDG?F      ", 21);
            memcpy(d8, "                  ", 21);
            memcpy(d9, "                  ", 21);
            memcpy(d10, "                  ", 21);
        break;
        case HADES_OWL_SAVING:
            memcpy(d0, "                  ", 21);
            memcpy(d1, "IFHKNORGT7A       ", 21);
            memcpy(d2, "                  ", 21);
            memcpy(d3, "BZELDG            ", 21);
            memcpy(d4, "                  ", 21);
            memcpy(d5, "12CDQECDGWBG      ", 21);
            memcpy(d6, "                  ", 21);
            memcpy(d7, "]G?-MJFPGBVH      ", 21);
            memcpy(d8, "                  ", 21);
            memcpy(d9, "U5JBCXFSHU,       ", 21);
            memcpy(d10, "ELPGEYBG8J(QS     ", 21);
        break;
        case HADES_GUARDS_AWAKENED:
            memcpy(d0, "                  ", 21);
            memcpy(d1, "                  ", 21);
            memcpy(d2, "                  ", 21);
            memcpy(d3, "                  ", 21);
            memcpy(d4, "EFPAEGBAWCBCEOCH! ", 21);
            memcpy(d5, "                  ", 21);
            memcpy(d6, "JA:KLDYBAI[-OMH!! ", 21);
            memcpy(d7, "                  ", 21);
            memcpy(d8, "                  ", 21);
            memcpy(d9, "                  ", 21);
            memcpy(d10, "                  ", 21);
        break;
        case HADES_DEATH:
            memcpy(d0, "                  ", 21);
            memcpy(d1, "IQTADJGK          ", 21);
            memcpy(d2, "                  ", 21);
            memcpy(d3, "I65EGM  XC.       ", 21);
            memcpy(d4, "                  ", 21);
            memcpy(d5, "IQTKDILDBG,       ", 21);
            memcpy(d6, "                  ", 21);
            memcpy(d7, "IQTANC?K          ", 21);
            memcpy(d8, "                  ", 21);
            memcpy(d9, "]DDJGDYVBGHDG?F.  ", 21);
            memcpy(d10, "                  ", 21);
        break;
        case BOSS_CHARON_INTRO:
            memcpy(d0, "                  ", 21);
            memcpy(d1, "PLKIQS.           ", 21);
            memcpy(d2, "                  ", 21);
            memcpy(d3, "T:'VOD]GJ         ", 21);
            memcpy(d4, "                  ", 21);
            memcpy(d5, "CEN]D1W2!         ", 21);
            memcpy(d6, "                  ", 21);
            memcpy(d7, "BLAOFPDMUR,       ", 21);
            memcpy(d8, "                  ", 21);
            memcpy(d9, "]GKBLAEKC(LH      ", 21);
            memcpy(d10, "                  ", 21);
        break;
        case BOSS_CHARON_BEATED:
            memcpy(d0, "                  ", 21);
            memcpy(d1, "IQTAYB0OC         ", 21);
            memcpy(d2, "                  ", 21);
            memcpy(d3, "6DEA]FKP6LD.      ", 21);
            memcpy(d4, "                  ", 21);
            memcpy(d5, "PPOCA6DEAGM8K     ", 21);
            memcpy(d6, "                  ", 21);
            memcpy(d7, "I6-D.             ", 21);
            memcpy(d8, "                  ", 21);
            memcpy(d9, "SS8,EAMNH         ", 21);
            memcpy(d10, "                  ", 21);
        break;
        case BOSS_CERBERUS_INTRO:
            memcpy(d0, "                  ", 21);
            memcpy(d1, "41MIGA5PFWZQRSGV7B", 21);
            memcpy(d2, "G                 ", 21);
            memcpy(d3, "FTNFTOCH.         ", 21);
            memcpy(d4, "                  ", 21);
            memcpy(d5, "[A8K3TOCH!        ", 21);
            memcpy(d6, "                  ", 21);
            memcpy(d7, "W3AAFDWGJI0BYHD8N,", 21);
            memcpy(d8, "2G:9'AOEDUG3JB6N  ", 21);
            memcpy(d9, "XBG(XWLKG!        ", 21);
            memcpy(d10, "                  ", 21);
        break;
        case BOSS_CERBERUS_BEATED:
            memcpy(d0, "                  ", 21);
            memcpy(d1, "LMNGT7JDIED       ", 21);
            memcpy(d2, "                  ", 21);
            memcpy(d3, "R4AVCSHUWXGYK     ", 21);
            memcpy(d4, "                  ", 21);
            memcpy(d5, "ZAIAB6A           ", 21);
            memcpy(d6, "                  ", 21);
            memcpy(d7, "0PFOGQ-OCH.       ", 21);
            memcpy(d8, "                  ", 21);
            memcpy(d9, "SS8               ", 21);
            memcpy(d10, "                  ", 21);
        break;
        case BOSS_MINOS_INTRO:
            memcpy(d0, "                  ", 21);
            memcpy(d1, "(CKEZBZGH7A       ", 21);
            memcpy(d2, "QTND1             ", 21);
            memcpy(d3, "OZPEZJ1B8!        ", 21);
            memcpy(d4, "                  ", 21);
            memcpy(d5, "IQTACAYJBWO       ", 21);
            memcpy(d6, "VMQNI3NJ]E1W2.    ", 21);
            memcpy(d7, "                  ", 21);
            memcpy(d8, "BLA(KERKMDEWY5    ", 21);
            memcpy(d9, "VMQKBBLJI[F!      ", 21);
            memcpy(d10, "                  ", 21);
        break;
        case BOSS_MINOS_BEATED:
            memcpy(d0, "                  ", 21);
            memcpy(d1, "PRKGUSBD          ", 21);
            memcpy(d2, "                  ", 21);
            memcpy(d3, "IQTJIE3UD[FUEOCH! ", 21);
            memcpy(d4, "                  ", 21);
            memcpy(d5, "                  ", 21);
            memcpy(d6, "L:'GUBZBMJEZED    ", 21);
            memcpy(d7, "                  ", 21);
            memcpy(d8, "I65A4YJR5N0W!     ", 21);
            memcpy(d9, "                  ", 21);
            memcpy(d10, "                  ", 21);
        break;
        case BOSS_AEACUS_INTRO:
            memcpy(d0, "                  ", 21);
            memcpy(d1, "IMNVH':'G7        ", 21);
            memcpy(d2, "                  ", 21);
            memcpy(d3, "44BKRPTXC,        ", 21);
            memcpy(d4, "                  ", 21);
            memcpy(d5, "O1AYZ3MJ52FE?!    ", 21);
            memcpy(d6, "                  ", 21);
            memcpy(d7, "                  ", 21);
            memcpy(d8, "BM(LDQSJ1BCPXU    ", 21);
            memcpy(d9, "                  ", 21);
            memcpy(d10, "                  ", 21);
        break;
        case BOSS_AEACUS_BEATED:
            memcpy(d0, "                  ", 21);
            memcpy(d1, "                  ", 21);
            memcpy(d2, "':'G7KDILD!       ", 21);
            memcpy(d3, "                  ", 21);
            memcpy(d4, "PPKHCFRJMAB6DC!   ", 21);
            memcpy(d5, "                  ", 21);
            memcpy(d6, "                  ", 21);
            memcpy(d7, "PPK,NOC7ASQFKCET! ", 21);
            memcpy(d8, "                  ", 21);
            memcpy(d9, "                  ", 21);
            memcpy(d10, "                  ", 21);
        break;
        case BOSS_HADES_INTRO:
            memcpy(d0, "                  ", 21);
            memcpy(d1, "                  ", 21);
            memcpy(d2, "FGJMN7BEDILD!     ", 21);
            memcpy(d3, "                  ", 21);
            memcpy(d4, "                  ", 21);
            memcpy(d5, "PQE7ARSKTAIOE     ", 21);
            memcpy(d6, "                  ", 21);
            memcpy(d7, "                  ", 21);
            memcpy(d8, "II6LOCH.          ", 21);
            memcpy(d9, "                  ", 21);
            memcpy(d10, "                  ", 21);
        break;
        case BOSS_HADES_BEATED:
            memcpy(d0, "                  ", 21);
            memcpy(d1, "STG7KDIL          ", 21);
            memcpy(d2, "4YBGJ0BLH         ", 21);
            memcpy(d3, "DGBG2MRW          ", 21);
            memcpy(d4, "DC2FAJB5BG(EPNQOG ", 21);
            memcpy(d5, "]5NCOK            ", 21);
            memcpy(d6, "X0XC!             ", 21);
            memcpy(d7, "                  ", 21);
            memcpy(d8, "                  ", 21);
            memcpy(d9, "                  ", 21);
            memcpy(d10, "                  ", 21);
        break;
        case END_ORPHEUS_FOLLOW:
            memcpy(d1, "3WVZDNJPCGXYB...    ", 21);
            memcpy(d2, "RMADTBSL0C,         ", 21);
            memcpy(d3, "RMADKA1UBO.         ", 21);
            memcpy(d4, "RMAM2DAV7K4OV,      ", 21);
            memcpy(d5, "TCNKSEA.            ", 21);
            memcpy(d6, "H5IVHEQLIHV6,       ", 21);
            memcpy(d7, "                    ", 21);
            memcpy(d8, "RMAPTJAJAOB8FL.     ", 21);
            memcpy(d9, "                    ", 21);
            return 9u;
        break;
        case END_ORPHEUS_EURIDYCE:
            memcpy(d1, "                    ", 21);
            memcpy(d2, "      []ABC!        ", 21);
            memcpy(d3, "                    ", 21);
            return 3u;
        break;
        case END_EURIDYCE_NOOO:
            memcpy(d1, "                    ", 21);
            memcpy(d2, "       70AGGG!      ", 21);
            memcpy(d3, "                    ", 21);
            return 3u;
        break;
        case END_EURIDYCE_BOX:
            memcpy(d1, "EFPYJMG3KI          ", 21);
            memcpy(d2, "NAIAO...3RTVGXD3KI  ", 21);
            memcpy(d3, "                    ", 21);
            memcpy(d4, "EFW0IQPGNCDPGA9U    ", 21);
            memcpy(d5, "NCGFL.              ", 21);
            memcpy(d6, "                    ", 21);
            memcpy(d7, "B4E1BCABH5W         ", 21);
            memcpy(d8, "C6NCGSCHMG.         ", 21);
            memcpy(d9, "                    ", 21);
            memcpy(d10, "'():?Z...          ", 21);
            memcpy(d11, "H5PCEUBL           ", 21);
            memcpy(d12, "                    ", 21);
            return 12u;
        break;
        case ENDSCREEN_SEEYOUIN2027:
            memcpy(d1, "      G0OACK!       ", 21);
            memcpy(d2, "    DBEA4OATHJOAL   ", 21);
            memcpy(d2, "     FOT6IACK!      ", 21);
            return 3u;
        break;
    }
    return 0u;
}