/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdubois <pdubois@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 18:44:38 by paul              #+#    #+#             */
/*   Updated: 2023/01/10 15:40:58 by pdubois          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	ft_check(int ac, char **av)
{
	int	len_av;

	if (ac != 2)
		ft_error(NULL, "too many or no arguments");
	len_av = ft_strlen(av[1]);
	if (ft_strcmp(av[1] + (len_av - 4), ".cub") != 0)
		ft_error(NULL, "The file is not a .cub");
	if (len_av == 4)
		ft_error(NULL, "The file is not a .cub");
}