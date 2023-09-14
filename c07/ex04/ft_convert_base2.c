/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangmle2 <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 18:57:36 by sangmle2          #+#    #+#             */
/*   Updated: 2023/09/06 20:24:42 by sangmle2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strlen(char *str)
{
	int	cur;

	cur = 0;
	while (str[cur] != 0)
		cur++;
	return (cur);
}

char	*rev_str(char *str)
{
	int		size;
	int		cur;
	char	tmp;

	size = ft_strlen(str) - 1;
	cur = 0;
	while (cur < size - cur)
	{
		tmp = str[cur];
		str[cur] = str[size - cur];
		str[size - cur] = tmp;
		cur++;
	}
	return (str);
}

int	pos_in_str(char *str, char c)
{
	int	cur;

	cur = 0;
	while (str[cur] != 0)
	{
		if (str[cur] == c)
			return (cur);
		cur++;
	}
	return (-1);
}
