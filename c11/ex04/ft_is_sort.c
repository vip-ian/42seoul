/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangmle2 <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 11:31:40 by sangmle2          #+#    #+#             */
/*   Updated: 2023/09/14 14:51:11 by sangmle2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_is_sort(int *tab, int length, int (*f)(int, int))
{
	int	i;
	int	min;
	int	max;

	i = 0;
	min = 0;
	max = 0;
	if (length == 0 || length == 1)
		return (1);
	while (i < length - 1)
	{
		if ((*f)(tab[i], tab[i + 1]) >= 0)
			max++;
		if ((*f)(tab[i], tab[i + 1]) <= 0)
			min++;
		i++;
	}
	if (min == i || max == i)
		return (1);
	return (0);
}

//#include <stdio.h>
//
//int	big(int a, int b)
//{
//	return (a - b);
//}
//
//int main()
//{
//	int arr[] = {3,2,1,3};
//	int size = 4;
//
//	printf("%d\n", ft_is_sort(arr, size, &big));
//}
