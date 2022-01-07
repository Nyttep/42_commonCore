/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdubois <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 14:47:52 by pdubois           #+#    #+#             */
/*   Updated: 2021/12/07 14:49:19 by pdubois          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H 

# include <stdlib.h>
# include <unistd.h>

char	*get_next_line(int fd);
int		ft_is_newline(char	*s);
int		ft_strlen(char	*s);
char	*ft_kinda_strcat(char	*s, char	*init);
void	ft_get_reste(char	*s, char	*reste, int read_return);
char	*ft_cpy_and_rst_reste(char	*ret, char	*reste);
char	*ft_free(char *ret, char *s);
void	ft_init(char	**s, char	**ret, int	*read_return, char	*reste);
#endif
