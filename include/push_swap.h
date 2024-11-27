/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hali-mah <hali-mah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 18:18:00 by hali-mah          #+#    #+#             */
/*   Updated: 2024/11/27 01:16:56 by hali-mah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../ft_printf/ft_printf.h"
# include <stdio.h>
# include <stdlib.h>
# include <limits.h>
# include <string.h>

typedef struct s_node
{
	int				value;
	struct s_node	*next;
}	t_node;

typedef struct s_stack
{
	t_node	*top;
	int		size;
	int		min;
	int		max;
}	t_stack;

typedef struct s_partition
{
	int	pushed;
	int	rotated;
}	t_partition;

// Stack Operations
t_stack	*init_stack(void);
void	push(t_stack *stack, int value);
int		pop(t_stack *stack);
int		peek(t_stack *stack);
void	swap(t_stack *stack);
void	rotate(t_stack *stack, char *operation);
void	reverse_rotate(t_stack *stack, char *operation);
void	push_to(t_stack *from, t_stack *to, char *operation);
void	print_stack(t_stack *stack);
void	free_stack(t_stack *stack);

// Validation
int		is_valid_number(char *str);
int		has_duplicates(char **argv, int argc);
int		has_duplicates_in_split(char **numbers);

// Sorting Utilities
int		is_sorted(t_stack *stack);
void	quick_sort_stack(t_stack *a, t_stack *b, int len);
void	quick_sort_partition(t_stack *a, t_stack *b,
			int len, t_partition *partition);
void	sort_3(t_stack *stack);
void	sort_5(t_stack *stack_a, t_stack *stack_b);
int		find_smallest(t_stack *stack);
int		find_largest(t_stack *stack);
int		find_median(t_stack *stack, int len);
void	push_chunk(t_stack *a, t_stack *b, int min, int chunk_size);
void	push_back_sorted(t_stack *a, t_stack *b);
void	sort_large(t_stack *a, t_stack *b);
void	choose_sort_method(t_stack *a, t_stack *b);

// stack utils
void	update_min_max(t_stack *stack);
int		get_position(t_stack *stack, int value);
int		find_median(t_stack *stack, int len);

// Main Logic
void	handle_errors(int argc, char **argv);
void	init_and_sort(int argc, char **argv);
void	free_split(char **split);
void	exit_error(t_stack *stack, char **split);
void	update_min_max(t_stack *stack);
int		get_position(t_stack *stack, int value);
#endif
