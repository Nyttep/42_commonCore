/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_utils2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdubois <pdubois@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 10:25:10 by pdubois           #+#    #+#             */
/*   Updated: 2022/01/28 02:28:38 by pdubois          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_compare_diff(t_Stack *stack_a, int *diff, int i)
{
	int	k;
	int	nearest;

	k = 0;
	nearest = 0;
	while (++k <= 4)
		if (diff[k] < 0)
			diff[k] *= -1;
	if (diff[1] <= diff[0])
		nearest = stack_a->top - i;
	else if (diff[2] <= diff[0])
		nearest = i;
	else if (diff[3] <= diff[0])
		nearest = stack_a->top - i;
	else if (diff[4] <= diff[0])
		nearest = i;
	k = 0;
	while (++k <= 4)
		if (diff[k] <= diff[0])
			diff[0] = diff[k];
	return (nearest);
}

int	ft_get_nearest(t_Stack *s_a, t_Stack *s_b, int *diff, int j)
{
	int	i;
	int	nearest;

	nearest = 0;
	i = (s_b->top / 15);
	if (i > s_a->top)
		i = s_a->top - 1;
	while (i >= 0)
	{
		diff[1] = s_b->array[s_b->top - j] - s_a->array[s_a->top - i];
		diff[2] = s_b->array[s_b->top - j] - s_a->array[i];
		diff[3] = s_b->array[j] - s_a->array[s_a->top - i];
		diff[4] = s_b->array[j] - s_a->array[i];
		if (ft_compare_diff(s_a, diff, i))
			nearest = ft_compare_diff(s_a, diff, i);
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
	j = stack_b->top / 250;
	if (j > stack_b->top)
		j = stack_b->top - 1;
	diff[0] = 2147483647;
	while (j >= 0)
	{
		if (ft_get_nearest(stack_a, stack_b, diff, j))
			nearest = ft_get_nearest(stack_a, stack_b, diff, j);
		j--;
	}
	return (nearest);
}
