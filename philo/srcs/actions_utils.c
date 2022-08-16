/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdubois <pdubois@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/11 01:37:53 by pdubois           #+#    #+#             */
/*   Updated: 2022/08/16 05:26:09 by pdubois          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_will_die_waiting_fork(t_info *bag, int name, long int last_meal)
{
	int	sleep_time;

	sleep_time = bag->tt_eat - bag->tt_sleep;
	if (bag->nbr_philo % 2 == EVEN && last_meal <= 30)
	{
		if (ft_will_die_during_usleep(bag, sleep_time, name, last_meal) == TRUE)
			return (TRUE);
	}
	else if (bag->nbr_philo % 2 == ODD && last_meal <= 30)
	{
		if (ft_will_die_during_usleep(bag, sleep_time, name, last_meal) == TRUE)
			return (TRUE);
	}
	return (FALSE);
}

int	ft_take_forks_not_last_philo(t_info *bag, int name, long int *last_meal,
		int *took_fork)
{
	(void)last_meal;
	if (pthread_mutex_lock(&(bag->forks[name - 1])) != 0)
		return (ft_putstr_fd("Philo: mutex_lock failed\n", 2), FAILED);
	took_fork[0] = 1;
	if (ft_print_msg(bag, name, "has taken a fork"))
		return (FAILED);
	if (ft_will_die_waiting_fork(bag, name, *last_meal))
		return (SUCCESS);
	if (pthread_mutex_lock(&(bag->forks[name])) != 0)
		return (ft_putstr_fd("Philo: mutex_lock failed\n", 2), FAILED);
	took_fork[1] = 1;
	if (ft_print_msg(bag, name, "has taken a fork"))
		return (FAILED);
	return (SUCCESS);
}
