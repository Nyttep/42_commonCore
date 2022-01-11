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

int	ft_find_place(int target, t_Stack *stack_b)
{
	int	i;

	i = stack_b->top;
	if (target > ft_find_max(stack_b))
		while (i && ft_find_max(stack_b) != stack_b->array[i - 1])
			i--;
	else if (target < ft_find_min(stack_b))
		while (ft_find_min(stack_b) != stack_b->array[i])
			i--;
	else
		while (!(target < stack_b->array[i] && target > stack_b->array[i - 1]) && i)
			i--;
	return (i);
}

void	ft_algo(t_Stack *stack_a, t_Stack *stack_b)
{
	int	place;
	int	nearest;

	ft_pb(stack_a, stack_b);
	ft_pb(stack_a, stack_b);
	if (TOP_B < BOTTOM_B)
		ft_rb(stack_b);
	while (!ft_is_empty(stack_a))
	{
		nearest = ft_find_nearest(stack_a, stack_b);
		place = ft_find_place(stack_a->array[nearest], stack_b);
		ft_move_stacks(stack_a, stack_b, nearest, place);
		ft_pb(stack_a, stack_b);
	}
	while (!ft_is_empty(stack_b))
		ft_pa(stack_a, stack_b);
	while (ft_is_sorted(stack_a))
		ft_move_stacks(stack_a, stack_b, ft_is_sorted(stack_a) - 1, 0);
}

void	ft_move_stacks(t_Stack *stack_a, t_Stack *stack_b, int ind_target, int ind_place)
{
	int	target;
	int place;

	target = stack_a->array[ind_target];
	place = stack_b->array[ind_place];
	while(TOP_A != target)
	{
		if(ind_target > (stack_a->top + 1) / 2)
		{
			if (ind_place > (stack_b->top + 1) / 2 && BOTTOM_B != place)
				ft_rr(stack_a, stack_b);
			else
				ft_ra(stack_a);
		}
		else
		{
			if (ind_place <= (stack_b->top + 1) / 2 && BOTTOM_B != place)
				ft_rrr(stack_a, stack_b);
			else
				ft_rra(stack_a);
		}
	}
	while(BOTTOM_B != place)
	{
		if (ind_place > (stack_b->top + 1) / 2)
			ft_rb(stack_b);
		else
			ft_rrb(stack_b);
	}
}