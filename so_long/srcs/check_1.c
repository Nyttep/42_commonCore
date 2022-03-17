/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdubois <pdubois@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 01:20:44 by pdubois           #+#    #+#             */
/*   Updated: 2022/03/17 18:16:31 by pdubois          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_check_min_char(char **map, int i, int j, int *check)
{
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'E')
				check[0]++;
			else if (map[i][j] == 'C')
				check[1] = 1;
			else if (map[i][j] == 'P')
				check[2]++;
			else if (map[i][j] == '1')
				check[3] = 1;
			j++;
		}
		i++;
	}
	i = -1;
	while (++i < 4)
		if (check[i] != 1)
			return (-1);
	return (1);
}

int	ft_check_char(char **map)
{
	int	i;
	int	j;
	int	check[4];

	i = -1;
	while (++i < 4)
		check[i] = 0;
	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] != '0' && map[i][j] != '1' && map[i][j] != 'C' &&
				map[i][j] != 'E' && map[i][j] != 'P' && map[i][j] != 'B')
				return (-1);
			j++;
		}
		i++;
	}
	i = 0;
	j = 0;
	if (ft_check_min_char(map, i, j, check) == -1)
		return (-1);
	return (1);
}

int	ft_check_shape(char **map)
{
	int	i;

	i = 0;
	if (ft_strslen(map) < 3)
		return (-1);
	if (ft_strlen(map[0]) < 3)
		return (-1);
	while (map[++i])
		if (ft_strlen(map[i]) != ft_strlen(map[i - 1])
			&& ft_strlen(map[i]) != 0)
			return (-1);
	return (1);
}

int	ft_check_map(char **map)
{
	if (ft_check_char(map) == -1)
		return (-1);
	if (ft_check_shape(map) == -1)
		return (-1);
	if (ft_check_closed(map) == -1)
		return (-1);
	return (1);
}

void	ft_check(int argc, char **argv)
{
	int		len_argv;
	char	**map;

	if (argc != 2)
		ft_error(NULL, "too many or no arguments");
	len_argv = ft_strlen(argv[1]);
	if (argv[1][len_argv - 1] != 'r' || argv[1][len_argv - 2] != 'e' ||
		argv[1][len_argv - 3] != 'b' || argv[1][len_argv - 4] != '.')
		ft_error(NULL, "The file is not a \".ber\"");
	map = malloc(sizeof(char *) * (2));
	if (!map)
		ft_error(ft_free_strs(map), NULL);
	map = ft_init_map(argv[1], map);
	if (map == (char **)-1)
		ft_error(NULL, NULL);
	if (ft_check_map(map) == -1)
		ft_error(ft_free_strs(map), "not a valid map");
	ft_free_strs(map);
}
