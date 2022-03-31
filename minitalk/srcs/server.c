/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdubois <pdubois@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 17:11:28 by pdubois           #+#    #+#             */
/*   Updated: 2022/03/31 19:19:57 by pdubois          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

void	ft_display_pid(void)
{
	ft_printf("%d", getpid());
}

void	ft_error(char *s)
{
	if (s)
		free(s);
	exit(-1);
}

char	*ft_handle_zero(char *ret, int *i)
{
	ret[*i / 8] = ret[*i / 8] << 1;
	*i++;
	if (*i % 8 == 0 && ret[*i / 9] != 0)
	{
		ret = ft_realloc(ret, ft_strlen(ret) + 2);
		if (!ret)
			ft_error(ret);
	}
}

char	*ft_handle_one(char *ret, int *i)
{

}

void	ft_handle_signal(int signum)
{
	static char	*ret = NULL;
	static int	i = 0;

	if (!ret)
		ft_bzero(ret = malloc(2), 2);
	if (!ret)
		ft_error(ret);
	if (signum == SIGUSR1)
		ret = ft_handle_zero(ret, &i); 
	if (signum == SIGUSR2)
		ret = ft_handle_one(ret, &i); 
	if (ret[i / 9] == 0 && i % 8 == 0)
	{
		write(1, ret, ft_strlen(ret));
		free(ret);
		ret = NULL;
		i = 0;
	}
}

int	main(void)
{
	ft_display_pid();
	if (signal(SIGUSR1, ft_handle_signal) == SIG_ERR)
		return (-1);
	if (signal(SIGUSR2, ft_handle_signal) == SIG_ERR)
		return (-1);
	pause();
}