/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdubois <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 17:58:54 by pdubois           #+#    #+#             */
/*   Updated: 2021/12/09 00:10:01 by pdubois          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>

int		ft_strlen(const char	*str);
void	ft_putchar(char c);
int		ft_putstr(const char	*str, int i, int k);
int		ft_c(int c);
int		ft_s(char *str);
int		ft_putnbr_hexa_u(unsigned long long int nbr);
int		ft_putnbr(int nbr);
int		ft_putnbr_u(int nbr);
int		ft_putnbr_hexa(int nbr);
int		ft_putnbr_hexa_maj(int nbr);
void	ft_find_format(const char *str, int i, int *j, va_list args);
int		ft_printf(const char *str, ...);

#endif
