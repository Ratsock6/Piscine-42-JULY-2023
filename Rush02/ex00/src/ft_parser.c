/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvandepu <rvandepu@student.42lehavre.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/22 15:54:17 by rvandepu          #+#    #+#             */
/*   Updated: 2023/07/23 20:44:39 by rvandepu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush_02.h"

int	ft_parse_line(struct s_entry *entry, char *line)
{
	int	i;
	int	s;

	i = ft_is_valid_line_start(line);
	if (i == 0)
		return (0);
	while (line[i] == ' ')
		i++;
	s = i;
	while (' ' <= line[i] && line[i] <= '~')
		i++;
	if (i == s || line[i] != '\n')
		return (0);
	while (line[--i] == ' ')
		;
	entry->n = ft_atoi(line);
	if (!ft_cpy_line_val(entry, line, s, i + 1))
		return (0);
	return (1);
}

int	ft_parse_dict(struct s_entry **dict, char *dict_str)
{
	int	i;
	int	n;
	int	c;

	*dict = malloc(sizeof(struct s_entry) * (ft_count_lines(dict_str) + 1));
	if (*dict == NULL)
		return (0);
	i = -1;
	n = 0;
	c = 1;
	while (dict_str[++i])
	{
		if (c && ' ' <= dict_str[i] && dict_str[i] <= '~')
		{
			if (ft_parse_line(*dict + n, dict_str + i))
				n++;
			c = 0;
		}
		else if (dict_str[i] == '\n')
			c = 1;
	}
	(*dict)[n].v = NULL;
	if (n != ft_count_lines(dict_str))
		return (!ft_free_dict(*dict, n));
	return (1);
}

int	ft_is_nb_in_dict(struct s_entry *dict, long long nb)
{
	while (dict->v)
		if (dict++->n == nb)
			return (1);
	return (0);
}

int	ft_filter_dict(struct s_entry **dict)
{
	int				i;
	int				j;
	struct s_entry	*new_dict;

	i = 0;
	while (i < FILTER_SIZE)
		if (!ft_is_nb_in_dict(*dict, g_filter[i++]))
			return (0);
	new_dict = malloc(sizeof(struct s_entry) * (FILTER_SIZE + 1));
	if (new_dict == NULL)
		return (0);
	i = -1;
	while (++i < FILTER_SIZE)
	{
		j = 0;
		while ((*dict)[j].n != g_filter[i])
			j++;
		new_dict[i].n = g_filter[i];
		new_dict[i].v = (*dict)[j].v;
		(*dict)[j].n = -1;
	}
	new_dict[i].v = NULL;
	ft_free_dict(*dict, -2);
	*dict = new_dict;
	return (1);
}

char	*ft_parse_number(char *nbr_str)
{
	int	i;
	int	l;

	i = 0;
	l = ft_strlen(nbr_str);
	while (nbr_str[i] == ' ')
		i++;
	if (nbr_str[i] == '+')
		i++;
	while (nbr_str[i] == '0' && i < l - 1)
		i++;
	return (ft_strdup(nbr_str + i));
}
