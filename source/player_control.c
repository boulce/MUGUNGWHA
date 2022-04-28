#include <windows.h>
#include <time.h>
#include "object_def.h"
#include "field_def.h"

/*
    ����Ű ��
*/

#define LEFT VK_LEFT
#define RIGHT VK_RIGHT

void print_obj_del(OBJECT* obj);
void print_obj_upd(OBJECT* obj);

int KEY(int key)
{
	return GetAsyncKeyState(key) & 0x8000;
}

void print_obj_name_del(OBJECT* obj);
short is_dead(OBJECT* obj);
clock_t punch_old, punch_curr;

void player_control()
{
	// ü�� 0�Ǹ� ���
	if(is_dead(&player))
	{
		print_obj_del(&player);
		if (KEY(LEFT))
			if (player.curr_x > 1)
			{
				player.curr_x--;
			}
		if (KEY(RIGHT))
			if (player.curr_x < SIZE_X - 2)
			{
				player.curr_x++;	
			}
		print_obj_upd(&player);
	}
	else
	{
		print_obj_del(&player);
		print_obj_upd(&player);

		if (GetAsyncKeyState(VK_RETURN) & 0x8000) // �����
			main();
	}
}
