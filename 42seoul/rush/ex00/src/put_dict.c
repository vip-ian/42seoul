/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_dict.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangmle2 <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/09 10:20:00 by sangmle2          #+#    #+#             */
/*   Updated: 2023/09/09 11:45:59 by sangmle2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include "put_dict_func.h"

extern int	g_is_err;

int	put_l_start(int *cur, char *str, char **num)
{
	*cur = 0;
	if (g_number(cur, str, num) != 0)
		return (1);
	while (str[*cur] == ' ')
		*cur = *cur + 1;
	if (str[*cur] != ':')
		return (1);
	*cur = *cur + 1;
	while (str[*cur] == ' ')
		*cur = *cur + 1;
	return (0);
}

int	put_l_string(char *str, char **num, char **v)
{
	int	cur;
	int	v_cur;

	if (put_l_start(&cur, str, num) != 0)
		return (1);
	*v = (char *)malloc(sizeof(char) * (g_v_size(cur, str) + 2));
	v_cur = 0;
	while (str[cur] >= 32 && str[cur] <= 126)
	{
		if (is_only_space(cur, str) == 1)
			break ;
		if (str[cur] != ' ' || (str[cur] == ' ' && str[cur - 1] != ' '))
		{
			(*v)[v_cur] = str[cur];
			v_cur++;
		}
		cur++;
	}
	(*v)[v_cur] = 0;
	return (0);
}

int	put_dict_string(char **strs, char ***nums, char ***vals)
{
	int	cur;

	cur = 0;
	while (strs[cur] != 0)
		cur++;
	*nums = (char **)malloc(sizeof(char *) * (cur + 1));
	*vals = (char **)malloc(sizeof(char *) * (cur + 1));
	cur = 0;
	while (strs[cur] != 0)
	{
		if (put_l_string(strs[cur], &(*nums)[cur], &(*vals)[cur]) != 0)
		{
			g_is_err = 1;
			return (1);
		}
		cur++;
	}
	(*nums)[cur] = 0;
	(*vals)[cur] = 0;
	return (0);
}
