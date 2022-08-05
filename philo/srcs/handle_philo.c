/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_philo.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdubois <pdubois@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/31 19:59:46 by pdubois           #+#    #+#             */
/*   Updated: 2022/08/05 21:59:14 by pdubois          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	ft_get_name(t_info *bag)
{
	int	name;

	if (pthread_mutex_lock(bag->name_m) != 0)
		return (ft_putstr_fd("Philo: pthread_mutex_lock failed", 2), FAILED_V2);
	name = (bag->nbr_philo - bag->name) + 1;
	bag->name--;
	if (pthread_mutex_unlock(bag->name_m) != 0)
		return (ft_putstr_fd("Philo: pthread_mutex_unlock failed", 2), pthread_mutex_unlock(bag->name_m), FAILED_V2);
	return (name);
}

int	ft_my_turn_to_eat(int name, int turn, int odd_waiting)
{
	if (name == 1)
	{
		if (odd_waiting == 9)
			return (1);
	}
	else
	{
		if (odd_waiting == name - 1)
			return (1);
	}
	if (name % 2 == turn && odd_waiting != name)
		return (1);
	else
		return (0);
}

int	ft_get_odd_waiting(t_info *bag)
{
	if ((bag->nbr_philo % 2) == 1)
		return (bag->nbr_philo);
	else
		return (NOBODY_WAIT);
	return (0);
}

int	ft_take_forks(t_info *bag, int name)
{
	struct timeval	time;
	int timestamp;

	if (pthread_mutex_lock(&(bag->forks[name - 1])) != 0)
		return (ft_putstr_fd("Philo: pthred_mutex_lock failed", 2), FAILED_V2);
	gettimeofday(&time, NULL);
	timestamp = (int)time.tv_usec;
	if (pthread_mutex_lock(bag->mic_m) != 0)
		return (ft_putstr_fd("Philo: pthread_mutex_lock failed", 2), FAILED_V2);
	printf("%d %d has taken a fork\n", (ft_get_current_time() - bag->starting_time), name);
	if (pthread_mutex_unlock(bag->mic_m) != 0)
		return (ft_putstr_fd("Philo: pthread_mutex_unlock failed", 2), FAILED_V2);
	if (name != bag->nbr_philo && pthread_mutex_lock(&(bag->forks[name])) != 0)
		return (ft_putstr_fd("Philo: pthred_mutex_lock failed", 2), FAILED_V2);
	else if (name == bag->nbr_philo && pthread_mutex_lock(&(bag->forks[0])) != 0)
		return (ft_putstr_fd("Philo: thread_mutex_lock failed", 2), FAILED_V2);	
	gettimeofday(&time, NULL);
	timestamp = (int)time.tv_usec;
	if (pthread_mutex_lock(bag->mic_m) != 0)
		return (ft_putstr_fd("Philo: pthread_mutex_lock failed", 2), FAILED_V2);
	printf("%d %d has taken a fork\n", (ft_get_current_time() - bag->starting_time), name);
	if (pthread_mutex_unlock(bag->mic_m) != 0)
		return (ft_putstr_fd("Philo: pthread_mutex_unlock failed", 2), FAILED_V2);
	return (SUCCESS);
}

int	ft_put_back_forks(t_info *bag, int name)
{
	if (pthread_mutex_unlock(&(bag->forks[name - 1])) != 0)
		return (ft_putstr_fd("Philo: thread_mutex_unlock failed", 2), FAILED_V2);	
	if (name != bag->nbr_philo && pthread_mutex_unlock(&(bag->forks[name])) != 0)
		return (ft_putstr_fd("Philo: thread_mutex_unlock failed", 2), FAILED_V2);	
	else if (name == bag->nbr_philo && pthread_mutex_unlock(&(bag->forks[0])) != 0)
		return (ft_putstr_fd("Philo: thread_mutex_unlock failed", 2), FAILED_V2);	
	return (SUCCESS);
}

int	ft_eat(t_info *bag, int name)
{
	struct timeval	time;
	int timestamp;

	ft_take_forks(bag, name);
	gettimeofday(&time, NULL);
	timestamp = (int)time.tv_usec;
	if (pthread_mutex_lock(bag->mic_m) != 0)
		return (ft_putstr_fd("Philo: pthread_mutex_lock failed", 2), FAILED_V2);
	printf("%d %d is eating\n", (ft_get_current_time() - bag->starting_time), name);
	if (pthread_mutex_unlock(bag->mic_m) != 0)
		return (ft_putstr_fd("Philo: pthread_mutex_unlock failed", 2), FAILED_V2);
	usleep(bag->tt_eat * 1000);
	ft_put_back_forks(bag, name);
	return (SUCCESS);
}

int	ft_think(t_info* bag, int name)
{
	struct timeval	time;
	int timestamp;

	gettimeofday(&time, NULL);
	timestamp = (int)time.tv_usec;
	if (pthread_mutex_lock(bag->mic_m) != 0)
		return (ft_putstr_fd("Philo: pthread_mutex_lock failed", 2), FAILED_V2);
	printf("%d %d is thinking\n", (ft_get_current_time() - bag->starting_time), name);
	if (pthread_mutex_unlock(bag->mic_m) != 0)
		return (ft_putstr_fd("Philo: pthread_mutex_unlock failed", 2), FAILED_V2);
	// usleep((bag->tt_eat + bag->tt_sleep) * 1000);
	usleep(10);
	return (SUCCESS);
}

int	ft_sleep(t_info *bag, int name)
{
	struct timeval	time;
	int timestamp;

	gettimeofday(&time, NULL);
	timestamp = (int)time.tv_usec;
	if (pthread_mutex_lock(bag->mic_m) != 0)
		return (ft_putstr_fd("Philo: pthread_mutex_lock failed", 2), FAILED_V2);
	printf("%d %d is sleeping\n", (ft_get_current_time() - bag->starting_time), name);
	if (pthread_mutex_unlock(bag->mic_m) != 0)
		return (ft_putstr_fd("Philo: pthread_mutex_unlock failed", 2), FAILED_V2);
	usleep(bag->tt_sleep * 1000);
	return (SUCCESS);
}

int	ft_philo_life(t_info *bag, int name, int turn, int odd_waiting)
{
	int	i;
	
	i = 0;
	if (pthread_mutex_lock(bag->is_somebody_dead_m) != 0)
		return (ft_putstr_fd("Philo: pthread_mutex_lock failed", 2), FAILED_V2);
	while (bag->is_somebody_dead != 1)
	{
		if (pthread_mutex_unlock(bag->is_somebody_dead_m) != 0)
			return (ft_putstr_fd("Philo: pthread_mutex_unlock failed", 2), FAILED_V2);
		if (ft_my_turn_to_eat(name, turn, odd_waiting))
		{
			ft_eat(bag, name);
			i++;
			if (bag->max_meal != NO_LIMIT && i == bag->max_meal)
				break ;
			ft_sleep(bag,name);
			// printf("%d can eat waiting = %d\n", name, odd_waiting);
		}
		else
		{
			// printf("%d can't eat waiting = %d\n", name, odd_waiting);
			ft_think(bag, name);
		}
		if (odd_waiting != 1 && odd_waiting != NOBODY_WAIT)
			odd_waiting -= 1;
		else if (odd_waiting != NOBODY_WAIT)
			odd_waiting = ft_get_odd_waiting(bag);
		turn = !turn;
		if (pthread_mutex_lock(bag->is_somebody_dead_m) != 0)
			return (ft_putstr_fd("Philo: pthread_mutex_lock failed", 2), FAILED_V2);
	}
	return (SUCCESS);
}

void	*ft_handle_philo(void *bag)
{
	int	name;
	int	turn;
	int	i;
	int	odd_waiting;

	i = 0;
	turn = 1;
	name = ft_get_name((t_info*)bag);
	if (name == FAILED_V2)
		return (NULL); //tell other it failed
	odd_waiting = ft_get_odd_waiting((t_info*)bag);
	if (odd_waiting == FAILED_V2)
		return (NULL); //tell other it failed
	ft_philo_life((t_info*)bag, name, turn, odd_waiting);
	return (NULL);
}
