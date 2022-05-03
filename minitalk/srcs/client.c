/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdubois <pdubois@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 16:59:20 by pdubois           #+#    #+#             */
/*   Updated: 2022/05/03 21:07:55 by pdubois          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client.h"

int	g_sent = 0;

void	ft_time_out()
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

void	ft_check(int ac, char **av)
{
	if (ac != 3)
		ft_wrong_args(av);
}

void	ft_wrong_pid()
{
	ft_putstr_fd("Wrong PID or server has been shut down", 2);
	exit(1);
}

int		ft_figure_out_bin(char **av)
{
	static int	i = 0;
	static int	comp = 0b10000000;
	int			ret;

	if ((av[2][i / 8] | comp) == (av[2][i / 8]))
		ret = 1;
	else
		ret = 0;
	comp = comp >> 1;
	if (comp == 0)
		comp = 0b10000000;
	i++;
	return (ret);
}

void	ft_init_com(int pid, char **av)
{
	if (ft_figure_out_bin(av) == 0)
	{
		if (kill(pid, SIGUSR1) == -1)
			ft_wrong_pid();
	}
	else
		if (kill(pid, SIGUSR2) == -1)
			ft_wrong_pid();
}

void	ft_count_sent(int signum)
{
	(void)signum;
	g_sent++;
}

void	ft_communication(int pid, char **av)
{
	int	i;
	int	len;

	len = ft_strlen(av[2]);
	i = 1;
	signal(SIGUSR1, ft_count_sent);
	while (i / 8 <= len)
	{
		usleep(5000);
		if (g_sent != i)
			ft_time_out();
		if (ft_figure_out_bin(av) == 0)
		{
			if (kill(pid, SIGUSR1) == -1)
				ft_wrong_pid();
		}
		else
			if (kill(pid, SIGUSR2) == -1)
				ft_wrong_pid();
		i++;
	}
}

int	main(int ac, char **av)
{
	int	pid;

	pid = ft_atoi(av[1]);
	ft_check(ac, av);
	ft_init_com(pid, av);
	ft_communication(pid, av);
	// kill(ft_atoi(av[1]), SIGUSR1);
}
