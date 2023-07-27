/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aallou-v <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/15 15:22:42 by aallou-v          #+#    #+#             */
/*   Updated: 2023/07/15 17:09:22 by aallou-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	getmallocsize(int size, char **strs, char *sep)
{
	int	i;
	int	tab;

	if (size == 0)
		return (1);
	i = 0;
	tab = 0;
	while (i < size)
		tab += ft_strlen(strs[i++]);
	tab += ft_strlen(sep) * (size - 1);
	return (tab + 1);
}

char	*ft_strcat(char *dest, char *src)
{
	int	i;
	int	i2;

	i = 0;
	i2 = 0;
	while (dest[i] != '\0')
		i++;
	while (src[i2] != '\0')
	{
		dest[i] = src[i2];
		i++;
		i2++;
	}
	dest[i] = '\0';
	return (dest);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	char	*tab;
	int		i;

	tab = malloc(getmallocsize(size, strs, sep) * sizeof(char));
	if (!tab)
		return (NULL);
	tab[0] = 0;
	if (size == 0)
		return (tab);
	i = 0;
	while (i < size)
	{
		ft_strcat(tab, strs[i]);
		if (i != size - 1)
			ft_strcat(tab, sep);
		i++;
	}
	tab[ft_strlen(tab)] = '\0';
	return (tab);
}
