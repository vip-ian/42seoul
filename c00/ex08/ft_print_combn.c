/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_combn.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangmle2 <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 10:12:09 by sangmle2          #+#    #+#             */
/*   Updated: 2023/08/26 14:57:42 by sangmle2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

void	cp_combn(char*combn, char*fincombn, int n);

void	print_combn(char*combn, char*fincombn, int n);	

void	ft_print_combn(int n)
{
	char	combn[10];
	char	fincombn[10];
	int		a;

	a = 0;
	while (a < n)
	{
		combn[a] = '0' + a;
		fincombn[a] = '0' + a + (10 - n);
		a++;
	}
	print_combn(combn, fincombn, n);
	cp_combn(combn, fincombn, n);
}

void	cp_combn(char*combn, char*fincombn, int n)
{
	int	i;
	int	a;

	a = 0;
	while (combn[0] != fincombn[0])
	{
		i = n - 1;
		while (combn[i] == fincombn[i])
		{
			i -= 1;
		}
		a = ++combn[i];
		while (i < n)
		{
			combn[++i] = ++a;
		}
		print_combn(combn, fincombn, n);
	}
}

void	print_combn(char*combn, char*fincombn, int n)
{
	char	b[2];

	b[0] = ',';
	b[1] = ' ';
	if (combn[0] == fincombn[0])
	{
		write(1, combn, n);
		return ;
	}
	write(1, combn, n);
	if (combn[0] != fincombn[0])
	{
		write(1, b, 2);
	}	
}
