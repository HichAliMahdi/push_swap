/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hali-mah <hali-mah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 01:31:11 by hali-mah          #+#    #+#             */
/*   Updated: 2024/11/27 01:31:37 by hali-mah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	handle_two_numbers(t_stack *stack)
{
	if (stack->top->value > stack->top->next->value)
		swap(stack, "sa");
}

void	handle_three_case1(t_stack *stack, int first, int second, int third)
{
	if (first > second && second > third)
	{
		swap(stack, "sa");
		reverse_rotate(stack, "rra");
	}
	else if (first > second && second < third && first > third)
		rotate(stack, "ra");
}

void	handle_three_case2(t_stack *stack, int first, int second, int third)
{
	if (first > second && second < third && first < third)
		swap(stack, "sa");
	else if (first < second && second > third && first > third)
		reverse_rotate(stack, "rra");
	else if (first < second && second > third && first < third)
	{
		swap(stack, "sa");
		rotate(stack, "ra");
	}
}

void	sort_3(t_stack *stack)
{
	int	first;
	int	second;
	int	third;

	if (stack->size <= 1)
		return ;
	if (stack->size == 2)
	{
		handle_two_numbers(stack);
		return ;
	}
	first = stack->top->value;
	second = stack->top->next->value;
	third = stack->top->next->next->value;
	handle_three_case1(stack, first, second, third);
	handle_three_case2(stack, first, second, third);
}
