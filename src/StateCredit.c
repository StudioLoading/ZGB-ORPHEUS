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

#define NOTE_COUNT_MAX 80
#define PRESSSTART_COUNT_MAX 8
#define INITIAL_DELAY_MAX 50
#define CAMERA_STATE1_FINAL_POSX 240
#define CAMERA_STATE0_FINAL_POSX 80

IMPORT_MAP(mapcredit0);
IMPORT_MAP(mapcredit1);
IMPORT_MAP(mapcredit2);
IMPORT_MAP(mapcredit3);
IMPORT_MAP(maptitlescreen);
IMPORT_TILES(font);
DECLARE_MUSIC(intro);

UINT8 note_countdown = 0;
UINT8 note_configured = 1;
UINT8 rndm = 0u;
UINT8 credit_page_counter = 0u;
UINT8 intro_music_started = 0u;
INT8 test_sfx_counter = 0;
UINT8 initial_delay_counter = 0u;
UINT8 opt_selected = 0;
UINT8 flag_camera_move = 0u;
UINT8 camera_state = 0u;
UINT8 btns_selected = 0;

UINT8 J_INT=J_A;//0x10;
UINT8 J_ATK=J_B;//0x20;

void write_menu(UINT8 arg_opt_selected) BANKED;
void write_btns(UINT8 arg_btns_selected) BANKED;

extern UINT8 stop_music_on_new_state;
uint8_t sgb_checked = 0;
extern void manage_sgb_border() BANKED;
extern void manage_sgb_palette() BANKED;

void START(){
    manage_sgb_palette();
    switch(credit_page_counter){
        case 0u: 
            sgb_checked = sgb_check();
            NR52_REG = 0x80; //Enables sound, you should always setup this first
            NR51_REG = 0xFF; //Enables all channels (left and right)
            NR50_REG = 0x77; //Max volumes
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
            manage_sgb_border();
            InitScroll(BANK(maptitlescreen), &maptitlescreen, 0, 0);
            scroll_target = SpriteManagerAdd(SpriteCamera, 80u, 72u);
        break;
    }
    INIT_FONT(font, PRINT_BKG);
    initial_delay_counter = 0u;
    stop_music_on_new_state = 0;
    if(intro_music_started == 0){
        intro_music_started = 1;
        PlayMusic(intro, 1);
    }
}


void write_menu(UINT8 arg_opt_selected) BANKED{
    switch(arg_opt_selected){
        case 0: PRINT(8, 12, "START"); break;
        case 1: PRINT(3, 13, "CONFIG BUTTONS"); break;
        case 2: PRINT(7, 14, "CREDITS"); break;
        case 99:{
            PRINT(8, 12, "START");
            PRINT(3, 13, "CONFIG BUTTONS");
            PRINT(7, 14, "CREDITS");
        }break;
    }
}


void write_btns(UINT8 arg_btns_selected) BANKED{
    switch(arg_btns_selected){
        case 0:
            PRINT(24, 4, "A  INTERACT"); 
            PRINT(24, 5, "B  PLAY LYRE"); 
        break;
        case 1: 
            PRINT(24, 8, "A  PLAY LYRE"); 
            PRINT(24, 9, "B  INTERACT"); 
        break;
        case 99:{
            PRINT(24, 4, "A  INTERACT"); 
            PRINT(24, 5, "B  PLAY LYRE"); 
            PRINT(24, 8, "A  PLAY LYRE"); 
            PRINT(24, 9, "B  INTERACT"); 
        }break;
    }
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
        if(flag_camera_move){
            switch(camera_state){
                case 0:{//move right
                    if(scroll_target->x < CAMERA_STATE1_FINAL_POSX){
                        scroll_target->x++;
                    }else{
                        initial_delay_counter = 0;
                        flag_camera_move = 0;
                        camera_state = 1;
                    }
                }break;
                case 1:{//move left
                    if(scroll_target->x > CAMERA_STATE0_FINAL_POSX){
                        scroll_target->x--;
                    }else{
                        initial_delay_counter = 0;
                        flag_camera_move = 0;
                        camera_state = 0;
                    }
                }break;
            }
        }else{
            switch(camera_state){
                case 0:{
                    if(initial_delay_counter < INITIAL_DELAY_MAX){
                        initial_delay_counter++;
                        return;
                    }else if(initial_delay_counter == INITIAL_DELAY_MAX){
                        write_menu(99);
                        initial_delay_counter++;
                    }
                    note_countdown++;
                    if(note_countdown >= PRESSSTART_COUNT_MAX){
                        note_countdown = 0;
                        if(rndm == 0){rndm = 1;}
                        else{rndm = 0;}
                        switch(rndm){
                            case 0u:{
                                write_menu(opt_selected);
                            }break;
                            case 1u: 
                                switch(opt_selected){
                                    case 0: PRINT(8, 12, "     "); break;
                                    case 1: PRINT(3, 13, "              "); break;
                                    case 2: PRINT(7, 14, "       "); break;
                                }
                            break;
                        }
                    }
                    if(KEY_TICKED(J_SELECT) || KEY_TICKED(J_DOWN)){
                        write_menu(99);
                        opt_selected++;
                        if(opt_selected >= 3){
                            opt_selected = 0;
                        }
                    }
                    if(KEY_TICKED(J_UP)){
                        write_menu(99);
                        opt_selected--;
                        if(opt_selected >= 3){
                            opt_selected = 2;
                        }
                    }
                    if(KEY_TICKED(J_START) || KEY_TICKED(J_A) || KEY_TICKED(J_B)){
                        switch(opt_selected){
                            case 0:{//START
                                credit_page_counter++;
                                note_countdown = 0;
                                rndm = 0;
                                if(btns_selected){
                                    J_INT=J_B;//0x20;
                                    J_ATK=J_A;//0x10;
                                }
                                SetState(StateIntro);
                            }break;
                            case 1:{//CONFIG BUTTONS
                                if(flag_camera_move == 0){
                                    flag_camera_move = 1;
                                }
                            }break;
                            case 2:{//CREDITS
                                credit_page_counter = 0;
                                SetState(StateCredit);
                            }break;
                        }
                    }
                }break;
                case 1:{
                    if(initial_delay_counter < INITIAL_DELAY_MAX){
                        initial_delay_counter++;
                        return;
                    }else if(initial_delay_counter == INITIAL_DELAY_MAX){
                        write_btns(99);
                        initial_delay_counter++;
                    }
                    note_countdown++;
                    if(note_countdown >= PRESSSTART_COUNT_MAX){
                        note_countdown = 0;
                        if(rndm == 0){rndm = 1;}
                        else{rndm = 0;}
                        switch(rndm){
                            case 0u:{
                                write_btns(btns_selected);
                            }break;
                            case 1u: 
                                switch(btns_selected){
                                    case 0:
                                        PRINT(24, 4, "           "); 
                                        PRINT(24, 5, "            "); 
                                    break;
                                    case 1: 
                                        PRINT(24, 8, "            "); 
                                        PRINT(24, 9, "            "); 
                                    break;
                                }
                            break;
                        }
                    }
                    if(KEY_TICKED(J_SELECT) || KEY_TICKED(J_DOWN)){
                        write_btns(99);
                        btns_selected++;
                        if(btns_selected >= 2){
                            btns_selected = 0;
                        }
                    }
                    if(KEY_TICKED(J_START) || KEY_TICKED(J_A) || KEY_TICKED(J_B)){
                        flag_camera_move = 1;
                    }
                }break;
            }   
        }
    }else{
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
            }
        }
    }
}