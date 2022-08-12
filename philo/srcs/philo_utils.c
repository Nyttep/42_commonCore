/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdubois <pdubois@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/10 05:07:39 by pdubois           #+#    #+#             */
/*   Updated: 2022/08/12 21:47:44 by pdubois          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_update_odd_waiting(t_info *bag, int odd_waiting)
{
	if (odd_waiting > 1)
		odd_waiting--;
	else if (odd_waiting != NOBODY_WAIT)
		odd_waiting = bag->nbr_philo;
	return (odd_waiting);
}

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

int	ft_print_msg(t_info *bag, int name, char *msg)
{
	if (pthread_mutex_lock(bag->mic_m) != 0)
		return (ft_putstr_fd("Philo: mutex_lock failed\n", 2), FAILED);
	if (pthread_mutex_lock(bag->is_somebody_dead_m) != 0)
		return (ft_putstr_fd("Philo: mutex_lock failed\n", 2), FAILED);
	if (bag->is_somebody_dead == TRUE)
	{
		if (pthread_mutex_unlock(bag->mic_m) != 0)
			return (ft_putstr_fd("Philo: mutex_unlock failed\n", 2),
				FAILED);
		if (pthread_mutex_unlock(bag->is_somebody_dead_m) != 0)
			return (ft_putstr_fd("Philo: mutex_unlock failed\n", 2),
				FAILED);
		return (SUCCESS);
	}
	printf("%ld %d %s\n", ft_get_current_time() - bag->starting_time, name, msg);
	if (pthread_mutex_unlock(bag->is_somebody_dead_m) != 0)
		return (ft_putstr_fd("Philo: mutex_lock failed\n", 2), FAILED);
	if (pthread_mutex_unlock(bag->mic_m) != 0)
		return (ft_putstr_fd("Philo: mutex_unlock failed\n", 2), FAILED);
	return (SUCCESS);
}
