/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdubois <pdubois@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/28 06:58:07 by pdubois           #+#    #+#             */
/*   Updated: 2022/03/02 13:58:57 by pdubois          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	t_game	*game;
	// char	*addr;
	// int		bpp;
	// int		length;
	// int		endian;
	
	game = malloc(sizeof(t_game));
	ft_check(argc, argv);
	ft_init(&game, argv);
	// addr = mlx_get_data_addr(game->plyr->down, &bpp, &length, &endian);
	// (void) addr;
	// printf("%x", addr[10]);
	game->win = mlx_new_window(game->mlx, 1920, 1080, "so_long");
	mlx_put_image_to_window(game->mlx, game->win, game->plyr->right, 0, 0);
	mlx_put_image_to_window(game->mlx, game->win, game->plyr->down, 30, 0);
	mlx_loop(game->mlx);
}