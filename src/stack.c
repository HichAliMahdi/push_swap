/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hali-mah <hali-mah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 18:57:58 by hali-mah          #+#    #+#             */
/*   Updated: 2024/11/26 15:16:13 by hali-mah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

t_stack	*init_stack(void)
{
	t_stack	*stack;

	stack = (t_stack *)malloc(sizeof(t_stack));
	if (!stack)
	{
		ft_printf("Error: Failed to allocate memory for stack.\n");
		exit(EXIT_FAILURE);
	}
	stack->top = NULL;
	stack->size = 0;
	stack->min = INT_MAX;
	stack->max = INT_MIN;
	return (stack);
}

void	push(t_stack *stack, int value)
{
	t_node	*new_node;

	new_node = (t_node *)malloc(sizeof(t_node));
	if (!new_node)
		exit_error(stack, NULL);
	new_node->value = value;
	new_node->next = stack->top;
	stack->top = new_node;
	stack->size++;
	if (value < stack->min)
		stack->min = value;
	if (value > stack->max)
		stack->max = value;
}

int	pop(t_stack *stack)
{
	t_node	*temp;
	int		value;

	if (stack->size == 0)
		return (-1);
	temp = stack->top;
	value = temp->value;
	stack->top = stack->top->next;
	free(temp);
	stack->size--;
	update_min_max(stack);
	return (value);
}

void	swap(t_stack *stack)
{
	t_node	*first;
	t_node	*second;

	if (stack->size < 2)
		return ;
	first = stack->top;
	second = first->next;
	first->next = second->next;
	second->next = first;
	stack->top = second;
	ft_printf("sa\n");
}

void	print_stack(t_stack *stack)
{
	t_node	*current;

	current = stack->top;
	ft_printf("Stack (top to bottom):\n");
	while (current)
	{
		ft_printf("%d\n", current->value);
		current = current->next;
	}
	ft_printf("Size: %d\n", stack->size);
}
