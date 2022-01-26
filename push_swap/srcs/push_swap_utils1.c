/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils1.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdubois <pdubois@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/18 23:15:34 by pdubois           #+#    #+#             */
/*   Updated: 2022/01/06 00:35:44 by pdubois          ###   ########.fr       */
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
	int		i[2];

	i[0] = -1;
	if (!s2)
		return (s1);
	ret = malloc (sizeof(char *) * (ft_strslen(s1) + ft_strslen(s2) + 1));
	while (s1[++i[0]] && ret)
	{
		ret[i[0]] = ft_strdup(s1[i[0]]);
		if (!ret[i[0]])
			return (ft_free_strs(ret));
	}
	i[1] = -1;
	while (s2[++i[1]] && ret)
	{
		ret[i[0] + i[1]] = ft_strdup(s2[i[1]]);
		if (!ret[i[0] + i[1]])
			return (ft_free_strs(ret));
	}
	if (ret)
		ret[i[0] + i[1]] = NULL;
	ft_free_strs(s1);
	ft_free_strs(s2);
	return (ret);
}
