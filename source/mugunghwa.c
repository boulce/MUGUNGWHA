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
char* mugunghwa_arr[10] = { "��", "��", "ȭ", "��", "��", "��", "��", "��", "��", "��" };
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
    if (player.curr_x > goal_x) // �÷��̾ ���������� ������
    {
        check_factor = 1;
    }

    if (check_factor == 0)
        mugunghwa();
    else if (check_factor == 1) // ����
    {
        print_result(0);

        if (GetAsyncKeyState(VK_RETURN) & 0x8000) // �����
            main();
    }
    else if (check_factor == 2) // ����
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

        if (time_rand_cnt == 0)// �� ���ڸ��� �������� ���� �ð� 
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

        if (attack_x != player.curr_x) // ������ �ڵ��ƺ� �� �÷��̾ �����̸�
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

    if (bullet.curr_x <= player.curr_x) // �Ѿ��� �÷��̾ ������
    {
        player.health = 0;
        print_result(1);
    }
}