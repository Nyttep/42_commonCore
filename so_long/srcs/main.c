/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdubois <pdubois@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/28 06:58:07 by pdubois           #+#    #+#             */
/*   Updated: 2022/03/14 14:20:06 by pdubois          ###   ########.fr       */
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
	game->win = mlx_new_window(game->mlx, game->col * 100, game->row * 100, "so_long");
	ft_display_beginning(game);
	mlx_hook(game->win, 17, 0L, ft_quit, game);
	mlx_hook(game->win, 2, 1L<<0, ft_key_events, game);
	mlx_loop(game->mlx);
}