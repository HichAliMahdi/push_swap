/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_logic.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hali-mah <hali-mah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 18:18:00 by hali-mah          #+#    #+#             */
/*   Updated: 2024/11/30 13:45:54 by hali-mah         ###   ########.fr       */
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

void	find_and_push_min(t_stack **stack_a, t_stack **stack_b)
{
	int		min;
	t_stack	*temp;
	int		pos;
	int		size;

	min = INT_MAX;
	temp = *stack_a;
	pos = 0;
	size = stack_size(*stack_a);
	while (temp)
	{
		if (temp->value < min)
			min = temp->value;
		temp = temp->next;
	}
	while ((*stack_a)->value != min)
	{
		if (pos < size / 2)
			ra(stack_a);
		else
			rra(stack_a);
	}
	pb(stack_a, stack_b);
}

void	sort_big(t_stack **stack_a, t_stack **stack_b)
{
	int	size;

	size = stack_size(*stack_a);
	while (size > 3)
	{
		find_and_push_min(stack_a, stack_b);
		size--;
	}
	sort_three(stack_a);
	while (*stack_b)
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
	else
		sort_big(stack_a, stack_b);
}
