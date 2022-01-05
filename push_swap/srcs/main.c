/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdubois <pdubois@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/17 21:19:42 by pdubois           #+#    #+#             */
/*   Updated: 2022/01/05 19:49:18 by pdubois          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include "../libft/libft.h"
#include <stdio.h>

int	ft_error(void)
{
	ft_putstr_fd("Error\n", 2);
	return (-1);
}

void	ft_display(t_Stack *stack_a, t_Stack *stack_b)
{
	int	i;
	int	j;

	i = stack_a->top;
	j = stack_b->top;
	while (i >= 0)
	{
		printf("%d   ", stack_a->array[i]);
		if (j >= 0)
			printf("%d\n", stack_b->array[j]);
		else
			printf(" \n");
		j--;
		i--;
	}
	printf("_   _\na   b\n---------------------\n");
}

int	main(int argc, char **argv)
{
	t_Stack	*stack_a;
	t_Stack	*stack_b;

	stack_a = NULL;
	stack_b = NULL;
	if (argc < 2)
		return (0);
	if (!ft_check(argc, argv))
	 	return (ft_error());
	if (!ft_init(&stack_a, &stack_b, argc, argv))
		return (ft_error());
	ft_sa(stack_a);
	ft_display(stack_a, stack_b);
	free(stack_a->array);
	free(stack_a);
	free(stack_b->array);
	free(stack_b);
	return (0);
}
