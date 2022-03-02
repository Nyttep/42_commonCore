/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdubois <pdubois@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/28 03:24:42 by pdubois           #+#    #+#             */
/*   Updated: 2022/03/02 13:58:58 by pdubois          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

typedef struct	s_vars {
	void	*mlx;
	void	*win;
	void	*chara;
	int		x_chara;
	int		y_chara;
	void	*black;
}				t_vars;

int destroy(t_vars *vars)
{
	mlx_destroy_window(vars->mlx, vars->win);
	mlx_destroy_image(vars->mlx, vars->chara);
	mlx_destroy_image(vars->mlx, vars->black);
	mlx_destroy_display(vars->mlx);
	free(vars->mlx);
	exit(1);
}

int	escape(int keycode, t_vars *vars)
{
	if(keycode == ESC)
		destroy(vars);
	else if(keycode == LEFT || keycode == A)
	{
		mlx_put_image_to_window(vars->mlx, vars->win, vars->black, 0, 0);
		vars->x_chara -= 91;
		mlx_put_image_to_window(vars->mlx, vars->win, vars->chara, vars->x_chara, vars->y_chara);
	}
	else if(keycode == RIGHT || keycode == D)
	{
		mlx_put_image_to_window(vars->mlx, vars->win, vars->black, 0, 0);
		vars->x_chara += 91;
		mlx_put_image_to_window(vars->mlx, vars->win, vars->chara, vars->x_chara, vars->y_chara);
	}
	else if(keycode == UP || keycode == W)
	{
		mlx_put_image_to_window(vars->mlx, vars->win, vars->black, 0, 0);
		vars->y_chara -= 104;
		mlx_put_image_to_window(vars->mlx, vars->win, vars->chara, vars->x_chara, vars->y_chara);
	}
	else if(keycode == DOWN || keycode == S)
	{
		mlx_put_image_to_window(vars->mlx, vars->win, vars->black, 0, 0);
		vars->y_chara += 104;
		mlx_put_image_to_window(vars->mlx, vars->win, vars->chara, vars->x_chara, vars->y_chara);
	}
	return(1);
}

int	main(void)
{
	t_vars vars;
	int	width;
	int	height;
	vars.x_chara = 0;
	vars.y_chara = 0;

	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, 1920, 1080, "Hello World !");
	vars.chara = mlx_xpm_file_to_image(vars.mlx, "images/down_player.xpm", &width, &height);
	vars.black = mlx_xpm_file_to_image(vars.mlx, "images/black_screen.xpm", &width, &height);
	if (vars.chara)
		mlx_put_image_to_window(vars.mlx, vars.win, vars.chara, 0, 0);
	// mlx_key_hook(vars.win, escape, &vars);
	mlx_hook(vars.win, 2, 1L<<0, escape, &vars);
	mlx_hook(vars.win, 17, 0L, destroy, &vars);
	mlx_loop(vars.mlx);
}