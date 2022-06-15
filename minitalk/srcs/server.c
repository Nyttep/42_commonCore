/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdubois <pdubois@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 17:11:28 by pdubois           #+#    #+#             */
/*   Updated: 2022/06/15 22:37:55 by pdubois          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

int	g_received[2] = {0, 0};

void	ft_display_pid(void)
{
	ft_putnbr_fd(getpid(), 1);
	ft_putchar_fd('\n', 1);
	return ;
}

void	ft_exit_SIGINT(char *s)
{
	if (s)
		free(s);
	exit(130);
}

void	ft_exit_SIGQUIT(char *s)
{
	if (s)
		free(s);
	exit(131);
}

void	ft_clean_exit(char *msg, char *s)
{
	if (s)
		free(s);
	ft_putstr_fd(msg, 2);
	exit(1);
}

char	*ft_handle_zero(char *ret, int *i, int *buffer_size)
{
	ret[(*i) / 8] = ret[(*i) / 8] << 1;
	(*i)++;
	if ((*i) % 8 == 0&& ((*i) / 8) == *buffer_size && ret[(*i) / 9] != 0)
	{
		*buffer_size = *buffer_size *2;
		ret = ft_realloc(ret, *buffer_size);
		if (!ret)
			ft_clean_exit("Error : Malloc failed", ret);
	}
	return (ret);
}

char	*ft_handle_one(char *ret, int *i, int *buffer_size)
{
	ret[(*i) / 8] = ret[(*i) / 8] << 1;
	ret[(*i) / 8] = ret[(*i) / 8] + 0b00000001;
	(*i)++;
	if ((*i) % 8 == 0 && ((*i) / 8) == *buffer_size && ret[((*i) - 1) / 8] != 0)
	{
		*buffer_size = *buffer_size * 2;
		ret = ft_realloc(ret, *buffer_size);
		if (!ret)
			ft_clean_exit("Error : Malloc failed", ret);
	}
	return (ret);
}

char	*ft_new_client(int *i, char *ret, int *pid, int *buffer_size)
{
	if (ret)
		free(ret);
	ft_bzero(ret = malloc(*buffer_size), *buffer_size);
	*i = 0;
	*pid = g_received[PID_CLIENT];
	*buffer_size = 2;
	return (ret);
}

void	ft_handle_signal(int signum, siginfo_t *info, void *context)
{
	static int	pid = 0;

	(void) context;
	if (pid != info->si_pid)
	{
		pid = info->si_pid;
		g_received[PID_CLIENT] = info->si_pid;
	}
	if (signum == SIGUSR1)
		g_received[MSG_CLIENT] = SIGUSR1;
	else if (signum == SIGUSR2)
		g_received[MSG_CLIENT] = SIGUSR2;
	else if (signum == SIGINT)
		g_received[MSG_CLIENT] = SIGINT;
	else if (signum == SIGQUIT)
		g_received[MSG_CLIENT] = SIGQUIT;
	return ;
}

int	main(void)
{
	struct sigaction	sa;
	int					i;
	char				*ret;
	int					pid;
	int					buffer_size;

	buffer_size = 2;
	ret = NULL;
	i = 0;
	pid = 0;
	ft_bzero((void*)&sa, sizeof(struct sigaction));
	sa.sa_flags = SA_SIGINFO;
	sa.sa_sigaction = ft_handle_signal;
	ft_display_pid();
	if (sigaction(SIGUSR1, &sa, NULL) == -1)
		ft_clean_exit("Error : sigaction failed", ret);
	if (sigaction(SIGUSR2, &sa, NULL) == -1)
		ft_clean_exit("Error : sigaction failed", ret);
	if (sigaction(SIGINT, &sa, NULL) == -1)
		ft_clean_exit("Error : sigaction failed", ret);
	if (sigaction(SIGQUIT, &sa, NULL) == -1)
		ft_clean_exit("Error : sigaction failed", ret);
	while (1)
	{
		pause();
		if (g_received[PID_CLIENT] != pid)
		{
			ret = ft_new_client(&i, ret, &pid, &buffer_size);
			if (!ret)
				ft_clean_exit("Error : Malloc failed", ret);
		}
		if (g_received[MSG_CLIENT] == SIGUSR1)
			ret = ft_handle_zero(ret, &i, &buffer_size);
		else if (g_received[MSG_CLIENT] == SIGUSR2)
			ret = ft_handle_one(ret, &i, &buffer_size);
		else if (g_received[MSG_CLIENT] == SIGINT)
			ft_exit_SIGINT(ret);
		else if (g_received[MSG_CLIENT] == SIGQUIT)
			ft_exit_SIGQUIT(ret);
		if (ret[(i - 1) / 8] == 0 && i % 8 == 0)
		{
			ft_putstr_fd(ret, 1);
			free(ret);
			ret = NULL;
			i = 0;
		}
		if (kill(pid, SIGUSR1) == -1)
			ft_clean_exit("weird", ret);
	}
}
