/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdubois <pdubois@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/05 21:26:37 by pdubois           #+#    #+#             */
/*   Updated: 2022/08/12 18:39:08 by pdubois          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long int	ft_get_current_time(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return ((unsigned long int)((time.tv_sec * 1000) + (time.tv_usec / 1000)));
}

int	my_usleep(t_info *bag, unsigned long int sleep_time, int name,
			long int *last_meal)
{
	int	ret1;

	ret1 = ft_will_die_during_usleep(bag, sleep_time / 1000, name, *last_meal);
	if (ret1 == TRUE)
		return (SUCCESS);
	else if (ret1 == FAILED_V2)
		return (FAILED);
	if (usleep(sleep_time) != 0)
		return (FAILED);
	return (SUCCESS);
}
