/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdubois <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 17:52:34 by pdubois           #+#    #+#             */
/*   Updated: 2021/12/03 23:53:10 by pdubois          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
int	ft_is_newline_EOF(char	*s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

int	ft_strlen(char	*s)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i] && s[i] != '\n')
		i++;
	if (s[i] == '\n')
		i++;
	return (i);
}

char	*ft_kinda_strcat(char	*s, char	*init)
{
	char	*ret;
	int		len_s;
	int		len_init;
	int		i;
	int		j;

	i = -1;
	j = 0;
	len_s = ft_strlen(s);
	len_init = ft_strlen(init);
	ret = malloc(len_init + len_s + 1);
	ret[len_init + len_s] = 0;
	while (++i < len_init)
		ret[i] = init[i];
	j = i;
	i = 0;
	free(init);
	while (i < len_s && s[i] != '\n')
	{
		ret[i + j] = s[i];
		i++;
	}
	if (s[i] == '\n')
		ret[i + j] = '\n';
	return (ret);
}

char	*ft_get_reste(char	*s, char	*reste)
{
	int	i;
	int	j;

	j = 0;
	i = 0;
	while (s[i] != '\n' && s[i])
		i++;
	if (s[i] == 0)
		return (reste);
	while (s[++i])
		reste[j++] = s[i];
	reste[j] = 0;
	return (reste);
}

char	*ft_cpy_and_rst_reste(char	*ret, char	*reste)
{
	int	i;
	int	j;

	j = 0;
	i = 0;
	while (reste[i] && reste[i] != '\n')
	{
		ret[i] = reste[i];
		i++;
	}
	if (reste[i] == '\n')
		ret[i] = reste[i];
	while (reste[++i])
	{
		reste[j] = reste[i];
		j++;
	}
	while (j < BUFFER_SIZE)
		reste[j++] = 0;
	return (ret);
}

char	*get_next_line(int fd)
{
	char		*s;
	char		*ret;
	static char	*reste = NULL;
	int			found;
	int read_return;

	if (!reste)
		reste = malloc(BUFFER_SIZE);
	//printf("|RESTE : %s|", reste);
	s = malloc(BUFFER_SIZE + 1);
	ret = malloc(BUFFER_SIZE + 1);
	ret[BUFFER_SIZE] = 0;
	ret = ft_cpy_and_rst_reste(ret, reste);
	found = ft_is_newline_EOF(ret);
	//printf(" found = %d\n", found);
	while (!found && (read_return = read(fd, s, BUFFER_SIZE)))
	{
		s[read_return] = '\0';
		found = ft_is_newline_EOF(s);
		ret = ft_kinda_strcat(s, ret);
	}
	if (!read_return && !ft_strlen(ret))
	{
		free(ret);
		return (NULL);
	}
	//if (!reste[0])
	reste = ft_get_reste(s, reste);
	free(s);
	return (ret);
}
