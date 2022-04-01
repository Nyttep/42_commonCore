/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdubois <pdubois@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 18:43:32 by pdubois           #+#    #+#             */
/*   Updated: 2022/04/01 16:53:10 by pdubois          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void *ft_realloc(void *ptr, size_t size)
{
	char	*ret;
	int		i;

	i = -1;
	ret = malloc(size);
	if (!ret)
		return ((void *)-1);
	ft_bzero(ret, size);
	while ((char*)ptr + ++i && i < (int) size)
		ret[i] = *(char*) ptr + i;
	free(ptr);
	return (ret);
}