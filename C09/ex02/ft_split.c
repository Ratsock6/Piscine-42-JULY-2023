/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aallou-v <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 08:58:48 by aallou-v          #+#    #+#             */
/*   Updated: 2023/07/24 21:17:21 by aallou-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>

void	ft_strncpy(char *dest, char *src, int count)
{
	int	i;

	i = 0;
	while (src[i] && i < count)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
}

int	is_sep(char *charset, char c)
{
	int		i;

	i = 0;
	while (charset[i] != '\0')
	{
		if (c == charset[i])
			return (1);
		i++;
	}
	if (c == '\0')
		return (1);
	return (0);
}

int	get_word_length(char *str, char *charset)
{
	int	count;

	count = 0;
	while (str[count] && !is_sep(charset, str[count]))
		count++;
	return (count);
}

int	count_words(char *str, char *sep)
{
	int	i;
	int	wc;

	i = 0;
	wc = 0;
	while (str[i])
	{
		if (!is_sep(sep, str[i]) && (is_sep(sep, str[i + 1])))
			wc++;
		i++;
	}
	return (wc);
}

char	**ft_split(char *str, char *charset)
{
	char	**splits;
	int		i;
	int		j;
	int		count;

	i = -1;
	j = 0;
	splits = (char **)malloc((count_words(str, charset) + 1) * sizeof(char *));
	if (!splits)
		return (NULL);
	while (str[++i])
	{
		if (!is_sep(charset, str[i]))
		{
			count = get_word_length(&str[i], charset);
			splits[j] = (char *)malloc((count + 1) * sizeof(char));
			if (splits[j] == NULL)
				return (NULL);
			ft_strncpy(splits[j++], &str[i], count);
			i += count - 1;
		}
	}
	splits[j] = NULL;
	return (splits);
}
/*
int	main(void)
{
	int		i = -1;
	char	string[] = ",   ,hello, world,  tes,t jdjdj, hdhd,dkdk  ,,   " ;
	char	**splits = ft_split(string, ", ");
	while (splits[++i])
	{
		printf("%s\n", splits[i]);
		free(splits[i]);
	}
	free(splits);
	return (0);
}
*/
