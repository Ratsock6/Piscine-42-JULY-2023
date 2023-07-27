/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verificator.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjouenne <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 18:05:45 by cjouenne          #+#    #+#             */
/*   Updated: 2023/07/25 12:05:10 by rvandepu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"
#include "ft.h"

int	ft_verif_map(char *file_buffer)
{
	int	i;

	i = -1;
	while (file_buffer[++i])
		;
	if (i < 7 || file_buffer[i - 1] != '\n')
		return (0);
	i = 0;
	while (file_buffer[i] != '\n')
		i++;
	if (!ft_verif_line(&file_buffer[i + 1]))
		return (0);
	return (1);
}

int	ft_verif_line(char *file_buffer)
{
	int	line_len;
	int	n;
	int	i;
	int	is_first_line;

	if (*file_buffer == '\0' || *file_buffer == '\n')
		return (0);
	n = 0;
	i = -1;
	is_first_line = 1;
	while (file_buffer[++i])
	{
		if (file_buffer[i] == '\n')
		{
			is_first_line = 0;
			if (line_len != n)
				return (0);
			n = 0;
			continue ;
		}
		n++;
		if (is_first_line)
			line_len = n;
	}
	return (1);
}
