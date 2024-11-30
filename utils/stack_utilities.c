/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utilities.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hali-mah <hali-mah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 18:18:00 by hali-mah          #+#    #+#             */
/*   Updated: 2024/11/30 14:38:23 by hali-mah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

// Get the size of the stack
int	stack_size(t_stack *stack)
{
	int		size;
	t_stack	*current;

	size = 0;
	current = stack;
	while (current)
	{
		size++;
		current = current->next;
	}
	return (size);
}

void	selection_sort(int *arr, int size)
{
	int	i;
	int	j;
	int	min_index;
	int	temp;

	i = 0;
	while (i < size - 1)
	{
		min_index = i;
		j = i + 1;
		while (j < size)
		{
			if (arr[j] < arr[min_index])
				min_index = j;
			j++;
		}
		if (min_index != i)
		{
			temp = arr[i];
			arr[i] = arr[min_index];
			arr[min_index] = temp;
		}
		i++;
	}
}

int	find_median(t_stack *stack, int k)
{
	int		size;
	int		*arr;
	int		i;
	int		median;
	t_stack	*current;

	i = 0;
	size = stack_size(stack);
	arr = (int *)malloc(size * sizeof(int));
	if (!arr)
		return (0);
	current = stack;
	while (current)
	{
		arr[i++] = current->value;
		current = current->next;
	}
	selection_sort(arr, size);
	median = arr[k];
	free(arr);
	return (median);
}

int	ft_atoi(const char *str)
{
	int		sign;
	long	result;

	sign = 1;
	result = 0;
	while (*str == ' ' || *str == '\t' || *str == '\n'
		|| *str == '\v' || *str == '\f' || *str == '\r')
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		result = result * 10 + (*str - '0');
		str++;
		if (result * sign > INT_MAX)
			return (INT_MAX);
		if (result * sign < INT_MIN)
			return (INT_MIN);
	}
	return ((int)(result * sign));
}

int	has_duplicate(t_stack *stack, int value)
{
	while (stack)
	{
		if (stack->value == value)
			return (1);
		stack = stack->next;
	}
	return (0);
}
