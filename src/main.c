/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hali-mah <hali-mah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 19:22:38 by hali-mah          #+#    #+#             */
/*   Updated: 2024/11/26 15:24:25 by hali-mah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	handle_errors(int argc, char **argv)
{
	if (argc < 2)
		exit(EXIT_SUCCESS);
	if (has_duplicates(argv, argc))
	{
		ft_printf("Error\n");
		exit(EXIT_FAILURE);
	}
}

void	init_and_sort(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	int		i;

	stack_a = init_stack();
	stack_b = init_stack();
	i = argc - 1;
	while (i > 0)
	{
		if (!is_valid_number(argv[i]))
			exit_error(stack_a, NULL);
		push(stack_a, atoi(argv[i]));
		i--;
	}
	if (!is_sorted(stack_a))
		sort_5(stack_a, stack_b);
	free_stack(stack_a);
	free_stack(stack_b);
}

int	main(int argc, char **argv)
{
	handle_errors(argc, argv);
	init_and_sort(argc, argv);
	return (0);
}
