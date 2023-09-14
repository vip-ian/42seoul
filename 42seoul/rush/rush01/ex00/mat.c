/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush01.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangmle2 <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/01 19:28:00 by sangmle2          #+#    #+#             */
/*   Updated: 2023/09/03 16:34:16 by sangmle2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>

void	mat(char *str, char matrix[4][4])
{
	int	i;
	int row;
	int col;

	i = 0;
	row = 0;
	col = 0;
	while (str[i] == '\0')
	{
		if (str[i] >= '0' && str[i] <= '9')
		{
			if (col == 3)
			{
				matrix[row][col] = str[i];
				row++;
				col = 0;
			}
			else
			{
				matrix[row][col] = str[i];
				col++;
			}
		}
		i++;
	}
}
