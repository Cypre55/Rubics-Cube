#include <stdio.h>

void cub(int arr[][4], int arr2[][4])
{
			 /*arr[24][4]={
			    		{0, 4, 1, 'A'},
			    		{0, 3, 4, 'B'}, 
			    		{0, 2, 3, 'C'}, 
			    		{0, 1, 2, 'D'}, 
						{1, 0, 4, 'E'},
						{1, 2, 0, 'F'},
						{1, 5, 2, 'G'},
						{1, 4, 5, 'H'},
						{2, 0, 1, 'I'},
						{2, 3, 0, 'J'},
						{2, 5, 3, 'K'},
						{2, 1, 5, 'L'},
						{3, 0, 2, 'M'},
						{3, 4, 0, 'N'},
						{3, 5, 4, 'O'},
						{3, 2, 5, 'P'},
						{4, 0, 3, 'Q'},
						{4, 1, 0, 'R'},
						{4, 5, 1, 'S'},
						{4, 3, 5, 'T'},
						{5, 2, 1, 'U'},
						{5, 3, 2, 'V'},
						{5, 4, 3, 'W'},
						{5, 1, 4, 'X'},
					};	*/
	for(int i = 0; i < 24; i++)
	{
		arr[i][3] = 65 + i;
		if (i < 4)
		{
			arr[i][0] = 0;
			int a = 1,b = 2,c = 3,d = 4;
			if (i%4 == 0)
			{
				arr[i][1] = d;
				arr[i][2] = a;
			}
			else if (i%4 == 1)
			{
				arr[i][1] = c;
				arr[i][2] = d;
			}
			else if (i%4 == 2)
			{
				arr[i][1] = b;
				arr[i][2] = c;
			}
			else if (i%4 == 3)
			{
				arr[i][1] = a;
				arr[i][2] = b;
			}
		}
		else if (i < 8)
		{
			arr[i][0] = 1;
			int a = 4,b = 5,c = 2,d = 0;
			if (i%4 == 0)
			{
				arr[i][1] = d;
				arr[i][2] = a;
			}
			else if (i%4 == 1)
			{
				arr[i][1] = c;
				arr[i][2] = d;
			}
			else if (i%4 == 2)
			{
				arr[i][1] = b;
				arr[i][2] = c;
			}
			else if (i%4 == 3)
			{
				arr[i][1] = a;
				arr[i][2] = b;
			}
		}
		else if (i < 12)
		{
			arr[i][0] = 2;
			int a = 1, b = 5, c = 3, d = 0;
			if (i%4 == 0)
			{
				arr[i][1] = d;
				arr[i][2] = a;
			}
			else if (i%4 == 1)
			{
				arr[i][1] = c;
				arr[i][2] = d;
			}
			else if (i%4 == 2)
			{
				arr[i][1] = b;
				arr[i][2] = c;
			}
			else if (i%4 == 3)
			{
				arr[i][1] = a;
				arr[i][2] = b;
			}
		}
		else if (i < 16)
		{
			arr[i][0] = 3;
			int a = 2, b = 5, c = 4, d = 0;
			if (i%4 == 0)
			{
				arr[i][1] = d;
				arr[i][2] = a;
			}
			else if (i%4 == 1)
			{
				arr[i][1] = c;
				arr[i][2] = d;
			}
			else if (i%4 == 2)
			{
				arr[i][1] = b;
				arr[i][2] = c;
			}
			else if (i%4 == 3)
			{
				arr[i][1] = a;
				arr[i][2] = b;
			}
		}
		else if (i < 20)
		{
			arr[i][0] = 4;
			int a = 3, b = 5, c = 1, d = 0;
			if (i%4 == 0)
			{
				arr[i][1] = d;
				arr[i][2] = a;
			}
			else if (i%4 == 1)
			{
				arr[i][1] = c;
				arr[i][2] = d;
			}
			else if (i%4 == 2)
			{
				arr[i][1] = b;
				arr[i][2] = c;
			}
			else if (i%4 == 3)
			{
				arr[i][1] = a;
				arr[i][2] = b;
			}
		}
		else if (i < 24)
		{
			arr[i][0] = 5;
			int a = 1, b = 4, c = 3, d = 2;
			if (i%4 == 0)
			{
				arr[i][1] = d;
				arr[i][2] = a;
			}
			else if (i%4 == 1)
			{
				arr[i][1] = c;
				arr[i][2] = d;
			}
			else if (i%4 == 2)
			{
				arr[i][1] = b;
				arr[i][2] = c;
			}
			else if (i%4 == 3)
			{
				arr[i][1] = a;
				arr[i][2] = b;
			}
		}
	}
	for (int i = 0; i <24; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			arr2[i][j] = arr[i][j];
		}
	}			
	
}
