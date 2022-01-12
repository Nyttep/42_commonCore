/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_utils1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdubois <pdubois@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 22:18:54 by pdubois           #+#    #+#             */
/*   Updated: 2022/01/06 00:35:43 by pdubois          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include "../libft/libft.h"

int	ft_is_sorted(t_Stack *stack)
{
	int	i;

	i = stack->top;
	while (i > 0)
	{
		if (stack->array[i] > stack->array[i - 1])
			return (i);
		i--;
	}
	return (0);
}

int	ft_find_max(t_Stack *stack)
{
	int	max;
	int	i;

	i = stack->top;
	max = -2147483648;
	while (i >= 0)
	{
		if (stack->array[i] >= max)
			max = stack->array[i];
		i--;
	}
	return (max);
}

int	ft_find_min(t_Stack *stack)
{
	int	min;
	int	i;

	i = stack->top;
	min = 2147483647;
	while (i >= 0)
	{
		if (stack->array[i] <= min)
			min = stack->array[i];
		i--;
	}
	return (min);
}

int	ft_find_place_a(int target, t_Stack *stack_a)
{
	int	i;

	i = stack_a->top;
	if (target > ft_find_max(stack_a))
		while (ft_find_max(stack_a) != stack_a->array[i])
			i--;
	else if (target < ft_find_min(stack_a))
		while (i && ft_find_min(stack_a) != stack_a->array[i - 1])
			i--;
	else
		while (!(target < stack_a->array[i - 1]
				&& target > stack_a->array[i]) && i)
			i--;
	return (i);
}

int	ft_find_place_b(int target, t_Stack *stack_b)
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
		while (!(target < stack_b->array[i]
				&& target > stack_b->array[i - 1]) && i)
			i--;
	return (i);
}
