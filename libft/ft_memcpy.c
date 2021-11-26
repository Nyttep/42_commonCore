/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdubois <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 02:32:10 by pdubois           #+#    #+#             */
/*   Updated: 2021/11/26 02:32:12 by pdubois          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	char		*tmp1;
	const char	*tmp2;
	size_t		i;

	i = -1;
	tmp1 = dest;
	tmp2 = src;
	while (n > ++i)
		tmp1[i] = tmp2[i];
	return (dest);
}
