/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdubois <pdubois@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 23:02:14 by pdubois           #+#    #+#             */
/*   Updated: 2022/02/01 13:47:33 by pdubois          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_very_smol_algo(t_Stack *stack_a)
{
	while (ft_is_sorted(stack_a))
	{
		if (stack_a->array[stack_a->top] > stack_a->array[stack_a->top - 1])
			ft_sa(stack_a);
		else
			ft_rra(stack_a);
	}
}

void	ft_smol_algo(t_Stack *stack_a, t_Stack *stack_b)
{
	int	place;

	if (!ft_is_sorted(stack_a))
		return ;
	while (stack_a->top != 2)
		ft_pb(stack_a, stack_b);
	ft_very_smol_algo(stack_a);
	while (!ft_is_empty(stack_b))
	{
		place = ft_find_place_a(stack_b->array[stack_b->top], stack_a);
		if (place)
			ft_move_stacks(stack_a, stack_b, place - 1, 0);
		ft_pa(stack_a, stack_b);
	}
	while (ft_is_sorted(stack_a))
		ft_move_stacks(stack_a, stack_b, ft_is_sorted(stack_a) - 1, 0);
}

void	ft_algo(t_Stack *stack_a, t_Stack *stack_b)
{
	int	place;
	int	nearest;

	if (!ft_is_sorted(stack_a))
		return ;
	ft_pb(stack_a, stack_b);
	ft_pb(stack_a, stack_b);
	if (stack_b->array[stack_b->top] < stack_b->array[0])
		ft_rb(stack_b);
	while (!ft_is_empty(stack_a))
	{
		nearest = ft_find_nearest(stack_a, stack_b);
		place = ft_find_place_b(stack_a->array[nearest], stack_b);
		ft_move_stacks(stack_a, stack_b, nearest, place);
		ft_pb(stack_a, stack_b);
	}
	while (!ft_is_empty(stack_b))
		ft_pa(stack_a, stack_b);
	while (ft_is_sorted(stack_a))
		ft_move_stacks(stack_a, stack_b, ft_is_sorted(stack_a) - 1, 0);
}

void	ft_move_b(t_Stack *stack_b, int place, int ind_place)
{
	while (stack_b->array[0] != place)
	{
		if (ind_place >= (stack_b->top + 1) / 2)
			ft_rb(stack_b);
		else
			ft_rrb(stack_b);
	}
}

void	ft_move_stacks(t_Stack *stack_a, t_Stack *stack_b, int i_t, int i_p)
{
	int	target;
	int	place;

	target = stack_a->array[i_t];
	place = stack_b->array[i_p];
	while (stack_a->array[stack_a->top] != target)
	{
		if (i_t >= (stack_a->top + 1) / 2)
		{
			if (i_p > (stack_b->top + 1) / 2 && stack_b->array[0] != place)
				ft_rr(stack_a, stack_b);
			else
				ft_ra(stack_a);
		}
		else
		{
			if (i_p < (stack_b->top + 1) / 2 && stack_b->array[0] != place)
				ft_rrr(stack_a, stack_b);
			else
				ft_rra(stack_a);
		}
	}
	ft_move_b(stack_b, place, i_p);
}
