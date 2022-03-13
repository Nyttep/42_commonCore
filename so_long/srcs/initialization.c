/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialization.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdubois <pdubois@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 02:21:27 by pdubois           #+#    #+#             */
/*   Updated: 2022/03/13 15:05:19 by pdubois          ###   ########.fr       */
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

char	**ft_init_map(char *path, char **map)
{
	int		fd;
	int		state;
	int		i;

	i = 1;
	fd = open(path, O_RDONLY);
	if (fd < 0)
		ft_error(NULL, NULL);
	map[0] = NULL;
	map[1] = NULL;
	state = get_next_line(fd, &map[0]);
	while (state)
	{
		map = ft_expand_strs(map);
		if (map == (char**)-1)
			return (close(fd),ft_free_strs(map), (char**)-1);
		state = get_next_line(fd, &map[i++]);
	}
	if (state == -1)
		return (close(fd), ft_free_strs(map), (char**)-1);
	map = ft_format_map(map);
	close(fd);
	return (map);
}

void	ft_init_img(t_game **game, t_img **img, char *path)
{
	(*img)->img = mlx_xpm_file_to_image((*game)->mlx, path, &(*img)->width,
		&(*img)->height);
	if(!(*img)->img)
		ft_error(*game, NULL);
	(*img)->addr = mlx_get_data_addr((*img)->img, &(*img)->bpp,
		&(*img)->size_line, &(*img)->size_line);
	if(!(*img)->addr)
		ft_error(*game, NULL);
}

void	ft_init_player(t_game **game)
{
	(*game)->plyr = malloc(sizeof(t_player));
	if (!(*game)->plyr)
		ft_error(*game, NULL);
	(*game)->plyr->u = malloc(sizeof(t_img));
	if (!(*game)->plyr->u)
		ft_error(*game, NULL);
	(*game)->plyr->d = malloc(sizeof(t_img));
	if (!(*game)->plyr->d)
		ft_error(*game, NULL);
	(*game)->plyr->l = malloc(sizeof(t_img));
	if (!(*game)->plyr->l)
		ft_error(*game, NULL);
	(*game)->plyr->r = malloc(sizeof(t_img));
	if (!(*game)->plyr->r)
		ft_error(*game, NULL);
	ft_init_img(game, &(*game)->plyr->u, "img/plyr_u.xpm");
	ft_init_img(game, &(*game)->plyr->d, "img/plyr_d.xpm");
	ft_init_img(game, &(*game)->plyr->l, "img/plyr_l.xpm");
	ft_init_img(game, &(*game)->plyr->r, "img/plyr_r.xpm");
}

void	ft_init_walls(t_game **game)
{
	(*game)->bot_wall = malloc(sizeof(t_img));
	if(!(*game)->bot_wall)
		ft_error(*game, NULL);
	ft_init_img(game, &(*game)->bot_wall, "img/bot_wall.xpm");
	(*game)->top_wall = malloc(sizeof(t_img));
	if(!(*game)->top_wall)
		ft_error(*game, NULL);
	ft_init_img(game, &(*game)->top_wall, "img/top_wall.xpm");
	(*game)->right_wall = malloc(sizeof(t_img));
	if(!(*game)->right_wall)
		ft_error(*game, NULL);
	ft_init_img(game, &(*game)->right_wall, "img/right_wall.xpm");
	(*game)->left_wall = malloc(sizeof(t_img));
	if(!(*game)->left_wall)
		ft_error(*game, NULL);
	ft_init_img(game, &(*game)->left_wall, "img/left_wall.xpm");

}

void	ft_init_corners(t_game **game)
{
	(*game)->bot_left = malloc(sizeof(t_img));
	if(!(*game)->bot_left)
		ft_error(*game, NULL);
	ft_init_img(game, &(*game)->bot_left, "img/bot_left.xpm");
	(*game)->bot_right = malloc(sizeof(t_img));
	if(!(*game)->bot_right)
		ft_error(*game, NULL);
	ft_init_img(game, &(*game)->bot_right, "img/bot_right.xpm");
	(*game)->top_left = malloc(sizeof(t_img));
	if(!(*game)->top_left)
		ft_error(*game, NULL);
	ft_init_img(game, &(*game)->top_left, "img/top_left.xpm");
	(*game)->top_right = malloc(sizeof(t_img));
	if(!(*game)->top_right)
		ft_error(*game, NULL);
	ft_init_img(game, &(*game)->top_right, "img/top_right.xpm");
}

void	ft_init_ressources(t_game **game)
{
	(*game)->coin = malloc(sizeof(t_img));
	if(!(*game)->coin)
		ft_error(*game, NULL);
	ft_init_img(game, &(*game)->coin, "img/coin.xpm");
	(*game)->floor = malloc(sizeof(t_img));
	if(!(*game)->floor)
		ft_error(*game, NULL);
	ft_init_img(game, &(*game)->floor, "img/floor.xpm");
	(*game)->rock = malloc(sizeof(t_img));
	if(!(*game)->rock)
		ft_error(*game, NULL);
	ft_init_img(game, &(*game)->rock, "img/rock.xpm");
	(*game)->opened_exit = malloc(sizeof(t_img));
	if(!(*game)->opened_exit)
		ft_error(*game, NULL);
	ft_init_img(game, &(*game)->opened_exit, "img/opened_exit.xpm");
	(*game)->closed_exit = malloc(sizeof(t_img));
	if(!(*game)->closed_exit)
		ft_error(*game, NULL);
	ft_init_img(game, &(*game)->closed_exit, "img/closed_exit.xpm");
	ft_init_walls(game);
	ft_init_corners(game);
}

void	ft_init(t_game **game, char **argv)
{
	(*game)->mlx = mlx_init();
	if (!(*game)->mlx)
		ft_error(*game, NULL);
	(*game)->map = malloc(sizeof(char*) * (2));
	if (!(*game)->map)
		ft_error(*game, NULL);
	(*game)->map = ft_init_map(argv[1], (*game)->map);
	if ((*game)->map == (char**)-1)
		ft_error(*game, NULL);
	(*game)->col = ft_strlen((*game)->map[0]);
	(*game)->row = ft_strslen((*game)->map);
	(*game)->move = 0;
	ft_init_player(game);
	ft_init_ressources(game);
	(*game)->plyr->x = ft_find_char_in_strs((*game)->map, 'P', 'x');
	(*game)->plyr->y = ft_find_char_in_strs((*game)->map, 'P', 'y');
}