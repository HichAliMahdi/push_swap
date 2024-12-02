/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_large_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hali-mah <hali-mah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 16:59:14 by hali-mah          #+#    #+#             */
/*   Updated: 2024/12/02 17:11:56 by hali-mah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	push_to_b_until_size(t_stack **stack_a, t_stack **stack_b, int size)
{
	int	pushed;

	pushed = 0;
	while (size > 3 && pushed < size - 3)
	{
		pb(stack_a, stack_b);
		pushed++;
	}
}

void	rotate_stack_to_min_pos(t_stack **stack_a, int min_pos, int size_a)
{
	if (min_pos > size_a / 2)
	{
		while (min_pos < size_a--)
			rra(stack_a);
	}
	else
	{
		while (min_pos-- > 0)
			ra(stack_a);
	}
}
