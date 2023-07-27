/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_advanced_sort_string_tab.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aallou-v <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 18:36:09 by aallou-v          #+#    #+#             */
/*   Updated: 2023/07/25 00:50:13 by aallou-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_tab_size(char **tab)
{
	int	i;

	i = -1;
	while (tab[++i])
		;
	return (i);
}

void	ft_strswap(char **str1, char **str2)
{
	char	*temp;

	temp = *str1;
	*str1 = *str2;
	*str2 = temp;
}

void	ft_advanced_sort_string_tab(char **tab, int (*cmp)(char *, char *))
{
	int		i;
	int		j;
	int		size;

	i = -1;
	size = ft_tab_size(tab);
	while (++i < size)
	{
		j = 0;
		while (j < (size - i) - 1)
		{
			if (cmp(tab[j], tab[j + 1]) > 0)
			{
				ft_strswap(&tab[j], &tab[j + 1]);
			}
			j++;
		}
	}
}

/*
#include <stdio.h>

int    ft_strcmplen(char *s1, char *s2)
{
    int    i;
    int    j;

    i = 0;
    j = 0;
    while (s1[i])
        i++;
    while (s2[j])
        j++;
    return (i - j);
}

int    main(int argc, char *argv[])
{
    int    i;

    ft_advanced_sort_string_tab(argv + 1, &ft_strcmplen);
    i = 1;
    while (i < argc)
    {
        printf("%s\n", argv[i]);
        i++;
    }
}
*/
