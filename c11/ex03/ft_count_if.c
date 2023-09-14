/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_if.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangmle2 <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 10:09:30 by sangmle2          #+#    #+#             */
/*   Updated: 2023/09/11 14:45:41 by sangmle2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_count_if(char **tab, int length, int (*f)(char *))
{
	int	i;
	int	cnt;

	i = 0;
	cnt = 0;
	if (tab == NULL || f == NULL || length == 0)
		return (0);
	while (i < length)
	{
		if (f(tab[i]))
		{
			cnt++;
		}
		i++;
	}
	return (cnt);
}

//#include <stdio.h>
//
//int	ft_strlen(char *a)
//{
//	int i;
//
//	i = 0;
//	while (a[i] != '\0')
//		i++;
//	return (i);
//}
//
//int main(int argc, char **argv)
//{
//	printf("%d\n", ft_count_if(argv + 1, argc - 1, &ft_strlen));
//}
