/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hali-mah <hali-mah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 19:22:38 by hali-mah          #+#    #+#             */
/*   Updated: 2024/11/26 02:47:34 by hali-mah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	fill_stack(t_stack *stack, int argc, char **argv)
{
	int		i;
	int		j;
	char	**numbers;
	int		value;

	i = 1;
	while (i < argc)
	{
		numbers = ft_split(argv[i], ' ');
		if (!numbers)
			exit_error(stack, NULL);
		j = 0;
		while (numbers[j])
		{
			if (!is_valid_number(numbers[j]))
				exit_error(stack, numbers);
			value = atoi(numbers[j]);
			push(stack, value);
			j++;
		}
		free_split(numbers);
		i++;
	}
}

void	handle_errors(int argc, char **argv)
{
	int	i;

	i = 1;
	while (i < argc)
	{
		if (!is_valid_number(argv[i]))
		{
			ft_printf("Invalid number: %s\n", argv[i]);
			exit(1);
		}
		if (has_duplicates(argv, argc))
		{
			ft_printf("Duplicate found in input.\n");
			exit(1);
		}
		i++;
	}
}

void	init_and_sort(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	stack_a = init_stack();
	stack_b = init_stack();
	fill_stack(stack_a, argc, argv);
	ft_printf("Initial stack:\n");
	print_stack(stack_a);
	if (!is_sorted(stack_a))
	{
		ft_printf("Sorting the stack...\n");
		sort_small_stack(stack_a, stack_b);
	}
	ft_printf("Sorted stack:\n");
	print_stack(stack_a);
	free_stack(stack_a);
	free_stack(stack_b);
}

int	main(int argc, char **argv)
{
	if (argc < 2)
	{
		ft_printf("Usage: ./push_swap number1 number2 ...\n");
		return (1);
	}
	handle_errors(argc, argv);
	init_and_sort(argc, argv);
	return (0);
}
