/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donson <donson@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 20:40:29 by donson            #+#    #+#             */
/*   Updated: 2023/09/14 00:18:51 by sangmle2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h> // de
#include <stdlib.h>
#include <unistd.h> // de
#include "algorithms.h"
#include "standard_input.h"
#include "parse.h"
#include "free_tool.h"

int free_two_while_res(char **a, int **b, int size, int *result)
{
	int i;

	i = 0;
	while (i < size)
	{
		free(a[i]);
		i++;
	}
	free(a);
	while (i < size)
	{
		free(b[i]);
		i++;
	}
	free(b);
	free(result);
	return (1);
}

int	argc1(void)
{
	int		size[2];
	char	characters[3];
	char	**map;
	int		**num;
	int		*result;

	if (!arg1(&map, size, characters))
		return (0);
	if (!check(map, size, characters) && free_while(map, size[0]))
		return (0);
	num = convert_map(map, characters, size);
	if (size[0] == 1 && size[1] == 1)
	{
		print_map_one_one(map, characters);
		free_four(map[0], num[0], map, num);
		return (1);
	}
	if (size[0] == 1)
	{
		print_map_one(map, size, characters);
		free_four(map[0], num[0], map, num);
		return (1);
	}
	if (size[1] == 1)
	{
		print_map_one(map, size, characters);
		free_two_while(map, num, size[0]);
		return (1);
	}
	result = find_largest_square(size[0], size[1], num);
	print_map(map, result, size, characters[2]);
	free_two_while_res(map, num, size[0], result);
	return (1);
}

int	argc2(char *argv[], int i)
{
	int		size[2];
	char	characters[3];
	char	**map;
	int		**num;
	int		*result;

	map = parse(argv[i], size, characters);
	if (map == 0)
		return (0);
	if (!check(map, size, characters) && free_while(map, size[0]))
		return (0);
	num = convert_map(map, characters, size);
	if (size[0] == 1 || size[1] == 1)
	{
		if (size[0] == 1 && size[1] ==1)
			print_map_one_one(map, characters);
		else
			print_map_one(map, size, characters);
		free_two_while(map, num, size[0]);
		return (1);
	}
	result = find_largest_square(size[0], size[1], num);
	print_map(map, result, size, characters[2]);
	free_two_while_res(map, num, size[0], result);
	return (1);
}

int	main(int argc, char *argv[])
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
