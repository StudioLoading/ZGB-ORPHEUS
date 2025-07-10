#include "Banks/SetAutoBank.h"

#include "BankManager.h"
#include "SpriteManager.h"
#include <string.h>
#include "ZGBMain.h"

#include "custom_datas.h"
#include "UtilsLoadSave.h"

SpriteBackup sprite_stack[MAX_SPRITES];
UINT8 sprite_stack_top = 0u;

extern Sprite* sprite_manager_sprites[];
extern UINT8* sprite_manager_sprites_pool;
extern Sprite* s_orpheus;
extern Sprite* s_block_00;
extern Sprite* s_blade;

extern void e_configure(Sprite* s_enemy, UINT8 sprite_type) BANKED;

void SaveSprites() BANKED{
    sprite_stack_top = 0u;
    UINT8 scroll_sl_tile;
    Sprite* slspr;
    SPRITEMANAGER_ITERATE(scroll_sl_tile, slspr) {
        sprite_stack[sprite_stack_top].type = slspr->type;
        sprite_stack[sprite_stack_top].x = slspr->x;
        sprite_stack[sprite_stack_top].y = slspr->y;
        memcpy(sprite_stack[sprite_stack_top].custom_data, slspr->custom_data, sizeof(slspr->custom_data));
        // puoi salvare anche spr->frame, spr->anim_frame, ecc.
        sprite_stack_top++;
    }
}

void RestoreSprites() BANKED{
    for (UINT8 i = 0; i < sprite_stack_top; i++) {
        Sprite* spr = SpriteManagerAdd(
            sprite_stack[i].type,
            sprite_stack[i].x,
            sprite_stack[i].y
        );
        memcpy(spr->custom_data, sprite_stack[i].custom_data, sizeof(sprite_stack[i].custom_data));
        switch(sprite_stack[i].type){
            case SpriteBlock: s_block_00 = spr; break;
            case SpriteBlade: s_blade = spr; break;
            case SpriteSkeleton: e_configure(spr, SKELETON); break;
            case SpriteDog: e_configure(spr, DOG); break;
            case SpriteSkeletonshield: e_configure(spr, SKELETON_SHIELD); break;
            case SpriteInfernalimp: e_configure(spr, INFERNALIMP); break;
            case SpriteLostsoul: e_configure(spr, LOSTSOUL); break;
            case SpriteTartarus: e_configure(spr, TARTARUS); break;
            case SpriteOoze: e_configure(spr, OOZE); break;
            case SpriteSentinel: e_configure(spr, SENTINEL); break;
            case SpriteItem:
                struct ItemInfo* i_data = (struct ItemInfo*) spr->custom_data; 
                i_data->i_configured = 1;
            break;
            case SpriteOrpheus: s_orpheus = spr; break;
        }
        // puoi anche ripristinare altre info, se le hai salvate
    }
    sprite_stack_top = 0;
}
