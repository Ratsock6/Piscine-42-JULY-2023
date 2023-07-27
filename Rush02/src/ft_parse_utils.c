/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvandepu <rvandepu@student.42lehavre.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/22 12:58:05 by rvandepu          #+#    #+#             */
/*   Updated: 2023/07/23 22:22:24 by rvandepu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush_02.h"

int	ft_is_valid_nbr(char *str, int is_stdin)
{
	int	i;
	int	s;

	i = 0;
	while (str[i] == ' ')
		i++;
	if (str[i] == '+')
		i++;
	s = i;
	while ('0' <= str[i] && str[i] <= '9')
		i++;
	if (s == i || i - s > 12)
		return (0);
	else
		return (str[i] == '\0'
			|| (is_stdin && str[i] == '\n' && str[i + 1] == '\0'));
}

int	ft_count_lines(char *str)
{
	int	i;
	int	n;
	int	c;

	i = -1;
	n = 0;
	c = 1;
	while (str[++i] != '\0')
	{
		if (c && ' ' <= str[i] && str[i] <= '~')
		{
			n++;
			c = 0;
		}
		else if (str[i] == '\n')
			c = 1;
	}
	return (n);
}

int	ft_is_valid_line_start(char *line)
{
	int	i;
	int	s;

	i = 0;
	while (line[i] == ' ')
		i++;
	if (line[i] == '+')
		i++;
	s = i;
	while ('0' <= line[i] && line[i] <= '9')
		i++;
	if (s == i)
		return (0);
	while (line[i] == ' ')
		i++;
	if (line[i++] != ':')
		return (0);
	return (i);
}

int	ft_cpy_line_val(struct s_entry *d, char *src, int start, int end)
{
	int		i;
	char	*dest;

	dest = malloc(end - start + 1);
	if (dest == NULL)
		return (0);
	i = 0;
	while (start + i < end)
	{
		while (src[start + i - 1] == ' ' && src[start + i] == ' ')
			start++;
		dest[i] = src[start + i];
		i++;
	}
	dest[i] = '\0';
	d->v = ft_strdup(dest);
	if (d->v == NULL)
	{
		free(dest);
		return (0);
	}
	free(dest);
	return (1);
}

int	ft_free_dict(struct s_entry *dict, int n)
{
	int	i;

	i = 0;
	while (i < n || (n <= -1 && dict[i].v))
	{
		if (n != -2)
			free(dict[i].v);
		else if (dict[i].n != -1)
			free(dict[i].v);
		i++;
	}
	free(dict);
	return (1);
}
