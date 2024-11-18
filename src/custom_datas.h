#ifndef CUSTOMDATAS_FILE
#define CUSTOMDATAS_FILE

typedef enum{
	GENERIC_IDLE,
	GENERIC_WALK,
	IDLE_UP,
	IDLE_DOWN,
	IDLE_LEFT,
	IDLE_RIGHT,
	WALK_LEFT,
	WALK_RIGHT,
	WALK_UP,
	WALK_DOWN,
	JUMP,
	ATTACK,
	HIT,
	DIE
}SPRITE_STATES;

struct OrpheusInfo{
	SPRITE_STATES ow_state;
	UINT8 tile_collision;
	INT8 vx;
	INT8 vy;
    INT8 charming;
};

typedef enum{
	SKELETON,
	SKELETON_SHIELD
}ENEMY_TYPE;

struct EnemyInfo{
	SPRITE_STATES e_state;
	UINT8 tile_collision;
	INT8 vx;
	INT8 vy;
    UINT8 wait;
	UINT8 frmskip_wait;
	UINT8 e_configured;
	UINT8 frmskip;
};

typedef enum{
	ATTRACT,
	SLEEP,
	REPEL
}SONG;

typedef enum{
	LYRE,
	HEART,
	KEY,
	BLOCK,
	BLOCK_FIXED,
	BUTTON,
	DOOR,
	DOOR_KEY,
	DOOR_ENEMY
}ITEM_TYPE;

struct ItemInfo{
	ITEM_TYPE item_type;
	UINT8 i_configured;
	INT8 counter_x;
	INT8 counter_y;
	INT8 counter_verso;//1 o -1
};

typedef enum{
	TUTORIAL,
	HADES_ZERO,
	HADES_ONE,
	HADES_TWO,
	HADES_THREE,
	HADES_FOUR
}MACROMAP;

struct LoadedItem{
	ITEM_TYPE item_type;
	UINT16 pos_x;
	UINT16 pos_y;
	struct ItemInfo iinfo;
};

struct LoadedEnemy{
	ENEMY_TYPE item_type;
	UINT16 posx;
	UINT16 posy;
	struct EnemyInfo einfo;
};

#endif