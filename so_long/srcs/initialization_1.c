/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialization_1.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdubois <pdubois@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 02:21:27 by pdubois           #+#    #+#             */
/*   Updated: 2022/03/17 18:17:01 by pdubois          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_init_walls(t_game **game)
{
	(*game)->bot_wall = malloc(sizeof(t_img));
	if (!(*game)->bot_wall)
		ft_error(*game, NULL);
	ft_init_img(game, &(*game)->bot_wall, "img/bot_wall.xpm");
	(*game)->top_wall = malloc(sizeof(t_img));
	if (!(*game)->top_wall)
		ft_error(*game, NULL);
	ft_init_img(game, &(*game)->top_wall, "img/top_wall.xpm");
	(*game)->right_wall = malloc(sizeof(t_img));
	if (!(*game)->right_wall)
		ft_error(*game, NULL);
	ft_init_img(game, &(*game)->right_wall, "img/right_wall.xpm");
	(*game)->left_wall = malloc(sizeof(t_img));
	if (!(*game)->left_wall)
		ft_error(*game, NULL);
	ft_init_img(game, &(*game)->left_wall, "img/left_wall.xpm");
}

void	ft_init_corners(t_game **game)
{
	(*game)->bot_left = malloc(sizeof(t_img));
	if (!(*game)->bot_left)
		ft_error(*game, NULL);
	ft_init_img(game, &(*game)->bot_left, "img/bot_left.xpm");
	(*game)->bot_right = malloc(sizeof(t_img));
	if (!(*game)->bot_right)
		ft_error(*game, NULL);
	ft_init_img(game, &(*game)->bot_right, "img/bot_right.xpm");
	(*game)->top_left = malloc(sizeof(t_img));
	if (!(*game)->top_left)
		ft_error(*game, NULL);
	ft_init_img(game, &(*game)->top_left, "img/top_left.xpm");
	(*game)->top_right = malloc(sizeof(t_img));
	if (!(*game)->top_right)
		ft_error(*game, NULL);
	ft_init_img(game, &(*game)->top_right, "img/top_right.xpm");
}

void	ft_init_ressources(t_game **game)
{
	(*game)->coin = malloc(sizeof(t_img));
	if (!(*game)->coin)
		ft_error(*game, NULL);
	ft_init_img(game, &(*game)->coin, "img/coin.xpm");
	(*game)->floor = malloc(sizeof(t_img));
	if (!(*game)->floor)
		ft_error(*game, NULL);
	ft_init_img(game, &(*game)->floor, "img/floor.xpm");
	(*game)->rock = malloc(sizeof(t_img));
	if (!(*game)->rock)
		ft_error(*game, NULL);
	ft_init_img(game, &(*game)->rock, "img/rock.xpm");
	(*game)->opened_exit = malloc(sizeof(t_img));
	if (!(*game)->opened_exit)
		ft_error(*game, NULL);
	ft_init_img(game, &(*game)->opened_exit, "img/opened_exit.xpm");
	(*game)->closed_exit = malloc(sizeof(t_img));
	if (!(*game)->closed_exit)
		ft_error(*game, NULL);
	ft_init_img(game, &(*game)->closed_exit, "img/closed_exit.xpm");
	ft_init_walls(game);
	ft_init_corners(game);
}

void	ft_pre_init(t_game **game)
{
	(*game)->mlx = NULL;
	(*game)->win = NULL;
	(*game)->map = NULL;
	(*game)->coin = NULL;
	(*game)->bot_left = NULL;
	(*game)->bot_right = NULL;
	(*game)->top_left = NULL;
	(*game)->top_right = NULL;
	(*game)->bot_wall = NULL;
	(*game)->top_wall = NULL;
	(*game)->right_wall = NULL;
	(*game)->left_wall = NULL;
	(*game)->floor = NULL;
	(*game)->rock = NULL;
	(*game)->opened_exit = NULL;
	(*game)->closed_exit = NULL;
	(*game)->plyr = NULL;
}

void	ft_init(t_game **game, char **argv)
{
	ft_pre_init(game);
	(*game)->mlx = mlx_init();
	if (!(*game)->mlx)
		ft_error(*game, NULL);
	(*game)->map = malloc(sizeof(char *) * (2));
	if (!(*game)->map)
		ft_error(*game, NULL);
	(*game)->map = ft_init_map(argv[1], (*game)->map);
	if ((*game)->map == (char **) - 1)
		ft_error(*game, NULL);
	(*game)->col = ft_strlen((*game)->map[0]);
	(*game)->row = ft_strslen((*game)->map);
	(*game)->move = 0;
	ft_init_player(game);
	ft_init_ressources(game);
	(*game)->plyr->x = ft_find_char_in_strs((*game)->map, 'P', 'x');
	(*game)->plyr->y = ft_find_char_in_strs((*game)->map, 'P', 'y');
	(*game)->to_collect = ft_count_collectibles(*game);
}
