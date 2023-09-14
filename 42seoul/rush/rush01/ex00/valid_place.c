/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_place.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangmle2 <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/02 10:02:48 by sangmle2          #+#    #+#             */
/*   Updated: 2023/09/03 16:37:28 by sangmle2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
int vis_left(char solve_m[4][4], int row, int col, char check);
int vis_right(char solve_m[4][4], int row, int col, char check);
int vis_up(char solve_m[4][4], int row, int col, char check);
int vis_down(char solve_m[4][4], int row, int col, char chekc);

int	valid_place(char solve_m[4][4], int row, int col, char h, char matrix[4][4])
{
	int i;

	i = 0;
	while (i < 4)
	{
		if (solve_m[row][i] == h || solve_m[i][col] == h)
			return (0);
		i++;
	}
	if (!(vis_up(solve_m, row, col, matrix[0][row])) || !(vis_down(solve_m, row, col, matrix[1][row])))
		return (0);
	if (!(vis_left(solve_m, row, col, matrix[2][col])) || !(vis_right(solve_m, row, col, matrix[3][col])))
		return (0);
	return (1);
}

int	vis_left(char solve_m[4][4], int row, int col, char check)
{
    char vis;
	int i;

	i = 0;
	vis = '0';
    while (i < col)
	{
        if (solve_m[row][i] > vis)
		{
            vis = solve_m[row][i];
		}
		i++;
    }
	if (vis == check)
		return (1);
	else
		return (0);
}

int	vis_right(char solve_m[4][4], int row, int col, char check)
{
    char vis;
	int i;

	i = col + 1;
	vis = '0';
    while (i < 4)
	{
        if (solve_m[row][i] > vis)
		{
            vis = solve_m[row][i];
        }
		i++;
    }
	if (vis == check)
		return (1);
	else
		return (0);
}

int	vis_up(char solve_m[4][4], int row, int col, char check)
{
    char vis;
	int i;

	i = 0;
	vis = '0';
    while (i < row)
	{
        if (solve_m[i][col] > vis)
		{
            vis = solve_m[i][col];
        }
		i++;
    }
	if (vis == check)
		return (1);
	else
		return (0);
}

int	vis_down(char solve_m[4][4], int row, int col, char check)
{
    char vis;
	int i;

	i = row + 1;
	vis = '0';
    while (i < 4)
	{
        if (solve_m[i][col] > vis)
		{
            vis = solve_m[i][col];
        }
		i++;
    }
	if (vis == check)
		return (1);
	else
		return (0);
}
