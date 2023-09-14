/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_function.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donson <donson@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 21:38:07 by sangmle2          #+#    #+#             */
/*   Updated: 2023/09/13 14:35:23 by donson           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

int	ft_atoi(char *str, int len)
{
	int	nb;
	int i;

	nb = 0;
	i = 0;
	while ((str[i] >= '0' && str[i] <= '9') && i < len - 3)
	{
		nb = (nb * 10) + (str[i] - '0');
		i++;
	}
	return (nb);
}
