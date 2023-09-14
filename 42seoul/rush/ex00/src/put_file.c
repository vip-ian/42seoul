/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_file.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangmle2 <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/09 10:20:06 by sangmle2          #+#    #+#             */
/*   Updated: 2023/09/09 11:42:42 by sangmle2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include "put_file_func.h"

int	ft_g_l_num(const char *path)
{
	int		file;
	char	c;
	int		i;
	int		l_index;

	file = open(path, O_RDONLY);
	if (file == -1)
		return (-1);
	c = 0;
	i = 0;
	l_index = 0;
	while (read(file, &c, 1))
	{
		if (c == '\n')
			i = -1;
		if (i == 0)
			l_index++;
		i++;
	}
	close(file);
	return (l_index);
}

int	*ft_g_l_lens(const char *path)
{
	int		file;
	int		*file_sizes;

	file_sizes = malloc(sizeof(int) * (1 + ft_g_l_num(path)));
	if (file_sizes == NULL)
		return (NULL);
	file_sizes[0] = ft_g_l_num(path);
	file = open(path, O_RDONLY);
	if (file == -1 || file_sizes[0] == -1)
		return (NULL);
	if (ft_g_l_lens_loop(file, file_sizes) == NULL)
		return (NULL);
	close(file);
	return (file_sizes);
}

int	ft_g_ls(const char *path, char ***ls)
{
	int			file;
	int			*file_sizes;
	const char	*default_path = "dict/numbers.dict";

	if (path == NULL)
		path = default_path;
	file_sizes = ft_g_l_lens(path);
	file = open(path, O_RDONLY);
	if (file_sizes == NULL || file == -1)
		return (-1);
	*ls = malloc(sizeof(char *) * (file_sizes[0] + 1));
	if (*ls == NULL)
		return (-1);
	if (ft_g_ls_loop(file, file_sizes, ls) == -1)
		return (-1);
	free(file_sizes);
	close(file);
	return (0);
}
