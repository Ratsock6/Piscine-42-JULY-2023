/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aallou-v <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 12:51:08 by aallou-v          #+#    #+#             */
/*   Updated: 2023/07/25 12:55:53 by aallou-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_strlen(char *str);
int		stris0(char *values);
void	ft_putnbr(int nb);
void	ft_putstr(char *str);
int		ft_atoi(char *str);
int		ft_addition(int i1, int i2);
int		ft_subtraction(int i1, int i2);
int		ft_multiplication(int i1, int i2);
int		ft_division(int i1, int i2);
int		ft_modulo(int i1, int i2);

int	ft_calculate(int i1, int i2, int (*f) (int, int))
{
	int	calcul;

	calcul = f(i1, i2);
	return (calcul);
}

int	doop(int i1, char c, int i2)
{
	if (c == '+')
		return (ft_calculate(i1, i2, ft_addition));
	if (c == '-')
		return (ft_calculate(i1, i2, ft_subtraction));
	if (c == '*')
		return (ft_calculate(i1, i2, ft_multiplication));
	if (c == '/')
		return (ft_calculate(i1, i2, ft_division));
	if (c == '%')
		return (ft_calculate(i1, i2, ft_modulo));
	return (0);
}

int	main(int argc, char **argv)
{
	char	c;

	if (argc != 4)
		return (1);
	if (ft_strlen(argv[2]) != 1)
	{
		ft_putnbr(0);
		ft_putstr("\n");
		return (1);
	}
	c = argv[2][0];
	if (c == '%' && stris0(argv[3]))
	{
		ft_putstr("Stop : modulo by zero\n");
		return (1);
	}
	if (c == '/' && stris0(argv[3]))
	{
		ft_putstr("Stop : division by zero\n");
		return (1);
	}
	ft_putnbr(doop(ft_atoi(argv[1]), c, ft_atoi(argv[3])));
	ft_putstr("\n");
	return (0);
}
