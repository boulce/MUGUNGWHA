#pragma once

// 필드 크기
#define SIZE_Y 18
#define SIZE_X 93

//필드 텍스쳐
typedef enum f_texture
{
	EMPTY, // "  "
	WALL_V, // "┃"
	WALL_H, // "━"
	WALL_LT, // "┏"
	WALL_RT, // "┓"
	WALL_LB, // "┗"
	WALL_RB // "┛"
} F_TEXTURE;

typedef struct _FIELD
{
	char* name;
	F_TEXTURE data_arr[SIZE_Y][SIZE_X];
}FIELD;

// 시작 필드
FIELD start_field;