/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangmle2 <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/27 12:03:16 by sangmle2          #+#    #+#             */
/*   Updated: 2023/08/31 16:29:56 by sangmle2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	first(char *str)
{
	if (*str >= 'a' && *str <= 'z')
		*str -= 32;
}

char	*ft_strcapitalize(char *str)
{
	char	*tmp;

	tmp = str;
	first(str);
	str++;
	while (*str != '\0')
	{
		if (*str >= 'A' && *str <= 'Z')
			*str += 32;
		if (*str >= 'a' && *str <= 'z')
		{
			if (!(*(str - 1) >= 'a' && *(str - 1) <= 'z'))
			{
				if (!(*(str - 1) >= '0' && *(str - 1) <= '9'))
				{
					if (!(*(str - 1) >= 'A' && *(str - 1) <= 'Z'))
					{
						*str -= 32;
					}
				}
			}
		}
		str++;
	}
	return (tmp);
}
