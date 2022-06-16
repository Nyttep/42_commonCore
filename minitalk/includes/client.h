/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdubois <pdubois@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 17:10:30 by pdubois           #+#    #+#             */
/*   Updated: 2022/06/16 19:23:56 by pdubois          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLIENT_H
# define CLIENT_H

# include <signal.h>
# include <unistd.h>
# include "libft.h"

void	ft_check(int ac, char **av);

int		ft_error(char *msg);
void	ft_time_out(void);
void	ft_wrong_args(char **av);
void	ft_pid_lower_than_one(void);
void	ft_pid_bigger_than_maxint(void);
void	ft_wrong_pid(void);

#endif