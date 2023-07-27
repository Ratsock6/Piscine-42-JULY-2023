/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aallou-v <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 02:59:57 by aallou-v          #+#    #+#             */
/*   Updated: 2023/07/20 03:40:54 by aallou-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	is_valid_base(char *base)
{
	int	i;
	int	j;

	i = -1;
	if (ft_strlen(base) < 2)
		return (0);
	while (base[++i + 1])
	{
		j = i;
		while (base[++j])
		{
			if (base[i] == base[j] || base[i] == '-' || base[i] == '+'
				|| base[j] == '-' || base[j] == '+' || base[i] <= 32
				|| base[i] >= 127 || base[j] <= 32 || base[j] >= 127)
				return (0);
		}
	}
	return (1);
}

int	index_in_base(char c, char *base)
{
	int	i;

	i = 0;
	while (base[i])
	{
		if (base[i] == c)
			return (i);
		i++;
	}
	return (-1);
}

int	ft_atoi_base(char *str, char *base)
{
	int	values;
	int	neg;
	int	lenght;
	int	i;

	if (!is_valid_base(base))
		return (0);
	i = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == ' ')
		i++;
	neg = 1;
	while (str[i] == '+' || str[i] == '-')
		if (str[i++] == '-')
			neg = neg * -1;
	values = 0;
	lenght = ft_strlen(base);
	while (str[i])
	{
		if (index_in_base(str[i], base) == -1)
			return (0);
		values = values * lenght;
		values = values + index_in_base(str[i++], base);
	}
	return (values * neg);
}

/*
#include <stdio.h>
#include <stdlib.h>

int    main(int argc, char *argv[])
{
    if (1 < argc)
    {
        printf("ft_atoi_base = '%d'\n", ft_atoi_base(argv[1], argv[2]));
    }
    else
        printf("required 'nb' 'base'\n");
}
*/
