/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hali-mah <hali-mah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 18:18:00 by hali-mah          #+#    #+#             */
/*   Updated: 2024/12/02 02:26:20 by hali-mah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/push_swap.h"

void	handle_error(t_stack **stack)
{
	write(2, "Error\n", 6);
	free_stack(*stack);
	exit(1);
}

void	add_to_stack(t_stack **stack, int value)
{
	t_stack	*current;
	t_stack	*prev;

	if (has_duplicate(*stack, value))
		handle_error(stack);
	current = create_node(value);
	if (!*stack)
		*stack = current;
	else
	{
		prev = *stack;
		while (prev->next)
			prev = prev->next;
		prev->next = current;
	}
}

void	parse_args(int argc, char **argv, t_stack **stack_a)
{
	int		i;
	int		value;

	i = 1;
	*stack_a = NULL;
	while (i < argc)
	{
		value = ft_atoi(argv[i], stack_a);
		add_to_stack(stack_a, value);
		i++;
	}
	(void)argc;
}

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	if (argc == 1)
		return (0);
	if (argc < 2)
	{
		write(2, "Error\n", 6);
		return (1);
	}
	stack_a = NULL;
	stack_b = NULL;
	parse_args(argc, argv, &stack_a);
	//ft_printf("\nNumbers to sort: ");
	//print_stack(stack_a);
	sort_stack(&stack_a, &stack_b);
	//ft_printf("\nSorted numbers: ");
	//print_stack(stack_a);
	free_stack(stack_a);
	free_stack(stack_b);
	return (0);
}
