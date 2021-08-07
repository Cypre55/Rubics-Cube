#ifndef EDGE_H
#define EDGE_H

#include <stdio.h>

int is_buffer_edge(int curr_edge[2])
{
	if (curr_edge[0] == 2 && curr_edge[1] == 5)
		return 0;
	else if (curr_edge[0] == 5 && curr_edge[1] == 2)
		return 0;
	else
		return 1;
}

// Marks the corner at ith place is solved
// returns number of edges complete
int edge_done(int i, int edge_comb[12][2], int edge_status[24])
{
	if (i != 20 && i != 10 )
	{
		int f = 0;
		for (int j = 0; j < 12; j++)
		{
			for (int k = 0; k < 2; k++)
			{
				if (edge_comb[j][k] == i)
				{
					for (int l = 0; l < 2; l++)
					{
						edge_status[edge_comb[j][l]] = 1;
					}
					f = 1;
					break;
				}
			}
			if (f == 1)
				break;
		}
	}

	int sum = 0;
	for (int i = 0; i < 24; i++)
	{
		sum += edge_status[i];
	}
	return sum;
}

// Used when Cycle is broken, to modify the actual cube
void edge_swap(int edge[24][2], int a, int b, int edge_comb[12][2])
{
	int x[2], y[2];
	for (int i = 0; i < 12; i++)
	{
		for (int j = 0; j < 2; j++)
		{
			if (edge_comb[i][j] == a)
			{
				x[0] = a;
				x[1] = edge_comb[i][(j + 1) % 2];
			}

			if (edge_comb[i][j] == b)
			{
				y[0] = b;
				y[1] = edge_comb[i][(j + 1) % 2];
			}
		}
	}

	for (int i = 0; i < 2; i++)
	{
		int t;

		for (int j = 0; j < 2; j++)
		{
			t = edge[x[i]][j];
			edge[x[i]][j] = edge[y[i]][j];
			edge[y[i]][j] = t;
		}
	}
}

// Handles I C W S swapping on even moves
char edge_move(int i, int n, int parity)
{
	int t = i;


	if (n % 2 == 0)
	{
		if (parity == 0)
			return (char)(65 + t);
		else 
			return (char)(97 + t); 
	}
	else
	{
		if (i == 2)
		{
			t = 22;
		}
		else if (i == 22)
		{
			t = 2;
		}
		else if (i == 8)
		{
			t = 18;
		}
		else if (i == 18)
		{
			t = 8;
		}
		if (parity == 1)
			return (char)(65 + t);
		else 
			return (char)(97 + t);
	}
}
#endif