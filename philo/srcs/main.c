/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdubois <pdubois@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/31 17:28:55 by pdubois           #+#    #+#             */
/*   Updated: 2022/07/31 20:19:29 by pdubois          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_init(pthread_t **philos, pthread_mutex_t **forks, t_info **bag, char **av)
{
	int	i;

	i = 0;
	*forks = malloc(sizeof(pthread_mutex_t) * (ft_atoi(av[1])));
	if (*forks == NULL)
		return (ft_putstr_fd("Philo: Malloc failed", 2), 1);
	ft_bzero(*forks, sizeof(pthread_mutex_t) * (ft_atoi(av[1]))); 
	*bag = malloc(sizeof(t_info) * (ft_atoi(av[1])));
	if (*bag == NULL)
		return (free(*forks), ft_putstr_fd("Philo: Malloc failed", 2), 1);
	ft_bzero(*bag, sizeof(t_info) * (ft_atoi(av[1])));
	*philos = malloc(sizeof(pthread_t) * (ft_atoi(av[1])));
	if (*philos == NULL)
		return (free(*forks), free(*bag), ft_putstr_fd("Philo: Malloc failed", 2), 1);
	ft_bzero(*philos, sizeof(pthread_mutex_t) * (ft_atoi(av[1]))); 
	while (i < ft_atoi(av[1]))
	{
		if (pthread_create(&(*philos[i]), NULL, ft_handle_philo, &(*bag[i]))  != 0)
			return (free(*philos), free(*forks), free(*bag), ft_putstr_fd("Philo: failed to create a thread", 2), 1);
		i++;
	}
	return (0);
}

int	main(int ac, char **av)
{
	pthread_t		*philos;
	pthread_mutex_t	*forks;
	t_info			*bag;
	int	i;

	(void)ac;
	(void)av;
	if (ft_init(&philos, &forks, &bag, av) != 0)
		return (1);
	i = 0;
	return (0);
}

//NEED TO INIT THE BAGS TOO AND CHECK PARSING ERRORS