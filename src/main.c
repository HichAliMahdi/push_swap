/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hali-mah <hali-mah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 19:22:38 by hali-mah          #+#    #+#             */
/*   Updated: 2024/11/26 01:53:21 by hali-mah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static void	fill_stack(t_stack *stack, int argc, char **argv)
{
	int	i;
	int	value;

	i = 1;
	while (i < argc)
	{
		value = atoi(argv[i]);
		push(stack, value);
		i++;
	}
}

static void	display_operations(t_stack *stack)
{
	ft_printf("Initial Stack:\n");
	print_stack(stack);
	ft_printf("\nAfter Swap:\n");
	swap(stack);
	print_stack(stack);
	ft_printf("\nPopped: %d\n", pop(stack));
	print_stack(stack);
}

int	main(int argc, char **argv)
{
	t_stack	*stack_a;

	if (argc < 2)
	{
		ft_printf("Usage: ./push_swap number1 number2 ...\n");
		return (1);
	}
	stack_a = init_stack();
	fill_stack(stack_a, argc, argv);
	display_operations(stack_a);
	free_stack(stack_a);
	return (0);
}
