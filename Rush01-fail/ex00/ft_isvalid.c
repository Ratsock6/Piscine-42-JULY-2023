/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isvalid.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aallou-v <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/15 13:31:29 by aallou-v          #+#    #+#             */
/*   Updated: 2023/07/15 14:03:43 by aallou-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	is_number_valid(char c)
{
	if (c >= '1' && c <= '4')
		return (1);
	return (0);
}

int	is_space(char c)
{
	if (c == ' ')
		return (1);
	return (0);
}