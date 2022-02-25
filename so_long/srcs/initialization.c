/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialization.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdubois <pdubois@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 02:21:27 by pdubois           #+#    #+#             */
/*   Updated: 2022/02/25 05:11:28 by pdubois          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char **ft_expand_strs(char **map)
{
	char	**tmp;
	int		i;

	i = 0;
	tmp = map;
	map = malloc(sizeof(char**) * (ft_strslen(tmp) + 2));
	if (!map)
		return(ft_free_strs(tmp), (char**)-1);
	map[ft_strslen(tmp)] = NULL;
	map[ft_strslen(tmp) + 1] = NULL;
	while (tmp[i])
	{
		map[i] = tmp[i];
		i++;
	}
	free(tmp[ft_strslen(tmp)]);
	free(tmp);
	return (map);
}

char	**ft_format_map(char **map)
{
	int	i;

	i = -1;
	while (map[++i])
		if (map[i][ft_strlen(map[i]) - 1] == '\n')
		{
			if (ft_strlen(map[i]) == 1)
				map[i] = NULL;
			else
				map[i][ft_strlen(map[i]) - 1] = 0;
		}
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
	if (!map)
		return (close(fd), (char**)-1);
	map[0] = NULL;
	map[1] = NULL;
	state = get_next_line(fd, &map[0]);
	while (state)
	{
		map = ft_expand_strs(map);
		if (map == (char**)-1)
			return (close(fd), (char**)-1);
		state = get_next_line(fd, &map[i++]);
	}
	if (state == -1)
		return (close(fd), ft_free_strs(map), (char**)-1);
	map = ft_format_map(map);
	close(fd);
	return (map);
}

void	ft_init(t_game **game, char **argv)
{
	(*game)->mlx = mlx_init();
	if (!(*game)->mlx)
		ft_error(*game, NULL);
	// (*game)->win = mlx_new_window((*game)->mlx, 1920, 1080, "so_long");
	// if (!(*game)->win)
		// ft_error(*game, NULL);
	(*game)->map = ft_init_map(argv[1]);
	if ((*game)->map == (char**)-1)
		ft_error(*game, NULL);
	(*game)->col = ft_strlen((*game)->map[0]);
	(*game)->row = ft_strslen((*game)->map);
	(*game)->plyr = malloc(sizeof(t_player));
	if (!(*game)->plyr)
		ft_error(*game, NULL);
	(*game)->plyr->u = mlx_xpm_file_to_image((*game)->mlx, "img/plyr_u.xpm", &((*game)->plyr->u_x), &((*game)->plyr->u_y));
	if (!(*game)->plyr->u)
		ft_error(*game, NULL);
	(*game)->plyr->d = mlx_xpm_file_to_image((*game)->mlx, "img/down_player.xpm", &((*game)->plyr->d_x), &((*game)->plyr->d_y));
	if (!(*game)->plyr->d)
		ft_error(*game, NULL);
	(*game)->plyr->l = mlx_xpm_file_to_image((*game)->mlx, "img/plyr_l.xpm", &((*game)->plyr->l_x), &((*game)->plyr->l_y));
	if (!(*game)->plyr->l)
		ft_error(*game, NULL);
	(*game)->plyr->r = mlx_xpm_file_to_image((*game)->mlx, "img/plyr_r.xpm", &((*game)->plyr->r_x), &((*game)->plyr->r_y));
	if (!(*game)->plyr->r)
		ft_error(*game, NULL);
	(*game)->plyr->x = ft_find_char_in_strs((*game)->map, 'P', 'x');
	(*game)->plyr->y = ft_find_char_in_strs((*game)->map, 'P', 'y');
}