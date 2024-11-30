/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_large.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hali-mah <hali-mah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 18:18:00 by hali-mah          #+#    #+#             */
/*   Updated: 2024/12/01 00:31:12 by hali-mah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	get_chunk_size(int size)
{
	if (size <= 100)
	{
		return (15);
	}
	else
	{
		return (30);
	}
}

void	push_chunks(t_stack **stack_a, t_stack **stack_b, int chunk_size)
{
	int	min;
	int	max;
	int	pushed;
	int	rotations;

	min = find_min(*stack_a);
	max = min + chunk_size;
	rotations = 0;
	pushed = 0;
	while (*stack_a && pushed < chunk_size)
	{
		if ((*stack_a)->value >= min && (*stack_a)->value <= max)
		{
			pb(stack_a, stack_b);
			pushed++;
			if ((*stack_b)->value < min + (chunk_size / 2))
				rb(stack_b);
		}
		else
		{
			ra(stack_a);
			rotations++;
			if (rotations >= stack_size(*stack_a))
				break ;
		}
	}
}

void	push_sorted(t_stack **stack_a, t_stack **stack_b)
{
	int	max_val;
	int	pos;
	int	size_b;

	while (*stack_b)
	{
		max_val = find_max(*stack_b);
		pos = find_position(*stack_b, max_val);
		size_b = stack_size(*stack_b);

		while ((*stack_b)->value != max_val)
		{
			if (pos <= size_b / 2)
			{
				rb(stack_b);
			}
			else
			{
				rrb(stack_b);
			}
		}
		pa(stack_a, stack_b);
	}
}

void	sort_large(t_stack **stack_a, t_stack **stack_b)
{
	int	size;
	int	chunk_size;

	size = stack_size(*stack_a);
	chunk_size = get_chunk_size(size);

	while (size > 3 && *stack_a)
	{
		push_chunks(stack_a, stack_b, chunk_size);
		size = stack_size(*stack_a);
	}
	sort_three(stack_a);
	push_sorted(stack_a, stack_b);
}
