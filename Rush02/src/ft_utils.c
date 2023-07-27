/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvandepu <rvandepu@student.42lehavre.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/22 12:40:17 by rvandepu          #+#    #+#             */
/*   Updated: 2023/07/23 20:54:22 by rvandepu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush_02.h"

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

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	write(1, str, i);
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

long long	ft_atoi(char *str)
{
	long long	n;

	n = 0;
	while (*str == ' ')
		str++;
	if (*str == '+')
		str++;
	while ('0' <= *str && *str <= '9')
		n = (n * 10) + (*str++ - '0');
	return (n);
}
