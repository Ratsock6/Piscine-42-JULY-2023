/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjouenne <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 21:28:07 by cjouenne          #+#    #+#             */
/*   Updated: 2023/07/25 00:13:29 by rvandepu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

int	is_charset(char *str, char *charset, int start)
{
	int	i;

	i = -1;
	while (charset[++i])
		if (str[start] == charset[i])
			return (1);
	return (0);
}

int	count_word(char *str, char *charset)
{
	int	i;
	int	n;
	int	c;

	i = -1;
	n = 0;
	c = 1;
	while (str[++i])
	{
		if (c && !is_charset(str, charset, i))
		{
			n++;
			c = 0;
		}
		else if (is_charset(str, charset, i))
			c = 1;
	}
	return (n);
}

char	*_ft_strdup(char *src, char *charset)
{
	int		i;
	char	*buf;

	buf = (char *) malloc(sizeof(char) * ft_strlen(src) + 1);
	if (buf == NULL)
		return (NULL);
	i = 0;
	while (src[i] && !(is_charset(src, charset, i)))
	{
		buf[i] = src[i];
		++i;
	}
	buf[i] = '\0';
	return (buf);
}

char	**ft_split(char *str, char *charset)
{
	char	**split;
	int		i;
	int		j;

	split = (char **) malloc(sizeof(char *) * (count_word(str, charset) + 1));
	if (split == NULL)
		return (NULL);
	i = -1;
	j = 0;
	while (str[++i])
	{
		if (is_charset(str, charset, i))
			i += 0;
		else
		{
			split[j] = _ft_strdup(str + i, charset);
			i += ft_strlen(split[j]) - 1;
			j++;
		}
	}
	split[j] = 0;
	return (split);
}
