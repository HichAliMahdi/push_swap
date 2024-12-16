/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hali-mah <hali-mah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 18:18:00 by hali-mah          #+#    #+#             */
/*   Updated: 2024/12/16 11:57:49 by hali-mah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"
# include "../ft_printf/ft_printf.h"
# include <stdio.h>
# include <stdlib.h>
# include <limits.h>
# include <string.h>

typedef struct s_stack
{
	int				value;
	int				index;
	int				cost_a;
	int				cost_b;
	int				pos;
	int				target_pos;
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

// Utilities
int		has_duplicate(t_stack *stack, int value);
int		ft_atoi(const char *str, t_stack **stack);
int		ft_abs(int n);

// Rotation utilities
void	do_rr_operations(t_stack **stack_a, t_stack **stack_b,
			int *cost_a, int *cost_b);
void	do_single_operations(t_stack **stack, int *cost, void (*op)(t_stack **),
			void (*reverse_op)(t_stack **));
void	chose_and_do_rr_or_r(t_stack **stack_a,
			t_stack **stack_b, int cost_a, int cost_b);

// Sort large utils
void	push_to_b_until_size(t_stack **stack_a, t_stack **stack_b, int size);
void	rotate_stack_to_min_pos(t_stack **stack_a, int min_pos, int size_a);
void	process_stack_b(t_stack **stack_a, t_stack **stack_b);

// Stack Utils
int		stack_size(t_stack *stack);
void	get_position_stack(t_stack *stack_a, t_stack *stack_b);
void	get_target_position_stack(t_stack *stack_a, t_stack *stack_b);

// Sorting utils
int		find_position(t_stack *stack, int value);
int		find_min(t_stack *stack);
int		get_min_index(t_stack *stack);

// ARG utils
char	**split_args(char *str);
void	free_split(char **split);
void	process_split_arg(char *arg, t_stack **stack_a);

// Sorting
void	sort_three(t_stack **stack);
void	sort_four(t_stack **stack_a, t_stack **stack_b);
void	sort_five(t_stack **stack_a, t_stack **stack_b);
void	sort_stack(t_stack **stack_a, t_stack **stack_b);

// Sorting large
void	sort_large(t_stack **stack_a, t_stack **stack_b);

// Main logic
void	handle_error(t_stack **stack);
void	add_to_stack(t_stack **stack, int value);
void	parse_args(int argc, char **argv, t_stack **stack_a);
int		main(int argc, char **argv);
#endif