/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hali-mah <hali-mah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 02:11:14 by hali-mah          #+#    #+#             */
/*   Updated: 2024/11/26 15:26:49 by hali-mah         ###   ########.fr       */
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
	if (stack_a->size <= 3)
		sort_3(stack_a);
	else if (stack_a->size <= 5)
		sort_5(stack_a, stack_b);
	else
		quick_sort_stack(stack_a, stack_b, stack_a->size);
}

void	quick_sort_stack(t_stack *a, t_stack *b, int len)
{
	t_partition	partition;

	if (len <= 3)
	{
		sort_3(a);
		return ;
	}
	partition.pushed = 0;
	partition.rotated = 0;
	quick_sort_partition(a, b, len, &partition);
	quick_sort_stack(a, b, len - partition.pushed);
	quick_sort_stack(b, a, partition.pushed);
	while (partition.pushed--)
		push_to(b, a, "pa");
}

void	quick_sort_partition(t_stack *a, t_stack *b,
		int len, t_partition *partition)
{
	while (partition->pushed + partition->rotated < len)
	{
		if (a->top->value < find_median(a, len))
		{
			push_to(a, b, "pb");
			partition->pushed++;
		}
		else
		{
			rotate(a, "ra");
			partition->rotated++;
		}
	}
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
	while (!is_sorted(stack))
	{
		if (stack->top->value > stack->top->next->value)
			swap(stack);
		if (!is_sorted(stack))
			rotate(stack, "ra");
		if (!is_sorted(stack))
			reverse_rotate(stack, "rra");
	}
}
