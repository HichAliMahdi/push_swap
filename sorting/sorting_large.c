/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_large.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hali-mah <hali-mah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 18:18:00 by hali-mah          #+#    #+#             */
/*   Updated: 2024/12/02 17:10:33 by hali-mah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	get_target_position_stack(t_stack *stack_a, t_stack *stack_b)
{
	t_stack	*current_b;
	int		target_pos;
	int		closest_bigger;
	t_stack	*current_a;

	current_b = stack_b;
	while (current_b)
	{
		target_pos = get_min_index(stack_a);
		closest_bigger = INT_MAX;
		current_a = stack_a;
		while (current_a)
		{
			if (current_a->value > current_b->value
				&& current_a->value < closest_bigger)
			{
				closest_bigger = current_a->value;
				target_pos = current_a->pos;
			}
			current_a = current_a->next;
		}
		current_b->target_pos = target_pos;
		current_b = current_b->next;
	}
}

static void	get_cost_stack(t_stack *stack_a, t_stack *stack_b)
{
	int		size_a;
	int		size_b;
	t_stack	*current;

	size_a = stack_size(stack_a);
	size_b = stack_size(stack_b);
	current = stack_b;
	while (current)
	{
		if (current->pos <= size_b / 2)
			current->cost_b = current->pos;
		else
			current->cost_b = -(size_b - current->pos);
		if (current->target_pos <= size_a / 2)
			current->cost_a = current->target_pos;
		else
			current->cost_a = -(size_a - current->target_pos);
		current = current->next;
	}
}

static void	get_cheapest_move(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*current;
	int		cheapest_cost;
	int		cost_a;
	int		cost_b;
	int		total_cost;

	current = *stack_b;
	cheapest_cost = INT_MAX;
	while (current)
	{
		total_cost = ft_abs(current->cost_a) + ft_abs(current->cost_b);
		if (total_cost < cheapest_cost)
		{
			cheapest_cost = total_cost;
			cost_a = current->cost_a;
			cost_b = current->cost_b;
		}
		current = current->next;
	}
	chose_and_do_rr_or_r(stack_a, stack_b, cost_a, cost_b);
	pa(stack_a, stack_b);
}

void	process_stack_b(t_stack **stack_a, t_stack **stack_b)
{
	while (*stack_b)
	{
		get_position_stack(*stack_a, *stack_b);
		get_target_position_stack(*stack_a, *stack_b);
		get_cost_stack(*stack_a, *stack_b);
		get_cheapest_move(stack_a, stack_b);
	}
}

void	sort_large(t_stack **stack_a, t_stack **stack_b)
{
	int	size;
	int	min_pos;
	int	size_a;

	size = stack_size(*stack_a);
	push_to_b_until_size(stack_a, stack_b, size);
	sort_three(stack_a);
	process_stack_b(stack_a, stack_b);
	get_position_stack(*stack_a, NULL);
	min_pos = get_min_index(*stack_a);
	size_a = stack_size(*stack_a);
	rotate_stack_to_min_pos(stack_a, min_pos, size_a);
}
