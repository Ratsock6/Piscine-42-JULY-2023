/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fibonacci.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aallou-v <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 13:37:29 by aallou-v          #+#    #+#             */
/*   Updated: 2023/07/11 21:05:35 by aallou-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_fibonacci(int index)
{
	int	i;
	int	n0;
	int	n1;
	int	n2;

	i = 0;
	n0 = 0;
	n1 = 1;
	if (index == 0)
		return (0);
	if (index < 0)
		return (-1);
	while (i < index)
	{
		n2 = n1 + n0;
		n0 = n1;
		n1 = n2;
		i++;
	}
	return (n0);
}
