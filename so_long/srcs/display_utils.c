/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdubois <pdubois@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 17:59:48 by pdubois           #+#    #+#             */
/*   Updated: 2022/03/14 13:27:24 by pdubois          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_put_pixel(t_img *img, int x, int y, int color)
{
	char	*dst;

	dst = img->addr + (y * img->size_line + x * (img->bpp / 8));
	*(unsigned int*) dst = color;
}

t_img	*ft_create_spec_image(t_game *game, t_img *img)
{
	unsigned int	*tmp_background;
	unsigned int	*tmp_foreground;
	t_img			*tmp_img;
	int				i;

	i = 0;
	tmp_img = malloc(sizeof(t_img));
	if (!tmp_img)
		ft_error(game, NULL);
	tmp_img->img = mlx_new_image(game->mlx, 100, 100);
	tmp_img->addr = mlx_get_data_addr(tmp_img->img, &tmp_img->bpp,
		&tmp_img->size_line, &tmp_img->endian);
	tmp_background = (unsigned int*) game->floor->addr;
	tmp_foreground = (unsigned int*) img->addr;
	while (i < 10000)
	{
		if (tmp_foreground[i] == 0x00ff00)
			*((unsigned int*) tmp_img->addr + i) = tmp_background[i];
		else
			*((unsigned int*) tmp_img->addr + i) = tmp_foreground[i];
		i++;
	}
	return (tmp_img);
}

void	ft_put_spec_image_to_window(t_game *game, t_img *img, int x, int y)
{
	t_img			*dst;

	dst = ft_create_spec_image(game, img);
	mlx_put_image_to_window(game->mlx, game->win, dst->img, 100 * x, 100 * y);
	mlx_destroy_image(game->mlx, dst->img);
	free(dst);
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
			ft_put_spec_image_to_window(game, game->rock, x, y);
	}
	else if (game->map[y][x] == '0')
		mlx_put_image_to_window(game->mlx, game->win, game->floor->img,
			100 * x, 100 * y);
	else if (game->map[y][x] == 'E')
		ft_put_spec_image_to_window(game, game->closed_exit, x, y);
	else if (game->map[y][x] == 'C')
		ft_put_spec_image_to_window(game, game->coin, x, y);
	else if (game->map[y][x] == 'P')
		ft_put_spec_image_to_window(game, game->plyr->d, x, y);

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