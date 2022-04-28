#include "object_def.h"
#include <windows.h>

#define RED 4
#define WHITE 15

void setColor(int color)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}

short is_dead(OBJECT* obj);

void graphic_del(OBJECT* obj)
{
	switch (obj->obj_type)
	{
		case PLAYER:
            gotoxy(correct_x(obj->curr_x), obj->curr_y);
            printf("  ");

            gotoxy(correct_x(obj->curr_x), obj->curr_y + 1);
            printf("  ");

            gotoxy(correct_x(obj->curr_x), obj->curr_y + 2);
            printf("  ");

            gotoxy(correct_x(obj->curr_x - 1), obj->curr_y + 1);
            printf("  ");
            gotoxy(correct_x(obj->curr_x + 1), obj->curr_y + 1);
            printf("  ");
			break;
		case ENEMY:
			break;
		case NPC:
			break;
        case BULLET:
            gotoxy(correct_x(obj->curr_x), obj->curr_y);
            printf("    ");
            break;
	}
}

void punchColor()
{
	setColor(RED);
	printf("¡Ü");
	setColor(WHITE);
}

void graphic_upd(OBJECT* obj)
{
    switch (obj->obj_type)
    {
        case PLAYER:
            /*
            (-1,-1)(0,-1)(1,-1)
              (-1,0)(0,0)(1,0)
      (-3, 1)(-2,1)(-1,1)(0,1)(1,1)(2,1)(3,1)
              (-1,2)(0,2)(1,2)
              (-1,3)
            */
            if (is_dead(&player))
            {
                gotoxy(correct_x(obj->curr_x), obj->curr_y);
                printf("¡Û");

                gotoxy(correct_x(obj->curr_x), obj->curr_y + 1);
                printf("¦«");

                gotoxy(correct_x(obj->curr_x), obj->curr_y + 2);
                printf("¥Ø");

                gotoxy(correct_x(obj->curr_x - 1), obj->curr_y + 1);
                printf("¦£");
                gotoxy(correct_x(obj->curr_x + 1), obj->curr_y + 1);
                printf("¦¤");
            }
            else
            {
                gotoxy(correct_x(obj->curr_x - 2), obj->curr_y + 2);
                printf("¡Û");
                gotoxy(correct_x(obj->curr_x - 1), obj->curr_y + 2);
                printf("¦«");
                gotoxy(correct_x(obj->curr_x), obj->curr_y + 2);
                printf("<");
            }
            break;

        case ENEMY:
            break;
        case NPC:
            break;
        case BULLET:
            gotoxy(correct_x(obj->curr_x), obj->curr_y);
            printf("¡¤=");
            break;
    }
}