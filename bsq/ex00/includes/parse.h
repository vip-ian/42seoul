/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donson <donson@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 14:28:06 by donson            #+#    #+#             */
/*   Updated: 2023/09/13 22:32:54 by donson           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSE_H
# define PARSE_H

int		*get_length(char *argv);
char	*get_arr(char *argv, int len);
char	*get_buf(char *argv, int first, int buf_size);
char	**parse(char *argv, int size[2], char character[3]);

#endif
