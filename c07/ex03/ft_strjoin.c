/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangmle2 <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 15:23:45 by sangmle2          #+#    #+#             */
/*   Updated: 2023/09/06 10:29:53 by sangmle2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strcpy(char *dest, char *src)
{
	int	i;

	i = 0;
	while (*src)
	{
		*dest = *src;
		src++;
		dest++;
	}
	return (dest);
}

int	ft_strlen(char *str)
{
	int	len;

	len = 0;
	while (*str)
	{
		len++;
		str++;
	}
	return (len);
}

int	rlen(int size, char **strs, int len)
{
	int	i;
	int	l;

	i = -1;
	l = len * -1;
	while (++i < size)
		l += len + ft_strlen(strs[i]);
	return (l);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	char	*res;
	int		i;
	int		len;

	i = -1;
	if (size == 0)
	{
		res = (char *)malloc(1);
		return (res);
	}
	len = rlen(size, strs, ft_strlen(sep));
	res = malloc(sizeof(char) * (len + 1));
	if (res == 0)
		return (0);
	while (++i < size)
	{
		res = ft_strcpy(res, strs[i]);
		if (i + 1 < size)
			res = ft_strcpy(res, sep);
	}
	*res = '\0';
	return (res - len);
}

//#include <stdio.h>
//
//int main()
//{
//	char *str[3];
//	char *sep = ",";
//	char *join;
//
//	str[0] = "cat";
//	str[1] = "dog";
//	str[2] = "bee";
//
//	join = ft_strjoin(3, str, sep);
//
//	printf("%s", join);
//}
