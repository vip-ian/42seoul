/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangmle2 <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/25 18:08:03 by sangmle2          #+#    #+#             */
/*   Updated: 2023/08/27 18:03:47 by sangmle2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
void	rush(int x, int y);

unsigned int	_atoi(char *a)
{
	unsigned int	data;
	int				i;

	data = 0;
	i = 0;
	while (*a != '\0')
	{
		if (*a >= '0' && *a <= '9')
		{
			data = data * 10 + *a - '0';
		}
		else
		{
			return (0);
		}
		if (data > 2147483647)
			return (0);
		a++;
		i++;
	}
	if (i > 10)
		return (0);
	return (data);
}

int	main(int argc, char *argv[])
{
	int	a;
	int	b;

	if (argc != 3)
		return (0);
	a = _atoi(argv[1]);
	b = _atoi(argv[2]);
	if (a < 1 || b < 1)
		return (0);
	rush(a, b);
	return (0);
}
