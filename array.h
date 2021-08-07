#ifndef ARRAY_H
#define ARRAY_H

#include <stdio.h>
// [0: Blue, 1: White, 2: Red, 3: Yellow, 4: Orange, 5: Green]

// Solved state of cube
void cube(int arr[][4], int arr2[][4])
{
	arr[24][4] = {
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
	};
	for (int i = 0; i < 24; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			arr2[i][j] = arr[i][j];
		}
	}
}

// Gives all the 8 triplets of corner faces
void triplets(int arr[8][3])
{
	arr[8][3] = {
		{0, 17, 4},
		{1, 13, 16},
		{2, 9, 12},
		{3, 5, 8},
		{6, 20, 11},
		{10, 21, 15},
		{14, 22, 19},
		{7, 18, 23},
	};
}

// Gives all the 12 pair of edge faces
void pairs(int arr[12][2])
{
	arr[12][2] = {
		{0, 16},
		{1, 12},
		{2, 8},
		{3, 4},
		{5, 11},
		{9, 15},
		{13, 19},
		{7, 17},
		{10, 20},
		{14, 21},
		{18, 22},
		{6, 23},
	};
}

#endif