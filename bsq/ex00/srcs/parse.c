/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donson <donson@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 22:58:12 by sangmle2          #+#    #+#             */
/*   Updated: 2023/09/13 22:26:38 by donson           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse_func.h"
#include "str_function.h"
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

int	*get_length(char *argv, int len[2])
{
	int	fd;
	char chk;

	len[0] = 0;
	len[1] = 0;
	fd = open(argv, O_RDONLY);
	if (fd == -1)
		return (0);
	while (read(fd, &chk, 1) != 0)
	{
		if (chk == '\n')
			break ;
		len[0]++;
	}
	while (read(fd, &chk, 1) != 0)
	{
		if (chk == '\n')
			break ;
		len[1]++;
	}
	close(fd);
	return (len);
}

char	*get_arr(char *argv, int len)
{
	int		fd;
	char	*arr;
	char	*cp_arr;

	arr = (char *)malloc(sizeof(char) * (len + 1));
	fd = open(argv, O_RDONLY);
	if (fd == -1)
		return (0);
	read(fd, arr, (len + 1));
	cp_arr = ft_strdup(arr, (len + 1));
	close(fd);
	free(arr);
	return (cp_arr);
}

char	*get_buf(char *argv, int first, int buf_size)
{
	int		fd;
	char	chk[2];
	char	*buf;
	char	*buf_first;
	char	*split;

	buf_first = (char *)malloc(sizeof(char) * first + 1);
	buf = (char *)malloc(sizeof(char) * buf_size);
	fd = open(argv, O_RDONLY);
	if (fd == -1)
	{
		free(buf_first);
		free(buf);
		return (0);
	}
	read(fd, buf_first, first);
	if (read(fd, buf, buf_size) < buf_size)
	{
		free(buf_first);
		free(buf);
		return (0);
	}
	if (!(read(fd, chk, 2) < 2))
	{
		free(buf_first);
		free(buf);
		return (0);
	}
	split = ft_strdup(buf, buf_size);
	free(buf_first);
	free(buf);
	close(fd);
	return (split);
}

char	**parse(char *argv, int size[2], char character[3])
{
	int		line;
	int		i;
	int		buf_size;
	int		first;
	char	**buf;
	char	*arr;

	if (argv == NULL)
		return (0);
	size = get_length(argv, size);
	if (size == 0 || size[0] < 4)
		return (0);
	first = size[0];
	arr = get_arr(argv, size[0]);
	line = ft_atoi(arr, size[0]);
	if (line == 0)
	{
		free(arr);
		return (0);
	}
	i = 0;
	while (i < 3)
	{
		character[i] = arr[size[0] - 3 + i];
		i++;
	}
	size[0] = line;
	free(arr);
	buf_size = (size[1] + 1) * size[0];
	arr = get_buf(argv, first, buf_size);
	if (arr == 0)
	{
		free(arr);
		return (0);
	}
	buf = ft_split(arr, "\n");
	free(arr);
	return (buf);
}
