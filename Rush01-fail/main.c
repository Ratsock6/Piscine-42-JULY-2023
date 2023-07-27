/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aallou-v <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/15 12:01:27 by aallou-v          #+#    #+#             */
/*   Updated: 2023/07/15 14:08:27 by aallou-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int	ft_strlen(char *str);

int	is_number_valid(char c);

int	is_space(char c);

void	rush(int *up, int *down, int *left, int *right);

int	ft_atoi(char *str);

int	checkerror(char *argv)
{
	int	i;

	i = -0;
	if (ft_strlen(argv) != 31)
		return (0);
	while (argv[++i])
	{
		if (i % 2 == 0)
		{
			if (!is_number_valid(argv[i]))
				return (0);
		}
		else
		{
			if (!is_space(argv[i]))
				return (0);
		}
	}
	return (1);
}

int	*pickup_tabint(char *argv, int start, int size)
{
	printf("test\n");
	int	i;
	int	*tab;

	i = 0;
	tab = malloc(sizeof(int) * 4);
	while (argv[start] && start < size)
	{
		if(argv[start] == ' ')
		{
			start++;
			continue ;
		}
		tab[i] = argv[start] - 48;
		i++;
	}
	return (tab);
}

int	main(int argc, char **argv)
{
	if (argc != 2)
	{
		write(1, "Error\n", 6);
		return (1);
	}
	if(checkerror(argv[1]) == 0)
	{
		write(1, "Error\n", 6);
		return (1);
	}
	printf("test\n");
	rush(pickup_tabint(argv[1], 0, 6), pickup_tabint(argv[1], 0, 6), pickup_tabint(argv[1], 0, 6), pickup_tabint(argv[1], 0, 6));
	return (0);
}
