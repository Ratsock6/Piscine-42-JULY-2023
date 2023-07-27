/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_algo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aallou-v <aallou-v@student.42lehavre.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/22 15:01:49 by aallou-v          #+#    #+#             */
/*   Updated: 2023/07/23 22:26:08 by rvandepu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush_02.h"

int	stris0(char *values)
{
	int	i;

	i = -1;
	while (values[++i])
		if (values[i] != '0')
			return (0);
	return (1);
}

void	ft_putvalues(t_entry *dict, long long values, int x, int space)
{
	int	i;

	i = 0;
	if (values == 0 && x == 0)
		return ;
	while (dict[i].n != values)
		i++;
	ft_putstr(dict[i].v);
	if (space)
		write(1, " ", 1);
	else
		write(1, "\n", 1);
}

void	ft_algo(t_entry *dict, char *values, int mod, int s)
{
	if (ft_strlen(values) == 3)
	{
		ft_putvalues(dict, values[0] - 48, 0, 1);
		if (values[0] != '0')
			ft_putvalues(dict, 100, 0, mod || s != 100);
		if (values[1] - 48 != 0 && values[1] - 48 != 1)
			ft_putvalues(dict, (values[1] - 48) * 10, 0, mod || s != 10);
		if (values[2] - 48 != 0 && values[1] - 48 != 1)
			ft_putvalues(dict, values[2] - 48, 0, mod || s != 1);
		if (values[1] - 48 == 1)
			ft_putvalues(dict, 10 + values[2] - 48, 0, mod || s != 1);
	}
	if (ft_strlen(values) == 2)
	{
		if (values[0] - 48 != 1)
			ft_putvalues(dict, (values[0] - 48) * 10, 0, mod || s != 10);
		if (values[1] - 48 != 0 && values[0] - 48 != 1)
			ft_putvalues(dict, values[1] - 48, 0, mod || s != 1);
		if (values[0] - 48 == 1)
			ft_putvalues(dict, 10 + values[1] - 48, 0, mod || s != 1);
	}
	if (ft_strlen(values) == 1)
		ft_putvalues(dict, values[0] - 48, 0, mod || s != 1);
	if (mod)
		ft_putvalues(dict, mod, 0, !(mod <= s && s <= mod * 100));
}

int	ft_last(char vals[4][4])
{
	int	i;
	int	n;

	i = -1;
	while (++i < 12)
	{
		if (vals[i / 3][i % 3] == '0')
			n *= 10;
		else
			n = 1;
	}
	return (n);
}

void	ft_show(t_entry *dict, char *values)
{
	int		len;
	int		i;
	char	vals[4][4];

	if (stris0(values))
		ft_putvalues(dict, 0, 1, 0);
	if (stris0(values))
		return ;
	len = ft_strlen(values);
	i = -1;
	while (++i < 16)
		vals[i / 4][i % 4] = '\0';
	i = -1;
	while (++i < len)
		vals[(12 - len + i) / 3][(12 - len + i) % 3] = values[i];
	i = 12 - len;
	if (len > 9 && !stris0(vals[0] + i))
		ft_algo(dict, vals[0] + i, 1000000000, ft_last(vals));
	if (len > 6 && !stris0(vals[1] + i % 3 *!(len > 9)))
		ft_algo(dict, vals[1] + i % 3 *!(len > 9), 1000000, ft_last(vals));
	if (len > 3 && !stris0(vals[2] + i % 3 *!(len > 6)))
		ft_algo(dict, vals[2] + i % 3 *!(len > 6), 1000, ft_last(vals));
	ft_algo(dict, vals[3] + i % 3 *!(len > 3), 0, ft_last(vals));
}
