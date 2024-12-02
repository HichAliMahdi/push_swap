/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utilities.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hali-mah <hali-mah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 18:18:00 by hali-mah          #+#    #+#             */
/*   Updated: 2024/12/02 16:52:36 by hali-mah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

// Get the size of the stack
int	stack_size(t_stack *stack)
{
	int		size;
	t_stack	*current;

	size = 0;
	current = stack;
	while (current)
	{
		size++;
		current = current->next;
	}
	return (size);
}

void	get_position_stack(t_stack *stack_a, t_stack *stack_b)
{
	t_stack	*current;
	int		position;

	position = 0;
	current = stack_a;
	while (current)
	{
		current->pos = position++;
		current = current->next;
	}
	if (stack_b)
	{
		current = stack_b;
		position = 0;
		while (current)
		{
			current->pos = position++;
			current = current->next;
		}
	}
}

int	is_stacks_sort(t_stack *stack_a, t_stack *stack_b)
{
	if (stack_b)
		return (0);
	while (stack_a && stack_a->next)
	{
		if (stack_a->value > stack_a->next->value)
			return (0);
		stack_a = stack_a->next;
	}
	return (1);
}
