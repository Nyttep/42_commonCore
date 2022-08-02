/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_philo.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdubois <pdubois@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/31 19:59:46 by pdubois           #+#    #+#             */
/*   Updated: 2022/08/02 19:22:24 by pdubois          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	ft_get_name(t_info *bag)
{
	int	name;

	pthread_mutex_lock(bag->name_m);
	pthread_mutex_lock(bag->nbr_philo_m);
	name = (bag->nbr_philo - bag->name) + 1;
	bag->name--;
	pthread_mutex_unlock(bag->name_m);
	pthread_mutex_unlock(bag->nbr_philo_m);
	return (name);
}

int	ft_my_turn_to_eat(t_info *bag, int name, int turn)
{
	pthread_mutex_lock(bag->odd_waiting_m);
	if (name % 2 == turn && bag->odd_waiting != name)
		return (pthread_mutex_unlock(bag->odd_waiting_m), 1);
	else
		return (pthread_mutex_unlock(bag->odd_waiting_m), 0);
}

void	*ft_handle_philo(void *bag)
{
	int	name;
	int	turn;
	int	i;

	i = 0;
	turn = 1;
	name = ft_get_name((t_info*)bag);
	while (i < 10)
	{
		if (ft_my_turn_to_eat((t_info*)bag, name, turn))
		{
			printf("%d can eat\n", name);
			usleep(1000);
		}
		else
		{
			printf("%d can't eat\n", name);
			usleep(1000);
		}
		turn = !turn;
		i++;
	}
	return (NULL);
}
