/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hali-mah <hali-mah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 01:59:08 by hali-mah          #+#    #+#             */
/*   Updated: 2024/11/26 02:05:31 by hali-mah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	rotate(t_stack *stack)
{
	t_node	*temp;
	t_node	*last;

	if (stack->size < 2)
		return ;
	temp = stack->top;
	stack->top = stack->top->next;
}

void	reverse_rotate(t_stack	*stack)
{
	t_node	*second_last;
	t_node	*last;

	if (stack->size < 2)
		return ;
	second_last = stack->top;
	while (second_last->next && second_last->next->next)
		second_last = second_last->next;
	last = second_last->next;
	second_last->next = NULL;
	last->next = stack->top;
	stack->top = last;
}
