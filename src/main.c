/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hali-mah <hali-mah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 19:22:38 by hali-mah          #+#    #+#             */
/*   Updated: 2024/11/25 19:27:38 by hali-mah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	int		i;
	int		value;

	if (argc < 2)
	{
		ft_printf("Usage: ./push_swap number1 number2 ...\n");
		return (1);
	}
	stack_a = init_stack();
	i = 1;
	while (i < argc)
	{
		value = atoi(argv[i]);
		push(stack_a, value);
		i++;
	}
	ft_printf("Initial Stack:\n");
	print_stack(stack_a);
	ft_printf("\nAfter Swap:\n");
	swap(stack_a);
	print_stack(stack_a);
	ft_printf("\nPopped: %d\n", pop(stack_a));
	print_stack(stack_a);
	free_stack(stack_a);
	return (0);
}
