/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_any.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aallou-v <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 11:46:38 by aallou-v          #+#    #+#             */
/*   Updated: 2023/07/25 12:03:31 by aallou-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_any(char **tab, int (*f)(char*))
{
	int	i;

	i = -1;
	while (tab[++i])
		if (f(tab[i]) != 0)
			return (1);
	return (0);
}

/*
#include <stdio.h>
#include <stdlib.h>

int    ft_str_is_alpha(char *str)
{
    while (*str)
    {
        if (*str < 'A' || ('Z' < *str && *str < 'a') || 'z' < *str)
            return (0);
        str++;
    }
    return (1);
}

int    main(int argc, char *argv[])
{
    if (1 < argc)
    {
        argv++;
        argc--;
        printf("ft_any = %d\n", ft_any(argv, &ft_str_is_alpha));
    }
    else
        printf("required 's1' ...\n");
}
*/
