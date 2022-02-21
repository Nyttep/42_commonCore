/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdubois <pdubois@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 01:45:15 by pdubois           #+#    #+#             */
/*   Updated: 2022/02/21 06:24:40 by pdubois          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_error(t_game *game, char *s)
{
	if (game != NULL)
	{
		ft_free_strs(game->map);
	}
	if (s)	
		printf("Error : %s\n", s);
	else
		perror("Error ");
	exit(-1);
}