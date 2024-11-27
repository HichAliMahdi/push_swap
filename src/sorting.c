/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hali-mah <hali-mah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 02:11:14 by hali-mah          #+#    #+#             */
/*   Updated: 2024/11/27 01:13:43 by hali-mah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	is_sorted(t_stack *stack)
{
	t_node	*current;

	if (!stack || stack->size < 2)
		return (1);
	current = stack->top;
	while (current->next)
	{
		if (current->value > current->next->value)
			return (0);
		current = current->next;
	}
	return (1);
}

void	sort_3(t_stack *stack)
{
	if (stack->size <= 1)
		return ;
	if (stack->size == 2)
	{
		if (stack->top->value > stack->top->next->value)
			swap(stack);
		return ;
	}
	if (stack->top->value > stack->top->next->value)
		swap(stack);
	if (!is_sorted(stack))
		rotate(stack, "ra");
	if (!is_sorted(stack))
		reverse_rotate(stack, "rra");
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
