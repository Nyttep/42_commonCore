/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdubois <pdubois@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 01:45:15 by pdubois           #+#    #+#             */
/*   Updated: 2022/03/02 13:58:58 by pdubois          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int ft_destroy(t_game *game)
{
	if (game->win)
		mlx_destroy_window(game->mlx, game->win);
	if (game->plyr->up)
		mlx_destroy_image(game->mlx, game->plyr->up);
	if (game->plyr->down)
		mlx_destroy_image(game->mlx, game->plyr->down);
	if (game->plyr->left)
		mlx_destroy_image(game->mlx, game->plyr->left);
	if (game->plyr->right)
		mlx_destroy_image(game->mlx, game->plyr->right);
	if (game->mlx)
		mlx_destroy_display(game->mlx);
	if (game->mlx)
		free(game->mlx);
}

void	ft_error(t_game *game, char *s)
{
	if (game)
	{
		if (game->map)
			ft_free_strs(game->map);
		if (game->plyr)
			free(game->plyr);
		ft_destroy(game);
		free(game);
	}
	if (s)	
		printf("Error : %s\n", s);
	else
		perror("Error ");
	exit(-1);
}