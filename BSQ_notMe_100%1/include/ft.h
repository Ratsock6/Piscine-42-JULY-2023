/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjouenne <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 14:54:53 by cjouenne          #+#    #+#             */
/*   Updated: 2023/07/24 21:42:32 by rvandepu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_H
# define FT_H

# include <stdlib.h>

void	*ft_realloc(char *buf, int size);
char	*ft_strdup(char *src);
int		ft_min(int a, int b);
int		ft_atoi(char *str);

#endif
