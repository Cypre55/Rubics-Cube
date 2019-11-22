#include <stdio.h>
#include "lib.h"

void checkcor(int a, int cor[][3], int cube1[][4], int arr[][2], int d);

int main(void)
{
	int cube1[24][4];
	int cube2[24][4];
	int edge[24][2];
	int cor[24][3];
	int fcor[24][2];
	for (int i = 0; i < 24; i++)
	{
		for (int j = 0; j < 2; j++)
		{
			fcor[i][j] = -1;
		}
	}
	cub(cube1, cube2);
	input(edge, cor);
	int n = 0;
	for (int i = 0; i < 24; i++)
	{
		if (i == 0)
		{
			checkcor(i, cor, cube1, fcor, i);
		}
		else
		{
			checkcor(fcor[i - 1][0], cor, cube1, fcor, i);
		}
	}
	for (int i = 0; i < 24; i++)
	{
		if (fcor[i][0] != -1)
		{
			printf("%i %c\n", fcor[i][0], fcor[i][1]);
		}
	}



}

void checkcor(int a, int cor[][3], int cube1[][4], int arr[][2], int d)
{
	int k = 0;
	for (int i = 0; i < 24; i++)
	{
		if (cube1[i][0] == cor[a][0] && cube1[i][1] == cor[a][1] && cube1[i][2] == cor[a][2])
		{
			if (i != 0 && i != 17 && i != 4)
			{
				arr[d][0] = i;
				arr[d][1] = cube1[i][3];
				cube1[i][0] = 7;
				cube1[i][2] = 7;
				break;
			}
			else
			{
				while (arr[d][0] == -1 && arr[d][1] == -1)
				{
					if  (cube1[k][0] != 7 && cube1[k][1] != 7 && cube1[k][2] != 7 && k != 0 && k!= 17 && k != 4)
					{
						arr[d][0] = cube1[k][0];
						arr[d][1] = cube1[k][3];
						break;
					}
					k++;
				}
			}
		}

	}
}