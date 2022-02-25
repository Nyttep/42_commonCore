/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdubois <pdubois@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/28 01:23:33 by pdubois           #+#    #+#             */
/*   Updated: 2022/02/25 06:14:00 by pdubois          ###   ########.fr       */
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


typedef struct s_player
{
	void	*up;
	int		up_x;
	int		up_y;
	void	*down;
	int		down_x;
	int		down_y;
	void	*left;
	int		left_x;
	int		left_y;
	void	*right;
	int		right_x;
	int		right_y;
	int		x;
	int		y;
}	t_player;

typedef struct	s_game
{
	void		*mlx;
	void		*win;
	char		**map;
	int			col;
	int			row;
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
char	**ft_init_map(char *path);
int		ft_find_char_in_strs(char **map, char target, char ret);
void	ft_init(t_game **game, char **argv);

#endif