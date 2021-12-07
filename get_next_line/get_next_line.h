#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H 
#include <stdlib.h>
#include <unistd.h>
char	*get_next_line(int fd);
int		ft_is_newline(char	*s);
int		ft_strlen(char	*s);
char	*ft_kinda_strcat(char	*s, char	*init);
void	ft_get_reste(char	*s, char	*reste, int read_return);
char	*ft_cpy_and_rst_reste(char	*ret, char	*reste);
char	*ft_free(char *ret, char *s);
# endif
