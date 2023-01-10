/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paul <paul@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 18:34:28 by paul              #+#    #+#             */
/*   Updated: 2022/12/27 18:51:48 by paul             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	CUB3D_H
# define CUB3D_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <errno.h>
# include <fcntl.h>
# include "mlx.h"
# include "libft.h"

typedef struct s_game
{
	void	*mlx;
	void	*win;
	char	**map;
}	t_game;

#endif