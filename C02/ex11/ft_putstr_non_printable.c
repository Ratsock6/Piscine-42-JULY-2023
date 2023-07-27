/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aallou-v <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 22:11:32 by aallou-v          #+#    #+#             */
/*   Updated: 2023/07/12 22:41:38 by aallou-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int	ft_str_is_printable(char c)
{
	if (c < 0x20 || c > 0x7e)
		return (0);
	return (1);
}

void	ft_putstr_non_printable(char *str)
{
	char			*base;
	unsigned char	c;
	int				i;

	base = "0123456789abcdef";
	i = -1;
	while (str[++i])
	{
		if (ft_str_is_printable(str[i]) == 1)
		{
			ft_putchar(str[i]);
			continue ;
		}
		c = (unsigned char) str[i];
		write (1, "\\", 1);
		ft_putchar(base[c / 16]);
		ft_putchar(base[c % 16]);
	}
}

/*
int	main(void)
{
	ft_putstr_non_printable("Coucou\ntu vas bien ?");
	return (0);
}
*/
