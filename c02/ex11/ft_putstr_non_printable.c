/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangmle2 <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/27 15:22:38 by sangmle2          #+#    #+#             */
/*   Updated: 2023/09/01 15:16:18 by sangmle2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	hex_c(char hex[])
{
	hex[0] = '0';
	hex[1] = '1';
	hex[2] = '2';
	hex[3] = '3';
	hex[4] = '4';
	hex[5] = '5';
	hex[6] = '6';
	hex[7] = '7';
	hex[8] = '8';
	hex[9] = '9';
	hex[10] = 'a';
	hex[11] = 'b';
	hex[12] = 'c';
	hex[13] = 'd';
	hex[14] = 'e';
	hex[15] = 'f';
}

void	ft_putstr_non_printable(char *str)
{
	char			hex[16];
	unsigned char	i;
	unsigned char	j;
	unsigned char	*c;
	int				a;

	a = -1;
	hex_c(hex);
	c = (unsigned char *)str;
	while (c[++a] != '\0')
	{
		if (c[a] < 32 || c[a] > 126)
		{
			i = hex[c[a] / 16];
			j = hex[c[a] % 16];
			write(1, "\\", 1);
			write(1, &i, 1);
			write(1, &j, 1);
		}
		else
			write(1, &c[a], 1);
	}
}
