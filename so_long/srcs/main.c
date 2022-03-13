/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdubois <pdubois@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/28 06:58:07 by pdubois           #+#    #+#             */
/*   Updated: 2022/03/13 16:13:39 by pdubois          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	t_game	*game;

	ft_check(argc, argv);
	game = malloc(sizeof(t_game));
	if (!game)
		ft_error(game, NULL);
	ft_init(&game, argv);
	game->win = mlx_new_window(game->mlx, 1920, 1080, "so_long");
	ft_display_beginning(game);
	mlx_hook(game->win, 17, 0L, ft_quit, game);
	mlx_loop(game->mlx);
}