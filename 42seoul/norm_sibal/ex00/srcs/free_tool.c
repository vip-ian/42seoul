/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_tool.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangmle2 <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 22:48:46 by sangmle2          #+#    #+#             */
/*   Updated: 2023/09/14 00:16:42 by sangmle2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	free_func_two(char *a, char *b)
{
	free(a);
	free(b);
	return (1);
}

int	free_func(char *a)
{
	free(a);
	return (1);
}

int	free_while(char **a, int size)
{
	int i;

	i = 0;
	while (i < size)
	{
		free(a[i]);
		i++;
	}
	free(a);
	return (1);
}

void free_four(char *a, char *b, char **c, char **d)
{
	free(a);
	free(b);
	free(c);
	free(d);
}

int free_two_while(char **a, char **b, int size)
{
	int i;

	i = 0;
	while (i < size)
	{
		free(a[i]);
		i++;
	}
	free(a);
	while (i < size)
	{
		free(b[i]);
		i++;
	}
	free(b);
	return (1);
}
