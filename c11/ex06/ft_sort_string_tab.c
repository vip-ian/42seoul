/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_string_tab.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangmle2 <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 14:29:25 by sangmle2          #+#    #+#             */
/*   Updated: 2023/09/11 14:48:41 by sangmle2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] == s2[i] && s1[i])
		i++;
	return (s1[i] - s2[i]);
}

void	ft_sort_string_tab(char **tab)
{
	int		i;
	char	*tmp;

	if (tab == NULL || tab[0] == NULL)
		return ;
	i = 0;
	while (tab[i + 1] != NULL)
	{
		if (ft_strcmp(tab[i], tab[i + 1]) > 0)
		{
			tmp = tab[i];
			tab[i] = tab[i + 1];
			tab[i + 1] = tmp;
			i = 0;
		}
		else
			i++;
	}
}

//#include <stdio.h>
//
//int main(int argc, char **argv)
//{
//	(void)argc;
//	for (int i = 0; argv[i] != NULL; i++)
//		printf("%s\n", argv[i]);
//	ft_sort_string_tab(argv);
//	printf("---result---\n");
//	for (int i = 0; argv[i] != NULL; i++)
//		printf("%s\n", argv[i]);
//}
