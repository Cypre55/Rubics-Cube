#ifndef CORNER_H
#define CORNER_H

int is_buffer_cor(int curr_cor[3])
{
	if (curr_cor[0] == 0 && curr_cor[1] == 4 && curr_cor[2] == 1)
		return 0;
	else if (curr_cor[0] == 1 && curr_cor[1] == 0 && curr_cor[2] == 4)
		return 0;
	else if (curr_cor[0] == 4 && curr_cor[1] == 1 && curr_cor[2] == 0)
		return 0;
	else
		return 1;
}

// Marks the corner at ith place is solved
// Returns number of solved corners
int cor_done(int i, int cor_comb[8][3], int cor_status[24])
{
	if (i != 0 && i != 4 && i != 17)
	{
		int f = 0;
		for (int j = 0; j < 8; j++)
		{
			for (int k = 0; k < 3; k++)
			{
				if (cor_comb[j][k] == i)
				{
					for (int l = 0; l < 3; l++)
					{
						cor_status[cor_comb[j][l]] = 1;
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
		sum += cor_status[i];
	}
	return sum;
}

// Used when Cycle is broken, to modify the actual cube
void cor_swap(int cor[24][3], int a, int b, int cor_comb[8][3])
{
	int x[3], y[3];
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			if (cor_comb[i][j] == a)
			{
				x[0] = a;
				x[1] = cor_comb[i][(j + 1) % 3];
				x[2] = cor_comb[i][(j + 2) % 3];
			}

			if (cor_comb[i][j] == b)
			{
				y[0] = b;
				y[1] = cor_comb[i][(j + 1) % 3];
				y[2] = cor_comb[i][(j + 2) % 3];
			}
		}
	}

	for (int i = 0; i < 3; i++)
	{
		int t;

		for (int j = 0; j < 3; j++)
		{
			t = cor[x[i]][j];
			cor[x[i]][j] = cor[y[i]][j];
			cor[y[i]][j] = t;
		}
	}
}
#endif