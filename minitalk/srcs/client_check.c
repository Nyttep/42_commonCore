/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_check.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdubois <pdubois@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 19:18:25 by pdubois           #+#    #+#             */
/*   Updated: 2022/06/16 19:41:31 by pdubois          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client.h"

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

void	ft_check(int ac, char **av)
{
	int	i;

	i = 0;
	if (ac != 3)
		ft_wrong_args(av);
	while (ft_isdigit(av[1][i]) && av[1][i])
		i++;
	if (av[1][i] != 0)
		ft_wrong_args(av);
	if (ft_long_atoi(av[1]) > 2147483647 || ft_strlen(av[1]) > 12)
		ft_pid_bigger_than_maxint();
	if (ft_long_atoi(av[1]) < 1)
		ft_pid_lower_than_one();
}
