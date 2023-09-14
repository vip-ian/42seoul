/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_any.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangmle2 <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 09:55:37 by sangmle2          #+#    #+#             */
/*   Updated: 2023/09/13 11:44:42 by sangmle2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_any(char **tab, int (*f)(char*))
{
	int	i;

	i = 0;
	if (tab == NULL || f == NULL)
		return (0);
	while (tab[i])
	{
		if (f(tab[i]))
			return (1);
		i++;
	}
	return (0);
}

//#include <stdio.h>
//
//int	ft_strlen(char *str)
//{
//	int i;
//
//	i = 0;
//	while (str[i] != '\0')
//		i++;
//	return (i);
//}
//
//int	main(int argc, char **argv)
//{
//	(void)argc;
//
//	if(ft_any(argv + 1, &ft_strlen))
//		printf("String");
//	else
//		printf("Empty");
//	return (0);
//}
