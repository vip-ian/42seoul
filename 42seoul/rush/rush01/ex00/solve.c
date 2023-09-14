/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangmle2 <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/01 23:13:31 by sangmle2          #+#    #+#             */
/*   Updated: 2023/09/03 16:33:29 by sangmle2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>

int		complete(char solve_m[4][4]);
void	find_empty(char solve_m[4][4], int *row, int *col);
int		valid_place(char solve_m[4][4], int row, int col, int h, char matrix[4][4]);

int	solve(char matrix[4][4], char solve_m[4][4])
{
	int row;
	int col;
	char h;

	if (complete(solve_m))
	{
		return (1);
	}

	find_empty(solve_m, &row, &col);
	h = '1';
	while (h <= '4')
	{
		if (valid_place(solve_m, row, col, h, matrix))
		{
			solve_m[row][col] = h;
			if (solve(matrix, solve_m))
			{
				return (1);
			}
			solve_m[row][col] = 0;
		}
		h++;
	}
	return (0);
}

int	complete(char solve_m[4][4])
{
	int i;
	int j;

	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			if (solve_m[i][j] == '0')
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

void	find_empty(char solve_m[4][4], int *row, int *col)
{
	int	i;
	int	j;

	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			if (solve_m[i][j] == '0')
			{
				*row = i;
				*col = j;
				return ;
			}
			j++;
		}
		i++;
	}
}
