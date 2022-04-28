#include "object_def.h"
#include "field_def.h"

extern int goal_x;
void object_set()
{
	// 플레이어 초기화
	player.name = "456"; // 플레이어나 몬스터 이름은 영어로 지어야할 것. 그래야 지우기 편함
	player.health = 100;
	player.curr_field = &start_field;
	player.curr_x = 1;
	player.curr_y = SIZE_Y-4;
	player.obj_type = PLAYER;
	player.obj_ld = W;
	player.p_state = DEFAULT;

	//총알 초기화
	bullet.name = "bullet";
	bullet.curr_field = &start_field;
	bullet.curr_x = goal_x+1;
	bullet.curr_y = SIZE_Y-3;
	bullet.obj_type = BULLET;
}

short is_dead(OBJECT* obj)
{
	if (obj->health > 0)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}