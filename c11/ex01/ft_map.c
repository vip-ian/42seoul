/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangmle2 <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 09:27:06 by sangmle2          #+#    #+#             */
/*   Updated: 2023/09/11 10:09:02 by sangmle2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

//int ft_square(int n)
//{
//	return n * n;
//}

int	*ft_map(int *tab, int length, int (*f)(int))
{
	int	*arr;
	int	i;

	if (tab == NULL || f == NULL)
		return (NULL);
	i = 0;
	arr = (int *)malloc(sizeof(int) * length);
	if (arr == NULL)
		return (NULL);
	while (i < length)
	{
		arr[i] = f(tab[i]);
		i++;
	}
	return (arr);
}

//#include <stdio.h>
//
//int main()
//{
//	int array[] = {1, 3, 5, 7, 9};
//	int length = 5;
//	int i = 0;
//
//	int *a = ft_map(array, length, &ft_square);
//	
//	if (a == NULL)
//		printf("--X--");
//	else
//	{
//		while (i < length)
//		{
//			printf("%d\n", a[i]);
//			i++;
//		}
//	}
//}
