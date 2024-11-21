#include "Banks/SetAutoBank.h"

#include "ZGBMain.h"
#include "Palette.h"
#include "Scroll.h"
#include "Sprite.h"
#include "SpriteManager.h"

#include "custom_datas.h"

void START() {
    THIS->lim_x = 1000u;
    THIS->lim_y = 1000u;
    struct EnemyInfo* g_data = (struct EnemyInfo*) THIS->custom_data;
    g_data->frmskip = 0;
    g_data->frmskip_wait = 12;
    g_data->vx = 0;
    g_data->vy = 0;
    g_data->tile_collision = 0;
    g_data->wait = 16;
    g_data->e_configured = 0;
}

void UPDATE() {
    struct EnemyInfo* g_data = (struct EnemyInfo*) THIS->custom_data;
    switch(g_data->e_configured){
        case 0u: break;
        case 1u:{
            g_data->frmskip++; 
            if(g_data->frmskip < g_data->frmskip_wait){
                return;
            }
            g_data->frmskip = 0u;
            g_data->vy++;
            THIS->x--;
            if( g_data->vy >= g_data->wait){
                g_data->e_configured = 2u;
            }
        }break;
    }

}

void DESTROY() {
}