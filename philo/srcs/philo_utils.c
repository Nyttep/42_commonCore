/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdubois <pdubois@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/10 05:07:39 by pdubois           #+#    #+#             */
/*   Updated: 2022/08/10 06:01:34 by pdubois          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_get_name(t_info *bag)
{
	int	name;

	if (pthread_mutex_lock(bag->name_m) != 0)
		return (ft_putstr_fd("Philo: mutex_lock failed\n", 2), FAILED_V2);
	name = (bag->nbr_philo - bag->name) + 1;
	bag->name--;
	if (pthread_mutex_unlock(bag->name_m) != 0)
		return (ft_putstr_fd("Philo: mutex_unlock failed\n", 2), FAILED_V2);
	return (name);
}

int	ft_get_odd_waiting(t_info *bag)
{
	if ((bag->nbr_philo % 2) == 1)
		return (bag->nbr_philo);
	else
		return (NOBODY_WAIT);
	return (0);
}

static int	ft_lock_death_and_print(t_info *bag, int name, char *msg)
{
	if (pthread_mutex_lock(bag->is_somebody_dead_m) != 0)
		return (ft_putstr_fd("Philo: mutex_lock failed\n", 2), FAILED);
	ft_putnbr_fd(ft_get_current_time() - bag->starting_time, 1);
	ft_putstr_fd(" ", 1);
	ft_putnbr_fd(name, 1);
	ft_putstr_fd(" ", 1);
	ft_putstr_fd(msg, 1);
	ft_putstr_fd("\n", 1);
	if (pthread_mutex_unlock(bag->is_somebody_dead_m) != 0)
		return (ft_putstr_fd("Philo: mutex_lock failed\n", 2), FAILED);
	return (SUCCESS);
}

int	ft_print_msg(t_info *bag, int name, char *msg)
{
	int	ret;

	ret = ft_is_somebody_dead(bag);
	if (ret == TRUE)
		return (SUCCESS);
	else if (ret == FAILED_V2)
		return (FAILED);
	if (pthread_mutex_lock(bag->mic_m) != 0)
		return (ft_putstr_fd("Philo: mutex_lock failed\n", 2), FAILED);
	ret = ft_is_somebody_dead(bag);
	if (ret == TRUE)
	{
		if (pthread_mutex_unlock(bag->mic_m) != 0)
			return (ft_putstr_fd("Philo: mutex_unlock failed\n", 2), FAILED);
		return (SUCCESS);
	}
	else if (ret == FAILED_V2)
		return (FAILED);
	if (ft_lock_death_and_print(bag, name, msg))
		return (FAILED);
	if (pthread_mutex_unlock(bag->mic_m) != 0)
		return (ft_putstr_fd("Philo: mutex_unlock failed\n", 2), FAILED);
	return (SUCCESS);
}
