#include <windows.h>
#include <stdio.h>

void removeCursor(void) //Ä¿¼­±ôºýÀÌ Á¦°Å
{

    CONSOLE_CURSOR_INFO curInfo;

    GetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &curInfo);

    curInfo.bVisible = 0;

    SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &curInfo);

}

void window_set()
{
	removeCursor();
    system("title ¹«±ÃÈ­ ²ÉÀÌ ÇÇ¾ú½À´Ï´Ù. Red Light, Green Light");
	system("mode concols=350 lines=22");
    for (int i = 1; i <= 22; i++)
    {
        for (int j = 1; j <= 22; j++)
        {
            printf(" ");
        }
        printf("\n");
    }
}