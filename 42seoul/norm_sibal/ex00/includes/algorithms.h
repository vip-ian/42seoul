/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithms.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donson <donson@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 23:28:43 by donson            #+#    #+#             */
/*   Updated: 2023/09/13 22:32:31 by donson           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ALGORITHMS_H
# define ALGORITHMS_H

int		*find_largest_square(int row, int col, int **m);
void	print_map(char **map, int result[3], int size[2], char fill);
int		**convert_map(char **map, char characters[3], int size[2]);
void	print_map_one(char **map, int size[2], char characters[3]);
void	print_map_one_one(char **map, char characters[3]);
int		check(char	**map, int	*size, char	*characters);

#endif
