/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hali-mah <hali-mah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 00:31:01 by hali-mah          #+#    #+#             */
/*   Updated: 2024/11/27 00:31:20 by hali-mah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	choose_sort_method(t_stack *a, t_stack *b)
{
	if (a->size <= 3)
		sort_3(a);
	else if (a->size <= 5)
		sort_5(a, b);
	else
		sort_large(a, b);
}
