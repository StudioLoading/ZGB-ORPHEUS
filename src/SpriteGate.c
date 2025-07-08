#include "Banks/SetAutoBank.h"

#include "ZGBMain.h"
#include "Palette.h"
#include "Scroll.h"
#include "Sprite.h"
#include "SpriteManager.h"

#include "custom_datas.h"

Sprite* s_gate_other;
extern UINT8 gate_pushed;

UINT8 other_gate_created = 0u;

void START() {
    THIS->lim_x = 1000u;
    THIS->lim_y = 1000u;
    struct EnemyInfo* g_data = (struct EnemyInfo*) THIS->custom_data;
    g_data->frmskip = 0;
    g_data->frmskip_wait = 12;
    g_data->vx = 0;
    g_data->tile_collision = 0;
    g_data->wait = 14;
    g_data->e_configured = 0;
    if(other_gate_created == 0u){
        other_gate_created = 1u;
        s_gate_other = SpriteManagerAdd(SpriteGate, ((UINT16) 31u << 3) -4, ((UINT16) 21u << 3) +3);
        s_gate_other->mirror = V_MIRROR;
        struct EnemyInfo* g_data_other = (struct EnemyInfo*) s_gate_other->custom_data;
        g_data_other->frmskip = 0;
        g_data_other->frmskip_wait = 12;
        g_data_other->vx = 0;
        g_data_other->vy = 0;
        g_data_other->tile_collision = 0;
        g_data_other->wait = 14;
        g_data_other->e_configured = 0;
		if(gate_pushed == 1u){
            s_gate_other->x = ((UINT16) 32u << 3);
            g_data_other->e_configured = 0;
        }
    }
}

void UPDATE() {
    struct EnemyInfo* g_data = (struct EnemyInfo*) THIS->custom_data;
    INT16 delta_scroll_t = scroll_target->y - THIS->y;
    switch(g_data->e_configured){
        case 0u: break;
        case 1u:{
            if(s_gate_other != THIS){
                struct EnemyInfo* g_data_other2 = (struct EnemyInfo*) s_gate_other->custom_data;
                if(g_data_other2->e_configured == 0){
                    g_data_other2->e_configured = 2;
                }
            }
            g_data->frmskip++; 
            if(g_data->frmskip < g_data->frmskip_wait){
                return;
            }
            g_data->frmskip = 0u;
            g_data->vx++;
            if(delta_scroll_t < -20){
                THIS->x = ((UINT16) 28u << 3);
                THIS->y = ((UINT16) 21u << 3)+3;
                g_data->e_configured = 0u;
                return;
            }
            THIS->x--;
            if( (UINT8)g_data->vx >= g_data->wait){
                g_data->e_configured = 0u;
            }
        }break;
        case 2u:{
            g_data->frmskip++; 
            if(g_data->frmskip < g_data->frmskip_wait){
                return;
            }
            g_data->frmskip = 0u;
            g_data->vx++;
            if(delta_scroll_t < -20){
                THIS->x = ((UINT16) 32u << 3);
                THIS->y = ((UINT16) 21u << 3)+3;
                g_data->e_configured = 0u;
                return;
            }
            THIS->x++;
            if( (UINT8)g_data->vx >= g_data->wait){
                g_data->e_configured = 0u;
            }
        }break;
    }

}

void DESTROY() {
}