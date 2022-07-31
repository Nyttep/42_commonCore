/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdubois <pdubois@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/31 17:28:55 by pdubois           #+#    #+#             */
/*   Updated: 2022/07/31 19:07:04 by pdubois          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int ac, char **av)
{
	pthread_t		*philos;
	pthread_mutex_t	*forks;
	struct timeval	time;
	t_info			*bag;
	int	i;

	(void)ac;
	(void)av;
	i = 0;
	forks = malloc (sizeof(pthread_mutex_t) * (ft_atoi(av[1]) + 1));
	if (forks == NULL)
		return (free(philos), ft_pustr_fd("Philo: Malloc failed", 2), 1);
	forks[ft_atoi(av[1]) + 1] = NULL;
	bag = malloc (sizeof(t_info) * (ft_atoi(av[1]) + 1));
	if (bag == NULL)
		return (free(philos), free(forks), ft_pustr_fd("Philo: Malloc failed", 2), 1);
	bag[ft_atoi(av[1]) + 1] = NULL;
	philos = malloc (sizeof(pthread_t) * (ft_atoi(av[1]) + 1));
	if (philos == NULL)
		return (ft_pustr_fd("Philo: Malloc failed", 2), 1);
	philos[ft_atoi(av[1]) + 1] = NULL;
	while (i < (ft_atoi(av[1]) + 1))
	{
		if (pthread_create(philos[i++], NULL, ft_handle_philo, &bag[i])  != 0)
			return (free(philos), ft_pustr_fd("Philo: failed to create a thread", 2));
	}
}
