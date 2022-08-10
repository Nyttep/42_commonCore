/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mutex.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdubois <pdubois@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/10 05:26:45 by pdubois           #+#    #+#             */
/*   Updated: 2022/08/10 05:31:59 by pdubois          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	ft_init_forks(t_info **bag, char **av)
{
	int	i;

	i = 0;
	(*bag)->forks = malloc(sizeof(pthread_mutex_t) * (ft_atoi(av[1])));
	if ((*bag)->forks == NULL)
		return (ft_free_mutex((*bag)->max_reached_m),
			ft_free_mutex((*bag)->is_somebody_dead_m),
			ft_free_mutex((*bag)->mic_m),
			ft_free_mutex((*bag)->name_m),
			ft_putstr_fd("Philo: Malloc failed\n", 2), FAILED);
	while (i < ft_atoi(av[1]))
	{
		if (pthread_mutex_init(&((*bag)->forks[i++]), NULL) != 0)
		{
			while (--i >= 0)
				ft_free_mutex(&((*bag)->forks[i]));
			return (ft_free_mutex((*bag)->max_reached_m),
				ft_free_mutex((*bag)->is_somebody_dead_m),
				ft_free_mutex((*bag)->mic_m),
				ft_free_mutex((*bag)->name_m), free((*bag)->forks),
				ft_putstr_fd("Philo: Malloc failed\n", 2), FAILED);
		}
	}
	return (SUCCESS);
}

static int	ft_init_mutex2(t_info **bag)
{
	(*bag)->is_somebody_dead_m = malloc(sizeof(pthread_mutex_t));
	if ((*bag)->is_somebody_dead_m == NULL)
		return (ft_free_mutex((*bag)->mic_m), ft_free_mutex((*bag)->name_m),
			ft_putstr_fd("Philo: Malloc failed\n", 2), FAILED);
	if (pthread_mutex_init((*bag)->is_somebody_dead_m, NULL) != 0)
		return (free((*bag)->is_somebody_dead_m), ft_free_mutex((*bag)->mic_m),
			ft_free_mutex((*bag)->name_m),
			ft_putstr_fd("Philo: Mutex initialisation failed\n", 2), FAILED);
	(*bag)->max_reached_m = malloc(sizeof(pthread_mutex_t));
	if ((*bag)->max_reached_m == NULL)
		return (ft_free_mutex((*bag)->is_somebody_dead_m),
			ft_free_mutex((*bag)->mic_m), ft_free_mutex((*bag)->name_m),
			ft_putstr_fd("Philo: Malloc failed\n", 2), FAILED);
	if (pthread_mutex_init((*bag)->max_reached_m, NULL) != 0)
		return (free((*bag)->max_reached_m),
			ft_free_mutex((*bag)->is_somebody_dead_m),
			ft_free_mutex((*bag)->mic_m), ft_free_mutex((*bag)->name_m),
			ft_putstr_fd("Philo: Mutex initialisation failed\n", 2), FAILED);
	return (SUCCESS);
}

int	ft_init_mutex1(t_info **bag, char **av)
{
	(*bag)->name_m = malloc(sizeof(pthread_mutex_t));
	if ((*bag)->name_m == NULL)
		return (ft_putstr_fd("Philo: Malloc failed\n", 2), FAILED);
	if (pthread_mutex_init((*bag)->name_m, NULL) != 0)
		return (free((*bag)->name_m),
			ft_putstr_fd("Philo: Mutex initialisation failed\n", 2), FAILED);
	(*bag)->mic_m = malloc(sizeof(pthread_mutex_t));
	if ((*bag)->mic_m == NULL)
		return (ft_free_mutex((*bag)->name_m),
			ft_putstr_fd("Philo: Malloc failed\n", 2), FAILED);
	if (pthread_mutex_init((*bag)->mic_m, NULL) != 0)
		return (free((*bag)->mic_m), ft_free_mutex((*bag)->name_m),
			ft_putstr_fd("Philo: Mutex initialisation failed\n", 2), FAILED);
	if (ft_init_mutex2(bag))
		return (FAILED);
	if (ft_init_forks(bag, av))
		return (FAILED);
	return (SUCCESS);
}
