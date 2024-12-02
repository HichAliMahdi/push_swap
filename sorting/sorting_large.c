/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_large.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hali-mah <hali-mah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 18:18:00 by hali-mah          #+#    #+#             */
/*   Updated: 2024/12/02 16:06:54 by hali-mah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static int	get_min_index(t_stack *stack)
{
	t_stack	*current;
	int		min_value;
	int		min_index;

	if (!stack)
		return (0);
	current = stack;
	min_value = current->value;
	min_index = current->pos;
	while (current)
	{
		if (current->value < min_value)
		{
			min_value = current->value;
			min_index = current->pos;
		}
		current = current->next;
	}
	return min_index;
}

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

void	sort_large(t_stack **stack_a, t_stack **stack_b)
{
	int	size;
	int	pushed;
	int	min_pos;
	int	size_a;

	size = stack_size(*stack_a);
	pushed = 0;
	while (size > 3 && pushed < size - 3)
	{
		pb(stack_a, stack_b);
		pushed++;
	}
	sort_three(stack_a);
	while (*stack_b)
	{
		get_position_stack(*stack_a, *stack_b);
		get_target_position_stack(*stack_a, *stack_b);
		get_cost_stack(*stack_a, *stack_b);
		get_cheapest_move(stack_a, stack_b);
	}
	get_position_stack(*stack_a, NULL);
	min_pos = get_min_index(*stack_a);
	size_a = stack_size(*stack_a);
	if (min_pos > size_a / 2)
		while (min_pos < size_a--)
			rra(stack_a);
	else
		while (min_pos-- > 0)
			ra(stack_a);
}
