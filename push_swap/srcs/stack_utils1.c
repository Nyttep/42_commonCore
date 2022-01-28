/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdubois <pdubois@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/18 21:31:20 by pdubois           #+#    #+#             */
/*   Updated: 2022/01/28 02:29:04 by pdubois          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_Stack	*ft_create_stack(unsigned int capacity)
{
	t_Stack	*stack;

	stack = malloc(sizeof(t_Stack));
	if (!stack)
		return (NULL);
	stack->top = -1;
	stack->capacity = capacity;
	stack->array = malloc(sizeof(int) * capacity);
	if (!stack->array)
	{
		free (stack);
		return (NULL);
	}
	return (stack);
}

int	ft_is_empty(t_Stack *stack)
{
	return (stack->top == -1);
}

void	ft_add(t_Stack *stack, int item)
{
	stack->array[++stack->top] = item;
}

void	ft_remove(t_Stack *stack)
{
	if (ft_is_empty(stack))
		return ;
	stack->top--;
}

void	*ft_init(t_Stack **stack_a, t_Stack **stack_b, int argc, char **argv)
{
	char	**s;
	int		len;

	s = NULL;
	while (--argc > 0)
	{
		s = ft_strsjoin(s, ft_split(argv[argc], ' '));
		if (!s)
			return (NULL);
	}
	len = ft_strslen(s);
	*stack_a = ft_create_stack(len);
	if (!*stack_a)
		return (ft_free_strs(s));
	*stack_b = ft_create_stack(len);
	if (!*stack_b)
	{
		free((*stack_a)->array);
		free(*stack_a);
		return (ft_free_strs(s));
	}
	while (s[argc])
		ft_add(*stack_a, ft_atoi((const char *) s[len - argc++ - 1]));
	ft_free_strs(s);
	return ((void *)1);
}
