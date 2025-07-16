#ifndef CUSTOMDATAS_FILE
#define CUSTOMDATAS_FILE


typedef enum{
	BORDER_SKY,
	BORDER_FLAMES
}CURRENT_BORDER;

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
	DIE,
	PREATTACK_RIGHT,
	PREATTACK_UP,
	PREATTACK_LEFT,
	PREATTACK_DOWN
}SPRITE_STATES;

struct OrpheusInfo{
	SPRITE_STATES ow_state;
	UINT8 tile_collision;
	INT8 vx;
	INT8 vy;
    INT8 charming;
};

struct CharonInfo{
	SPRITE_STATES e_state;
	UINT8 tile_collision;
	INT8 vx;
    INT8 wait;
	INT8 wait_max;
	INT8 countdown;
};

struct CerberusInfo{
	SPRITE_STATES e_state;
	INT8 vx;
	INT8 vy;
    INT8 wait;
	INT8 frmskip;
	INT8 frmskip_max;
	INT8 head_config;
};

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

struct NoteInfo{
	UINT8 is_enemy;
	INT8 vx;
	INT8 vy;
	UINT8 wait;
	INT8 frmskip;
	INT8 frmskip_max;
};

typedef enum{
	ATTRACT,
	SLEEP,
	REPEL
}SONG;

typedef enum{
	ITEM_NONE,
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

struct ExclamationInfo{
	INT8 counter;
};

struct ItemSpawnedByCommon{
	UINT8 sprite_type;
	ITEM_TYPE item_type;
	UINT8 spawned;
};

typedef enum{
	MAP_NONE,
	TUTORIAL,
	HADES_ZERO,
	HADES_ONE,
	HADES_TWO,
	HADES_THREE,
	HADES_FOUR,
	HADES_FIVE,
	BOSS_CHARON,
	HADES_SIX,
	HADES_SEVEN,
	HADES_EIGHT,
	HADES_NINE,
	HADES_TEN,
	BOSS_CERBERUS,
	HADES_ELEVEN,
	END_DEMO
}MACROMAP;

typedef enum{
	DEATH_NONE,
	DEATH_SKULL,
	DEATH_PUFF_LEFT_0,
	DEATH_PUFF_LEFT_1,
	DEATH_PUFF_RIGHT_0,
	DEATH_PUFF_RIGHT_1,
}DEATH_COMPONENT;

typedef enum{
	PUSH_NONE, PUSH_UP, PUSH_RIGHT, PUSH_DOWN, PUSH_LEFT
}PUSHING;

typedef enum{
	ENEMY_REACT_NONE,
	ENEMY_REACT_DIE,
	ENEMY_REACT_TURN,
	ENEMY_REACT_PASSTHROUGH
}ENEMY_REACTION;

#endif