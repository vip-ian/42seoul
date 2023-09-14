/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_func.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donson <donson@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 17:54:28 by sangmle2          #+#    #+#             */
/*   Updated: 2023/09/13 16:45:14 by donson           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "str_function.h"
#include <stdlib.h>

char	*ft_strdup(char *src, int len)
{
	char	*dest;
	int		i;

	dest = (char *)malloc(sizeof(char) * len);
	i = 0;
	if (dest == 0)
		return (0);
	else
	{
		while (src[i])
		{
			dest[i] = src[i];
			i++;
		}
		dest[i] = '\0';
		return (dest);
	}
}

int	check_charset(unsigned char c, unsigned char *charset)
{
	int	i;

	i = 0;
	while (charset[i] != '\0')
		if (charset[i++] == c)
			return (1);
	return (0);
}

int	count_word(unsigned char *str, unsigned char *charset)
{
	int	i;
	int	count;

	count = 0;
	i = 0;
	while (str[i] != '\0')
	{
		while (str[i] != '\0' && check_charset(str[i], charset))
			i++;
		if (str[i] != '\0')
			count++;
		while (str[i] != '\0' && !check_charset(str[i], charset))
			i++;
	}
	return (count);
}

int	len_word(unsigned char *str, unsigned char *charset)
{
	int	i;

	i = 0;
	while (str[i] != '\0' && !check_charset(str[i], charset))
			i++;
	return (i);
}

unsigned char	*fill(unsigned char *str, unsigned char *charset)
{
	int				len;
	int				i;
	unsigned char	*word;

	i = 0;
	len = len_word(str, charset);
	word = (unsigned char *)malloc(sizeof(unsigned char) * (len + 1));
	while (i < len)
	{
		word[i] = str[i];
		i++;
	}
	word[i] = '\0';
	return (word);
}

char	**ft_split(char *str, char *charset)
{
	unsigned char	**result;
	unsigned char	*st;
	unsigned char	*set;
	int				i;
	int				c;

	if (str == 0 || charset == 0)
		return (0);
	i = 0;
	st = (unsigned char *)str;
	set = (unsigned char *)charset;
	c = count_word(st, set) + 1;
	result = (unsigned char **)malloc(c * (sizeof(unsigned char *)));
	while (*st != '\0')
	{
		while (*st != '\0' && check_charset(*st, set))
			st++;
		if (*st != '\0')
			result[i++] = fill(st, set);
		while (*st && !check_charset(*st, set))
				st++;
	}
	result[i] = 0;
	return ((char **)result);
}