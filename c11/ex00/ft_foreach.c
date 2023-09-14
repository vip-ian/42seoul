/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_foreach.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangmle2 <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 09:21:08 by sangmle2          #+#    #+#             */
/*   Updated: 2023/09/11 10:08:52 by sangmle2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <unistd.h>
//
//void	ft_putnbr(int nb)
//{
//	char	a;
//	char	b;
//
//	a = '0';
//	b = '-';
//	if (nb == -2147483648)
//	{
//		write(1, "-2147483648", 11);
//		return ;
//	}
//	if (nb < 0)
//	{
//		nb *= -1;
//		write(1, &b, 1);
//	}
//	if (nb > 9)
//	{
//		ft_putnbr(nb / 10);
//		ft_putnbr(nb % 10);
//	}
//	else if (nb <= 9)
//	{
//		a += nb;
//		write(1, &a, 1);
//	}
//}
//
void	ft_foreach(int *tab, int length, void (*f)(int))
{
	int	i;

	i = 0;
	while (i < length)
		f(tab[i++]);
}

//int main()
//{
//	int array[] = {11, 2, 5, 8};
//	int size = 4;
//	ft_foreach(array, size, &ft_putnbr);
//}
