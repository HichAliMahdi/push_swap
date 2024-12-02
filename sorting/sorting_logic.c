/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_logic.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hali-mah <hali-mah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 18:18:00 by hali-mah          #+#    #+#             */
/*   Updated: 2024/12/02 02:24:51 by hali-mah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	sort_three(t_stack **stack)
{
	int	first;
	int	second;
	int	third;

	if (!*stack || !(*stack)->next || !(*stack)->next->next)
		return ;
	first = (*stack)->value;
	second = (*stack)->next->value;
	third = (*stack)->next->next->value;
	if (first > second && second > third)
	{
		sa(stack);
		rra(stack);
	}
	else if (first > second && first > third)
		ra(stack);
	else if (first > second)
		sa(stack);
	else if (second > third)
	{
		rra(stack);
		if ((*stack)->value > (*stack)->next->value)
			sa(stack);
	}
}

void	sort_four(t_stack **stack_a, t_stack **stack_b)
{
	int	min;
	int	pos;

	min = find_min(*stack_a);
	pos = find_position(*stack_a, min);
	while (pos > 0)
	{
		if (pos <= 2)
			ra(stack_a);
		else
			rra(stack_a);
		pos = find_position(*stack_a, min);
	}
	pb(stack_a, stack_b);
	sort_three(stack_a);
	pa(stack_a, stack_b);
}

void	sort_five(t_stack **stack_a, t_stack **stack_b)
{
	int	min;
	int	pos;
	int	i;

	i = 0;
	while (i < 2)
	{
		min = find_min(*stack_a);
		pos = find_position(*stack_a, min);
		while (pos > 0)
		{
			if (pos <= 2)
				ra(stack_a);
			else
				rra(stack_a);
			pos = find_position(*stack_a, min);
		}
		pb(stack_a, stack_b);
		i++;
	}
	sort_three(stack_a);
	pa(stack_a, stack_b);
	pa(stack_a, stack_b);
}

void	sort_stack(t_stack **stack_a, t_stack **stack_b)
{
	int	size;

	if (!*stack_a || !(*stack_a)->next)
		return ;
	if (is_sorted(*stack_a))
		return ;
	size = stack_size(*stack_a);
	if (size == 2)
	{
		if ((*stack_a)->value > (*stack_a)->next->value)
			sa(stack_a);
	}
	else if (size == 3)
		sort_three(stack_a);
	else if (size == 4)
		sort_four(stack_a, stack_b);
	else if (size == 5)
		sort_five(stack_a, stack_b);
	else
		sort_large(stack_a, stack_b);
}
