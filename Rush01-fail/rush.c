/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aallou-v <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/16 14:48:04 by aallou-v          #+#    #+#             */
/*   Updated: 2023/07/16 14:48:07 by aallou-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	rush(int *up, int *down, int *left, int *right)
{
	printf("test\n");
	int	i;

	i = -1;
	while (++i < 4)
		printf("%i ", up[i]);
	printf("\n");
	i = -1;
	while (++i < 4)
		printf("%i ", down[i]);
	printf("\n");
	i = -1;
	while (++i < 4)
		printf("%i ", left[i]);
	printf("\n");
	i = -1;
	while (++i < 4)
		printf("%i\n", right[i]);
	printf("\n");
}