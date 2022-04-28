#include <stdio.h>
#include <windows.h>
#include "field_def.h"
#include "object_def.h"

#define INTERFACE_X (SIZE_X + 55)
#define INTERFACE_Y 30

#define GAP 2

#define R_INTERFACE_X 50
#define R_INTERFACE_Y 3

char* str_girl_f[18] =
{
"     ／￣￣＼\n",
"    ｜//////｜\n",
"  ●｜￣￣￣｜●\n",
"／  ｜○  ○｜  ＼\n",
"     ＼└─┘ ／\n",
"       ￣￣\n",
"   ／￣￣￣￣＼\n",
"  ｜ ｜    ｜ ｜\n",
"  ｜ ｜    ｜ ｜\n",
"  ｜ ｜    ｜ ｜\n",
"   ￣￣￣￣￣￣\n",
"    ／      ＼\n",
"   ｜        ｜\n",
"   ｜        ｜\n",
"    ￣￣￣￣￣\n",
"     ｜｜｜｜\n",
"     ｜｜｜｜\n",
"      ￣  ￣"
};

char* str_girl_b[18] =
{
"     ／￣￣＼\n",
"    ｜//////｜\n",
"  ●｜//////｜●\n",
"／  ｜//////｜  ＼\n",
"     ＼////／\n",
"       ￣￣\n",
"   ／￣￣￣￣＼\n",
"  ｜ ｜    ｜ ｜\n",
"  ｜ ｜    ｜ ｜\n",
"  ｜ ｜    ｜ ｜\n",
"   ￣￣￣￣￣￣\n",
"    ／      ＼\n",
"   ｜        ｜\n",
"   ｜        ｜\n",
"    ￣￣￣￣￣\n",
"     ｜｜｜｜\n",
"     ｜｜｜｜\n",
"      ￣  ￣"
};

void gotoxy(int x, int y)
{
        COORD pos = { x + GAP, y + GAP };
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

int correct_x(int x)
{
    return x * 2;
}

void print_obj_name_del(OBJECT* obj)
{
    gotoxy(correct_x(obj->curr_x)-1, obj->curr_y - 1);
    for(int i = 0; i < sizeof(obj->name); i++)
        printf("  "); //문자 바이트 고려해야할 듯
}

void print_obj_name_upd(OBJECT* obj)
{
    gotoxy(correct_x(obj->curr_x)-1, obj->curr_y - 1);
    printf("%s", obj->name); //문자 바이트 고려해야할 듯
}

void graphic_del(OBJECT* obj);
void graphic_upd(OBJECT* obj);

void print_obj_del(OBJECT* obj)
{
    //오브젝트 그래픽
    graphic_del(obj);
    print_obj_name_del(obj);
}

void print_obj_upd(OBJECT* obj)
{
    //오브젝트 그래픽
    graphic_upd(obj);
    print_obj_name_upd(obj);
}

#define RED 4
#define WHITE 15

void setColor();
int goal_x = SIZE_X - 12;
void print_field()
{
    // 필드 출력
    gotoxy(0, SIZE_Y - 1);
    for (int j = 0; j < SIZE_X; j++)
    {
        if (j == goal_x)
            setColor(RED);
        printf("▒▒");
        if (j == goal_x)
            setColor(WHITE);
    }
}

void print_girl_f()
{
    for (int i = 0; i < 18; i++)
    {
        gotoxy(correct_x(SIZE_X-9), SIZE_Y - 19 + i);
        printf("%s\n", str_girl_f[i]);
    }
}

void print_girl_b()
{
    for (int i = 0; i < 18; i++)
    {
        gotoxy(correct_x(SIZE_X - 9), SIZE_Y - 19 + i);
        printf("%s\n", str_girl_b[i]);
    }
}

void print_mugunghwa(char* str)
{
    gotoxy(correct_x(SIZE_X - 9) - 3, SIZE_Y - 19 + 4);
    printf("%s", str);
}

int main();

extern int count;
void print_start_screen(int n) // 0 출력, 1 삭제, 2 카운트 다운
{
    if (n == 0)
    {
        gotoxy(R_INTERFACE_X, R_INTERFACE_Y);
        printf("※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※");
        gotoxy(R_INTERFACE_X, R_INTERFACE_Y + 2);
        printf("                   무궁화 꽃이 피었습니다");
        gotoxy(R_INTERFACE_X, R_INTERFACE_Y + 4);
        printf("                            START?");
        gotoxy(R_INTERFACE_X, R_INTERFACE_Y + 5);
        printf("                       PRESS << ENTER >>");
        gotoxy(R_INTERFACE_X, R_INTERFACE_Y + 7);
        printf("※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※");
    }
    else if (n == 1)
    {
        gotoxy(R_INTERFACE_X, R_INTERFACE_Y);
        printf("                                                            ");
        gotoxy(R_INTERFACE_X, R_INTERFACE_Y + 2);
        printf("                                         ");
        gotoxy(R_INTERFACE_X, R_INTERFACE_Y + 4);
        printf("                                  ");
        gotoxy(R_INTERFACE_X, R_INTERFACE_Y + 5);
        printf("                                        ");
        gotoxy(R_INTERFACE_X, R_INTERFACE_Y + 7);
        printf("                                                            ");
    }
    else if (n == 2)
    {
        gotoxy(R_INTERFACE_X, R_INTERFACE_Y);
        printf("※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※");
        gotoxy(R_INTERFACE_X, R_INTERFACE_Y + 2);
        printf("                   무궁화 꽃이 피었습니다");
        gotoxy(R_INTERFACE_X, R_INTERFACE_Y + 4);
        printf("                             COUNT");
        gotoxy(R_INTERFACE_X, R_INTERFACE_Y + 5);
        printf("                               %d", count);
        gotoxy(R_INTERFACE_X, R_INTERFACE_Y + 7);
        printf("※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※");
    }
}

void print_result(short n) // 0 성공, 1 게임 오버
{
    if (n == 0)
    {
        gotoxy(R_INTERFACE_X, R_INTERFACE_Y);
        printf("※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※");
        gotoxy(R_INTERFACE_X, R_INTERFACE_Y + 2);
        printf("                           SUCCEED!");
        gotoxy(R_INTERFACE_X, R_INTERFACE_Y + 4);
        printf("                            RETRY?");
        gotoxy(R_INTERFACE_X, R_INTERFACE_Y + 5);
        printf("                       PRESS << ENTER >>");
        gotoxy(R_INTERFACE_X, R_INTERFACE_Y + 7);
        printf("※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※");
    }
    else if (n == 1)
    {
        gotoxy(R_INTERFACE_X, R_INTERFACE_Y);
        printf("※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※");
        gotoxy(R_INTERFACE_X, R_INTERFACE_Y + 2);
        printf("                            FAILED");
        gotoxy(R_INTERFACE_X, R_INTERFACE_Y + 4);
        printf("                            RETRY?");
        gotoxy(R_INTERFACE_X, R_INTERFACE_Y + 5);
        printf("                       PRESS << ENTER >>");
        gotoxy(R_INTERFACE_X, R_INTERFACE_Y + 7);
        printf("※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※");
    }
}