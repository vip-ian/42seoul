/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tool.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donson <donson@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 23:24:19 by donson            #+#    #+#             */
/*   Updated: 2023/09/13 18:40:14 by donson           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_atoi_3(char *str, int len)
{
	unsigned int	num;
	int				i;

	num = 0;
	i = 0;
	while (i < len && (str[i] >= '0' && str[i] <= '9'))
	{
		num = num * 10 + (str[i] - '0');
		i++;
	}
	return (num);
}

int	f_strlen(char *str)
{
	int		i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

int	min(int a, int b, int c)
{
	int buf;

	buf = a;
	if (buf > b)
		buf = b;
	if (buf > c)
		buf = c;
	return (buf);
}

char	*ft_strcpy(char *dest, char *src)
{
	int	i;

	i = 0;
	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

char	*f_strdup(char *src, int len)
{
	char	*str;

	str = (char *)malloc((len * sizeof(char) + 1));
	if (!str)
		return (0);
	ft_strcpy(str, src);
	return (str);
}