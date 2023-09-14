/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithms.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donson <donson@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 23:29:25 by donson            #+#    #+#             */
/*   Updated: 2023/09/13 22:35:45 by donson           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include "tool.h"

int	check(char	**map, int	*size, char	*characters)
{
	int	i;
	int	j;
	int line;

	j = 0;
	if (characters[0] == characters[1] ||
		characters[1] == characters[2] ||
		characters[0] == characters[2])
		return (0);
	while (j < size[0])
	{
		i = 0;
		line = f_strlen(map[i]);
		if (line != size[1])
			return (0);
		while (i < line)
		{
			if (map[j][i] == characters[0]
			|| map[j][i] == characters[1])
			{
				i++;
				continue;
			}
			else
				return (0);
		}
		j++;
	}
	return (1);
}

int	*find_largest_square(int row, int col, int **m)
{
	int	*result;
	int	i;
	int	j;

	i = 0;
	result = (int *)malloc(sizeof(int) * 3);
	while (++i < row)
	{
		j = 0;
		while (++j < col)
		{
			if (m[i][j] != 0 && m[i][j - 1] >= m[i][j]
				&& m[i - 1][j] >= m[i][j] && m[i - 1][j - 1] >= m[i][j])
			{
				m[i][j] = min(m[i][j - 1], m[i - 1][j], m[i - 1][j - 1]) + 1;
				if (m[i][j] > result[2])
				{
					result[0] = i;
					result[1] = j;
					result[2] = m[i][j];
				}
			}
		}
	}
	return (result);
}

void	print_map(char **map, int result[3], int size[2], char fill)
{
	int	i;
	int	j;

	i = 0;
	while (i < size[0])
	{
		j = 0;
		while (j < size[1])
		{
			if (i <= result[0] && i + result[2] > result[0]
				&& j <= result[1] && j + result[2] > result[1])
				write(1, &fill, 1);
			else
				write(1, &map[i][j], 1);
			j++;
		}
		write(1, "\n", 1);
		i++;
	}
}

void	print_map_one_one(char **map, char characters[3])
{
	if (map[0][0] == characters[0])
		write(1, &characters[2], 1);
	else
		write(1, &map[0][0], 1);
	write(1, "\n", 1);
}

void	print_map_one(char **map, int size[2], char characters[3])
{
	int	i;
	int	j;
	int tag;

	i = 0;
	tag = 1;
	while (i < size[0])
	{
		j = 0;
		while (j < size[1])
		{
			if (tag && map[i][j] == characters[0])
			{
				write(1, &characters[2], 1);
				tag = 0;
			}
			else
				write(1, &map[i][j], 1);
			j++;
		}
		write(1, "\n", 1);
		i++;
	}
}

int	**convert_map(char **map, char characters[3], int size[2])
{
	int	i;
	int	j;
	int	**num_map;

	i = 0;
	num_map = (int **)malloc(size[0] * sizeof(int *));
	while (i < size[0])
	{
		j = 0;
		num_map[i] = (int *)malloc(size[1] * sizeof(int));
		while (j < size[1])
		{
			if (map[i][j] == characters[0])
				num_map[i][j] = 1;
			if (map[i][j] == characters[1])
				num_map[i][j] = 0;
			j++;
		}
		i++;
	}
	return (num_map);
}
