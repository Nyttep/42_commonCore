/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdubois <pdubois@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 16:59:20 by pdubois           #+#    #+#             */
/*   Updated: 2022/06/15 22:38:04 by pdubois          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client.h"

int	g_sent = 0;

int	ft_error(char *msg)
{
	ft_putstr_fd(msg, 2);
	exit(1);
}

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

void	ft_pid_lower_than_one()
{
	ft_putstr_fd("wrong PID", 2);
	exit(1);
}


void	ft_pid_bigger_than_maxint()
{
	ft_putstr_fd("PID souldn't be bigger or lower than max int", 2);
	exit(1);
}

long long int	ft_long_atoi(const char *str)
{
	int				i;
	long long int	neg;
	long long int	res;

	i = 0;
	neg = 1;
	res = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == ' ')
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			neg = -1;
		i++;
	}
	while (ft_isdigit(str[i]))
	{
		res = (str[i] - 48) + (res * 10);
		i++;
	}
	return (res * neg);
}

void	ft_check(int ac, char **av)
{
	int	i;

	i = 0;
	if (ac != 3)
		ft_wrong_args(av);
	while (ft_isdigit(av[1][i]) && av[1][i])
		i++;
	if (av[1][i] != 0)
		ft_wrong_args(av);
	if (ft_long_atoi(av[1]) > 2147483647 || ft_strlen(av[1]) > 12)
		ft_pid_bigger_than_maxint();
	else if (ft_atoi(av[1]) < 1)
		ft_pid_lower_than_one();
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

void	ft_count_sent(int signum, siginfo_t *info, void *context)
{
	(void)signum;
	(void)info;
	(void)context;
	g_sent++;
}

void	ft_communication(int pid, char **av)
{
	int	i;
	int	len;

	len = ft_strlen(av[2]);
	i = 0;
	while (i / 8 <= len)
	{
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
		sleep(1);
		i++;
	}
}

int	main(int ac, char **av)
{
	int	pid;
	struct sigaction	sa;

	ft_bzero((void*)&sa, sizeof(struct sigaction));
	sa.sa_flags = SA_SIGINFO;
	sa.sa_sigaction = ft_count_sent;
	if (sigaction(SIGUSR1, &sa, NULL) == -1)
		ft_error("Error : Signal handling failed");
	ft_check(ac, av);
	pid = ft_atoi(av[1]);
	ft_communication(pid, av);
}
