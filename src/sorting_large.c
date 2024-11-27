/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_large.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hali-mah <hali-mah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 00:27:13 by hali-mah          #+#    #+#             */
/*   Updated: 2024/11/27 00:28:46 by hali-mah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	push_chunk(t_stack *a, t_stack *b, int min, int chunk_size)
{
	int	pushed;
	int	i;

	pushed = 0;
	i = 0;
	while (i < chunk_size && a->size > 0)
	{
		if (a->top->value <= min + chunk_size)
		{
			push_to(a, b, "pb");
			pushed++;
		}
		else
			rotate(a, "ra");
		i++;
	}
}

void	push_back_sorted(t_stack *a, t_stack *b)
{
	while (b->size > 0)
	{
		while (b->top->value != b->max)
		{
			if (get_position(b, b->max) <= b->size / 2)
				rotate(b, "rb");
			else
				reverse_rotate(b, "rrb");
		}
		push_to(b, a, "pa");
	}
}

void	sort_large(t_stack *a, t_stack *b)
{
	int	chunk_size;
	int	min;

	chunk_size = 15;
	if (a->size > 100)
		chunk_size = 30;
	min = a->min;
	while (a->size > 0)
	{
		push_chunk(a, b, min, chunk_size);
		min += chunk_size;
	}
	push_back_sorted(a, b);
}
