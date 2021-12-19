/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdubois <pdubois@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/17 21:19:41 by pdubois           #+#    #+#             */
/*   Updated: 2021/12/19 07:00:33 by pdubois          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

typedef struct s_Stack
{
	int		top;
	int		capacity;
	int		*array;
}	t_Stack;

t_Stack	*ft_create_stack(unsigned int capacity);
int		ft_is_empty(t_Stack *stack);
void	ft_add(t_Stack *stack, int item);
void	ft_remove(t_Stack *stack);
int		ft_error(void);
int		ft_strslen(char	**s);
void	*ft_free_strs(char	**s1);
void	*ft_init(t_Stack **stack_a, t_Stack **stack_b, int argc, char **argv);
char	**ft_strsjoin(char **s1, char **s2);
void	ft_sa(t_Stack	*stack_a);
void	ft_sb(t_Stack	*stack_b);
void	ft_ss(t_Stack *stack_a, t_Stack *stack_b);
void	ft_pa(t_Stack *stack_a, t_Stack *stack_b);
void	ft_pb(t_Stack *stack_a, t_Stack *stack_b);
void	ft_ra(t_Stack *stack_a);
void	ft_rb(t_Stack *stack_b);
void	ft_rr(t_Stack	*stack_a, t_Stack *stack_b);
void	ft_rra(t_Stack *stack_a);
void	ft_rrb(t_Stack *stack_b);
void	ft_rrr(t_Stack *stack_a, t_Stack *stack_b);
#endif