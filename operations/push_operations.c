/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_operations.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hali-mah <hali-mah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 18:18:00 by hali-mah          #+#    #+#             */
/*   Updated: 2024/11/30 04:52:53 by hali-mah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

// Push the top element of stack b to stack a
void	pa(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*top;

	if (*stack_b)
	{
		top = *stack_b;
		*stack_b = (*stack_b)->next;
		push(stack_a, top);
		ft_printf("pa\n");
	}
}

void	pb(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*top;

	if (*stack_a)
	{
		top = *stack_a;
		*stack_a = (*stack_a)->next;
		push(stack_b, top);
		ft_printf("pb\n");
	}
}
