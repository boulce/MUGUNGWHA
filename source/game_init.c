#include "field_def.h"
#include "object_def.h"
#include <time.h>
#include <windows.h>


void field_set();
void object_set();
void player_control();

void print_field();
void print_obj_upd(OBJECT* obj);
void print_start_screen(int n);

void Update();

clock_t f_oldtime, f_curtime;
void FPSWait()
{
	while (1)
	{
		f_curtime = clock();
		if (f_curtime - f_oldtime > 40)
		{
			f_oldtime = clock();
			break;
		}
	}
}

extern short check_factor;
extern clock_t time_cnt_old;
extern int arr_i, time_rand_cnt;
clock_t start_cnt_old, start_cnt_curr;
int count;

void START_SCREEN()
{
	// 시작 화면
	while (1)
	{
		print_start_screen(0);

		if (GetAsyncKeyState(VK_RETURN) & 0x8000) // 시작
			break;
	}
	print_start_screen(1);
	start_cnt_old = clock();
	do
	{
		start_cnt_curr = clock();
		count = 5 - ((int)(start_cnt_curr - start_cnt_old) / 1000);
		print_start_screen(2);

	} while (count >= 0);
	print_start_screen(1);
}

void GAME_INIT()
{
	girl_state = MUGUNGHWA;
	check_factor = 0, arr_i = 0, time_rand_cnt = 0;

	srand(time(NULL));

	field_set();
	object_set();

	print_obj_upd(&player);
	print_field();

	START_SCREEN();

	f_oldtime = clock();
	time_cnt_old = clock();
	while (1)
	{
		Update();
		FPSWait();
	}
}