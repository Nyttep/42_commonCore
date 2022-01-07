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
#include "get_next_line.h"

char	*ft_free(char *ret, char *s)
{
	free(ret);
	free(s);
	return (NULL);
}

void	ft_init(char	**s, char	**ret, int	*read_return, char	*reste)
{
	*s = malloc(BUFFER_SIZE + 1);
	if (!(*s))
		return ;
	*ret = malloc(BUFFER_SIZE + 1);
	if (!(*ret))
	{
		free(s);
		return ;
	}
	*s[0] = 0;
	*ret[0] = 0;
	*ret = ft_cpy_and_rst_reste(*ret, reste);
	*read_return = 0;
}

char	*get_next_line(int fd)
{
	char		*s;
	char		*ret;
	static char	reste[BUFFER_SIZE];
	int			found;
	int			read_return;

	ft_init(&s, &ret, &read_return, reste);
	if (!ret || !s)
		return (NULL);
	found = ft_is_newline(ret);
	if (!found)
		read_return = read(fd, s, BUFFER_SIZE);
	while (!found && read_return > 0)
	{
		s[read_return] = 0;
		found = ft_is_newline(s);
		ret = ft_kinda_strcat(s, ret);
		if (!found)
			read_return = read(fd, s, BUFFER_SIZE);
	}
	if (read_return <= 0 && !ft_strlen(ret))
		return (ft_free(ret, s));
	ft_get_reste(s, reste, read_return);
	free(s);
	return (ret);
}
