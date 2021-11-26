/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdubois <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 23:06:39 by pdubois           #+#    #+#             */
/*   Updated: 2021/11/26 04:39:21 by pdubois          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	const char	*tmp1;
	char		*tmp2;
	size_t		i;

	i = 0;
	tmp1 = src;
	tmp2 = dest;
	if (src < dest)
	{
		i = n;
		while (i)
		{
			i--;
			tmp2[i] = tmp1[i];
		}
	}
	else
	{
		while (i < n)
		{
			tmp2[i] = tmp1[i];
			i++;
		}
	}
	return (dest);
}
