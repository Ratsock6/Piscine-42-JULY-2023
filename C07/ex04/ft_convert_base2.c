/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aallou-v <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 15:30:57 by aallou-v          #+#    #+#             */
/*   Updated: 2023/07/26 15:30:58 by aallou-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		ft_strlen(char *str);
void	ft_add_dest(char *base, char *dest, long nbr, int index);

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
	while (str[i] && index_in_base(str[i], base) != -1)
	{
		values = values * lenght;
		values = values + index_in_base(str[i++], base);
	}
	return (values * neg);
}

int	ft_malloc_dest(long nbr, char *base)
{
	int	size;

	size = 0;
	if (nbr < 0)
	{
		size++;
		nbr *= -1;
	}
	while (nbr >= ft_strlen(base))
	{
		size++;
		nbr /= ft_strlen(base);
	}
	return (size);
}

char	*ft_putnbr_base(long nbr, char *base, char *dest)
{
	int	count;

	count = ft_malloc_dest((long)nbr, base);
	dest = malloc(sizeof(char) * count + 1);
	if (nbr < 0)
	{
		dest[0] = '-';
		nbr *= -1;
	}
	ft_add_dest(base, dest, nbr, count);
	dest[count + 1] = '\0';
	return (dest);
}
