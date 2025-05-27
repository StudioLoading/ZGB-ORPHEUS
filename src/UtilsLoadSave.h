#ifndef SPRITE_BACKUP_H
#define SPRITE_BACKUP_H

#include <gb/gb.h>
#include "ZGBMain.h"

#define MAX_SPRITES 16

typedef struct SpriteBackup {
    UINT8 type;
    INT16 x, y;
    UINT8 custom_data[8];
    // Aggiungi altri campi se vuoi salvare più stato
} SpriteBackup;

extern SpriteBackup sprite_stack[MAX_SPRITES];
extern UINT8 sprite_stack_top;

void SaveSprites() BANKED;
void RestoreSprites() BANKED;

#endif
