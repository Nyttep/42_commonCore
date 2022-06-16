/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_errors1.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdubois <pdubois@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 19:20:02 by pdubois           #+#    #+#             */
/*   Updated: 2022/06/16 19:39:32 by pdubois          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client.h"

int	ft_error(char *msg)
{
	ft_putstr_fd(msg, 2);
	exit(1);
}

void	ft_time_out(void)
{
	ft_putstr_fd("Server did not respond in time", 2);
	exit(1);
}

void	ft_wrong_args(char **av)
{
	ft_putstr_fd(av[0] + 2, 2);
	ft_putstr_fd(" should be called like so :\n", 2);
	ft_putstr_fd(av[0], 2);
	ft_putstr_fd(" <server PID> <string>\n", 2);
	exit(1);
}

void	ft_pid_bigger_than_maxint(void)
{
	ft_putstr_fd("PID souldn't be bigger or lower than max int", 2);
	exit(1);
}

void	ft_pid_lower_than_one(void)
{
	ft_putstr_fd("Wrong PID", 2);
	exit(1);
}
