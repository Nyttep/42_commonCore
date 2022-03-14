/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_events.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdubois <pdubois@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 13:55:23 by pdubois           #+#    #+#             */
/*   Updated: 2022/03/14 16:57:08 by pdubois          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_move_left(t_game *game)
{
	char next;

	next = game->map[game->plyr->y][game->plyr->x - 1];
	if (next == '0' || next == 'P' || next == 'C' ||
		(next == 'E' && game->to_collect == 0))
	{
		if (next == 'E')
		{
			write(1, "Congratulation you made it !\n", 29);
			ft_quit(game);
		}
		ft_put_spec_image_to_window(game, game->plyr->l, --game->plyr->x,
			game->plyr->y);
		mlx_put_image_to_window(game->mlx, game->win, game->floor->img,
			(game->plyr->x + 1) *100, game->plyr->y * 100);
		printf("number of move : %d\n", ++game->move);
		if (next == 'C')
		{
			game->map[game->plyr->y][game->plyr->x] = '0';
			if (--game->to_collect == 0)
				ft_put_spec_image_to_window(game, game->opened_exit, 
				ft_find_char_in_strs(game->map, 'E', 'x'),
				ft_find_char_in_strs(game->map, 'E', 'y'));
		}
	}
}

void	ft_move_right(t_game *game)
{
	char next;

	next = game->map[game->plyr->y][game->plyr->x + 1];
	if (next == '0' || next == 'P' || next == 'C' ||
		(next == 'E' && game->to_collect == 0))
	{
		if (next == 'E')
		{
			write(1, "Congratulation you made it !\n", 29);
			ft_quit(game);
		}
		ft_put_spec_image_to_window(game, game->plyr->r, ++game->plyr->x,
			game->plyr->y);
		mlx_put_image_to_window(game->mlx, game->win, game->floor->img,
			(game->plyr->x - 1) *100, game->plyr->y * 100);
		printf("number of move : %d\n", ++game->move);
		if (next == 'C')
		{
			game->map[game->plyr->y][game->plyr->x] = '0';
			if (--game->to_collect == 0)
				ft_put_spec_image_to_window(game, game->opened_exit, 
				ft_find_char_in_strs(game->map, 'E', 'x'),
				ft_find_char_in_strs(game->map, 'E', 'y'));
		}
	}
}

void	ft_move_up(t_game *game)
{
	char next;

	next = game->map[game->plyr->y - 1][game->plyr->x];
	if (next == '0' || next == 'P' || next == 'C' ||
		(next == 'E' && game->to_collect == 0))
	{
		if (next == 'E')
		{
			write(1, "Congratulation you made it !\n", 29);
			ft_quit(game);
		}
		ft_put_spec_image_to_window(game, game->plyr->u, game->plyr->x,
			--game->plyr->y);
		mlx_put_image_to_window(game->mlx, game->win, game->floor->img,
			game->plyr->x *100, (game->plyr->y + 1) * 100);
		printf("number of move : %d\n", ++game->move);
		if (next == 'C')
		{
			game->map[game->plyr->y][game->plyr->x] = '0';
			if (--game->to_collect == 0)
				ft_put_spec_image_to_window(game, game->opened_exit, 
				ft_find_char_in_strs(game->map, 'E', 'x'),
				ft_find_char_in_strs(game->map, 'E', 'y'));
		}
	}
}

void	ft_move_down(t_game *game)
{
	char next;

	next = game->map[game->plyr->y + 1][game->plyr->x];
	if (next == '0' || next == 'P' || next == 'C' ||
		(next == 'E' && game->to_collect == 0))
	{
		if (next == 'E')
		{
			write(1, "Congratulation you made it !\n", 29);
			ft_quit(game);
		}
		ft_put_spec_image_to_window(game, game->plyr->d, game->plyr->x,
			++game->plyr->y);
		mlx_put_image_to_window(game->mlx, game->win, game->floor->img,
			game->plyr->x *100, (game->plyr->y - 1) * 100);
		printf("number of move : %d\n", ++game->move);
		if (next == 'C')
		{
			game->map[game->plyr->y][game->plyr->x] = '0';
			if (--game->to_collect == 0)
				ft_put_spec_image_to_window(game, game->opened_exit, 
				ft_find_char_in_strs(game->map, 'E', 'x'),
				ft_find_char_in_strs(game->map, 'E', 'y'));
		}
	}
}


int	ft_key_events(int keycode, t_game *game)
{
	if (keycode == ESC)
		ft_quit(game);
	else if (keycode == LEFT || keycode == A)
		ft_move_left(game);
	else if (keycode == RIGHT || keycode == D)
		ft_move_right(game);
	else if (keycode == UP || keycode == W)
		ft_move_up(game);
	else if (keycode == DOWN || keycode == S)
		ft_move_down(game);
	return (1);
}
