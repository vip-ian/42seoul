/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush01.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangmle2 <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/01 18:36:14 by sangmle2          #+#    #+#             */
/*   Updated: 2023/09/03 16:39:08 by sangmle2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

void	mat(char *str,  char matrix[4][4]);
int		solve(char matrix[4][4], char solve_m[4][4]);
void	print(char matrix[4][4]);
void	initialize(char matrix[4][4]);

int main(int argc, char *argv[])
{
	char	matrix[4][4];
	char	solve_m[4][4];
	int		i;
	int		j;

	i = 0;
	if (argc != 2)
		return (0);
	//solve_m = malloc(sizeof(char*) * 4);
	//matrix = malloc(sizeof(char*) * 4);
	//while (i < 4)
	//{
	//	solve_m[i] = malloc(sizeof(char) * 4);
	//	matrix[i] = malloc(sizeof(char) * 4);
	//	i++;
	//}
	initialize(matrix);
	initialize(solve_m);
	mat(argv[1], matrix);
	if (solve(matrix, solve_m) == 1)
		print(solve_m);
	else
		print(solve_m);
		write(1, "Error", 5);
	//i = 0;
	//while (i < 4)
	//{
	//	free(matrix[i]);
	//	free(solve_m[i]);
	//	i++;
	//}
	//free(matrix);
	//free(solve_m);
	return (0);
}
