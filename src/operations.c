/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hali-mah <hali-mah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 01:59:08 by hali-mah          #+#    #+#             */
/*   Updated: 2024/11/26 15:04:59 by hali-mah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	rotate(t_stack *stack, char *operation)
{
	t_node	*temp;
	t_node	*last;

	if (!stack || stack->size < 2)
		return ;
	temp = stack->top;
	stack->top = temp->next;
	temp->next = NULL;
	last = stack->top;
	while (last->next)
		last = last->next;
	last->next = temp;
	if (operation)
		ft_printf("%s\n", operation);
	update_min_max(stack);
}

void	reverse_rotate(t_stack	*stack, char *operation)
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
	if (operation)
		ft_printf("%s\n", operation);
	update_min_max(stack);
}

void	push_to(t_stack *from, t_stack *to, char *operation)
{
	int	value;

	if (from->size == 0)
		return ;
	value = pop(from);
	push(to, value);
	if (operation)
		ft_printf("%s\n", operation);
	update_min_max(from);
	update_min_max(to);
}
