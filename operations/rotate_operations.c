/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_operations.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hali-mah <hali-mah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 18:18:00 by hali-mah          #+#    #+#             */
/*   Updated: 2024/11/30 04:49:59 by hali-mah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

// Rotate stack a
void	ra(t_stack **stack)
{
	t_stack	*top;
	t_stack	*current;

	if (*stack)
	{
		top = *stack;
		current = *stack;
		while (current->next)
			current = current->next;
		current->next = top;
		*stack = top->next;
		top->next = NULL;
		ft_printf("ra\n");
	}
}

// Rotate stack b
void	rb(t_stack **stack)
{
	ra(stack);
	ft_printf("rb\n");
}

// Rotate both stacks a and b
void	rr(t_stack **stack_a, t_stack **stack_b)
{
	ra(stack_a);
	rb(stack_b);
	ft_printf("rr\n");
}
