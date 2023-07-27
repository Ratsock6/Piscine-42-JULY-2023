/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aallou-v <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 12:31:57 by aallou-v          #+#    #+#             */
/*   Updated: 2023/07/13 13:42:45 by aallou-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_range(int min, int max)
{
	int	*tab;
	int	i;

	tab = (int *) malloc(sizeof(int) * (max - min));
	if (min > max || max == min)
		return (0);
	i = -1;
	while (min < max)
		tab[++i] = min++;
	return (tab);
}

/*
int	main(void)
{
	int	*tab[] = ft_range(0, 5);
	return (0);
}
*/
