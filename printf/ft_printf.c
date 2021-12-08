/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdubois <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 17:01:23 by pdubois           #+#    #+#             */
/*   Updated: 2021/12/09 00:45:56 by pdubois          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include "libftprintf.h"
#include <unistd.h>
#include <stdarg.h>
int	ft_strlen(const char	*str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int	ft_putstr(const char	*str, int i, int k)
{
	write(1, &str[k], i);
	return (i);
}

int	ft_c(int c)
{
	ft_putchar(c);
	return (1);
}

int	ft_s(char *str)
{
	int	len;

	if (!str)
	{
		write(1, "(null)", 6);
		return (6);
	}
	len = ft_strlen(str);
	write(1, str, len);
	return (len);
}

int	ft_putnbr_hexa_u(unsigned long long int nbr)
{
	char	*base;
	int		i;

	i = 0;
	base = "0123456789abcdef";
	if (nbr <= 15)
	{
		ft_putchar(base[nbr]);
		return (1);
	}
	else
	{
		i += ft_putnbr_hexa_u(nbr / 16);
		i += ft_putnbr_hexa_u(nbr % 16);
	}
	return (i);
}

int ft_putnbr(int nbr)
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
		i++;
		nbr *= -1;
		i += ft_putnbr(nbr);
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
		i += ft_putnbr_hexa_u(nbr / 10);
		i += ft_putnbr_hexa_u(nbr % 10);
	}
	return (i);
}

int	ft_putnbr_hexa(int nbr)
{
	char	*base;
	int		i;

	i = 0;
	base = "0123456789abcdef";
	if (nbr == -2147483648)
	{
		write(1, "-80000000", 9);
		return (9);
	}
	else if (nbr < 0)
	{
		write(1, "-", 1);
		i++;
		nbr *= -1;
		i += ft_putnbr_hexa(nbr);
	}
	else if (nbr <= 15)
	{
		ft_putchar(base[nbr]);
		return (1);
	}
	else
	{
		i += ft_putnbr_hexa_u(nbr / 16);
		i += ft_putnbr_hexa_u(nbr % 16);
	}
	return (i);
}

int	ft_putnbr_hexa_maj(int nbr)
{
	char	*base;
	int		i;

	i = 0;
	base = "0123456789ABCDEF";
	if (nbr == -2147483648)
	{
		write(1, "-80000000", 9);
		return (9);
	}
	else if (nbr < 0)
	{
		write(1, "-", 1);
		i++;
		nbr *= -1;
		i += ft_putnbr_hexa(nbr);
	}
	if (nbr <= 15)
	{
		ft_putchar(base[nbr]);
		return (1);
	}
	else
	{
		i += ft_putnbr_hexa_u(nbr / 16);
		i += ft_putnbr_hexa_u(nbr % 16);
	}
	return (i);
}

void	ft_find_format(const char *str, int i, int *j, va_list args)
{
	if (str[i] == 'c')
		*j += ft_c(va_arg(args, int));
	else if (str[i] == 's')
		*j += ft_s(va_arg(args, char *));
	else if (str[i] == 'p')
	{
		write (1, "0x", 2);
		*j += 2 + ft_putnbr_hexa_u(va_arg(args, unsigned long long int));
	}
	else if (str[i] == 'i' || str[i] == 'd')
		*j += ft_putnbr(va_arg(args, int));
	else if (str[i] == 'u')
		*j += ft_putnbr_u(va_arg(args, unsigned int));
	else if (str[i] == 'x')
		*j += ft_putnbr_hexa(va_arg(args, int));
	else if (str[i] == 'X')
		*j += ft_putnbr_hexa_maj(va_arg(args, int));
	else if (str[i] == '%')
	{
		ft_putchar('%');
		(*j)++;
	}
	return;
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int	i;
	int	j;
	int	k;

	k = 0;
	i = 0;
	j = 0;
	va_start(args, str);
	while (str[i])
	{
		if (str[i] == '%')
		{
			i++;
			ft_find_format(str, i, &j, args);
			k = i + 1;
		}
		else if (j++ >= 0)
			write(1, &str[i], 1);
		i++;
	}
	va_end(args);
	return (j);
}
