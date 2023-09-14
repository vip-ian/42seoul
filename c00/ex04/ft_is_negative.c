/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_negative.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangmle2 <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 12:19:25 by sangmle2          #+#    #+#             */
/*   Updated: 2023/08/24 12:14:44 by sangmle2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

void	ft_is_negative(int n)
{
	char	check[2];

	check[0] = 'N';
	check[1] = 'P';
	if (n < 0)
	{
		write(1, &check[0], 1);
	}
	else
	{
		write(1, &check[1], 1);
	}
}