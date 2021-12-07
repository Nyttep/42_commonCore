/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdubois <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 17:01:23 by pdubois           #+#    #+#             */
/*   Updated: 2021/12/07 17:59:08 by pdubois          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char	ft_find_type(char	*str)
{
	static int	i = 0;

	while (str[i])
	{
		if (s[i] == '%')
		{
			i++;
			if (s[i] == 'c' || s[i] == 's' || s[i] == 'p' || s[i] == 'u'
				|| s[i] == 'd'|| s[i] == 'i' || s[i] == 'x' || s[i] == 'X'
				|| s[i] == '%')
				return (s[i]);
			else
				return (NULL);
		}
		i++;
	}
	return ('e');
}

int ft_printf(const char *str, ...)
{
	va_list	args;
	char	type;

	type = ft_find_type(str);
	va_start(args, str);
	while (type != 'e')
	{
		type = ft_find_type(str);
	}
}
