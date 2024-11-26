/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hali-mah <hali-mah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 15:28:31 by hali-mah          #+#    #+#             */
/*   Updated: 2024/11/26 15:34:25 by hali-mah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	update_min_max(t_stack *stack)
{
	t_node	*current;

	if (!stack || !stack->top)
		return ;
	stack->min = stack->top->value;
	stack->max = stack->top->value;
	current = stack->top;
	while (current)
	{
		if (current->value < stack->min)
			stack->min = current->value;
		if (current->value > stack->max)
			stack->max = current->value;
		current = current->next;
	}
}

int	get_position(t_stack *stack, int value)
{
	t_node	*current;
	int		pos;

	if (!stack || !stack->top)
		return (-1);
	current = stack->top;
	pos = 0;
	while (current)
	{
		if (current->value == value)
			return (pos);
		current = current->next;
		pos++;
	}
	return (-1);
}

static void	bubble_sort(int *arr, int len)
{
	int	x;
	int	y;
	int	temp;

	x = 0;
	while (x < len - 1)
	{
		y = 0;
		while (y < len - x - 1)
		{
			if (arr[y] > arr[y + 1])
			{
				temp = arr[y];
				arr[y] = arr[y + 1];
				arr[y + 1] = temp;
			}
			y++;
		}
		x++;
	}
}

static int	*stack_to_array(t_stack *stack, int len)
{
	t_node	*current;
	int		*arr;
	int		i;

	arr = malloc(sizeof(int) * len);
	if (!arr)
		exit_error(stack, NULL);
	current = stack->top;
	i = 0;
	while (i < len && current)
	{
		arr[i] = current->value;
		i++;
		current = current->next;
	}
	return (arr);
}

int	find_median(t_stack *stack, int len)
{
	int	*arr;
	int	median;

	arr = stack_to_array(stack, len);
	bubble_sort(arr, len);
	median = arr[len / 2];
	free(arr);
	return (median);
}
