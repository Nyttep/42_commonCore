/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdubois <pdubois@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/28 01:23:33 by pdubois           #+#    #+#             */
/*   Updated: 2022/01/28 07:44:09 by pdubois          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <errno.h>
# include "mlx.h"
# include "libft.h"

typedef struct	s_game
{
	char	**map;
	int		col;
	int		row;
	int		x_player;
	int		y_player;
}	t_game


#endif