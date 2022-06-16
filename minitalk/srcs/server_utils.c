/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdubois <pdubois@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 19:12:45 by pdubois           #+#    #+#             */
/*   Updated: 2022/06/16 19:27:31 by pdubois          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

void	ft_display_pid(void)
{
	ft_putnbr_fd(getpid(), 1);
	ft_putchar_fd('\n', 1);
}

void	ft_exit_sigint(char *s)
{
	if (s)
		free(s);
	ft_putstr_fd("GOT CTRL-CED", 1);
	exit(130);
}

void	ft_exit_sigquit(char *s)
{
	if (s)
		free(s);
	ft_putstr_fd("GOT CTRL-\\ED", 1);
	exit(131);
}

void	ft_clean_exit(char *msg, char *s)
{
	if (s)
		free(s);
	ft_putstr_fd(msg, 2);
	exit(1);
}
