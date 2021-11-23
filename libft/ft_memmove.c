/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdubois <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 23:06:39 by pdubois           #+#    #+#             */
/*   Updated: 2021/11/23 23:36:10 by pdubois          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void *ft_memmove(void *dest, const void *src, size_t n)
{
	char	*tmp1;
	char	*tmp2;
	size_t	len;
	size_t	i;

	len = ft_strlen(src) - 1;
	i = 0;
	tmp1 = src;
	tmp2 = dest;
	if (src < dest)
	{
		while (len >= 0)
		{
			tmp2[len] = tmp1[len];
			len--;
		}
	}
	else
	{
		while(i < len)
		{
			tmp2[i] = tmp1[i];
			i++;
		}
	}
	return (dest);
}
