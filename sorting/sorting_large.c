/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_large.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hali-mah <hali-mah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 18:18:00 by hali-mah          #+#    #+#             */
/*   Updated: 2024/12/01 23:59:03 by hali-mah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	push_chunk_hundred(t_stack **stack_a,
			t_stack **stack_b, int *sorted, int chunk)
{
	int	start;
	int	end;
	int	size;

	size = stack_size(*stack_a);
	start = sorted[(size / 5) * chunk];
	end = sorted[(size / 5) * (chunk + 1) - 1];
	while (*stack_a)
	{
		if ((*stack_a)->value >= start && (*stack_a)->value <= end)
			pb(stack_a, stack_b);
		else
			ra(stack_a);
		if (!has_value_in_range(*stack_a, start, end))
			break ;
	}
}

void	sort_hundred(t_stack **stack_a, t_stack **stack_b)
{
	int	*sorted;
	int	chunk;
	int	size;

	size = stack_size(*stack_a);
	sorted = create_sorted_array(*stack_a);
	if (!sorted)
		return ;
	chunk = 0;
	while (chunk < 5)
	{
		push_chunk_hundred(stack_a, stack_b, sorted, chunk);
		chunk++;
	}
	push_back_sorted(stack_a, stack_b);
	free(sorted);
}

void	push_chunk_five_hundred(t_stack **stack_a, t_stack **stack_b,
	int *sorted, int chunk)
{
	int	start;
	int	end;
	int	size;

	size = stack_size(*stack_a);
	start = sorted[(size / 11) * chunk];
	end = sorted[(size / 11) * (chunk + 1) - 1];
	while (*stack_a)
	{
		if ((*stack_a)->value >= start && (*stack_a)->value <= end)
			pb(stack_a, stack_b);
		else
			ra(stack_a);
		if (!has_value_in_range(*stack_a, start, end))
			break ;
	}
}

void	sort_five_hundred(t_stack **stack_a, t_stack **stack_b)
{
	int		*sorted;
	int		chunk;
	int		size;

	size = stack_size(*stack_a);
	sorted = create_sorted_array(*stack_a);
	if (!sorted)
		return ;
	chunk = 0;
	while (chunk < 11)
	{
		push_chunk_five_hundred(stack_a, stack_b, sorted, chunk);
		chunk++;
	}
	push_back_sorted(stack_a, stack_b);
	free(sorted);
}
