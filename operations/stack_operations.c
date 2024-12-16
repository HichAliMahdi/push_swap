/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_operations.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hali-mah <hali-mah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 18:18:00 by hali-mah          #+#    #+#             */
/*   Updated: 2024/12/16 11:35:55 by hali-mah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

t_stack	*create_node(int value)
{
	t_stack	*node;

	node = (t_stack *)malloc(sizeof(t_stack));
	if (!node)
	{
		perror("malloc");
		exit(1);
	}
	node->value = value;
	node->next = NULL;
	return (node);
}

// Push a node to the top of the stack
void	push(t_stack **stack, t_stack *node)
{
	node->next = *stack;
	*stack = node;
}

//void	print_stack(t_stack *stack)
//{
	//t_stack	*current;
//
//	current = stack;
//	while (current)
//	{
//		ft_printf("%d ", current->value);
//		current = current->next;
//	}
//	ft_printf("\n");
//}

// Check if the stack is sorted
int	is_sorted(t_stack *stack)
{
	t_stack	*current;

	current = stack;
	while (current && current->next)
	{
		if (current->value > current->next->value)
			return (0);
		current = current->next;
	}
	return (1);
}

// Free the stack
void	free_stack(t_stack *stack)
{
	t_stack	*current;
	t_stack	*next;

	current = stack;
	while (current)
	{
		next = current->next;
		free(current);
		current = next;
	}
}
