/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdubois <pdubois@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/31 19:01:48 by pdubois           #+#    #+#             */
/*   Updated: 2022/07/31 20:09:33 by pdubois          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/time.h>
# include "libft.h"

typedef struct s_info
{
	int	name;
	int	tt_die;
	int	tt_eat;
	int	tt_sleep;
	int	max_eat;
	int	last_meal;
	int	dead;
	int	nbr_philo;
	struct timeval	time;
}	t_info;

void	*ft_handle_philo(void *bag);

#endif
