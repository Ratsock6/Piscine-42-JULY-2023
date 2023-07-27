/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aallou-v <aallou-v@student.42lehavre.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/21 23:15:23 by aallou-v          #+#    #+#             */
/*   Updated: 2023/07/23 20:59:18 by rvandepu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush_02.h"

int	rush(char *dict_path, char *nbr_str)
{
	struct s_entry	*dict;
	int				fd;
	char			*str;

	fd = open(dict_path, O_RDONLY);
	if (fd == -1)
		return (0);
	if (!ft_read_file(&str, fd))
		return (0);
	close(fd);
	if (!ft_parse_dict(&dict, str))
	{
		free(str);
		return (0);
	}
	free(str);
	if (!ft_filter_dict(&dict))
		return (!ft_free_dict(dict, -1));
	str = ft_parse_number(nbr_str);
	if (str == NULL)
		return (!ft_free_dict(dict, -1));
	ft_show(dict, str);
	ft_free_dict(dict, -1);
	free(str);
	return (1);
}

int	ft_main_error(char *str, int should_free)
{
	if (should_free && str)
		free(str);
	write(2, "Error\n", 6);
	return (1);
}

int	main(int argc, char *argv[])
{
	char	*path;
	char	*nbr_str;

	if (argc <= 3)
	{
		path = DICT_PATH;
		if (argc == 3)
			path = argv[1];
		nbr_str = argv[argc - 1];
		if (argc == 1 && !ft_read_file(&nbr_str, 0))
			return (ft_main_error(nbr_str, argc == 1));
		if (!ft_is_valid_nbr(nbr_str, argc == 1))
			return (ft_main_error(nbr_str, argc == 1));
		if (!rush(path, nbr_str))
		{
			write(1, "Dict ", 5);
			return (ft_main_error(nbr_str, argc == 1));
		}
		if (argc == 1)
			free(nbr_str);
		return (0);
	}
	else
		return (ft_main_error(*argv, 0));
}
