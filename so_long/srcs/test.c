/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdubois <pdubois@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/28 03:24:42 by pdubois           #+#    #+#             */
/*   Updated: 2022/01/28 07:44:13 by pdubois          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

typedef struct	s_vars {
	void	*mlx;
	void	*win;
	void	*img;
}				t_vars;

int	escape(int keycode, t_vars *vars)
{
	if(keycode == 0xff1b)
	{
		mlx_destroy_window(vars->mlx, vars->win);
		mlx_destroy_image(vars->mlx, vars->img);
		mlx_destroy_display(vars->mlx);
		exit(1);
	}
	return(1);
}
	

int	main(void)
{
	t_vars vars;
	int	width;
	int	height;

	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, 1920, 1080, "Hello World !");
	vars.img = mlx_xpm_file_to_image(vars.mlx, "img4.xpm", &width, &height);
	if (vars.img)
		mlx_put_image_to_window(vars.mlx, vars.win, vars.img, 0, 0);
	if (vars.img)
		mlx_put_image_to_window(vars.mlx, vars.win, vars.img,10, 10);
	mlx_key_hook(vars.win, escape, &vars);
	mlx_loop(vars.mlx);
}