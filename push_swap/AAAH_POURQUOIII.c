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

int	ft_compare_diff(t_Stack *stack_a, int *diff, int	*i)
{
	int	k;
	int nearest;

	k = 0;
	while (++k <= 4)
		if (diff[k] < 0)
			diff[k] *= -1;
	if (diff[1] <= diff[0])
		nearest = stack_a->top - *i;
	else if (diff[2] <= diff[0])
		nearest = *i;
	else if (diff[3] <= diff[0])
		nearest = stack_a->top - *i;
	else if (diff[4] <= diff[0])
		nearest = *i;
	k = 0;
	while (++k <= 4)
		if (diff[k] <= diff[0])
			diff[0] = diff[k];
	return (nearest);
}

int	ft_get_diff(t_Stack *stack_a, t_Stack *stack_b, int *diff, int j)
{
	int	i;
	int	nearest;

	nearest = 0;
	i = (stack_b->top / 15);
	if (i > stack_a->top)
		i = stack_a->top - 1;
	while (i >= 0)
	{
		diff[1] = stack_b->array[stack_b->top - j] - stack_a->array[stack_a->top - i];
		diff[2] = stack_b->array[stack_b->top - j] - stack_a->array[i];
		diff[3] = stack_b->array[j] - stack_a->array[stack_a->top - i];
		diff[4] = stack_b->array[j] - stack_a->array[i];
		nearest = ft_compare_diff(stack_a, diff, &i);
		i--;
	}
	return (nearest);
}

int	ft_find_nearest(t_Stack *stack_a, t_Stack *stack_b)
{
	int	j;
	int	nearest;
	int	diff[5];

	nearest = 0;
	j = (stack_b->top / 250);
	if (j > stack_b->top)
		j = stack_b->top - 1;
	diff[0] = 2147483647;
	while (j >= 0)
	{
		nearest = ft_get_diff(stack_a, stack_b, diff, j);
		j--;
	}
	return (nearest);
}

