/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdubois <pdubois@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 18:43:32 by pdubois           #+#    #+#             */
/*   Updated: 2022/05/03 20:05:44 by pdubois          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void *ft_realloc(void *ptr, size_t size)
{
	char	*tmp;
	char	*ret;
	int		i;

	tmp = (char*)ptr;
	i = 0;
	ret = malloc(size);
	if (!ret)
		return ((void *)NULL);
	ft_bzero(ret, size);
	while (tmp[i] && i < (int) size)
	{
		ret[i] = tmp[i];
		i++;
	}
	ret[i] = 0;
	free(ptr);
	return (ret);
}