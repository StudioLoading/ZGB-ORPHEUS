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
            memcpy(d1, "THIS IS THE TEST FOR", 22);
            memcpy(d2, "A THREE LINES DIAL  ", 22);
            memcpy(d3, "OG. LET'S SEE       ", 22);
            memcpy(d4, "WHAT IF I ADD MORE  ", 22);
            memcpy(d5, "THAN THREE LINES?   ", 22);
            memcpy(d6, "IS IT COMPOFTABLE?  ", 22);
            memcpy(d7, "NUMBERS?0123456789  ", 22);
            memcpy(d8, EMPTY_STRING_20, 22);
            memcpy(d9, "EMPTY LINE ABOVE    ", 22);
            return 9u;
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
