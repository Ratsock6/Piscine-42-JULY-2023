/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush01.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cduprez <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/08 07:35:14 by cduprez           #+#    #+#             */
/*   Updated: 2023/07/08 12:38:29 by jkerthe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

void	ft_show(int x_origin, int x, int y_origin, int y)
{
	while (x > 0)
	{
		if (((y_origin == y) || (y == 1)))
		{
			if ((x_origin == x && y == y_origin) || (x == 1 && y == y_origin))
				ft_putchar('A');
			else if ((x_origin == x && y == 1) || (x == 1 && y == 1))
				ft_putchar('C');
			else
				ft_putchar('B');
		}
		else if (x == x_origin || x == 1)
			ft_putchar('B');
		else
			ft_putchar(' ');
		x -= 1;
	}
}

void	rush(int x, int y)
{
	int	x_origin;
	int	y_origin;

	x_origin = x;
	y_origin = y;
	while (y > 0)
	{
		ft_show(x_origin, x, y_origin, y);
		ft_putchar('\n');
		y -= 1;
	}
}
