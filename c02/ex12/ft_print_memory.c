/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_memory.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangmle2 <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/27 20:06:55 by sangmle2          #+#    #+#             */
/*   Updated: 2023/09/01 15:16:50 by sangmle2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	hex_ch(char hex[])
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

void	hex_print(unsigned long long nb, int p)
{
	char	hex[16];

	hex_ch(hex);
	if (nb < 16 && p == 1)
		write(1, "0", 1);
	if (nb >= 16)
	{
		hex_print(nb / 16, 0);
		hex_print(nb % 16, 0);
	}
	else
		write(1, &hex[nb], 1);
}

void	print_data(unsigned char *c, int size)
{
	int	i;

	i = -1;
	while (i++ < 16)
	{
		if (i % 2 == 0)
			write(1, " ", 1);
		if (i < size)
			hex_print((unsigned long long)*(c + i), 1);
		else if (i != 16)
			write(1, "  ", 2);
	}
	i = -1;
	while (i++ < size - 1)
	{
		if (*(c + i) <= 31 || *(c + i) >= 126)
			write(1, ".", 1);
		else
			write(1, (c + i), 1);
	}
}

void	print_addr(unsigned long long addr)
{
	unsigned long long	tmp;
	int					i;

	tmp = addr;
	i = 1;
	while (i++ < 15)
	{
		if (tmp < 16)
			write(1, "0", 1);
		tmp /= 16;
	}
	hex_print(addr, 0);
}

void	*ft_print_memory(void *addr, unsigned int size)
{
	unsigned char	*addr_r;
	unsigned int	i;
	unsigned int	s_size;

	i = 0;
	addr_r = addr;
	while (i * 16 < size)
	{
		if (i < size / 16)
			s_size = 16;
		else
			s_size = size % 16;
		print_addr((unsigned long long)addr_r + (i * 16));
		write(1, ":", 1);
		print_data(addr_r + (i * 16), s_size);
		write(1, "\n", 1);
		i++;
	}
	return (addr);
}
