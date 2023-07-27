/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aallou-v <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 11:22:58 by aallou-v          #+#    #+#             */
/*   Updated: 2023/07/25 12:05:59 by aallou-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_map(int *tab, int lenght, int (*f)(int))
{
	int	*tabcpy;
	int	i;

	i = -1;
	tabcpy = (int *) malloc(sizeof(int) * lenght);
	if (!tabcpy)
		return (NULL);
	while (++i < lenght)
		tabcpy[i] = f(tab[i]);
	return (tabcpy);
}

/*
#include <stdio.h>
#include <stdlib.h>

int    ft_double(int nb)
{
    return (nb * 2);
}

int    main(int argc, char *argv[])
{
    int    *tab;
    int    *new_tab;
    int    i;

    if (1 < argc)
    {
        argv++;
        argc--;
        tab = malloc(argc * sizeof(int));
        i = -1;
        while (++i < argc)
            tab[i] = atoi(argv[i]);
        new_tab = ft_map(tab, argc, &ft_double);
        i = -1;
        while (++i < argc)
            printf("%d\n", new_tab[i]);
    }
    else
        printf("required 'nb1' ...\n");
}
*/
