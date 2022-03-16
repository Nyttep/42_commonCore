/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_exit_1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdubois <pdubois@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 01:45:15 by pdubois           #+#    #+#             */
/*   Updated: 2022/03/15 15:35:28 by pdubois          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_free_player(t_game *game)
{
	if (game->plyr->u)
		ft_free_img(game, game->plyr->u);
	if (game->plyr->d)
		ft_free_img(game, game->plyr->d);
	if (game->plyr->l)
		ft_free_img(game, game->plyr->l);
	if (game->plyr->r)
		ft_free_img(game, game->plyr->r);
	free(game->plyr);
}

void	ft_free_walls(t_game *game)
{
	if (game->bot_left)
		ft_free_img(game, game->bot_left);
	if (game->bot_right)
		ft_free_img(game, game->bot_right);
	if (game->top_left)
		ft_free_img(game, game->top_left);
	if (game->top_right)
		ft_free_img(game, game->top_right);
	if (game->bot_wall)
		ft_free_img(game, game->bot_wall);
	if (game->top_wall)
		ft_free_img(game, game->top_wall);
	if (game->right_wall)
		ft_free_img(game, game->right_wall);
	if (game->left_wall)
		ft_free_img(game, game->left_wall);
}

void	ft_free_ressources(t_game *game)
{
	if (game->coin)
		ft_free_img(game, game->coin);
	if (game->floor)
		ft_free_img(game, game->floor);
	if (game->rock)
		ft_free_img(game, game->rock);
	if (game->opened_exit)
		ft_free_img(game, game->opened_exit);
	if (game->closed_exit)
		ft_free_img(game, game->closed_exit);
	ft_free_walls(game);
}

int	ft_quit(t_game *game)
{
	if (game)
	{
		if (game->map)
			ft_free_strs(game->map);
		if (game->plyr)
			ft_free_player(game);
		ft_free_ressources(game);
		ft_destroy(game);
		free(game);
	}
	exit(-1);
}

void	ft_error(t_game *game, char *s)
{
	if (s)
		ft_printf("Error : %s\n", s);
	else
		perror("Error ");
	ft_quit(game);
}
