/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turns.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdubois <pdubois@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/10 05:05:35 by pdubois           #+#    #+#             */
/*   Updated: 2022/08/11 02:39:46 by pdubois          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_my_turn_to_eat_even(int name, int turn)
{
	if (name % 2 == turn)
		return (1);
	else
		return (0);
}

int	ft_my_turn_to_eat_odd(int name, int odd_waiting)
{
	int	diff;

	diff = name - odd_waiting;
	if (diff == 0)
		return (0);
	else if (diff > 0)
	{
		if (diff % 2 == ODD)
			return (1);
		else
			return (0);
	}
	else
	{
		if (diff % 2 == -ODD)
			return (0);
		else
			return (1);
	}
}

int	ft_my_turn_to_eat(int name, int turn, int odd_waiting, int nbr_philo)
{
	if (nbr_philo % 2 == ODD)
		return (ft_my_turn_to_eat_odd(name, odd_waiting));
	else
		return (ft_my_turn_to_eat_even(name, turn));
}
