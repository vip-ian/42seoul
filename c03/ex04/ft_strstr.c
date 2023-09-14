/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangmle2 <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 01:53:47 by sangmle2          #+#    #+#             */
/*   Updated: 2023/08/31 12:03:06 by sangmle2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strstr(char *str, char *to_find)
{
	int	i;
	int	chk;

	if (*to_find == '\0')
		return (str);
	while (*str != '\0')
	{
		if (*str == *to_find)
		{
			i = 0;
			chk = 0;
			while (to_find[i] != '\0')
			{
				if (str[i] != to_find[i])
					chk = 1;
				i++;
			}
			if (chk == 0)
				return (str);
		}
		str++;
	}
	return (0);
}
