/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_dict_func.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangmle2 <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/09 10:20:03 by sangmle2          #+#    #+#             */
/*   Updated: 2023/09/09 11:54:18 by sangmle2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

char	*str_dup(char *str, int s_cur, int e_cur)
{
	int		cur;
	char	*result;

	result = (char *)malloc(sizeof(char) * (e_cur - s_cur + 2));
	cur = 0;
	while (s_cur <= e_cur)
	{
		result[cur] = str[s_cur];
		s_cur++;
		cur++;
	}
	result[cur] = 0;
	return (result);
}

int	g_number(int *cur, char *str, char **number)
{
	int	start_cur;

	if (str[*cur] == '+' || str[*cur] == '-')
		*cur = *cur + 1;
	else if (str[*cur] < '0' || str[*cur] > '9')
		return (1);
	start_cur = *cur;
	while (str[*cur] >= '0' && str[*cur] <= '9')
		*cur = *cur + 1;
	*number = str_dup(str, start_cur, *cur - 1);
	return (0);
}

int	is_only_space(int cur, char *str)
{
	while (str[cur] != 0)
	{
		if (str[cur] != ' ')
			return (0);
		cur++;
	}
	return (1);
}

int	g_v_size(int cur, char *str)
{
	int	v_size;

	v_size = 0;
	while (str[cur] >= 32 && str[cur] <= 126)
	{
		if (is_only_space(cur, str) == 1)
			break ;
		if (str[cur] != ' ')
			v_size++;
		else if (str[cur] == ' ' && str[cur - 1] != ' ' && str[cur - 1] != ':')
			v_size++;
		cur++;
	}
	return (v_size);
}
