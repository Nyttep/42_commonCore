/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils4.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdubois <pdubois@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/19 05:50:50 by pdubois           #+#    #+#             */
/*   Updated: 2022/01/28 02:29:17 by pdubois          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_rra(t_Stack *stack_a)
{
	int	i;
	int	tmp;

	if (ft_is_empty(stack_a))
		return ;
	i = 0;
	tmp = stack_a->array[0];
	while (i < stack_a->top)
	{
		stack_a->array[i] = stack_a->array[i + 1];
		i++;
	}
	stack_a->array[stack_a->top] = tmp;
	write(1, "rra\n", 4);
}

void	ft_rrb(t_Stack *stack_b)
{
	int	i;
	int	tmp;

	if (ft_is_empty(stack_b))
		return ;
	i = 0;
	tmp = stack_b->array[0];
	while (i < stack_b->top)
	{
		stack_b->array[i] = stack_b->array[i + 1];
		i++;
	}
	stack_b->array[stack_b->top] = tmp;
	write(1, "rrb\n", 4);
}

void	ft_rrr(t_Stack *stack_a, t_Stack *stack_b)
{
	int	i;
	int	tmp;

	if (ft_is_empty(stack_a))
		return ;
	i = 0;
	tmp = stack_a->array[0];
	while (i < stack_a->top)
	{
		stack_a->array[i] = stack_a->array[i + 1];
		i++;
	}
	stack_a->array[stack_a->top] = tmp;
	if (ft_is_empty(stack_b))
		return ;
	i = 0;
	tmp = stack_b->array[0];
	while (i < stack_b->top)
	{
		stack_b->array[i] = stack_b->array[i + 1];
		i++;
	}
	stack_b->array[stack_b->top] = tmp;
	write(1, "rrr\n", 4);
}
