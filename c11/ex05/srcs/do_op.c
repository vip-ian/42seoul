/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_op.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangmle2 <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 12:03:49 by sangmle2          #+#    #+#             */
/*   Updated: 2023/09/13 13:58:29 by sangmle2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "do_op.h"

void	do_op(int input1, int input2, int op)
{
	int	(*arr[5])(int, int);

	arr[ADD] = ft_add;
	arr[SUB] = ft_sub;
	arr[MUL] = ft_mul;
	arr[DIV] = ft_div;
	arr[MOD] = ft_mod;
	if (op == DIV && input2 == 0)
		ft_putstr("Stop : division by zero\n");
	else if (op == MOD && input2 == 0)
		ft_putstr("Stop : modulo by zero\n");
	else
	{
		ft_putnbr(arr[op](input1, input2));
		ft_putchar('\n');
	}
}
