/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdubois <pdubois@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/25 04:08:27 by pdubois           #+#    #+#             */
/*   Updated: 2022/03/15 15:35:31 by pdubois          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_find_char_in_strs(char **map, char target, char ret)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == target)
			{
				if (ret == 'x')
					return (j);
				if (ret == 'y')
					return (i);
			}
			j++;
		}
		i++;
	}
	return (-1);
}

int	ft_count_collectibles(t_game *game)
{
	int	i;
	int	j;
	int	ret;

	i = 0;
	ret = 0;
	while (game->map[i])
	{
		j = 0;
		while (game->map[i][j])
		{
			if (game->map[i][j] == 'C')
				ret++;
			j++;
		}
		i++;
	}
	return (ret);
}
