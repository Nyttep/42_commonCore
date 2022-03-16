/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdubois <pdubois@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 14:50:25 by pdubois           #+#    #+#             */
/*   Updated: 2022/03/15 14:55:42 by pdubois          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_check_closed(char **map)
{
	int	i;
	int	max_x;
	int	max_y;

	max_x = ft_strlen(map[0]) - 1;
	max_y = ft_strslen(map) - 1;
	i = -1;
	while (map[0][++i])
		if (map[0][i] != '1')
			return (-1);
	i = -1;
	while (map[++i])
		if (map[i][0] != '1')
			return (-1);
	i = -1;
	while (map[max_y][++i])
		if (map[max_y][i] != '1')
			return (-1);
	i = -1;
	while (map[++i])
		if (map[i][max_x] != '1')
			return (-1);
	return (1);
}
