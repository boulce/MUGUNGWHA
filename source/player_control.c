#include <windows.h>
#include <time.h>
#include "object_def.h"
#include "field_def.h"

/*
    방향키 값
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
	// 체력 0되면 사망
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

		if (GetAsyncKeyState(VK_RETURN) & 0x8000) // 재시작
			main();
	}
}
