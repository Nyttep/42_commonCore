/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialization_2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdubois <pdubois@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 13:57:11 by pdubois           #+#    #+#             */
/*   Updated: 2022/03/15 15:35:30 by pdubois          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	**ft_expand_strs(char **map)
{
	char	**tmp;
	int		i;

	i = 0;
	tmp = map;
	map = malloc(sizeof(char **) * (ft_strslen(tmp) + 2));
	if (!map)
		return (ft_free_strs(tmp), (char **) - 1);
	map[ft_strslen(tmp)] = NULL;
	map[ft_strslen(tmp) + 1] = NULL;
	while (tmp[i])
	{
		map[i] = tmp[i];
		i++;
	}
	free(tmp[ft_strslen(tmp)]);
	free(tmp);
	return (map);
}

char	**ft_format_map(char **map)
{
	int	i;

	i = -1;
	while (map[++i])
	{
		if (map[i][ft_strlen(map[i]) - 1] == '\n')
		{
			if (ft_strlen(map[i]) == 1)
				map[i] = NULL;
			else
				map[i][ft_strlen(map[i]) - 1] = 0;
		}
	}
	return (map);
}

char	**ft_init_map(char *path, char **map)
{
	int		fd;
	int		state;
	int		i;

	i = 1;
	map[0] = NULL;
	map[1] = NULL;
	fd = open(path, O_RDONLY);
	if (fd < 0)
		ft_error(ft_free_strs(map), NULL);
	state = get_next_line(fd, &map[0]);
	while (state)
	{
		map = ft_expand_strs(map);
		if (map == (char **)-1)
			return (close(fd), ft_free_strs(map), (char **) - 1);
		state = get_next_line(fd, &map[i++]);
	}
	if (state == -1)
		return (close(fd), ft_free_strs(map), (char **)-1);
	map = ft_format_map(map);
	close(fd);
	return (map);
}

void	ft_init_img(t_game **game, t_img **img, char *path)
{
	(*img)->img = mlx_xpm_file_to_image((*game)->mlx, path, &(*img)->width,
			&(*img)->height);
	if (!(*img)->img)
		ft_error(*game, NULL);
	(*img)->addr = mlx_get_data_addr((*img)->img, &(*img)->bpp,
			&(*img)->size_line, &(*img)->size_line);
	if (!(*img)->addr)
		ft_error(*game, NULL);
}

void	ft_init_player(t_game **game)
{
	(*game)->plyr = malloc(sizeof(t_player));
	if (!(*game)->plyr)
		ft_error(*game, NULL);
	(*game)->plyr->u = malloc(sizeof(t_img));
	if (!(*game)->plyr->u)
		ft_error(*game, NULL);
	(*game)->plyr->d = malloc(sizeof(t_img));
	if (!(*game)->plyr->d)
		ft_error(*game, NULL);
	(*game)->plyr->l = malloc(sizeof(t_img));
	if (!(*game)->plyr->l)
		ft_error(*game, NULL);
	(*game)->plyr->r = malloc(sizeof(t_img));
	if (!(*game)->plyr->r)
		ft_error(*game, NULL);
	ft_init_img(game, &(*game)->plyr->u, "img/plyr_u.xpm");
	ft_init_img(game, &(*game)->plyr->d, "img/plyr_d.xpm");
	ft_init_img(game, &(*game)->plyr->l, "img/plyr_l.xpm");
	ft_init_img(game, &(*game)->plyr->r, "img/plyr_r.xpm");
}
