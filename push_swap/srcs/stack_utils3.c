/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils3.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdubois <pdubois@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/19 05:11:04 by pdubois           #+#    #+#             */
/*   Updated: 2022/01/05 22:06:08 by pdubois          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include "../libft/libft.h"

void	ft_ra(t_Stack *stack_a)
{
	int	i;
	int	tmp;

	if (ft_is_empty(stack_a))
		return ;
	i = stack_a->top;
	tmp = stack_a->array[stack_a->top];
	while (i > 0)
	{
		stack_a->array[i] = stack_a->array[i - 1];
		i--;
	}
	stack_a->array[0] = tmp;
	write(1, "ra\n", 3);
}

void	ft_rb(t_Stack *stack_b)
{
	int	i;
	int	tmp;

	if (ft_is_empty(stack_b))
		return ;
	i = stack_b->top;
	tmp = stack_b->array[stack_b->top];
	while (i > 0)
	{
		stack_b->array[i] = stack_b->array[i - 1];
		i--;
	}
	stack_b->array[0] = tmp;
	write(1, "rb\n", 3);
}

void	ft_rr(t_Stack	*stack_a, t_Stack *stack_b)
{
	ft_ra(stack_a);
	ft_rb(stack_b);
	write(1, "rr\n", 3);
}
