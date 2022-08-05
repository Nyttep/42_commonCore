/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdubois <pdubois@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/31 19:01:48 by pdubois           #+#    #+#             */
/*   Updated: 2022/08/05 21:46:41 by pdubois          ###   ########.fr       */
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

# define NO_LIMIT -1
# define NOBODY_WAIT -1
# define FALSE 0
# define TRUE 1
# define FAILED 1
# define SUCCESS 0
# define ODD 1
# define EVEN 0
# define FAILED_V2 -42

typedef struct s_info
{
	int	name;
	pthread_mutex_t	*name_m;
	int	tt_die;
	int	tt_eat;
	int	tt_sleep;
	int	max_meal;
	int	is_somebody_dead;
	pthread_mutex_t	*is_somebody_dead_m;
	int	nbr_philo;
	pthread_mutex_t	*forks;
	pthread_mutex_t	*mic_m;
	int	starting_time;
}	t_info;

void	*ft_handle_philo(void *bag);

void	ft_free_at_end(t_info **bag, pthread_t **philos);
void	ft_free_mutex(pthread_mutex_t *mutex);

int		ft_check_args(int a, char **av);

int		ft_get_current_time(void);

#endif
