/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdubois <pdubois@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 15:09:15 by pdubois           #+#    #+#             */
/*   Updated: 2022/08/09 06:41:06 by pdubois          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_free_mutex(pthread_mutex_t *mutex)
{
	pthread_mutex_destroy(mutex);
	free(mutex);
}

void	ft_free_at_end(t_info **bag, pthread_t **philos)
{
	int	i;

	i = 0;
	while (i < (*bag)->nbr_philo)
		pthread_mutex_destroy(&(*bag)->forks[i++]);
	ft_free_mutex((*bag)->name_m);
	ft_free_mutex((*bag)->mic_m);
	ft_free_mutex((*bag)->is_somebody_dead_m);
	ft_free_mutex((*bag)->starting_time_m);
	free((*bag)->forks);
	free(*bag);
	free(*philos);
}