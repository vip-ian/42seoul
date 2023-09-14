/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   change_func.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangmle2 <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/09 10:19:47 by sangmle2          #+#    #+#             */
/*   Updated: 2023/09/10 13:48:50 by sangmle2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_func.h"

extern int	g_is_err;

char	*g_v(char *key, char **nums, char **v_s)
{
	int		i;
	char	*empty;

	i = 0;
	while (nums[i])
	{
		if (ft_strcmp(nums[i], key) == 0)
			return (v_s[i]);
		i++;
	}
	g_is_err = 1;
	empty = (char *)malloc(1 * sizeof(char));
	empty[0] = 0;
	return (empty);
}

char	*g_mag(char *str)
{
	int		n;
	int		len;
	char	*mag;

	n = ft_strlen(str);
	len = ft_strlen(str);
	if (len >= 4)
		while ((n - 1) % 3 != 0)
			n--;
	else
		n = len;
	mag = malloc(n + 1);
	mag[0] = '1';
	mag[n] = '\0';
	while (--n > 0)
		mag[n] = '0';
	return (mag);
}

char	*g_mag_num(char *str)
{
	int		n;
	int		i;
	int		len;
	char	*num;

	len = ft_strlen(str);
	if (len >= 4)
	{
		n = (ft_strlen(str) - 1) % 3 + 1;
		num = malloc(n + 1);
		i = 0;
		while (i < n)
		{
			num[i] = str[i];
			i++;
		}
	}
	if (len <= 3)
	{
		n = 2;
		num = malloc(n);
		num[0] = str[0];
	}
	num[n] = '\0';
	return (num);
}

int	_zero(char *str)
{
	int	cur;

	cur = -1;
	while (cur++, str[cur] != 0)
		if (str[cur] != '0')
			return (1);
	return (0);
}
