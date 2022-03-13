/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdubois <pdubois@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 17:59:48 by pdubois           #+#    #+#             */
/*   Updated: 2022/03/13 16:33:33 by pdubois          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_put_pixel(t_img *img, int x, int y, int color)
{
	char	*dst;

	dst = img->addr + (y * img->size_line + x * (img->bpp / 8));
	*(unsigned int*) dst = color;
}

void	ft_find_and_put_sprite(t_game *game, int x, int y)
{
	if (game->map[y][x] == '1')
	{
		if (x + y == 0)
			mlx_put_image_to_window(game->mlx, game->win, game->top_left->img,
				0, 0);
		else if (y == 0 && x == game->col - 1)
			mlx_put_image_to_window(game->mlx, game->win, game->top_right->img,
				100 * x, 0);
		else if (y == game->row - 1 && x == 0)
			mlx_put_image_to_window(game->mlx, game->win, game->bot_left->img,
				0, 100 * y);
		else if (y == game->row - 1 && x == game->col - 1)
			mlx_put_image_to_window(game->mlx, game->win, game->bot_right->img,
				100 * x, 100 * y);
		else if (y == 0)
			mlx_put_image_to_window(game->mlx, game->win, game->top_wall->img,
				100 * x, 0);
		else if (x == 0)
			mlx_put_image_to_window(game->mlx, game->win, game->left_wall->img,
				0, 100 * y);
		else if (y == game->row - 1)
			mlx_put_image_to_window(game->mlx, game->win, game->bot_wall->img,
				100 * x, 100 * y);
		else if (x == game->col - 1)
			mlx_put_image_to_window(game->mlx, game->win, game->right_wall->img,
				100 * x, 100 * y);
		else
			mlx_put_image_to_window(game->mlx, game->win, game->rock->img,
				100 * x, 100 * y);
			// ft_put_spec_image_to_window(game, game->rock,
				// x, y);
	}
	else if (game->map[y][x] == '0')
		mlx_put_image_to_window(game->mlx, game->win, game->floor->img,
			100 * x, 100 * y);
	else if (game->map[y][x] == 'E')
		mlx_put_image_to_window(game->mlx, game->win, game->closed_exit->img,
			100 * x, 100 * y);
		// ft_put_spec_image_to_window(game, game->closed_exit,
			// x, y);
	else if (game->map[y][x] == 'C')
		mlx_put_image_to_window(game->mlx, game->win, game->coin->img,
			100 * x, 100 * y);
		// ft_put_spec_image_to_window(game, game->coin,
			// x, y);
	else if (game->map[y][x] == 'P')
		mlx_put_image_to_window(game->mlx, game->win, game->plyr->d->img,
			100 * x, 100 * y);
		// ft_put_spec_image_to_window(game game->plyr->d,
			// x, y);

}

void	ft_display_beginning(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (game->map[y])
	{
		x = 0;
		while(game->map[y][x])
		{
			ft_find_and_put_sprite(game, x, y);
			x++;
		}
		y++;
	}
}