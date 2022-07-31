/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdubois <pdubois@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/31 19:01:48 by pdubois           #+#    #+#             */
/*   Updated: 2022/07/31 19:07:01 by pdubois          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pthread.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/time.h>

typedef struct s_info
{
	int	name;
	int	tt_die;
	int	tt_eat;
	int	tt_sleep;
	int	max_eat;
	int	last_meal;
	int	dead;

}	t_info
