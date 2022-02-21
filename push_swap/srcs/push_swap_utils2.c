/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdubois <pdubois@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 22:17:20 by pdubois           #+#    #+#             */
/*   Updated: 2022/02/01 13:48:23 by pdubois          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long long int	ft_long_atoi(const char *str)
{
	int				i;
	long long int	neg;
	long long int	res;

	i = 0;
	neg = 1;
	res = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == ' ')
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			neg = -1;
		i++;
	}
	while (ft_isdigit(str[i]))
	{
		res = (str[i] - 48) + (res * 10);
		i++;
	}
	return (res * neg);
}

int	ft_check_digit(char **s)
{
	int	i;
	int	j;

	i = 0;
	while (s[i])
	{
		j = 0;
		if (s[i][j] == '-' || s[i][j] == '+')
			j++;
		while (s[i][j])
		{
			if (!ft_isdigit((int) s[i][j]))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	ft_check_intmax(char **s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (ft_long_atoi(s[i]) > 2147483647 || ft_long_atoi(s[i]) < -2147483648
			|| ft_strlen(s[i]) > 12)
			return (0);
		i++;
	}
	return (1);
}

int	ft_check_duplicate(char **s)
{
	int	i;
	int	j;

	i = 0;
	j = 1;
	while (s[i])
	{
		while (s[j])
		{
			if (ft_atoi(s[i]) == ft_atoi(s[j]))
				return (0);
			j++;
		}
		j = ++i + 1;
	}
	return (1);
}

int	ft_check(int argc, char **argv)
{
	char	**s;

	s = NULL;
	while (--argc > 0)
	{
		s = ft_strsjoin(s, ft_split(argv[argc], ' '));
		if (!s)
			return (ft_free_strs(s), 0);
	}
	if (!ft_check_digit(s))
		return (ft_free_strs(s), 0);
	if (!ft_check_intmax(s))
		return (ft_free_strs(s), 0);
	if (!ft_check_duplicate(s))
		return (ft_free_strs(s), 0);
	ft_free_strs(s);
	return (1);
}
