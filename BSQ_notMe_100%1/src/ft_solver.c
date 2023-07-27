/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_solver.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvandepu <rvandepu@student.42lehavre.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 18:43:05 by rvandepu          #+#    #+#             */
/*   Updated: 2023/07/25 17:28:57 by rvandepu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"
#include "ft.h"

int	ft_free_tab(int **tab, int n)
{
	int	i;

	i = 0;
	while (i < n || (n == -1 && tab[i]))
		free(tab[i++]);
	free(tab);
	return (1);
}

int	ft_create_tab(int ***tab, t_map m)
{
	int	i;

	*tab = malloc(sizeof(int *) * (m.h + 1));
	if (*tab == NULL)
		return (0);
	i = -1;
	while (++i < m.h)
	{
		(*tab)[i] = malloc(sizeof(int) * m.w);
		if ((*tab)[i] == NULL)
			return (!ft_free_tab(*tab, i));
	}
	i = -1;
	while (++i < m.w * m.h)
		(*tab)[i / m.w][i % m.w] = m.map[i / m.w][i % m.w] != m.c[1];
	(*tab)[m.h] = NULL;
	return (1);
}

void	ft_disp_map(t_map m, int x, int y, int size)
{
	int	i;
	int	j;

	i = -1;
	while (++i < m.h)
	{
		j = -1;
		while (++j < m.w)
		{
			if (x <= j && j < x + size && y <= i && i < y + size)
				write(1, m.c + 2, 1);
			else
				write(1, m.map[i] + j, 1);
		}
		write(1, "\n", 1);
	}
}

int	ft_solve(t_map m)
{
	int	**tab;
	int	i;
	int	emacs;

	if (!ft_create_tab(&tab, m))
		return (0);
	i = m.w * (m.h - 1);
	while (i-- > 0 && m.w > 1 && m.h > 1 && ((i % m.w == m.w - 1 && --i) || 1))
		tab[i / m.w][i % m.w] *= 1 + ft_min(tab[(i / m.w) + 1][(i % m.w) + 1], \
			ft_min(tab[(i / m.w) + 1][i % m.w], tab[i / m.w][(i % m.w) + 1]));
	emacs = 0;
	i = -1;
	while (++i < m.w * m.h)
		if (tab[i / m.w][i % m.w] > tab[emacs / m.w][emacs % m.w])
			emacs = i;
	ft_disp_map(m, emacs % m.w, emacs / m.w, tab[emacs / m.w][emacs % m.w]);
	ft_free_tab(tab, -1);
	return (1);
}
