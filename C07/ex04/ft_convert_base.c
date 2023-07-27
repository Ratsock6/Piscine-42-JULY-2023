/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aallou-v <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 15:03:50 by aallou-v          #+#    #+#             */
/*   Updated: 2023/07/26 15:03:53 by aallou-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		is_valid_base(char *base);
int		ft_atoi_base(char *str, char *base);
char	*ft_putnbr_base(long nbr, char *base, char *dest);
int		is_valid_base(char *base);

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	ft_add_dest(char *base, char *dest, long nbr, int index)
{
	if (nbr >= ft_strlen(base))
		ft_add_dest(base, dest, (nbr / ft_strlen(base)), index - 1);
	dest[index] = base[nbr % ft_strlen(base)];
}

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	int		i_nbr;
	char	*dest;

	dest = NULL;
	if (!is_valid_base(base_to) || !is_valid_base(base_from))
		return (NULL);
	i_nbr = ft_atoi_base(nbr, base_from);
	dest = ft_putnbr_base(i_nbr, base_to, dest);
	return (dest);
}

/*
#include <stdio.h>

int    main(int argc, char *argv[])
{
    char    *dest;

    if (3 < argc)
    {
        dest = ft_convert_base(argv[1], argv[2], argv[3]);
        printf("%s\n", dest);
    }
    else
        printf("required 'nb' 'base_from' 'base_to'\n");
}
*/
