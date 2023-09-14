/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   change.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangmle2 <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/09 10:19:38 by sangmle2          #+#    #+#             */
/*   Updated: 2023/09/10 13:48:54 by sangmle2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "ft_func.h"
#include "change_func.h"
#include "put_file.h"
#include "put_dict.h"

int	put_n(char *str, int print_o, char *str_num);

char		**g_nums;
char		**g_v_s;
extern int	g_is_err;

int	put_n_inf100(char *str, int print_o, char *str_num)
{
	char	*str_cop;
	int		num;
	int		sum;

	num = ft_atoi(str);
	if (num <= 20 || num % 10 == 0)
	{
		if (print_o)
			ft_strcat_space(str_num, g_v(str, g_nums, g_v_s));
		return (ft_strlen(g_v(str, g_nums, g_v_s)) + 1);
	}
	else if (num <= 100)
	{
		sum = 0;
		str_cop = ft_strdup(str);
		str_cop[1] = '0';
		sum += put_n(str_cop, print_o, str_num);
		sum += put_n(str + 1, print_o, str_num);
		free(str_cop);
		return (sum);
	}
	return (0);
}

int	put_n_sup100(char *str, int print_o, char *str_num)
{
	int		sum;
	char	*magnum;
	char	*rest;

	sum = 0;
	magnum = g_mag_num(str);
	sum += put_n(magnum, print_o, str_num);
	rest = g_v(g_mag(str), g_nums, g_v_s);
	if (print_o)
		ft_strcat_space(str_num, rest);
	sum += put_n(str + ft_strlen(magnum), print_o, str_num);
	sum += ft_strlen(rest) + 1;
	return (sum);
}

int	put_n(char *str, int print_o, char *str_num)
{
	int		len;

	while (str[0] == '0')
		str++;
	if (str[0] == 0)
		return (0);
	len = ft_strlen(str);
	if (len <= 2)
		return (put_n_inf100(str, print_o, str_num));
	else
		return (put_n_sup100(str, print_o, str_num));
	return (0);
}

char	*w_num(char *str, const char *dict_path)
{
	char	*str_num;
	int		str_size;
	int		cur;
	char	**dict_file_det;

	if (ft_g_ls(dict_path, &dict_file_det) != 0
		|| put_dict_string(dict_file_det, &g_nums, &g_v_s) != 0)
	{
		g_is_err = 1;
		return (0);
	}
	cur = 0;
	if (_zero(str) == 0)
		str_size = ft_strlen(g_v("0", g_nums, g_v_s));
	else
		str_size = put_n(str, 0, "");
	str_num = malloc(sizeof(char) * (str_size + 1));
	cur = -1;
	while (cur++ < str_size)
		str_num[cur] = 0;
	if (_zero(str) == 0)
		ft_strcat_space(str_num, g_v("0", g_nums, g_v_s));
	else
		put_n(str, 1, str_num);
	return (str_num);
}
