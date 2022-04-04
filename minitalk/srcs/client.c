/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdubois <pdubois@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 16:59:20 by pdubois           #+#    #+#             */
/*   Updated: 2022/04/04 02:33:31 by pdubois          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client.h"

int	g_sent = 0;

void	ft_wrong_args()
{
	ft_printf("client should be called like so :\n./client <server PID> <string>");
	exit(-1);
}

void	ft_check(int ac)
{
	if (ac != 3)
		ft_wrong_args();
}

void	ft_wrong_pid()
{
	ft_printf("Wrong PID or server has been shut down");
	exit(-1);
}

int		ft_figure_out_bin(char **av)
{
	static int	i = 0;
	static int	comp = 0b10000000;
	int			ret;

	if ((av[1][i / 8] | comp) == (av[1][i / 8]))
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
	g_sent++;
}

void	ft_communication(int pid, char **av)
{
	int	i;
	int	len;

	len = ft_strlen(av[1]);
	i = 1;
	write(1, "eeeeeeee", 9);
	while (i / 8 <= len)
	{
		sleep(1);
		write(1, "eeeeeeee", 9);
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
	signal(SIGUSR1, ft_copunt_sent);
}

int	main(int ac, char **av)
{
	int	pid;

	(void) ac;
	pid = ft_atoi(av[1]);
	ft_check(ac);
	ft_init_com(pid, av);
	ft_communication(pid, av);
	// kill(ft_atoi(av[1]), SIGUSR1);
}