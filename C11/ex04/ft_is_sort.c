/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aallou-v <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 12:43:00 by aallou-v          #+#    #+#             */
/*   Updated: 2023/07/25 12:49:55 by aallou-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_ascending(int *tab, int length, int (*f) (int, int))
{
	int	i;

	i = -1;
	while (++i < length - 1)
		if (f(tab[i], tab[i + 1]) > 0)
			return (0);
	return (1);
}

int	ft_descending(int *tab, int length, int (*f) (int, int))
{
	int	i;

	i = -1;
	while (++i < length - 1)
		if (f(tab[i], tab[i + 1]) < 0)
			return (0);
	return (1);
}

int	ft_is_sort(int *tab, int length, int (*f) (int, int))
{
	if (ft_ascending(tab, length, f))
		return (1);
	else if (ft_descending(tab, length, f))
		return (1);
	return (0);
}
