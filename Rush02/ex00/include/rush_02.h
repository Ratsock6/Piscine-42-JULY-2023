/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush_02.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvandepu <rvandepu@student.42lehavre.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/22 12:24:44 by rvandepu          #+#    #+#             */
/*   Updated: 2023/07/23 20:52:44 by rvandepu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RUSH_02_H
# define RUSH_02_H

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>

# define DICT_PATH "dicts/numbers.dict"
# define READ_SIZE 1024

typedef struct s_entry {
	long long	n;
	char		*v;
}	t_entry;

# define FILTER_SIZE 32

static const long long	g_filter[FILTER_SIZE] = {
	0,	1,	2,	3,	4,
	5,	6,	7,	8,	9,
	10,	11,	12,	13,	14,
	15,	16,	17,	18,	19,
	20,	30,	40,	50,	60,
	70,	80,	90,	100,
	1000,
	1000000,
	1000000000
};

// ft_parser
int			ft_parse_dict(struct s_entry **dict, char *dict_str);
int			ft_filter_dict(struct s_entry **dict);
char		*ft_parse_number(char *nbr_str);

// ft_read_utils
int			ft_read_file(char **str, int fd);

// ft_parse_utils
int			ft_is_valid_nbr(char *str, int is_stdin);
int			ft_count_lines(char *str);
int			ft_is_valid_line_start(char *line);
int			ft_cpy_line_val(struct s_entry *d, char *src, int start, int end);
int			ft_free_dict(struct s_entry *dict, int n);

// ft_utils
void		*ft_realloc(char *buf, int size);
char		*ft_strdup(char *src);
void		ft_putstr(char *str);
int			ft_strlen(char *str);
long long	ft_atoi(char *str);

// ft_algo
void		ft_show(t_entry *dict, char *values);

#endif
