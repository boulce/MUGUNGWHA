#pragma once

// �ʵ� ũ��
#define SIZE_Y 18
#define SIZE_X 93

//�ʵ� �ؽ���
typedef enum f_texture
{
	EMPTY, // "  "
	WALL_V, // "��"
	WALL_H, // "��"
	WALL_LT, // "��"
	WALL_RT, // "��"
	WALL_LB, // "��"
	WALL_RB // "��"
} F_TEXTURE;

typedef struct _FIELD
{
	char* name;
	F_TEXTURE data_arr[SIZE_Y][SIZE_X];
}FIELD;

// ���� �ʵ�
FIELD start_field;