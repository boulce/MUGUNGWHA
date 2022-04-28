#pragma once
#include "field_def.h"
#include <malloc.h>
#define MAX_BULLET_CNT SIZE_Y

typedef enum _OBJ_TYPE
{
	PLAYER,
	ENEMY,
	NPC,
	BULLET
}OBJ_TYPE;

typedef enum _LOOK_DIRECITION
{
	W,
	S,
	A,
	D
}LOOK_DIRECITON;

typedef enum
{
	DEFAULT,
	L_PUNCH,
	R_PUNCH
}P_STATE;

typedef struct _OBJECT
{
	char* name;
	double health;
	FIELD* curr_field;
	int curr_x, curr_y;
	OBJ_TYPE obj_type;
	LOOK_DIRECITON obj_ld;
	P_STATE p_state;
} OBJECT;
/*
	������Ʈ ����
*/

// �÷��̾� ������Ʈ
OBJECT player;

//�Ѿ� ������Ʈ
OBJECT bullet;

// ���� ����
typedef enum _GIRLSTATE
{
	MUGUNGHWA,
	ATTACK
} GIRLSTATE;

GIRLSTATE girl_state;
