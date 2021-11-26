/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdubois <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 02:31:56 by pdubois           #+#    #+#             */
/*   Updated: 2021/11/26 09:01:08 by pdubois          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_len_nbr(int n)
{
	int	ret;

	ret = 1;
	if (n < 0)
	{
		ret++;
		n *= -1;
	}
	while (n > 9)
	{
		n = n / 10;
		ret++;
	}
	return (ret);
}

char	*ft_itoa(int n)
{
	char	*ret;
	int		len_nbr;
	int		i;

	i = 0;
	len_nbr = ft_len_nbr(n);
	ret = malloc(sizeof(char) * (len_nbr + 1));
	if (!ret)
		return (NULL);
	ret[len_nbr--] = '\0';
	if (n == -2147483648)
		return ("-2147483648");
	if (n < 0)
	{
		ret[0] = '-';
		n *= -1;
		i = 1;
	}
	while (len_nbr >= i)
	{
		ret[len_nbr--] = (n % 10) + 48;
		n = n / 10;
	}
	return (ret);
}
