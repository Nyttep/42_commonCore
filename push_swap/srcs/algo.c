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

void	ft_very_smol_algo(t_Stack *stack_a)
{
	if (ft_is_sorted(stack_a))
	{
		if (stack_a->array[stack_a->top] > stack_a->array[stack_a->top - 1])
			ft_sa(stack_a);
		else
			ft_rra(stack_a);
		ft_very_smol_algo(stack_a);
	}
}

void	ft_smol_algo(t_Stack *stack_a, t_Stack *stack_b)
{
	if (stack_a->top == 4)
	{
		ft_pb(stack_a, stack_b);
		ft_pb(stack_a, stack_b);
	}
	else
		ft_pb(stack_a, stack_b);
	ft_very_smol_algo(stack_a);
	while (stack_b->array[stack_b->top] > stack_a->array[stack_a->top])
		ft_ra(stack_a);
	ft_pa(stack_a, stack_b);
	while (stack_b->array[stack_b->top] > stack_a->array[stack_a->top] && stack_b->top != -1)
		ft_ra(stack_a);
	ft_pa(stack_a, stack_b);
	while (ft_is_sorted(stack_a))
		ft_ra(stack_a);
}