/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdubois <pdubois@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/19 04:17:48 by pdubois           #+#    #+#             */
/*   Updated: 2021/12/19 05:07:25 by pdubois          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include "../libft/libft.h"

void	ft_sa(t_Stack	*stack_a)
{
	int	tmp;

	if (ft_is_empty(stack_a) || stack_a->top == 0)
		return ;
	tmp = stack_a->array[stack_a->top];
	stack_a->array[stack_a->top] = stack_a->array[stack_a->top -1];
	stack_a->array[stack_a->top -1] = tmp;
}

void	ft_sb(t_Stack	*stack_b)
{
	int	tmp;

	if (ft_is_empty(stack_b) || stack_b->top == 0)
		return ;
	tmp = stack_b->array[stack_b->top];
	stack_b->array[stack_b->top] = stack_b->array[stack_b->top -1];
	stack_b->array[stack_b->top -1] = tmp;
}

void	ft_ss(t_Stack *stack_a, t_Stack *stack_b)
{
	ft_sa(stack_a);
	ft_sb(stack_b);
}

void	ft_pa(t_Stack *stack_a, t_Stack *stack_b)
{
	if (ft_is_empty(stack_b))
		return ;
	ft_add(stack_a, stack_b->array[stack_b->top--]);
}

void	ft_pb(t_Stack *stack_a, t_Stack *stack_b)
{
	if (ft_is_empty(stack_a))
		return ;
	ft_add(stack_b, stack_a->array[stack_a->top--]);
}