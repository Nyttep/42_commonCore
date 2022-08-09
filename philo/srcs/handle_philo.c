/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_philo.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdubois <pdubois@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/31 19:59:46 by pdubois           #+#    #+#             */
/*   Updated: 2022/08/09 06:38:20 by pdubois          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	my_usleep(t_info *bag, int sleep_time, int name, int *last_meal)
{
	long long int	i;

	i = 0;
	while (i < sleep_time)
	{
		if (pthread_mutex_lock(bag->is_somebody_dead_m) != 0)
			return (ft_putstr_fd("Philo: pthread_mutex_lock failed", 2), FAILED);
		if (bag->is_somebody_dead == TRUE)
		{
			if (pthread_mutex_unlock(bag->is_somebody_dead_m) != 0)
				return (ft_putstr_fd("Philo: pthread_mutex_unlock failed", 2), FAILED);
			return (SUCCESS);
		}
		if (pthread_mutex_unlock(bag->is_somebody_dead_m) != 0)
			return (ft_putstr_fd("Philo: pthread_mutex_unlock failed", 2), FAILED);
		usleep(5 * 1000);
		i += 5;
		if (ft_check_if_starved(bag, name, last_meal) == FAILED)
			return (FAILED_V2);
	}
	return (SUCCESS);
}

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
		diff *= -1;
		if (diff % 2 == ODD)
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
	if (pthread_mutex_lock(bag->is_somebody_dead_m) != 0)
		return (ft_putstr_fd("Philo: pthread_mutex_lock failed", 2), FAILED);
	if (bag->is_somebody_dead == FALSE)
	{
		if (pthread_mutex_lock(bag->mic_m) != 0)
			return (ft_putstr_fd("Philo: pthread_mutex_lock failed", 2), FAILED);
		if (pthread_mutex_lock(bag->starting_time_m) != 0)
			return (ft_putstr_fd("Philo: pthread_mutex_lock failed", 2), FAILED);
		printf("%d %d %s\n", (ft_get_current_time() - bag->starting_time), name, msg);
		if (pthread_mutex_unlock(bag->starting_time_m) != 0)
			return (ft_putstr_fd("Philo: pthread_mutex_unlock failed", 2), FAILED);
		if (pthread_mutex_unlock(bag->mic_m) != 0)
			return (ft_putstr_fd("Philo: pthread_mutex_unlock failed", 2), FAILED);
	}
	if (pthread_mutex_unlock(bag->is_somebody_dead_m) != 0)
		return (ft_putstr_fd("Philo: pthread_mutex_unlock failed", 2), FAILED);
	return (SUCCESS);
}

int	ft_take_forks(t_info *bag, int name)
{
	if (pthread_mutex_lock(&(bag->forks[name - 1])) != 0)
		return (ft_putstr_fd("Philo: pthred_mutex_lock failed", 2), FAILED_V2);
	if (ft_print_msg(bag, name, "has taken a fork"))
		return (FAILED_V2);
	if (name != bag->nbr_philo && pthread_mutex_lock(&(bag->forks[name])) != 0)
		return (ft_putstr_fd("Philo: pthred_mutex_lock failed", 2), FAILED_V2);
	else if (name == bag->nbr_philo && pthread_mutex_lock(&(bag->forks[0])) != 0)
		return (ft_putstr_fd("Philo: thread_mutex_lock failed", 2), FAILED_V2);	
	if (ft_print_msg(bag, name, "has taken a fork"))
		return (FAILED_V2);
	return (SUCCESS);
}

int	ft_put_back_forks(t_info *bag, int name)
{
	if (name != bag->nbr_philo && pthread_mutex_unlock(&(bag->forks[name])) != 0)
		return (ft_putstr_fd("Philo: thread_mutex_unlock failed", 2), FAILED_V2);	
	else if (name == bag->nbr_philo && pthread_mutex_unlock(&(bag->forks[0])) != 0)
		return (ft_putstr_fd("Philo: thread_mutex_unlock failed", 2), FAILED_V2);	
	if (pthread_mutex_unlock(&(bag->forks[name - 1])) != 0)
		return (ft_putstr_fd("Philo: thread_mutex_unlock failed", 2), FAILED_V2);	
	return (SUCCESS);
}

int	ft_check_if_starved(t_info *bag, int name, int *last_meal)
{
	int	current_time;

	current_time = ft_get_current_time();
	if (*last_meal == 0)
		*last_meal = current_time;
	else if (current_time - *last_meal >= bag->tt_die)
	{
		if (ft_print_msg(bag, name, "died") == FAILED)
			return (FAILED);
		if (pthread_mutex_lock(bag->is_somebody_dead_m) != 0)
			return (ft_putstr_fd("Philo: pthread_mutex_lock failed", 2), FAILED);
		bag->is_somebody_dead = TRUE;
		if (pthread_mutex_unlock(bag->is_somebody_dead_m) != 0)
			return (ft_putstr_fd("Philo: pthread_mutex_unlock failed", 2), FAILED);
	}
	return (SUCCESS);

}

int	ft_eat(t_info *bag, int name, int *last_meal)
{
	ft_take_forks(bag, name);
	if (ft_print_msg(bag, name, "is eating"))
		return (FAILED_V2);
	*last_meal = ft_get_current_time();
	if (my_usleep(bag, bag->tt_eat, name, last_meal) == FAILED)
		return (FAILED_V2);
	ft_put_back_forks(bag, name);
	return (SUCCESS);
}

int	ft_think(t_info* bag, int name, int *last_meal)
{
	(void)last_meal;
	if (ft_print_msg(bag, name, "is thinking"))
		return (FAILED_V2);
	// my_usleep(bag, (bag->tt_eat + bag->tt_sleep) / 2, name, last_meal);
	// my_usleep(bag, 10, name, last_meal);
	return (SUCCESS);
}

int	ft_sleep(t_info *bag, int name, int *last_meal)
{
	if (ft_print_msg(bag, name, "is sleeping"))
		return (FAILED_V2);
	if (my_usleep(bag, bag->tt_sleep, name, last_meal) == FAILED)
		return (FAILED_V2);
	return (SUCCESS);
}

int	ft_philo_life(t_info *bag, int name, int turn, int odd_waiting)
{
	int	i;
	int	last_meal;
	
	last_meal = 0;
	i = 0;
	while (1)
	{
		if (ft_my_turn_to_eat(name, turn, odd_waiting, bag->nbr_philo))
		{
			i++;
			if (bag->max_meal != NO_LIMIT && i == bag->max_meal)
			{
				ft_take_forks(bag, name);
				ft_print_msg(bag, name, "is eating");
				ft_put_back_forks(bag, name);
				ft_print_msg(bag, name, "died");
				if (pthread_mutex_lock(bag->is_somebody_dead_m) != 0)
					return (ft_putstr_fd("Philo: pthread_mutex_lock failed", 2), FAILED_V2);
				bag->is_somebody_dead = TRUE;
				if (pthread_mutex_unlock(bag->is_somebody_dead_m) != 0)
					return (ft_putstr_fd("Philo: pthread_mutex_unlock failed", 2), FAILED_V2);
				break ;
			}
			ft_eat(bag, name, &last_meal);
			ft_sleep(bag, name, &last_meal);
		}
		else
		{
			ft_think(bag, name, &last_meal);
		}
		if (odd_waiting != 1 && odd_waiting != NOBODY_WAIT)
			odd_waiting--;
		else if (odd_waiting != NOBODY_WAIT)
			odd_waiting = ft_get_odd_waiting(bag);
		turn = !turn;
		if (pthread_mutex_lock(bag->is_somebody_dead_m) != 0)
			return (ft_putstr_fd("Philo: pthread_mutex_lock failed", 2), FAILED_V2);
		if (bag->is_somebody_dead == TRUE)
		{
			if (pthread_mutex_unlock(bag->is_somebody_dead_m) != 0)
				return (ft_putstr_fd("Philo: pthread_mutex_unlock failed", 2), FAILED_V2);
			break ;
		}
		if (pthread_mutex_unlock(bag->is_somebody_dead_m) != 0)
			return (ft_putstr_fd("Philo: pthread_mutex_unlock failed", 2), FAILED_V2);
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
