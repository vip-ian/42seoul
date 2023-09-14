/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangmle2 <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 12:31:43 by sangmle2          #+#    #+#             */
/*   Updated: 2023/09/14 14:50:07 by sangmle2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "do_op.h"

int	ft_is_val(char *str)
{
	if (ft_strlen(str) != 1)
		return (0);
	return (str[0] == '+' || str[0] == '-' || str[0] == '*'
		|| str[0] == '/' || str[0] == '%');
}

int	ft_valid(char **argv, int *input1, int *input2)
{
	if (!ft_is_val(argv[2]))
		return (-1);
	*input1 = ft_atoi(argv[1]);
	*input2 = ft_atoi(argv[3]);
	if (argv[2][0] == '+')
		return (ADD);
	else if (argv[2][0] == '-')
		return (SUB);
	else if (argv[2][0] == '*')
		return (MUL);
	else if (argv[2][0] == '/')
		return (DIV);
	else
		return (MOD);
}

int	main(int argc, char **argv)
{
	int	input1;
	int	input2;
	int	op;

	if (argc == 4)
	{
		op = ft_valid(argv, &input1, &input2);
		if (op != -1)
			do_op(input1, input2, op);
		else
		{
			ft_putchar('0');
			ft_putchar('\n');
		}
	}
	return (0);
}
