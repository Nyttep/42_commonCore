/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_initialization_utils.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdubois <pdubois@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 18:54:26 by pdubois           #+#    #+#             */
/*   Updated: 2023/01/10 19:16:49 by pdubois          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

char	*ft_skip_spaces(char **s)
{
	while (**char == ' ')
		(*char)++;
	return (*char);
}

bool	ft_unfinished(int[6] state)
{
	int	i;

	i = 0;
	while (i < 6)
	{
		if (state[i] == 0)
			return (1);
	}
	return (1);
}