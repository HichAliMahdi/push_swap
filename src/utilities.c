/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilities.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hali-mah <hali-mah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 02:14:48 by hali-mah          #+#    #+#             */
/*   Updated: 2024/11/26 15:23:47 by hali-mah         ###   ########.fr       */
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

void	sort_5(t_stack *stack_a, t_stack *stack_b)
{
	int	smallest_pos;

	while (stack_a->size > 3)
	{
		smallest_pos = get_position(stack_a, find_smallest(stack_a));
		while (stack_a->top->value != find_smallest(stack_a))
		{
			if (smallest_pos <= stack_a->size / 2)
				rotate(stack_a, "ra");
			else
				reverse_rotate(stack_a, "rra");
		}
		push_to(stack_a, stack_b, "pb");
	}
	sort_3(stack_a);
	while (stack_b->size > 0)
		push_to(stack_b, stack_a, "pa");
}
