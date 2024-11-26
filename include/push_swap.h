/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hali-mah <hali-mah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 18:18:00 by hali-mah          #+#    #+#             */
/*   Updated: 2024/11/26 02:51:19 by hali-mah         ###   ########.fr       */
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
}	t_stack;

// Stack Operations
t_stack	*init_stack(void);
void	push(t_stack *stack, int value);
int		pop(t_stack *stack);
void	swap(t_stack *stack);
void	rotate(t_stack *stack, char *operation);
void	reverse_rotate(t_stack *stack, char *operation);
void	push_to(t_stack *from, t_stack *to, char *operation);
void	print_stack(t_stack *stack);
void	free_stack(t_stack *stack);
void	free_split(char **split);
char	**ft_split(char const *s, char c);
void	exit_error(t_stack *stack, char **split);

// Validation
int		is_valid_number(char *str);
int		has_duplicates(char **argv, int argc);

// Sorting Utilities
int		is_sorted(t_stack *stack);
void	sort_small_stack(t_stack *stack_a, t_stack *stack_b);
void	sort_3(t_stack *stack);
int		find_smallest(t_stack *stack);

// Main Logic
void	handle_errors(int argc, char **argv);
void	init_and_sort(int argc, char **argv);
#endif
