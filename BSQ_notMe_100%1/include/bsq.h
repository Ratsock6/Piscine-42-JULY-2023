/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsq.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjouenne <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 13:07:02 by cjouenne          #+#    #+#             */
/*   Updated: 2023/07/25 17:17:04 by rvandepu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BSQ_H
# define BSQ_H

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>

# define READ_SIZE 4096

typedef struct s_map {
	char	**map;
	int		w;
	int		h;
	char	c[3];
}	t_map;

// ft_solver.c
int		ft_solve(t_map m);

// parser.c
int		ft_read_file(char **str, int fd);
int		ft_parse_first_line(char *buf, t_map *map, int *start);
int		ft_free_map(t_map m);
int		ft_parse_map(t_map *map, char *file, int start);

// verificator.c
int		ft_verif_map(char *file_buffer);
int		ft_verif_line(char *file_buffer);

// post_verificator.c
int		ft_post_verif_map(t_map *map);
int		ft_verif_char(t_map *map);
int		ft_is_valid_char(char c, t_map *map);
int		ft_verif_map_char(t_map *map);

// ft_split.c
char	*_ft_strdup(char *src, char *charset);
char	**ft_split(char *str, char *charset);
int		ft_strlen(char *str);
int		is_charset(char *str, char *charset, int start);
int		count_word(char *str, char *charset);
#endif
