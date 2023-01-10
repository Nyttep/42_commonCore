/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialization.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdubois <pdubois@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 17:09:12 by pdubois           #+#    #+#             */
/*   Updated: 2023/01/10 19:15:01 by pdubois          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	ft_init_map(char **av, t_game *game)
{

}

void	ft_init_ressources(char **av, t_game *game)
{
	char	set[6] = {"NO ", "SO ", "WE ", "EA ", "F ", "C "};
	char	*buff;
	int		i;
	bool	state[6] = {0, 0, 0, 0, 0, 0};
	
	i = 0;
	buff = get_next_line(fd);
	while (buff && !ft_unfinished(state))
	{
		while (i < 6 && buff[0] != '\n')
		{
			if (!ft_strncmp(ft_skip_spaces(&buff), set[i], ft_strlen(set[i])))
			{
				ft_init_img(game, buff, set[i]);
				state[i] = 1;
				break ;
			}
			i++;
		}
		if (i == 6 && ft_unfinished(state))
		{
			free(buff);
			ft_error(game, "The .cub does not conform");
		}
		i = 0;
		free(buff);
		buff = get_next_line(fd);
	}
}

void	ft_init(t_game *game, char **av)
{
	int	fd;
	ft_bzero(game, sizeof(game));
	game->mlx = mlx_init();
	if (!(game->mlx))
		ft_error(game, NULL);
	fd = open(av[1], O_RDONLY);
	if (fd < 0)
		ft_error(game, NULL);
	ft_init_ressources(av[1], game);
	ft_init_map(av[1], game);
	close(fd);
}