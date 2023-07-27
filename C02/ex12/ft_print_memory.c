/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_memory.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aallou-v <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 17:20:40 by aallou-v          #+#    #+#             */
/*   Updated: 2023/07/27 18:15:44 by aallou-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_hexa(unsigned long long addr, int size)
{
	char	*base;
	char	hex[16];
	int		i;

	base = "0123456789abcdef";
	i = -1;
	while (++i < size)
		hex[i] = '0';
	i = -1;
	while (addr != 0)
	{
		hex[++i] = base[addr % 16];
		addr /= 16;
	}
	while (size > 0)
		write(1, &hex[--size], 1);
}

void	ft_char_to_hex(char *addr, int index, int stop, int max)
{
	while (index < stop)
	{
		ft_hexa((unsigned long long)addr[index], 2);
		if (index % 2)
			write(1, " ", 1);
		index++;
	}
	while (index < max)
	{
		write(1, "  ", 2);
		if (index % 2)
			write(1, " ", 1);
		index++;
	}
}

void	ft_print_str(char *str, int index, int stop)
{
	while (index < stop)
	{
		if (str[index] >= ' ' && str[index] <= '~')
		{
			write(1, &str[index], 1);
			index++;
		}
		else
		{
			write(1, ".", 1);
			index++;
		}
	}
	write(1, "\n", 1);
}

int	ft_min(int a, int b)
{
	if (a < b)
		return (a);
	return (b);
}

void	*ft_print_memory(void *addr, unsigned int size)
{
	unsigned int	i;

	i = 0;
	if (size <= 0)
		return (addr);
	while (i < size)
	{
		ft_hexa((unsigned long long)&addr + i, 16);
		write(1, ": ", 2);
		ft_char_to_hex((char *)addr, i, ft_min(i + 16, size), i + 16);
		ft_print_str((char *)addr, i, ft_min(i + 16, size));
		i += 16;
	}
	return (addr);
}
