/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hali-mah <hali-mah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 16:52:02 by hali-mah          #+#    #+#             */
/*   Updated: 2024/12/02 16:53:40 by hali-mah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	do_rr_operations(t_stack **stack_a, t_stack **stack_b,
			int *cost_a, int *cost_b)
{
	while (*cost_a > 0 && *cost_b > 0)
	{
		rr(stack_a, stack_b);
		(*cost_a)--;
		(*cost_b)--;
	}
	while (*cost_a < 0 && *cost_b < 0)
	{
		rrr(stack_a, stack_b);
		(*cost_a)++;
		(*cost_b)++;
	}
}

void	do_single_operations(t_stack **stack, int *cost, void (*op)(t_stack **),
			void (*reverse_op)(t_stack **))
{
	while (*cost > 0)
	{
		op(stack);
		(*cost)--;
	}
	while (*cost < 0)
	{
		reverse_op(stack);
		(*cost)++;
	}
}

void	chose_and_do_rr_or_r(t_stack **stack_a, t_stack **stack_b,
			int cost_a, int cost_b)
{
	do_rr_operations(stack_a, stack_b, &cost_a, &cost_b);
	do_single_operations(stack_a, &cost_a, ra, rra);
	do_single_operations(stack_b, &cost_b, rb, rrb);
}
