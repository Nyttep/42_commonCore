/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdubois <pdubois@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 16:59:20 by pdubois           #+#    #+#             */
/*   Updated: 2022/04/01 19:13:51 by pdubois          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client.h"

int	main(int ac, char **av)
{
	(void) ac;
	kill(ft_atoi(av[1]), SIGUSR1);
	usleep(1000);
	kill(ft_atoi(av[1]), SIGUSR2);
	usleep(1000);
	kill(ft_atoi(av[1]), SIGUSR2);
	usleep(1000);
	kill(ft_atoi(av[1]), SIGUSR1);
	usleep(1000);
	kill(ft_atoi(av[1]), SIGUSR1);
	usleep(1000);
	kill(ft_atoi(av[1]), SIGUSR1);
	usleep(1000);
	kill(ft_atoi(av[1]), SIGUSR1);
	usleep(1000);
	kill(ft_atoi(av[1]), SIGUSR2);
	usleep(1000);
	kill(ft_atoi(av[1]), SIGUSR1);
	usleep(1000);
	kill(ft_atoi(av[1]), SIGUSR1);
	usleep(1000);
	kill(ft_atoi(av[1]), SIGUSR1);
	usleep(1000);
	kill(ft_atoi(av[1]), SIGUSR1);
	usleep(1000);
	kill(ft_atoi(av[1]), SIGUSR1);
	usleep(1000);
	kill(ft_atoi(av[1]), SIGUSR1);
	usleep(1000);
	kill(ft_atoi(av[1]), SIGUSR1);
	usleep(1000);
	kill(ft_atoi(av[1]), SIGUSR1);
}