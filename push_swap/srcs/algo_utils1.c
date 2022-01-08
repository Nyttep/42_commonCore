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
	max = 0;
	while (i >= 0)
	{
		if (stack->array[i] > max || !max)
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
	min = 0;
	while (i >= 0)
	{
		if (stack->array[i] < min || !min)
			min = stack->array[i];
		i--;
	}
	return (min);
}

int	ft_find_nearest(t_Stack *stack_a, t_Stack *stack_b)
{
	int	i;
	int	nearest;
	int	diff[3];

	i = (stack_a->top / 50) - 1; // a ameliorer
	nearest = 0;
	while (i >= 0)
	{
		diff[1] = TOP_B - stack_a->array[stack_a->top - i]; //a ameliorer
		diff[2] = TOP_B - stack_a->array[i];  // a ameliorer
		if (diff[1] < 0)
			diff[1] *= -1;
		if (diff[2] < 0)
			diff[2] *= -1;
		if (diff[1] <= diff[0])
			nearest = stack_a->top - i;
		else if (diff[2] <= diff[0])
			nearest = i;
		if (diff[1] <= diff[0])
			diff[0] = diff[1];
		else if (diff[2] <= diff[0])
			diff[0] = diff[2];
		i--;
	}
	return (nearest);
}

void	ft_go_to(t_Stack *stack, int target) //combiner lui avec celui du main algo pour rr & rrr
{
	if (target > (stack->top + 1) / 2)
		while ((stack->top - target++))
			ft_ra(stack);
	else
		while (1 + target--)
			ft_rra(stack);
}