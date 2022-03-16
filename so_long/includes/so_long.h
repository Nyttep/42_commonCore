/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdubois <pdubois@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/28 01:23:33 by pdubois           #+#    #+#             */
/*   Updated: 2022/03/16 17:03:38 by pdubois          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <errno.h>
# include <fcntl.h>
# include "mlx.h"
# include "libft.h"
# include "ft_printf.h"

# define BUFFER_SIZE 100
# define ESC 0xff1b
# define LEFT 0xff51
# define UP 0xff52
# define RIGHT 0xff53
# define DOWN 0xff54
# define A 0x0061
# define D 0x0064
# define S 0x0073
# define W 0x0077

typedef struct s_img
{
	void	*img;
	char	*addr;
	int		bpp;
	int		size_line;
	int		endian;
	int		height;
	int		width;
}	t_img;

typedef struct s_player
{
	t_img	*u;
	t_img	*d;
	t_img	*l;
	t_img	*r;
	int		x;
	int		y;
}	t_player;

typedef struct s_game
{
	void		*mlx;
	void		*win;
	char		**map;
	int			col;
	int			row;
	int			move;
	int			to_collect;
	t_img		*coin;
	t_img		*bot_left;
	t_img		*bot_right;
	t_img		*top_left;
	t_img		*top_right;
	t_img		*bot_wall;
	t_img		*top_wall;
	t_img		*right_wall;
	t_img		*left_wall;
	t_img		*floor;
	t_img		*rock;
	t_img		*opened_exit;
	t_img		*closed_exit;
	t_player	*plyr;
}	t_game;

int		get_next_line(int fd, char **ret);
int		ft_is_newline_gnl(char	*s);
int		ft_strlen_gnl(char	*s);
char	*ft_kinda_strcat_gnl(char	*s, char	*init);
void	ft_get_reste_gnl(char	*s, char	*reste, int read_return);
char	*ft_cpy_and_rst_reste_gnl(char	*ret, char	*reste);
void	ft_init_gnl(char	**s, char	**ret, int	*read_return, char	*reste);
void	ft_check(int argc, char **argv);
void	ft_error(t_game *game, char *s);
char	**ft_init_map(char *path, char **map);
int		ft_find_char_in_strs(char **map, char target, char ret);
void	ft_init(t_game **game, char **argv);
int		ft_quit(t_game *game);
void	ft_display_beginning(t_game *game);
int		ft_count_collectibles(t_game *game);
int		ft_key_events(int keycode, t_game *game);
void	ft_put_spec_image_to_window(t_game *game, t_img *img, int x, int y);
void	ft_init_img(t_game **game, t_img **img, char *path);
void	ft_init_player(t_game **game);
void	ft_destroy(t_game *game);
void	ft_free_img(t_game *game, t_img *img);
int		ft_check_closed(char **map);

#endif