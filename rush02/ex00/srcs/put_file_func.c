/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_file_func.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangmle2 <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/09 10:20:10 by sangmle2          #+#    #+#             */
/*   Updated: 2023/09/09 10:49:38 by sangmle2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>

int	*ft_g_l_lens_loop(int file, int *file_sizes)
{
	char	c;
	int		i;
	int		l_index;

	c = 0;
	i = 0;
	l_index = -1;
	while (read(file, &c, 1))
	{
		if (c == '\n')
		{
			if (i >= 0 && l_index >= 0)
				file_sizes[l_index + 1] = i;
			i = -1;
		}
		if (i == 0)
			l_index++;
		i++;
	}
	return (file_sizes);
}

int	ft_g_ls_read_c(char c, int *index[2], int *file_sizes, char ***ls)
{
	if (c == '\n')
	{
		if (*index[0] >= 0)
			(*ls)[*index[1]][*index[0]] = 0;
		*index[0] = -1;
	}
	if (*index[0] == 0)
	{
		(*index[1])++;
		(*ls)[*index[1]] = malloc(sizeof(char)
				* (file_sizes[*index[1] + 1] + 1));
		if ((*ls)[*index[1]] == NULL)
			return (-1);
	}
	if (*index[0] >= 0)
		(*ls)[*index[1]][*index[0]] = c;
	(*index[0])++;
	return (0);
}

int	ft_g_ls_loop(int file, int *file_sizes, char ***ls)
{
	char	c;
	int		i;
	int		l_index;
	int		read_res;
	int		*tab[2];

	c = 0;
	i = 0;
	l_index = -1;
	while (read(file, &c, 1))
	{
		tab[0] = &i;
		tab[1] = &l_index;
		read_res = ft_g_ls_read_c(c, tab, file_sizes, ls);
		if (read_res == -1)
			return (-1);
	}
	(*ls)[l_index + 1] = NULL;
	return (0);
}
