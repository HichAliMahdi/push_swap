/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hali-mah <hali-mah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 18:18:00 by hali-mah          #+#    #+#             */
/*   Updated: 2024/11/30 14:44:43 by hali-mah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../ft_printf/ft_printf.h"
# include <stdio.h>
# include <stdlib.h>
# include <limits.h>
# include <string.h>

typedef struct s_stack
{
	int				value;
	struct s_stack	*next;
}	t_stack;

// Sorting Operations
void	sa(t_stack **stack);
void	sb(t_stack **stack);
void	ss(t_stack **stack_a, t_stack **stack_b);
void	pa(t_stack **stack_a, t_stack **stack_b);
void	pb(t_stack **stack_a, t_stack **stack_b);
void	ra(t_stack **stack);
void	rb(t_stack **stack);
void	rr(t_stack **stack_a, t_stack **stack_b);
void	rra(t_stack **stack);
void	rrb(t_stack **stack);
void	rrr(t_stack **stack_a, t_stack **stack_b);

// Stack operations
t_stack	*create_node(int value);
void	push(t_stack **stack, t_stack *node);
void	print_stack(t_stack *stack);
int		is_sorted(t_stack *stack);
void	free_stack(t_stack *stack);

// Utils
int		stack_size(t_stack *stack);
void	selection_sort(int *arr, int size);
int		find_median(t_stack *stack, int k);
int		ft_atoi(const char *str);
int		has_duplicate(t_stack *stack, int value);

// Sorting
void	sort_three(t_stack **stack);
void	find_and_push_min(t_stack **stack_a, t_stack **stack_b);
void	sort_big(t_stack **stack_a, t_stack **stack_b);
void	sort_stack(t_stack **stack_a, t_stack **stack_b);

// Main logic
void	handle_error(t_stack **stack);
void	add_to_stack(t_stack **stack, int value);
void	parse_args(int argc, char **argv, t_stack **stack_a);
int		main(int argc, char **argv);
#endif