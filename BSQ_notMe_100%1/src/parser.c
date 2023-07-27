/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjouenne <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 13:44:56 by cjouenne          #+#    #+#             */
/*   Updated: 2023/07/25 17:15:52 by rvandepu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"
#include "bsq.h"

int	ft_parse_first_line(char *buf, t_map *map, int *start)
{
	int	i;
	int	j;

	i = 0;
	while (buf[i] != '\n' && buf[i])
		i++;
	if (i < 4 || buf[i] == '\0')
		return (0);
	j = 4;
	while (--j > 0)
		map->c[3 - j] = buf[i - j];
	i -= 3;
	j = 0;
	map->h = 0;
	while (j < i && '0' <= buf[j] && buf[j] <= '9')
		map->h = (map->h * 10) + (int)(buf[j++] - '0');
	if (j < i)
		return (0);
	*start = i + 3 + 1;
	return (1);
}

int	ft_free_map(t_map m)
{
	int	i;

	i = 0;
	while (m.map && m.map[i])
		free(m.map[i++]);
	if (m.map)
		free(m.map);
	return (1);
}

int	ft_parse_map(t_map *map, char *file, int start)
{
	int	i;

	if (!ft_verif_map(file))
		return (0);
	file += start;
	i = -1;
	while (file[++i] != '\n')
		;
	map->w = i;
	map->map = ft_split(file, "\n");
	i = -1;
	while (map->map[++i])
		;
	if (i != map->h)
		return (!ft_free_map(*map));
	return (1);
}
