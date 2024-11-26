/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilities.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hali-mah <hali-mah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 02:14:48 by hali-mah          #+#    #+#             */
/*   Updated: 2024/11/26 15:04:50 by hali-mah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	find_smallest(t_stack *stack)
{
	t_node	*current;
	int		smallest;

	if (!stack || stack->size == 0)
		return (0);
	current = stack->top;
	smallest = current->value;
	while (current)
	{
		if (current->value < smallest)
			smallest = current->value;
		current = current->next;
	}
	return (smallest);
}

void	sort_3(t_stack *stack)
{
	if (stack->top->value > stack->top->next->value)
		swap(stack);
	if (!is_sorted(stack))
		rotate(stack, "ra");
	if (!is_sorted(stack))
		reverse_rotate(stack, "rra");
}

void	exit_error(t_stack *stack, char **split)
{
	if (split)
		free_split(split);
	if (stack)
		free_stack(stack);
	ft_printf("Error\n");
	exit(1);
}

void	update_min(t_stack *stack, int value)
{
	if (value < stack->min)
		stack->min = value;
}

void	update_max(t_stack *stack, int value)
{
	if (value > stack->max)
		stack->max = value;
}
