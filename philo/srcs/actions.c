/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdubois <pdubois@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/10 04:58:49 by pdubois           #+#    #+#             */
/*   Updated: 2022/08/16 04:55:27 by pdubois          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_take_forks(t_info *bag, int name, long int *last_meal, int *took_fork)
{
	if (name != bag->nbr_philo)
		return (ft_take_forks_not_last_philo(bag, name, last_meal, took_fork));
	else
	{
		if (pthread_mutex_lock(&(bag->forks[0])) != 0)
			return (ft_putstr_fd("Philo: mutex_lock failed\n", 2), FAILED);
		took_fork[0] = 1;
		if (ft_print_msg(bag, name, "has taken a fork"))
			return (FAILED);
		if (ft_will_die_waiting_fork(bag, name, *last_meal))
			return (SUCCESS);
		if (pthread_mutex_lock(&(bag->forks[name - 1])) != 0)
			return (ft_putstr_fd("Philo: mutex_lock failed\n", 2), FAILED);
		took_fork[1] = 1;
		if (ft_print_msg(bag, name, "has taken a fork"))
			return (FAILED);
		return (SUCCESS);
	}
}

int	ft_put_back_forks(t_info *bag, int name, int *took_fork)
{
	if (name != bag->nbr_philo)
	{
		if (took_fork[1] && pthread_mutex_unlock(&(bag->forks[name])) != 0)
			return (ft_putstr_fd("Philo: mutex_unlock failed\n", 2), FAILED_V2);
		if (took_fork[0] && pthread_mutex_unlock(&(bag->forks[name - 1])) != 0)
			return (ft_putstr_fd("Philo: mutex_unlock failed\n", 2), FAILED_V2);
	}
	else
	{
		if (took_fork[1] && pthread_mutex_unlock(&(bag->forks[name - 1])) != 0)
			return (ft_putstr_fd("Philo: mutex_unlock failed\n", 2), FAILED_V2);
		if (took_fork[0] && pthread_mutex_unlock(&(bag->forks[0])) != 0)
			return (ft_putstr_fd("Philo: mutex_unlock failed\n", 2), FAILED_V2);
	}
	return (SUCCESS);
}

int	ft_eat(t_info *bag, int name, long int *last_meal)
{
	int	took_fork[2];

	took_fork[0] = 0;
	took_fork[1] = 0;
	if (ft_take_forks(bag, name, last_meal, took_fork))
		return (FAILED);
	if (ft_print_msg(bag, name, "is eating"))
		return (FAILED);
	*last_meal = ft_get_current_time() - bag->starting_time;
	if (my_usleep(bag, bag->tt_eat * 1000, name, last_meal))
		return (FAILED);
	if (ft_put_back_forks(bag, name, took_fork))
		return (FAILED);
	return (SUCCESS);
}

int	ft_think(t_info *bag, int name, long int *last_meal, int odd_waiting)
{
	if (ft_print_msg(bag, name, "is thinking"))
		return (FAILED);
	if (odd_waiting == name)
	{
		if (my_usleep(bag, bag->tt_eat * 999, name, last_meal) != 0)
			return (FAILED);
	}
	else if (*last_meal == -1)
		if (my_usleep(bag, bag->tt_eat * 999, name, last_meal) != 0)
			return (FAILED);
	return (SUCCESS);
}

int	ft_sleep(t_info *bag, int name, long int *last_meal)
{
	if (ft_print_msg(bag, name, "is sleeping"))
		return (FAILED);
	if (my_usleep(bag, bag->tt_sleep * 1000, name, last_meal))
		return (FAILED);
	return (SUCCESS);
}
