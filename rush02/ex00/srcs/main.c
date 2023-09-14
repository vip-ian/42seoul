/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangmle2 <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/09 10:19:56 by sangmle2          #+#    #+#             */
/*   Updated: 2023/09/10 15:46:54 by sangmle2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "change.h"
#include "ft_func.h"

int	g_is_err = 0;

void	ft_print_err(void)
{
	if (g_is_err == 1)
		write(1, "Dict err\n", 9);
	if (g_is_err == 2)
		write(1, "Error\n", 6);
}

int	check_arg(char *arg)
{
	int	i;

	i = 0;
	while (arg[i])
	{
		if (arg[i] < '0' || arg[i] > '9')
			return (-1);
		i++;
	}
	return (0);
}

char	*g_num_to_change(int argc, char **argv, char **dict_path)
{
	if (argc == 2)
	{
		*dict_path = NULL;
		if (check_arg(argv[1]) == 0)
			return (argv[1]);
	}
	if (argc == 3)
	{
		*dict_path = argv[1];
		if (check_arg(argv[2]) == 0)
			return (argv[2]);
	}
	g_is_err = 2;
	return (NULL);
}

int	main(int argc, char **argv)
{
	char	*w_n;
	char	*num_to_change;
	char	*dict_path;
	int		cur;

	num_to_change = g_num_to_change(argc, argv, &dict_path);
	if (num_to_change != NULL)
		w_n = w_num(num_to_change, dict_path);
	if (g_is_err != 0)
	{
		ft_print_err();
		free(w_n);
		return (-1);
	}
	cur = 1;
	while (w_n[cur])
	{
		write(1, &w_n[cur], 1);
		cur++;
	}
	free(w_n);
	return (0);
}
