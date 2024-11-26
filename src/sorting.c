/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hali-mah <hali-mah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 02:11:14 by hali-mah          #+#    #+#             */
/*   Updated: 2024/11/26 15:06:36 by hali-mah         ###   ########.fr       */
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
	int	pivot;
	int	pushed;
	int	rotated;

	if (len <= 3)
	{
		sort_3(a);
		return ;
	}
	pivot = find_median(a, len);
	pushed = 0;
	rotated = 0;
	quick_sort_partition(a, b, len, &pushed, &rotated);
	quick_sort_stack(a, b, len - pushed);
	quick_sort_stack(b, a, pushed);
	while (pushed--)
		push_to(b, a, "pa");
}
