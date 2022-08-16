/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdubois <pdubois@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/31 19:01:48 by pdubois           #+#    #+#             */
/*   Updated: 2022/08/16 05:26:27 by pdubois          ###   ########.fr       */
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
	int						name;
	pthread_mutex_t			*name_m;
	int						tt_die;
	int						tt_eat;
	int						tt_sleep;
	int						max_meal;
	int						max_reached;
	pthread_mutex_t			*max_reached_m;
	int						is_somebody_dead;
	pthread_mutex_t			*is_somebody_dead_m;
	int						nbr_philo;
	pthread_mutex_t			*forks;
	pthread_mutex_t			*mic_m;
	long int				starting_time;
}	t_info;

int			ft_init_mutex1(t_info **bag, char **av);

void		*ft_handle_philo(void *bag);

int			ft_get_name(t_info *bag);
int			ft_get_odd_waiting(t_info *bag);
int			ft_update_odd_waiting(t_info *bag, int odd_waiting);
int			ft_print_msg(t_info *bag, int name, char *msg);

void		ft_free_at_end(t_info **bag, pthread_t **philos);
void		ft_free_mutex(pthread_mutex_t *mutex);

int			ft_check_args(int a, char **av);

long int	ft_get_current_time(void);
int			my_usleep(t_info *bag, unsigned long int sleep_time, int name,
				long int *last_meal);

int			ft_is_somebody_dead(t_info *bag);
int			ft_will_die_during_usleep(t_info *bag, int sleep_time, int name,
				long int last_meal);
int			ft_philo_died(t_info *bag, int name);

int			ft_print_msg(t_info *bag, int name, char *msg);

int			ft_take_forks(t_info *bag, int name, long int *last_meal,
				int *took_fork);
int			ft_take_forks_not_last_philo(t_info *bag, int name,
				long int *last_meal, int *took_fork);
int			ft_put_back_forks(t_info *bag, int name, int *took_fork);
int			ft_will_die_waiting_fork(t_info *bag, int name, long int last_meal);
int			ft_eat(t_info *bag, int name, long int *last_meal);
int			ft_think(t_info *bag, int name, long int *last_meal,
				int odd_wainting);
int			ft_sleep(t_info *bag, int name, long int *last_meal);

int			ft_my_turn_to_eat_even(int name, int turn);
int			ft_my_turn_to_eat_odd(int name, int odd_waiting);
int			ft_my_turn_to_eat(int name, int turn, int odd_waiting,
				int nbr_philo);

#endif
