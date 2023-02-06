/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdubois <pdubois@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 18:44:38 by paul              #+#    #+#             */
/*   Updated: 2023/02/06 13:50:07 by pdubois          ###   ########.fr       */
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

int	ft_check_rgbformat(char *str, int i)
{
	int	j;
	int	k;

	k = 0;
	while (str[i])
	{
		j = 0;
		while (ft_isdigit(str[i]))
		{
			j++;
			i++;
		}
		if (j > 3 || j == 0)
			return (1);
		k++;
		if (str[i] != ',')
		{
			if (k == 3 && str[i] == ' ')
				if (*ft_skip_spaces(str + i) == '\0')
					return (0);
			if (k == 3 && str[i] == '\0')
				return (0);
			return (1);
		}
		i++;
	}
	if (k != 3)
		return (1);
	return (0);
}

int	ft_check_rgb(char *str)
{
	int	i;
	
	i = 0;
	if (ft_check_rgbformat(str, i))
		return (1);
	while (i < 3)
	{
		if (ft_atoi(str) < 0 || ft_atoi(str) > 255)
			return (1);
		while (*str != ',' && *str)
			str++;
		str++;
		i++;
	}
	return (0);
}
