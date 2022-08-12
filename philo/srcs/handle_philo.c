/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_philo.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdubois <pdubois@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/31 19:59:46 by pdubois           #+#    #+#             */
/*   Updated: 2022/08/12 18:38:45 by pdubois          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_finish_and_tell_everyone(t_info *bag, int name)
{
	if (pthread_mutex_lock(bag->mic_m) != 0)
		return (ft_putstr_fd("Philo: mutex_lock failed\n", 2), FAILED);
	if (pthread_mutex_lock(bag->is_somebody_dead_m) != 0)
		return (ft_putstr_fd("Philo: mutex_lock failed\n", 2), FAILED);
	if (bag->is_somebody_dead == TRUE)
	{
		if (pthread_mutex_unlock(bag->is_somebody_dead_m) != 0)
			return (ft_putstr_fd("Philo: mutex_unlock failed\n", 2), FAILED);
		if (pthread_mutex_unlock(bag->mic_m) != 0)
			return (ft_putstr_fd("Philo: mutex_unlock failed\n", 2), FAILED);
		return (SUCCESS);
	}
	printf("%ld %d is eating\n", (ft_get_current_time() - bag->starting_time),
		name);
	bag->is_somebody_dead = TRUE;
	if (pthread_mutex_unlock(bag->is_somebody_dead_m) != 0)
		return (ft_putstr_fd("Philo: mutex_unlock failed\n", 2), FAILED);
	if (pthread_mutex_unlock(bag->mic_m) != 0)
		return (ft_putstr_fd("Philo: mutex_unlock failed\n", 2), FAILED);
	if (usleep(bag->tt_eat * 1000) != 0)
		return (ft_putstr_fd("Philo: usleep() failed \n", 2), FAILED);
	return (TRUE);
}

int	ft_max_meal_reached(t_info *bag, int name, int i, long int *last_meal)
{
	if (i == bag->max_meal)
	{
		if (pthread_mutex_lock(bag->max_reached_m) != 0)
			return (ft_putstr_fd("Philo: mutex_lock failed\n", 2), FAILED);
		bag->max_reached--;
		if (bag->max_reached == 0)
		{
			if (pthread_mutex_unlock(bag->max_reached_m) != 0)
				return (ft_putstr_fd("Philo: mutex_unlock failed\n", 2), FAILED);
			if (ft_take_forks(bag, name, last_meal))
				return (FAILED);
			ft_finish_and_tell_everyone(bag, name);
			if (ft_put_back_forks(bag, name))
				return (FAILED);
			return (TRUE);
		}
		else if (pthread_mutex_unlock(bag->max_reached_m) != 0)
			return (ft_putstr_fd("Philo: mutex_unlock failed\n", 2), FAILED);
	}
	return (FALSE);
}

int	ft_eating_routine(t_info *bag, int name, int i, long int *last_meal)
{
	if (bag->max_meal != NO_LIMIT
		&& ft_max_meal_reached(bag, name, i, last_meal) == TRUE)
		return (FAILED);
	if (ft_eat(bag, name, last_meal))
		return (FAILED);
	if (ft_sleep(bag, name, last_meal))
		return (FAILED);
	return (SUCCESS);
}

int	ft_philo_life(t_info *bag, int name, int turn, int odd_waiting)
{
	int			i;
	long int	last_meal;

	last_meal = -1;
	i = 0;
	while (1)
	{
		if (ft_my_turn_to_eat(name, turn, odd_waiting, bag->nbr_philo))
		{
			if (ft_eating_routine(bag, name, i++, &last_meal))
				return (FAILED);
			odd_waiting = ft_update_odd_waiting(bag, odd_waiting);
		}
		else if (ft_think(bag, name, &last_meal, odd_waiting))
			return (FAILED);
		turn = !turn;
		odd_waiting = ft_update_odd_waiting(bag, odd_waiting);
		if (ft_is_somebody_dead(bag) == TRUE)
			return (SUCCESS);
	}
	return (SUCCESS);
}

void	*ft_handle_philo(void *bag)
{
	int	name;
	int	turn;
	int	odd_waiting;

	turn = 1;
	name = ft_get_name((t_info *)bag);
	if (name == FAILED_V2)
		return (ft_philo_died((t_info *)bag, 0), NULL);
	odd_waiting = ft_get_odd_waiting((t_info *)bag);
	if (odd_waiting == FAILED_V2)
		return (ft_philo_died((t_info *)bag, name), NULL);
	ft_philo_life((t_info *)bag, name, turn, odd_waiting);
	return (NULL);
}
