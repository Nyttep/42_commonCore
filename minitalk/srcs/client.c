/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdubois <pdubois@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 16:59:20 by pdubois           #+#    #+#             */
/*   Updated: 2022/06/16 19:26:30 by pdubois          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client.h"

int	g_sent = 0;

static int	ft_figure_out_bin(char **av)
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

static void	ft_init_com(int pid, char **av)
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

void	ft_count_sent(int signum, siginfo_t *info, void *context)
{
	(void)signum;
	(void)info;
	(void)context;
	g_sent++;
}

static void	ft_communication(int pid, char **av)
{
	int	i;
	int	len;

	len = ft_strlen(av[2]);
	i = 1;
	ft_init_com(pid, av);
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
	int					pid;
	struct sigaction	sa;

	ft_bzero((void *)&sa, sizeof(struct sigaction));
	sa.sa_flags = SA_SIGINFO;
	sa.sa_sigaction = ft_count_sent;
	if (sigaction(SIGUSR1, &sa, NULL) == -1)
		ft_error("Error : Signal handling failed");
	ft_check(ac, av);
	pid = ft_atoi(av[1]);
	ft_communication(pid, av);
}
