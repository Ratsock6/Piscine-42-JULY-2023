/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvandepu <rvandepu@student.42lehavre.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 22:51:08 by rvandepu          #+#    #+#             */
/*   Updated: 2023/07/24 18:02:01 by rvandepu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"
#include "bsq.h"

int	ft_read_file_return(char **str, char *buf, int c, int i);

int	ft_read_file(char **str, int fd)
{
	char	*buf;
	int		c;
	int		o;
	int		i;

	buf = malloc(READ_SIZE);
	if (buf == NULL)
		return (0);
	c = 1;
	o = 0;
	i = 0;
	while (c > 0)
	{
		c = read(fd, buf + i, READ_SIZE);
		i += c;
		if (i > o)
		{
			buf = ft_realloc(buf, o += READ_SIZE);
			if (buf == NULL)
				return (0);
		}
	}
	return (ft_read_file_return(str, buf, c, i));
}

int	ft_read_file_return(char **str, char *buf, int c, int i)
{
	if (c == 0)
	{
		buf[i] = '\0';
		*str = ft_strdup(buf);
		free(buf);
		if (*str == NULL)
			return (0);
		return (1);
	}
	free(buf);
	return (0);
}
