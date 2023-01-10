/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdubois <pdubois@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 15:35:30 by pdubois           #+#    #+#             */
/*   Updated: 2023/01/10 17:25:25 by pdubois          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int main(int ac, char** av)
{
	t_game	*game;

	ft_check(ac, av);
	game = malloc(sizeof(game));
	if (!game)
		ft_error(game, NULL);
	ft_init(game, av);
}
