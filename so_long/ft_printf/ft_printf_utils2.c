/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdubois <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 19:52:21 by pdubois           #+#    #+#             */
/*   Updated: 2021/12/09 19:56:43 by pdubois          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr(int nbr)
{
	int	i;

	i = 0;
	if (nbr == -2147483648)
	{
		write(1, "-2147483648", 11);
		return (11);
	}
	else if (nbr < 0)
	{
		write(1, "-", 1);
		nbr *= -1;
		i += ft_putnbr(nbr) + 1;
	}
	else if (nbr <= 9)
	{
		ft_putchar(nbr + '0');
		return (1);
	}
	else
	{
		i += ft_putnbr(nbr / 10);
		i += ft_putnbr(nbr % 10);
	}
	return (i);
}

int	ft_putnbr_u(unsigned int nbr)
{
	int		i;

	i = 0;
	if (nbr <= 9)
	{
		ft_putchar(nbr + '0');
		return (1);
	}
	else
	{
		i += ft_putnbr_u(nbr / 10);
		i += ft_putnbr_u(nbr % 10);
	}
	return (i);
}

int	ft_putnbr_hexa_maj_u(unsigned int nbr)
{
	char	*base;
	int		i;

	i = 0;
	base = "0123456789ABCDEF";
	if (nbr <= 15)
	{
		ft_putchar(base[nbr]);
		return (1);
	}
	else
	{
		i += ft_putnbr_hexa_maj_u(nbr / 16);
		i += ft_putnbr_hexa_maj_u(nbr % 16);
	}
	return (i);
}
