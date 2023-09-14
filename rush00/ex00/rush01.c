/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush04.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangmle2 <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/25 18:13:09 by sangmle2          #+#    #+#             */
/*   Updated: 2023/08/27 18:03:58 by sangmle2         ###   ########.fr       */
/*   Updated: 2023/08/26 11:34:26 by hyujeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
void	ft_putchar(char *a);

void	rush(int x, int y)
{
	int	c;
	int	r;

	r = 1;
	while (r <= y)
	{
		c = 1;
		while (c <= x)
		{
			if ((c == 1 && r == 1) || (c == x && r == y && c != 1 && r != 1))
				ft_putchar("/");
			else if ((c == x && r == 1) || (c == 1 && r == y))
				ft_putchar("\\");
			else if ((c == 1) || (c == x) || (r == 1) || (r == y))
				ft_putchar("*");
			else
				ft_putchar(" ");
			c++;
		}
		r++;
		ft_putchar("\n");
	}
}
