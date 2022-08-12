/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdubois <pdubois@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/31 17:28:55 by pdubois           #+#    #+#             */
/*   Updated: 2022/08/12 18:15:06 by pdubois          ###   ########.fr       */
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
	(*bag)->max_reached = ft_atoi(av[1]);
	return (SUCCESS);
}

static int	ft_init(pthread_t **philos, t_info **bag,
			char **av, int nbr_philo)
{
	int	i;

	i = 0;
	if (ft_init_bags(bag, av))
		return (FAILED);
	if (ft_init_mutex1(bag, av))
		return (free(*bag), FAILED);
	(*bag)->starting_time = ft_get_current_time();
	*philos = malloc(sizeof(pthread_t) * (ft_atoi(av[1])));
	if (*philos == NULL)
		return (free((*bag)->forks), free(*bag),
			ft_putstr_fd("Philo: Malloc failed\n", 2), FAILED);
	ft_bzero(*philos, sizeof(pthread_t) * (nbr_philo));
	while (i < nbr_philo)
	{
		if (pthread_create(&(*philos)[i], NULL, ft_handle_philo,
			*bag) != SUCCESS)
			return (free(*philos), free((*bag)->forks), free(*bag),
				ft_putstr_fd("Philo: failed to create a thread\n", 2), FAILED);
		i++;
	}
	return (SUCCESS);
}

int	main(int ac, char **av)
{
	pthread_t		*philos;
	t_info			*bag;
	int				i;
	int				nbr_philo;

	if (ft_check_args(ac, av))
		return (FAILED);
	nbr_philo = ft_atoi(av[1]);
	if (ft_init(&philos, &bag, av, nbr_philo))
		return (1);
	i = 0;
	while (i < nbr_philo)
	{
		pthread_join(philos[i++], NULL);
		usleep(1);
	}
	ft_free_at_end(&bag, &philos);
	return (0);
}
