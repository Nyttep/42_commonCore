/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialization.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdubois <pdubois@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 02:21:27 by pdubois           #+#    #+#             */
/*   Updated: 2022/02/21 06:24:39 by pdubois          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char **ft_expand_strs(char **map)
{
	char	**tmp;
	int		i;

	i = 0;
	tmp = map;
	free(map);
	map = malloc(sizeof(char**) * (ft_strslen(tmp) + 2));
	if (!map)
		return((char**)-1);
	map[ft_strslen(tmp)] = NULL;
	map[ft_strslen(tmp) + 1] = NULL;
	while (tmp[i])
	{
		map[i] = tmp[i];
		i++;
	}
	ft_free_strs(tmp);
	return (map);
}

char	**ft_init_map(char *path)
{
	char	**map;
	int		fd;
	int		state;
	int		i;

	i = 1;
	fd = open(path, O_RDONLY);
	if (fd < 0)
		ft_error(NULL, NULL);
	map = malloc(sizeof(char*) * (2));
	map[1] = NULL;
	state = get_next_line(fd, map[0]);
	while (state)
	{
		map = ft_expand_strs(map);
		if(map == (char**)-1)
			return(close(fd), (char**)-1);
		state = get_next_line(fd, map[i]);
	}
	if (state == -1)
		return(close(fd),ft_free_strs(map), (char**)-1);
	close(fd);
	return (map);
}
