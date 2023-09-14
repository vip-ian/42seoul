/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   standard_input.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donson <donson@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 23:31:40 by donson            #+#    #+#             */
/*   Updated: 2023/09/13 22:28:25 by donson           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include "tool.h"

char	*get_map_info() {
	char c;
	int count[3];//i count r
	char *buf;
	char *buf_buf;

	count[1] = 0;
	count[2] = read(0, &c, 1);
	if (count[2] == -1 || count[2] == 0)
		return (0);
	while (c != '\n')
	{
		if (count[1] != 0)
		{
			free(buf_buf);
			buf_buf = NULL;
			buf_buf = f_strdup(buf, count[1]);
			free(buf);
		}
		buf = (char *)malloc(sizeof(char) * (count[1] + 1));
		count[0] = -1;
		while (++count[0] <= count[1] && count[1] != 0)
			buf[count[0]] = buf_buf[count[0]];
		buf[count[1]++] = c;
		count[2] = read(0, &c, 1);
		if (count[2] == -1 || count[2] == 0)
		{
			free(buf_buf);
			free(buf);
			return (0);
		}
	}
	free(buf_buf);
	buf_buf = NULL;
	return (buf);
}

int arg1(char ***map, int size[2], char characters[3])
{
	char *info;
	char **map_buf;
	int len;
	int i;

	i = 0;
	info = get_map_info();
	if (info == 0)
	{
		free(info);
		return (0);
	}
	len = f_strlen(info);
	if (len < 3)
	{
		free(info);
		return (0);
	}
	characters[0] = info[len - 3];
	characters[1] = info[len - 2];
	characters[2] = info[len - 1];
	len = ft_atoi_3(info, len - 3);
	if (len == 0)
	{
		free(info);
		return (0);
	}
	size[0] = len;
	map_buf = (char **)malloc(len * sizeof(char *));
	while (i < len)
	{
		map_buf[i++] = get_map_info();
		if (map_buf[i - 1] == NULL)
		{
			free(info);
			free(map_buf[0]);
			free(map_buf);
			return (0);
		}
	}
	i = 0;
	size[1] = f_strlen(map_buf[0]);
	while (i < len)
		if(size[1] != f_strlen(map_buf[i++]))
		{
			free(info);
			free(map_buf[0]);
			free(map_buf);
			return (0);
		}
	*map = map_buf;
	free(info);
	return (1);
}