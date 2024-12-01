/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_utils2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hali-mah <hali-mah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 00:01:08 by hali-mah          #+#    #+#             */
/*   Updated: 2024/12/02 00:01:18 by hali-mah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int    has_value_in_range(t_stack *stack, int min, int max)
{
	t_stack *current;

	current = stack;
	while (current)
	{
		if (current->value >= min && current->value <= max)
			return (1);
		current = current->next;
	}
	return (0);
}

int    *create_sorted_array(t_stack *stack)
{
	int     *arr;
	int     size;
	t_stack *current;
	int     i;

	size = stack_size(stack);
	arr = malloc(sizeof(int) * size);
	if (!arr)
		return (NULL);
	current = stack;
	i = 0;
	while (current)
	{
		arr[i] = current->value;
		i++;
		current = current->next;
	}
	sort_array(arr, size);
	return (arr);
}

void    sort_array(int *arr, int size)
{
	int i;
	int j;
	int temp;

	i = 0;
	while (i < size - 1)
	{
		j = 0;
		while (j < size - i - 1)
		{
			if (arr[j] > arr[j + 1])
			{
				temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
			j++;
		}
		i++;
	}
}

void    push_back_sorted(t_stack **stack_a, t_stack **stack_b)
{
	int max;
	int pos;
	int size;

	while (*stack_b)
	{
		max = find_max(*stack_b);
		pos = find_position(*stack_b, max);
		size = stack_size(*stack_b);
		while ((*stack_b)->value != max)
		{
			if (pos <= size / 2)
				rb(stack_b);
			else
				rrb(stack_b);
		}
		pa(stack_a, stack_b);
	}
}
