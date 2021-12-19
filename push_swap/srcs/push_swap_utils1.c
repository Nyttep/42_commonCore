/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils1.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdubois <pdubois@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/18 23:15:34 by pdubois           #+#    #+#             */
/*   Updated: 2021/12/19 07:00:17 by pdubois          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include "../libft/libft.h"

int	ft_strslen(char	**s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	**ft_strsjoin(char **s2, char **s1)
{
	char	**ret;
	int		k;
	int		i;

	k = -1;
	if (!s2)
		return (s1);
	ret = malloc (sizeof(char *) * (ft_strslen(s1) + ft_strslen(s2)+ 1));
	while (s1[++k])
	{
		ret[k] = ft_strdup(s1[k]);
		if (!ret[k])
			return (ft_free_strs(ret));
	}
	i = -1;
	while (s2[++i])
	{
		ret[k + i] = ft_strdup(s2[i]);
		if (!ret[k + i])
			return (ft_free_strs(ret));
	}
	ret[k + i] = NULL;
	ft_free_strs(s1);
	ft_free_strs(s2);
	return (ret);
}

int	ft_check(int argc, char **argv)
{
	int i;
	int j;
	char	**s;

	i = 0;
	//check for non digit args
	while (++i < argc)
	{
		j = -1;
		while (argc[i][++j])
			if (!ft_isdigit((int) argv[i][j] && argv[i][j] != ' ')
				return (0);
	}
	//check for int > int_max
	s = NULL;
	while (--argc > 0)
	{
		s = ft_strsjoin(s, ft_split(argv[argc], ' '));
		if (!s)
			return (0);
	}
	while ()
	//check for doublons
	ft_free_strs(s);
	return (1);
}