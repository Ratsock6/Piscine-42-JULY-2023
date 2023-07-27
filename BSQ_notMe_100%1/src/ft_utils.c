/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjouenne <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 14:56:50 by cjouenne          #+#    #+#             */
/*   Updated: 2023/07/24 21:42:14 by rvandepu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

void	*ft_realloc(char *buf, int size)
{
	char	*new_buf;
	int		i;

	new_buf = malloc(size + READ_SIZE);
	if (new_buf == NULL)
	{
		free(buf);
		return (NULL);
	}
	i = -1;
	while (++i < size)
		new_buf[i] = buf[i];
	free(buf);
	return (new_buf);
}

char	*ft_strdup(char *src)
{
	char	*dest;
	int		i;

	i = 0;
	while (src[i])
		i++;
	dest = malloc(i + 1);
	if (dest)
	{
		dest[i] = '\0';
		while (i--)
			dest[i] = src[i];
	}
	return (dest);
}

int	ft_min(int a, int b)
{
	if (a < b)
		return (a);
	else
		return (b);
}

int	ft_atoi(char *str)
{
	int	n;

	n = 0;
	while ('0' <= *str && *str <= '9')
		n = (n * 10) + (*str++ - '0');
	return (n);
}
