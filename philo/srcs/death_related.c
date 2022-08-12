/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   death_related.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdubois <pdubois@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/10 04:46:13 by pdubois           #+#    #+#             */
/*   Updated: 2022/08/12 18:30:27 by pdubois          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_is_somebody_dead(t_info *bag)
{
	if (pthread_mutex_lock(bag->is_somebody_dead_m) != 0)
		return (ft_putstr_fd("Philo: mutex_lock failed\n", 2), FAILED_V2);
	if (bag->is_somebody_dead == TRUE)
	{
		if (pthread_mutex_unlock(bag->is_somebody_dead_m) != 0)
			return (ft_putstr_fd("Philo: mutex_unlock failed\n", 2),
				FAILED_V2);
		return (TRUE);
	}
	if (pthread_mutex_unlock(bag->is_somebody_dead_m) != 0)
		return (ft_putstr_fd("Philo: mutex_unlock failed\n", 2), FAILED_V2);
	return (FALSE);
}

int	ft_will_die_during_usleep(t_info *bag, int sleep_time, int name,
		long int last_meal)
{
	long int	time_since_last_meal;

	if (last_meal == -1)
		last_meal = 0;
	time_since_last_meal = (ft_get_current_time() - bag->starting_time);
	time_since_last_meal -= last_meal;
	if ((long int)bag->tt_die <= (time_since_last_meal + sleep_time))
	{
		usleep((bag->tt_die - time_since_last_meal) * 1000);
		if (ft_philo_died(bag, name))
			return (FAILED_V2);
		return (TRUE);
	}
	return (FALSE);
}

static int	ft_announce_death(t_info *bag, int name)
{
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
	bag->is_somebody_dead = TRUE;
	ft_putnbr_fd(ft_get_current_time() - bag->starting_time, 1);
	ft_putstr_fd(" ", 1);
	ft_putnbr_fd(name, 1);
	ft_putstr_fd(" ", 1);
	ft_putstr_fd("died\n", 1);
	if (pthread_mutex_unlock(bag->is_somebody_dead_m) != 0)
		return (ft_putstr_fd("Philo: mutex_unlock failed\n", 2), FAILED);
	return (SUCCESS);
}

int	ft_philo_died(t_info *bag, int name)
{
	if (pthread_mutex_lock(bag->mic_m) != 0)
		return (ft_putstr_fd("Philo: mutex_lock failed\n", 2), FAILED);
	if (ft_announce_death(bag, name))
		return (FAILED);
	if (pthread_mutex_unlock(bag->mic_m) != 0)
		return (ft_putstr_fd("Philo: mutex_unlock failed\n", 2), FAILED);
	return (SUCCESS);
}
