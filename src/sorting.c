/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hali-mah <hali-mah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 02:11:14 by hali-mah          #+#    #+#             */
/*   Updated: 2024/11/26 02:49:36 by hali-mah         ###   ########.fr       */
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

void	sort_small_stack(t_stack *stack_a, t_stack *stack_b)
{
	while (stack_a->size > 3)
	{
		if (stack_a->top->value == find_smallest(stack_a))
			push_to(stack_a, stack_b, "pb");
		else
			rotate(stack_a, "ra");
	}
	sort_3(stack_a);
	while (stack_b->size > 0)
		push_to(stack_b, stack_a, "pa");
}
