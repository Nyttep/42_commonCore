/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paul <paul@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 18:44:38 by paul              #+#    #+#             */
/*   Updated: 2022/12/27 19:05:06 by paul             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	ft_check(int ac, char **av)
{
	int	len_argv;

	if (argc != 2)
		ft_error(NULL, "too many or no arguments");
	len_argv = ft_strlen(argv[1]);
	if (ft_strcmp(argv[1] + (len_argv - 4), ".cub") != 0)
		ft_error(NULL, "The file is not a .cub");
	if (len_argv == 4)
		ft_error(NULL, "The file is not a .cub");
}