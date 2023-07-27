/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   post_verificator.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjouenne <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 20:07:33 by cjouenne          #+#    #+#             */
/*   Updated: 2023/07/25 17:21:22 by rvandepu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

int	ft_post_verif_map(t_map *map)
{
	if (!ft_verif_char(map))
		return (0);
	return (1);
}

int	ft_verif_char(t_map *map)
{
	int	i;
	int	j;
	int	size;

	i = -1;
	size = 3;
	while (++i < size - 1)
	{
		j = i;
		while (++j < size)
		{
			if (map->c[i] == map->c[j])
				return (0);
		}
	}
	if (!ft_verif_map_char(map))
		return (0);
	return (1);
}

int	ft_is_valid_char(char c, t_map *map)
{
	int	i;
	int	res;

	i = 0;
	res = 0;
	while (i < 2)
	{
		if (c == map->c[i++])
			res++;
	}
	return (res);
}

int	ft_verif_map_char(t_map *map)
{
	int	i;
	int	j;

	i = -1;
	while (++i < map->h)
	{
		j = -1;
		while (++j < map->w)
		{
			if (!ft_is_valid_char(map->map[i][j], map))
				return (0);
		}
	}
	return (1);
}
