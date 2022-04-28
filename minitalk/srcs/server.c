/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdubois <pdubois@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 17:11:28 by pdubois           #+#    #+#             */
/*   Updated: 2022/04/28 18:57:03 by pdubois          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

void	ft_display_pid(void)
{
	ft_putnbr_fd(getpid(), 1);
}

void	ft_exit_SIGINT(char *s)
{
	if (s)
		free(s);
	exit(130);
}

void	ft_clean_exit(char *msg, char *s)
{
	if (s)
		free(s);
	ft_putstr_fd(msg, 2);
	exit(1);
}

char	*ft_handle_zero(char *ret, int *i, int pid)
{
	ret[(*i) / 8] = ret[(*i) / 8] << 1;
	(*i)++;
	if ((*i) % 8 == 0 && ret[(*i) / 9] != 0)
	{
		ret = ft_realloc(ret, ft_strlen(ret) + 2);
		if (!ret)
			ft_clean_exit("malloc failed", ret);
	}
	(void)pid;
	kill(pid, SIGUSR1);
	return (ret);
}

char	*ft_handle_one(char *ret, int *i, int pid)
{
	ret[(*i) / 8] = ret[(*i) / 8] << 1;
	ret[(*i) / 8] = ret[(*i) / 8] + 0b00000001;
	(*i)++;
	if ((*i) % 8 == 0 && ret[(*i) / 9] != 0)
	{
		ret = ft_realloc(ret, ft_strlen(ret) + 2);
		if (!ret)
			ft_clean_exit("malloc failed", ret);
	}
	(void)pid;
	kill(pid, SIGUSR1);
	return (ret);
}

char	*ft_new_client(int *i, char *ret, int *pid, siginfo_t *info)
{
	if (ret)
		free(ret);
	ft_bzero(ret = malloc(2), 2);
	*i = 0;
	*pid = info->si_pid;
	return (ret);
}

void	ft_handle_signal(int signum, siginfo_t *info, void *context)
{
	static char	*ret = NULL;
	static int	i = 0;
	static int	pid = 0;

	(void) context;
	if (pid != info->si_pid)
		ret = ft_new_client(&i, ret, &pid, info);
	if (!ret)
		ft_clean_exit("malloc failed", ret);
	if (signum == SIGUSR1)
		ret = ft_handle_zero(ret, &i, pid); 
	if (signum == SIGUSR2)
		ret = ft_handle_one(ret, &i, pid); 
	if (signum == SIGINT)
		ft_exit_SIGINT(ret); 
	if (ret[i / 9] == 0 && i % 8 == 0)
	{
		ft_putstr_fd(ret, 1);
		free(ret);
		ret = NULL;
		i = 0;
	}
}

int	main(void)
{
	struct sigaction	sa;

	ft_bzero((void*)&sa, sizeof(struct sigaction));
	sa.sa_flags = SA_SIGINFO;
	sa.sa_sigaction = ft_handle_signal;
	ft_display_pid();
	if (sigaction(SIGUSR1, &sa, NULL) == -1)
		return (-1);
	if (sigaction(SIGUSR2, &sa, NULL) == -1)
		return (-1);
	if (sigaction(SIGINT, &sa, NULL) == -1)
		return (-1);
	while (1)
		pause();
}