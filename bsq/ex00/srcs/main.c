/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donson <donson@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 20:40:29 by donson            #+#    #+#             */
/*   Updated: 2023/09/13 21:16:50 by donson           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h> // de
#include <stdlib.h>
#include <unistd.h> // de
#include "algorithms.h"
#include "standard_input.h"
#include "parse.h"

int	argc1()
{
	int		size[2];//i, j
	char	characters[3];//empty, ob, fill
	char	**map;
	int		**num;
	int		*result;
	
	if (!arg1(&map, size, characters))
		return (0);
	if (!check(map, size, characters))
	{
		for (int i = 0; i < size[0]; i++)
		{
			free(map[i]);
			map[i] = NULL;
		}
		free(map);
		map = NULL;
		return (0);
	}
	num = convert_map(map, characters, size);
	if (size[0] == 1 && size[1] == 1)
	{
		print_map_one_one(map, characters);
		free(map[0]);
		free(num[0]);
		free(map);
		free(num);
		return (1);
	}
	if (size[0] == 1)
	{
		print_map_one(map, size, characters);
		free(map[0]);
		free(map);
		free(num[0]);
		free(num);
		return (1);
	}
	if (size[1] == 1)
	{
		print_map_one(map, size, characters);
		for (int i = 0; i < size[0]; i++)
			free(map[i]);
		free(map);
		for (int i = 0; i < size[0]; i++)
			free(num[i]);
		free(num);
		return (1);
	}
	result = find_largest_square(size[0], size[1], num);
	print_map(map, result, size, characters[2]);
	for (int i = 0; i < size[0]; i++)
			free(map[i]);
	free(map);
	for (int i = 0; i < size[0]; i++)
		free(num[i]);
	free(num);
	free(result);
	return (1);
}

int	argc2(char* argv[], int i)
{
	int		size[2];//i, j
	char	characters[3];//empty, ob, fill
	char	**map;
	int		**num;
	int		*result;

	map = parse(argv[i], size, characters);
	if (map == 0)
		return (0);
	if (!check(map, size, characters))
	{
		for (int i = 0; i < size[0]; i++)
		{
			free(map[i]);
			map[i] = NULL;
		}
		free(map);
		map = NULL;
		return (0);
	}
	num = convert_map(map, characters, size);
	if (size[0] == 1 && size[1] == 1)
	{
		print_map_one_one(map, characters);
		free(map[0]);
		free(num[0]);
		free(map);
		free(num);
		return (1);
	}
	if (size[0] == 1)
	{
		print_map_one(map, size, characters);
		free(map[0]);
		free(map);
		free(num[0]);
		free(num);
		return (1);
	}
	if (size[1] == 1)
	{
		print_map_one(map, size, characters);
		for (int i = 0; i < size[0]; i++)
			free(map[i]);
		free(map);
		for (int i = 0; i < size[0]; i++)
			free(num[i]);
		free(num);
		return (1);
	}
	result = find_largest_square(size[0], size[1], num);
	print_map(map, result, size, characters[2]);
	for (int i = 0; i < size[0]; i++)
			free(map[i]);
	free(map);
	for (int i = 0; i < size[0]; i++)
			free(num[i]);
	free(num);
	free(result);
	return (1);
}

int main(int argc, char *argv[])
{
	int		i;

	if (argc == 1)
	{
		if (!argc1())
			write(1, "map error\n", 10);
	}
	else if (argc >= 2)
	{
		i = 1;
		while (i < argc)
		{
			if (!argc2(argv, i))
				write(1, "map error\n", 10);
			if (i != argc - 1)
				write(1, "\n", 1);
			i++;
		}
	}
	system("leaks bsq");
	return (0);
}

