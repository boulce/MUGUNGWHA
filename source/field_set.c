#define _CRT_SECURE_NO_WARNINGS
#include <string.h>
#include "field_def.h"

void field_set()
{
	start_field.name = "시작 필드";

	for (int i = 0; i < SIZE_Y; i++)
	{
		for (int j = 0; j < SIZE_X; j++)
		{
			if (i != 0 && i != SIZE_Y - 1 && j != 0 && j != SIZE_X - 1)
			{
				start_field.data_arr[i][j] = EMPTY;
			}
			else
			{
				if (i == 0 && j == 0)
					start_field.data_arr[i][j] = WALL_LT;
				else if (i == 0 && j == SIZE_X - 1)
					start_field.data_arr[i][j] = WALL_RT;
				else if (i == SIZE_Y - 1 && j == 0)
					start_field.data_arr[i][j] = WALL_LB;
				else if (i == SIZE_Y - 1 && j == SIZE_X - 1)
					start_field.data_arr[i][j] = WALL_RB;
				else if (i == 0 || i == SIZE_Y-1)
					start_field.data_arr[i][j] = WALL_H;
				else
					start_field.data_arr[i][j] = WALL_V;
			}
		}
	}
}