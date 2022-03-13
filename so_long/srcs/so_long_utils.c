/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils1.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdubois <pdubois@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/25 04:08:27 by pdubois           #+#    #+#             */
/*   Updated: 2022/03/09 17:59:28 by pdubois          ###   ########.fr       */
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
			if(map[i][j] == target)
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
