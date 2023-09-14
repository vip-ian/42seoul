/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_op.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangmle2 <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 12:08:41 by sangmle2          #+#    #+#             */
/*   Updated: 2023/09/11 14:24:26 by sangmle2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DO_OP_H
# define DO_OP_H

# define ADD 0
# define SUB 1
# define MUL 2
# define DIV 3
# define MOD 4

void	do_op(int input1, int input2, int op);
int		ft_add(int a, int b);
int		ft_sub(int a, int b);
int		ft_mul(int a, int b);
int		ft_div(int a, int b);
int		ft_mod(int a, int b);
int		ft_atoi(char *str);
void	ft_putchar(char c);
void	ft_putnbr(long int n);
void	ft_putstr(char *str);
int		ft_strlen(char *str);

#endif
