/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_errors2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdubois <pdubois@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 19:38:52 by pdubois           #+#    #+#             */
/*   Updated: 2022/06/16 19:39:08 by pdubois          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client.h"

void	ft_wrong_pid(void)
{
	ft_putstr_fd("Wrong PID or server has been shut down", 2);
	exit(1);
}
