#include <stdio.h>
#include <stdlib.h>
#include "input.h"
#include "corner.h"
#include "edge.h"
// [0: Blue, 1: White, 2: Red, 3: Yellow, 4: Orange, 5: Green]

int cube_check(int cor[24][3], int cor_comb[8][3], int edge[24][2], int edge_comb[12][2], int cube[24][4]);

int main(void)
{
	FILE* fptr;
	fptr = fopen("sols.txt","w");
	
	// Solved status of Cube
	int cube[24][4] = {
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

	int edge[24][2];
	int cor[24][3];
	
	// Pair of edges on the same piece
	int edge_comb[12][2] = {
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

	// Triplets of corners on the same piece
	int cor_comb[8][3] = {
					{0, 17, 4},
					{1, 13, 16},
					{2, 9, 12},
					{3, 5, 8},
					{6, 20, 11},
					{10, 21, 15},
					{14, 22, 19},
					{7, 18, 23},
				};

	int cor_status[24] = {0};
	int edge_status[24] = {0};
	char cor_sol[24];
	char edge_sol[24];
	int cor_sum = 0;
	int edge_sum = 0;
	int parity = 0;
	
	for (int i = 0; i < 24; i++)
	{
		cor_sol[i] = (char)0;
		edge_sol[i] = (char)0;
	}

	input(edge, cor);
	int t = cube_check(cor, cor_comb, edge, edge_comb, cube);

    switch(t)
	{
		case 0:
			printf("Valid Cube Configuration!\n");
			break;
		case 1:
			printf("Invalid Edge Configuration\n");
			return 1;
			break;
		case 2:
			printf("Invalid Corner Configuration\n");
			return 1;
			break;
		case 3:
			printf("Invalid Edge and Corner Configuration\n");
			return 1;
			break;
		}

	// printf("%d %d\n", edge[7][0], edge[7][1]);

	// Searching corners that are already solved
	for (int i = 0; i < 24; i++)
	{
		if(i != 0 && i != 17 && i != 4 && cor_status[i] == 0)
		{
			if (cube[i][0] == cor[i][0] && cube[i][1] == cor[i][1] && cube[i][2] == cor[i][2])
			{
				cor_sum = cor_done(i, cor_comb, cor_status);
			}
		}
	}

	int curr_cor[3] = {cor[0][0], cor[0][1], cor[0][2]};

	int cor_move_index = 0;
	int c;
	while(cor_sum < 20)
	{
		while(is_buffer_cor(curr_cor))
		{
			for (int i = 0; i < 24; i++)
			{
				if (cor_status[i] == 1)
					continue;

				if (curr_cor[0] == cube[i][0] && curr_cor[1] == cube[i][1] && curr_cor[2] == cube[i][2])
				{
					cor_sol[cor_move_index] = (char)(65 + i);
					cor_sum = cor_done(i, cor_comb, cor_status);
					cor_move_index++;
					curr_cor[0] = cor[i][0];
					curr_cor[1] = cor[i][1];
					curr_cor[2] = cor[i][2];
					break;
				}
			}
			if (cor_sum > 20)
			{
				break;
			}
		}

		// Cycle Break
		for (int i = 0; i < 24; i++)
		{
			// Finding an incomplete corner thats not the buffer
			if (cor_status[i] == 1 || i == 0 || i == 17 || i == 4)
				continue;

			// Finding where buffer is currently
			for (int j = 0; j < 24; j++)
			{
				if (cor[j][0] == curr_cor[0] && cor[j][1] == curr_cor[1] && cor[j][2] == curr_cor[2])
				{
					c = j;
					break;
				}
			}
			
			curr_cor[0] = cor[i][0];
			curr_cor[1] = cor[i][1];
			curr_cor[2] = cor[i][2];

			cor_swap(cor, c, i, cor_comb);

			cor_sol[cor_move_index] = (char)(65 + i);

			cor_move_index++;

			break;
		}


	}

	printf("Corners: \n");
	if (cor_move_index == 0) fprintf(fptr, "Z");

	for (int i = 0; i < cor_move_index; i++)
	{
		printf("%c ", cor_sol[i]);
		fprintf(fptr, "%c ", cor_sol[i]);
	}
	fprintf(fptr, "\n");
	printf("\n");

	if (cor_move_index % 2 == 1)
	{
		parity = 1;
		printf("Parity!\n");
	}




 	// Searching edges that are already solved
	for (int i = 0; i < 24; i++)
	{
		if(i != 20 && i != 10 && edge_status[i] == 0)
		{
			if (cube[i][0] == edge[i][0] && cube[i][1] == edge[i][1])
			{
				edge_sum = edge_done(i, edge_comb, edge_status);
			}
		}
	}


	int curr_edge[2] = {edge[20][0], edge[20][1]};

	int edge_move_index = 0;

	while(edge_sum < 21)
	{
		while(is_buffer_edge(curr_edge))
		{
			for (int i = 0; i < 24; i++)
			{
				if (edge_status[i] == 1)
					continue;


				if (curr_edge[0] == cube[i][0] && curr_edge[1] == cube[i][1])
				{
					// printf("     %d\n", i);
					// for (int j = 0; j < 24; j++)
					// {
					// 	printf("%d ", edge_status[j]);
					// }
					// printf("\n");
					edge_sol[edge_move_index] = edge_move(i, edge_move_index, parity);
					edge_sum = edge_done(i, edge_comb, edge_status);
					edge_move_index++;
					curr_edge[0] = edge[i][0];
					curr_edge[1] = edge[i][1];
					// printf("%d %d\n", curr_edge[0], curr_edge[1]);
					// printf("   %d %d\n", edge_status[18], edge_status[22]);
					// printf("%d\n", edge_sum);
					break;
				}
			}
			// printf("%d\n", edge_sum);
			// for (int i = 0; i < 24; i++)
			// {
			// 	printf("%c ", edge_sol[i]);
			// }
			// printf("\n");
			if (edge_sum > 21)
			{
				break;
			}
		}

		// printf("%d\n", edge_sum);
		// printf("Cycle Break!\n");
		// for (int i = 0; i < 24; i++)
		// {
		// 	printf("%c ", edge_sol[i]);
		// }
		// printf("\n");

		// Cycle Break
		for (int i = 0; i < 24; i++)
		{
			// Finding an incomplete edge thats not the buffer
			if (edge_status[i] == 1 || i == 10 || i == 20)
				continue;
			
			// Finding where buffer is currently
			for (int j = 0; j < 24; j++)
			{
				if (edge[j][0] == curr_edge[0] && edge[j][1] == curr_edge[1])
				{
					c = j;
					break;
				}
			}

			curr_edge[0] = edge[i][0];
			curr_edge[1] = edge[i][1];

			// printf("   %d %d\n   %d %d\n", edge[c][0], edge[c][1], edge[i][0], edge[i][1]);
			edge_swap(edge, c, i, edge_comb);
			// printf("   %d %d\n   %d %d\n", edge[c][0], edge[c][1], edge[i][0], edge[i][1]);

			edge_sol[edge_move_index] = edge_move(i, edge_move_index, parity);

			edge_move_index++;

			break;
		}

	}

	printf("Edges: \n");
	if (edge_move_index == 0) fprintf(fptr, "Z");
	for (int i = 0; i < edge_move_index; i++)
	{
		printf("%c ", edge_sol[i]);
		fprintf(fptr, "%c ", edge_sol[i]);
	}
	printf("\n");

	if (parity)
	{
		fprintf(fptr, "\nP");
	}
	fclose(fptr);
}


int cube_check(int cor[24][3], int cor_comb[8][3], int edge[24][2], int edge_comb[12][2], int cube[24][4])
{
	int cor_tally[24] = {0};
	for (int i = 0; i < 24; i++)
	{
		if (cor_tally[i] == 0)
		{
			for (int j = 0; j < 8; j++)
			{
				int f = 0;
				for (int k = 0; k < 3; k++)
				{
					if (cor[i][0] == cube[cor_comb[j][k]][0] && cor[i][1] == cube[cor_comb[j][k]][1]
						&& cor[i][2] == cube[cor_comb[j][k]][2])
					{
						f = 1;
						cor_tally[i] = 1;
						break;

					}
				}
				if (f == 1)
				{
					break;
				}
			}
		}
	}


	int cor_sum = 0;
	for (int i = 0; i < 24; i++)
	{
		cor_sum += cor_tally[i];
	}

	int edge_tally[24] = {0};
	for (int i = 0; i < 24; i++)
	{
		if (edge_tally[i] == 0)
		{
			for (int j = 0; j < 12; j++)
			{
				int f = 0;
				for (int k = 0; k < 2; k++)
				{
					if (edge[i][0] == cube[edge_comb[j][k]][0] && edge[i][1] == cube[edge_comb[j][k]][1])
					{
						f = 1;
						edge_tally[i] = 1;
						break;

					}
				}
				if (f == 1)
				{
					break;
				}
			}
		}
	}

	int edge_sum = 0;
	for (int i = 0; i < 24; i++)
	{
		edge_sum += edge_tally[i];
	}

    // printf("%d %d\n", edge_sum, cor_sum);

	if (edge_sum == 24 && cor_sum == 24)
	{
		return 0;
	}
	else if (edge_sum != 24 && cor_sum == 24)
	{
		return 1;
	}
	else if (edge_sum == 24 && cor_sum != 24)
	{
		return 2;
	}
	else if (edge_sum != 24 && cor_sum != 24)
	{
		return 3;
	}

}
