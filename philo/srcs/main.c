/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdubois <pdubois@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/31 17:28:55 by pdubois           #+#    #+#             */
/*   Updated: 2022/08/05 21:46:26 by pdubois          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	ft_init_bags(t_info **bag, char **av)
{
	*bag = malloc(sizeof(t_info));
	if (*bag == NULL)
		return (ft_putstr_fd("Philo: Malloc failed\n", 2), FAILED);
	ft_bzero(*bag, sizeof(t_info));
	(*bag)->name = ft_atoi(av[1]);
	(*bag)->tt_die = ft_atoi(av[2]);
	(*bag)->tt_eat = ft_atoi(av[3]);
	(*bag)->tt_sleep = ft_atoi(av[4]);
	if (av[5] != NULL)
		(*bag)->max_meal = ft_atoi(av[5]);
	else
		(*bag)->max_meal = NO_LIMIT;
	(*bag)->is_somebody_dead = FALSE;
	(*bag)->nbr_philo = ft_atoi(av[1]);
	return (SUCCESS);
}

int	ft_init_mutex(t_info **bag, char **av)
{
	int	i;

	i = 0;
	(*bag)->name_m = malloc(sizeof(pthread_mutex_t));
	if ((*bag)->name_m == NULL)
		return (ft_putstr_fd("Philo: Malloc failed\n", 2), FAILED);
	if (pthread_mutex_init((*bag)->name_m, NULL) != 0)
		return (free((*bag)->name_m), ft_putstr_fd("Philo: Mutex initialisation failed\n", 2), FAILED);
	(*bag)->mic_m = malloc(sizeof(pthread_mutex_t));
	if ((*bag)->mic_m == NULL)
		return (ft_free_mutex((*bag)->name_m), ft_putstr_fd("Philo: Malloc failed\n", 2), FAILED);
	if (pthread_mutex_init((*bag)->mic_m, NULL) != 0)
		return (free((*bag)->mic_m), ft_free_mutex((*bag)->name_m), ft_putstr_fd("Philo: Mutex initialisation failed\n", 2), FAILED);
	(*bag)->is_somebody_dead_m = malloc(sizeof(pthread_mutex_t));
	if ((*bag)->is_somebody_dead_m == NULL)
		return (ft_free_mutex((*bag)->mic_m), ft_free_mutex((*bag)->name_m), ft_putstr_fd("Philo: Malloc failed\n", 2), FAILED);
	if (pthread_mutex_init((*bag)->is_somebody_dead_m, NULL) != 0)
		return (free((*bag)->is_somebody_dead_m), ft_free_mutex((*bag)->mic_m), ft_free_mutex((*bag)->name_m), ft_putstr_fd("Philo: Mutex initialisation failed\n", 2), FAILED);
	(*bag)->forks = malloc(sizeof(pthread_mutex_t) * (ft_atoi(av[1])));
	if ((*bag)->forks == NULL)
		return (ft_free_mutex((*bag)->is_somebody_dead_m), ft_free_mutex((*bag)->mic_m), ft_free_mutex((*bag)->name_m), ft_putstr_fd("Philo: Malloc failed\n", 2), FAILED);
	while (i < ft_atoi(av[1]))
	{
		if (pthread_mutex_init(&((*bag)->forks[i++]), NULL) != 0)
		{
			while (--i >= 0)
				pthread_mutex_destroy(&((*bag)->forks[i]));
			return (ft_free_mutex((*bag)->is_somebody_dead_m), ft_free_mutex((*bag)->mic_m), ft_free_mutex((*bag)->name_m), free((*bag)->forks), ft_putstr_fd("Philo: Malloc failed\n", 2), FAILED);
		}
	}
	return (SUCCESS);
}

static int	ft_init(pthread_t **philos, t_info **bag,
			char **av)
{
	int	i;

	i = 0;
	if (ft_init_bags(bag, av) == FAILED)
		return (FAILED);
	if (ft_init_mutex(bag, av) == FAILED)
		return (free(*bag), FAILED);
	*philos = malloc(sizeof(pthread_t) * (ft_atoi(av[1])));
	if (*philos == NULL)
		return (free((*bag)->forks), free(*bag),
			ft_putstr_fd("Philo: Malloc failed\n", 2), FAILED);
	ft_bzero(*philos, sizeof(pthread_t) * (ft_atoi(av[1])));
	while (i < ft_atoi(av[1]))
	{
		if (pthread_create(&(*philos)[i], NULL, ft_handle_philo,
				*bag) != SUCCESS)
			return (free(*philos), free((*bag)->forks), free(*bag),
				ft_putstr_fd("Philo: failed to create a thread\n", 2), FAILED);
		i++;
	}
	(*bag)->starting_time = ft_get_current_time();
	return (SUCCESS);
}

int	main(int ac, char **av)
{
	pthread_t		*philos;
	t_info			*bag;
	int				i;

	if (ft_check_args(ac, av) == FAILED)
		return (FAILED);
	if (ft_init(&philos, &bag, av) == FAILED)
		return (1);
	i = 0;
	while (i < ft_atoi(av[1]))
	{
		pthread_join(philos[i++], NULL);
		usleep(1);
	}
	ft_free_at_end(&bag, &philos);
	return (0);
}
