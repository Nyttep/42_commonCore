/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdubois <pdubois@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 16:30:28 by pdubois           #+#    #+#             */
/*   Updated: 2022/08/10 04:44:42 by pdubois          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static long long int	ft_long_atoi(const char *str)
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

static int	ft_check_intmax(char *s)
{
	if (ft_long_atoi(s) > 2147483647 || ft_long_atoi(s) < -2147483648
		|| ft_strlen(s) > 11)
		return (0);
	return (1);
}

static int	ft_check_digit(char *s)
{
	int	i;

	i = 0;
	if (s[i] == '-' || s[i] == '+')
		i++;
	if (s[i])
	{
		while (s[i])
		{
			if (!ft_isdigit((int)s[i]))
				return (0);
			i++;
		}
	}
	else
		return (0);
	return (1);
}

int	ft_check_numbers(char **av, int i)
{
	if (!ft_check_digit(av[i]))
	{
		ft_putstr_fd("Philo: argument should be a number\n", 2);
		return (FAILED);
	}
	if (!ft_check_intmax(av[i]))
	{
		ft_putstr_fd("Philo: arguments should not be greater than", 2);
		return (ft_putstr_fd(" maxint\n", 2), FAILED);
	}
	if (ft_atoi(av[i]) <= 0)
	{
		ft_putstr_fd("Philo: arguments should be greater than zero\n", 2);
		return (FAILED);
	}
	return (SUCCESS);
}

int	ft_check_args(int ac, char **av)
{
	int	i;

	i = 1;
	if (ac != 5 && ac != 6)
	{
		ft_putstr_fd("Philo: too much or not enough arguments\nphilo ", 2);
		ft_putstr_fd("should be called like this: ./philo <number_of_", 2);
		ft_putstr_fd("philosopher> <time_to_die> <time_to_eat> <time_to_", 2);
		ft_putstr_fd("sleep> [number_of_times_each_philosopher_must_eat]\n", 2);
		return (FAILED);
	}
	while (i < ac)
		if (ft_check_numbers(av, i++) == FAILED)
			return (FAILED);
	return (SUCCESS);
}
