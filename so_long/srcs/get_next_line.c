/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdubois <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 17:52:34 by pdubois           #+#    #+#             */
/*   Updated: 2021/12/06 19:16:24 by pdubois          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "so_long.h"

int	ft_free_gnl(char **ret, char *s)
{
	free(*ret);
	*ret = NULL;
	free(s);
	return (0);
}

void	ft_init_gnl(char **s, char **ret, int *read_return, char *reste)
{
	*s = malloc(BUFFER_SIZE + 1);
	if (!(*s))
		return ;
	if (*ret)
		free(*ret);
	*ret = malloc(BUFFER_SIZE + 1);
	if (!(*ret))
	{
		free(s);
		return ;
	}
	*s[0] = 0;
	*ret[0] = 0;
	*ret = ft_cpy_and_rst_reste_gnl(*ret, reste);
	*read_return = 0;
}

int	get_next_line(int fd, char **ret)
{
	char		*s;
	static char	reste[BUFFER_SIZE];
	int			found;
	int			read_return;

	ft_init_gnl(&s, ret, &read_return, reste);
	if (!*ret || !s)
		return (-1);
	found = ft_is_newline_gnl(*ret);
	if (!found)
		read_return = read(fd, s, BUFFER_SIZE);
	while (!found && read_return > 0)
	{
		s[read_return] = 0;
		found = ft_is_newline_gnl(s);
		*ret = ft_kinda_strcat_gnl(s, *ret);
		if (!found)
			read_return = read(fd, s, BUFFER_SIZE);
	}
	if (read_return <= 0 && !ft_strlen_gnl(*ret))
		return (ft_free_gnl(ret, s));
	ft_get_reste_gnl(s, reste, read_return);
	free(s);
	return (1);
}
