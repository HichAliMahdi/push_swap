/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   r_rotate_operations.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hali-mah <hali-mah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 18:18:00 by hali-mah          #+#    #+#             */
/*   Updated: 2024/12/02 16:23:40 by hali-mah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

// Reverse rotate stack a
void	rra(t_stack **stack)
{
	t_stack	*last;
	t_stack	*prev;

	if (*stack)
	{
		last = *stack;
		prev = NULL;
		while (last->next)
		{
			prev = last;
			last = last->next;
		}
		if (prev)
		{
			prev->next = NULL;
			last->next = *stack;
			*stack = last;
		}
		ft_printf("rra\n");
	}
}

// Reverse rotate stack b
void	rrb(t_stack **stack)
{
	t_stack	*last;
	t_stack	*prev;

	if (*stack)
	{
		last = *stack;
		prev = NULL;
		while (last->next)
		{
			prev = last;
			last = last->next;
		}
		if (prev)
		{
			prev->next = NULL;
			last->next = *stack;
			*stack = last;
		}
		ft_printf("rrb\n");
	}
}

// Reverse rotate both stacks a and b
static void	reverse_rotate_without_print(t_stack **stack)
{
	t_stack	*last;
	t_stack	*prev;

	if (*stack)
	{
		last = *stack;
		prev = NULL;
		while (last->next)
		{
			prev = last;
			last = last->next;
		}
		if (prev)
		{
			prev->next = NULL;
			last->next = *stack;
			*stack = last;
		}
	}
}

void	rrr(t_stack **stack_a, t_stack **stack_b)
{
	if (*stack_a || *stack_b)
	{
		reverse_rotate_without_print(stack_a);
		reverse_rotate_without_print(stack_b);
		ft_printf("rrr\n");
	}
}
