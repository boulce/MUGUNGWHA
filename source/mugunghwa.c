#include "object_def.h"
#include <time.h>
#include <windows.h>
#include <stdio.h>

void print_girl_f();
void print_girl_b();
void print_mugunghwa();
void print_obj_del(OBJECT* obj);
void print_obj_upd(OBJECT* obj);

clock_t time_cnt_old, time_cnt_curr;
char* mugunghwa_arr[10] = { "무", "궁", "화", "꽃", "이", "피", "었", "습", "니", "다" };
int arr_i = 0, time_rand, time_rand_cnt = 0;

short check_factor;

extern int goal_x;
void mugunghwa();
void print_result(int n);
void f_bullet();
void gotoxy(int x, int y);
int correct_x(int x);
int main();

int attack_x, attack_y;
void mugunghwa_check()
{
    if (player.curr_x > goal_x) // 플레이어가 도착지점을 넘으면
    {
        check_factor = 1;
    }

    if (check_factor == 0)
        mugunghwa();
    else if (check_factor == 1) // 성공
    {
        print_result(0);

        if (GetAsyncKeyState(VK_RETURN) & 0x8000) // 재시작
            main();
    }
    else if (check_factor == 2) // 실패
    {
        print_obj_upd(&bullet);
        f_bullet();
    }
}

void mugunghwa()
{
    time_cnt_curr = clock();
	if (girl_state == MUGUNGHWA)
	{
		print_girl_b();
        gotoxy(correct_x(SIZE_X - 9) - 3, SIZE_Y - 19 + 4);

        if (time_rand_cnt == 0)// 한 글자마다 정해지는 랜덤 시간 
        {
            time_rand = 50 + rand() % 51;
            time_rand_cnt = 1;
        }

        if (time_cnt_curr - time_cnt_old <= time_rand)
        {
            print_mugunghwa(mugunghwa_arr[arr_i]);
        }
        else
        {
            if (arr_i == 9)
            {
                printf("  ");
                arr_i = 0; 
                time_rand = 3000 + rand() % 3001;
                
                attack_x = player.curr_x;
                girl_state = ATTACK;
            }
            else
            {
                arr_i++;
            }
            time_cnt_old = clock();
            time_rand_cnt = 0;
        }
	}
	else if (girl_state == ATTACK)
	{
		print_girl_f();

        if (attack_x != player.curr_x) // 술래가 뒤돌아볼 때 플레이어가 움직이면
        {
            check_factor = 2;
        }

        if (time_cnt_curr - time_cnt_old > time_rand)
        {
            time_cnt_old = clock();
            girl_state = MUGUNGHWA;
        }
	}
}

void f_bullet()
{
    if (bullet.curr_x >= 1)
    {
        print_obj_del(&bullet);
        bullet.curr_x--;
        print_obj_upd(&bullet);
    }
    else
    {
        print_obj_del(&bullet);
    }

    if (bullet.curr_x <= player.curr_x) // 총알이 플레이어에 닿으면
    {
        player.health = 0;
        print_result(1);
    }
}