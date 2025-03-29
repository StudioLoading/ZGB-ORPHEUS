#include "Banks/SetAutoBank.h"

#include "BankManager.h"
#include "Sound.h"
#include "Music.h"

UINT8 sfx_cooldown = 0u;

void my_play_fx(UINT8 c, UINT8 mute_frames, UINT8 s0, UINT8 s1, UINT8 s2, UINT8 s3, UINT8 s4) BANKED;


void my_play_fx(UINT8 c, UINT8 mute_frames, UINT8 s0, UINT8 s1, UINT8 s2, UINT8 s3, UINT8 s4) BANKED{
    SOUND_CHANNEL channel = CHANNEL_5;
    switch(c){
        case 1u: channel = CHANNEL_1; break;
        case 2u: channel = CHANNEL_2; break;
        case 3u: channel = CHANNEL_3; break;
        case 4u: channel = CHANNEL_4; break;
    }
    PlayFx(channel, mute_frames, s0, s1, s2, s3, s4);
}