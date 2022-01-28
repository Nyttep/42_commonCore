/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdubois <pdubois@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/17 21:19:42 by pdubois           #+#    #+#             */
/*   Updated: 2022/01/28 02:28:49 by pdubois          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_error(void)
{
	ft_putstr_fd("Error\n", 2);
	return (-1);
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
	if (stack_a->capacity <= 3)
		ft_very_smol_algo(stack_a);
	else if (stack_a->capacity <= 5)
		ft_smol_algo(stack_a, stack_b);
	else
		ft_algo(stack_a, stack_b);
	free(stack_a->array);
	free(stack_a);
	free(stack_b->array);
	free(stack_b);
	return (0);
}
