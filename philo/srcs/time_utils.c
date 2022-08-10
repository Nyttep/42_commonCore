/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdubois <pdubois@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/05 21:26:37 by pdubois           #+#    #+#             */
/*   Updated: 2022/08/10 04:44:08 by pdubois          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_get_current_time(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return ((int)((time.tv_sec * 1000) + (time.tv_usec / 1000)));
}

int	my_usleep(t_info *bag, int sleep_time, int name, int *last_meal)
{
	int	ret1;
	int	ret2;

	ret1 = ft_is_somebody_dead(bag);
	ret2 = ft_will_die_during_usleep(bag, sleep_time / 1000, name, *last_meal);
	if (ret1 == TRUE || ret2 == TRUE)
		return (SUCCESS);
	else if (ret1 == FAILED_V2 || ret2 == FAILED_V2)
		return (FAILED);
	if (usleep(sleep_time) != 0)
		return (FAILED);
	if (ft_check_if_starved(bag, name, last_meal))
		return (FAILED);
	return (SUCCESS);
}
