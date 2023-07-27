/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_int_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aallou-v <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 16:16:27 by aallou-v          #+#    #+#             */
/*   Updated: 2023/07/20 16:16:29 by aallou-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_rev_int_tab(int *tab, int size)
{
	int	values;
	int	temp;
	int	i;

	i = -1;
	while (++i < size / 2)
	{
		values = tab[size - i - 1];
		temp = tab[i];
		tab[i] = values;
		tab[size - i - 1] = temp;
	}
}

/*
#include <stdio.h>

int    main(void)
{
    int    size;
    int    tab[] = {9, 8, 7, 6, 5, 4, 3, 2, 1, 0};

    size = 10;
    printf("%d, %d, %d, %d, %d, %d, %d, %d, %d, %d\n"
        , tab[0], tab[1], tab[2], tab[3], tab[4], tab[5],
        tab[6], tab[7], tab[8], tab[9]);
    printf("ft_rev_int_tab(tab, size);\n");
    ft_rev_int_tab(tab, size);
    printf("%d, %d, %d, %d, %d, %d, %d, %d, %d, %d\n"
        , tab[0], tab[1], tab[2], tab[3], tab[4], tab[5],
        tab[6], tab[7], tab[8], tab[9]);
    return (0);
}
*/