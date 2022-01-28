/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdubois <pdubois@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/17 21:19:41 by pdubois           #+#    #+#             */
/*   Updated: 2022/01/28 02:28:08 by pdubois          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include "../libft/libft.h"

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
int		ft_check(int argc, char **argv);
int		ft_is_sorted(t_Stack *stack);
void	ft_very_smol_algo(t_Stack *stack_a);
void	ft_smol_algo(t_Stack *stack_a, t_Stack *stack_b);
void	ft_algo(t_Stack *stack_a, t_Stack *stack_b);
int		ft_find_max(t_Stack *stack);
int		ft_find_min(t_Stack *stack);
int		ft_find_nearest(t_Stack *stack_a, t_Stack *stack_b);
int		ft_find_place_a(int target, t_Stack *stack_b);
int		ft_find_place_b(int target, t_Stack *stack_b);
void	ft_move_stacks(t_Stack *stack_a, t_Stack *stack_b, int i_t, int i_p);
#endif
