/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdubois <pdubois@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 23:02:14 by pdubois           #+#    #+#             */
/*   Updated: 2022/01/06 00:35:41 by pdubois          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include "../libft/libft.h"

void	ft_algo(t_Stack *stack_a, t_Stack *stack_b)
{
	int	ind_err;
	int	i;

	ind_err = ft_is_sorted(stack_a);
	i = 0;
	if(ind_err)
	{
		if(ind_err >= (stack_a->top + 1) / 2)
			while(stack_a->top - i++ > ind_err)
				ft_ra(stack_a);
		else
			while(i++ < ind_err)
				ft_rra(stack_a);
		if (ft_is_sorted(stack_a))
		{
			ft_sa(stack_a);
			ft_algo(stack_a, stack_b);
		}
	}
}