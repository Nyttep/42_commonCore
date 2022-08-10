/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdubois <pdubois@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/10 04:58:49 by pdubois           #+#    #+#             */
/*   Updated: 2022/08/10 05:59:53 by pdubois          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_take_forks(t_info *bag, int name)
{
	if (name != bag->nbr_philo)
	{
		if (pthread_mutex_lock(&(bag->forks[name - 1])) != 0)
			return (ft_putstr_fd("Philo: mutex_lock failed\n", 2), FAILED);
		if (ft_print_msg(bag, name, "has taken a fork"))
			return (FAILED);
		if (pthread_mutex_lock(&(bag->forks[name])) != 0)
			return (ft_putstr_fd("Philo: mutex_lock failed\n", 2), FAILED);
		if (ft_print_msg(bag, name, "has taken a fork"))
			return (FAILED);
	}
	else
	{
		if (pthread_mutex_lock(&(bag->forks[0])) != 0)
			return (ft_putstr_fd("Philo: mutex_lock failed\n", 2), FAILED);
		if (ft_print_msg(bag, name, "has taken a fork"))
			return (FAILED);
		if (pthread_mutex_lock(&(bag->forks[name - 1])) != 0)
			return (ft_putstr_fd("Philo: mutex_lock failed\n", 2), FAILED);
		if (ft_print_msg(bag, name, "has taken a fork"))
			return (FAILED);
	}
	return (SUCCESS);
}

int	ft_put_back_forks(t_info *bag, int name)
{
	if (name != bag->nbr_philo)
	{
		if (pthread_mutex_unlock(&(bag->forks[name])) != 0)
			return (ft_putstr_fd("Philo: mutex_unlock failed\n", 2), FAILED_V2);
		if (pthread_mutex_unlock(&(bag->forks[name - 1])) != 0)
			return (ft_putstr_fd("Philo: mutex_unlock failed\n", 2), FAILED_V2);
	}
	else
	{
		if (pthread_mutex_unlock(&(bag->forks[name - 1])) != 0)
			return (ft_putstr_fd("Philo: mutex_unlock failed\n", 2), FAILED_V2);
		if (pthread_mutex_unlock(&(bag->forks[0])) != 0)
			return (ft_putstr_fd("Philo: mutex_unlock failed\n", 2), FAILED_V2);
	}
	return (SUCCESS);
}

int	ft_eat(t_info *bag, int name, int *last_meal)
{
	if (ft_take_forks(bag, name))
		return (FAILED);
	if (ft_print_msg(bag, name, "is eating"))
		return (FAILED);
	*last_meal = ft_get_current_time();
	if (my_usleep(bag, bag->tt_eat * 1000, name, last_meal))
		return (FAILED);
	if (ft_put_back_forks(bag, name))
		return (FAILED);
	return (SUCCESS);
}

int	ft_think(t_info *bag, int name, int *last_meal)
{
	(void)last_meal;
	if (ft_print_msg(bag, name, "is thinking"))
		return (FAILED);
	return (SUCCESS);
}

int	ft_sleep(t_info *bag, int name, int *last_meal)
{
	if (ft_print_msg(bag, name, "is sleeping"))
		return (FAILED);
	if (my_usleep(bag, bag->tt_sleep * 1000, name, last_meal))
		return (FAILED);
	return (SUCCESS);
}
