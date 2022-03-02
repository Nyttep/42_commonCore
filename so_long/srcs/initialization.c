/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialization.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdubois <pdubois@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 02:21:27 by pdubois           #+#    #+#             */
/*   Updated: 2022/03/02 13:58:54 by pdubois          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char **ft_expand_strs(char **map)
{
	char	**tmp;
	int		i;

	i = 0;
	tmp = map;
	map = malloc(sizeof(char**) * (ft_strslen(tmp) + 2));
	if (!map)
		return(ft_free_strs(tmp), (char**)-1);
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
		if (map[i][ft_strlen(map[i]) - 1] == '\n')
		{
			if (ft_strlen(map[i]) == 1)
				map[i] = NULL;
			else
				map[i][ft_strlen(map[i]) - 1] = 0;
		}
	return (map);
}

char	**ft_init_map(char *path)
{
	char	**map;
	int		fd;
	int		state;
	int		i;

	i = 1;
	fd = open(path, O_RDONLY);
	if (fd < 0)
		ft_error(NULL, NULL);
	map = malloc(sizeof(char*) * (2));
	if (!map)
		return (close(fd), (char**)-1);
	map[0] = NULL;
	map[1] = NULL;
	state = get_next_line(fd, &map[0]);
	while (state)
	{
		map = ft_expand_strs(map);
		if (map == (char**)-1)
			return (close(fd), (char**)-1);
		state = get_next_line(fd, &map[i++]);
	}
	if (state == -1)
		return (close(fd), ft_free_strs(map), (char**)-1);
	map = ft_format_map(map);
	close(fd);
	return (map);
}

void	*ft_cpy_img(t_game	**game, char *path)
{
	void	*ret;
	char	*addr_ret;
	int		*int_addr_ret;
	void	*img;
	char	*addr_img;
	int		*int_addr_img;
	int		info[7];

	img = mlx_xpm_file_to_image((*game)->mlx, path, &((*game)->plyr->width),
								&((*game)->plyr->height));
	addr_img = mlx_get_data_addr(img, &info[0], &info[1], &info[2]);
	int_addr_img = (int*)addr_img;
	ret = mlx_new_image((*game)->mlx, (*game)->plyr->width,
						 (*game)->plyr->height);
	addr_ret = mlx_get_data_addr(ret, &info[3], &info[4], &info[5]);
	int_addr_ret = (int*)addr_ret;
	info[6] = 0;
	while (info[6] <= (((*game)->plyr->width * (info[0] / 8) +
			(*game)->plyr->height * info[1]) / 4))
	{
		if (int_addr_img[info[6]] != int_addr_img[0])
			int_addr_ret[info[6]] = int_addr_img[info[6]];
		info[6]++;
	}
	mlx_destroy_image((*game)->mlx, img);
	return(ret);
}

void	ft_init(t_game **game, char **argv)
{
	(*game)->mlx = mlx_init();
	if (!(*game)->mlx)
		ft_error(*game, NULL);
	// (*game)->height = 100;
	// (*game)->width = 100;
	(*game)->map = ft_init_map(argv[1]);
	if ((*game)->map == (char**)-1)
		ft_error(*game, NULL);
	(*game)->col = ft_strlen((*game)->map[0]);
	(*game)->row = ft_strslen((*game)->map);
	(*game)->plyr = malloc(sizeof(t_player));
	if (!(*game)->plyr)
		ft_error(*game, NULL);
	(*game)->plyr->up = ft_cpy_img(game, "img/plyr_u.xpm");
	if (!(*game)->plyr->up)
		ft_error(*game, NULL);
	(*game)->plyr->down = ft_cpy_img(game, "img/plyr_d.xpm");
	if (!(*game)->plyr->down)
		ft_error(*game, NULL);
	(*game)->plyr->left = ft_cpy_img(game, "img/plyr_l.xpm");
	if (!(*game)->plyr->left)
		ft_error(*game, NULL);
	(*game)->plyr->right = ft_cpy_img(game, "img/plyr_r.xpm");
	if (!(*game)->plyr->right)
		ft_error(*game, NULL);
	(*game)->plyr->x = ft_find_char_in_strs((*game)->map, 'P', 'x');
	(*game)->plyr->y = ft_find_char_in_strs((*game)->map, 'P', 'y');
}