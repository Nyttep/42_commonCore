/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdubois <pdubois@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/11 01:37:53 by pdubois           #+#    #+#             */
/*   Updated: 2022/08/11 05:12:47 by pdubois          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_take_forks_last_philo(t_info *bag, int name, int *last_meal)
{
	(void)last_meal;
	if (pthread_mutex_lock(&(bag->forks[name - 1])) != 0)
		return (ft_putstr_fd("Philo: mutex_lock failed\n", 2), FAILED);
	if (ft_print_msg(bag, name, "has taken a fork"))
		return (FAILED);
	if (pthread_mutex_lock(&(bag->forks[name])) != 0)
		return (ft_putstr_fd("Philo: mutex_lock failed\n", 2), FAILED);
	if (ft_print_msg(bag, name, "has taken a fork"))
		return (FAILED);
	return (SUCCESS);
}
