/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hali-mah <hali-mah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 18:18:00 by hali-mah          #+#    #+#             */
/*   Updated: 2024/11/30 13:51:03 by hali-mah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/push_swap.h"

void	parse_args(int argc, char **argv, t_stack **stack_a)
{
	t_stack	*prev;
	t_stack	*current;
	int		value;
	int		i;

	i = 1;
	prev = NULL;
	*stack_a = NULL;
	while (i < argc)
	{
		value = ft_atoi(argv[i]);
		current = create_node(value);
		if (!*stack_a)
			*stack_a = current;
		else
			prev->next = current;
		prev = current;
		i++;
	}
}

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	if (argc < 2)
	{
		write(2, "Error\n", 6);
		return (1);
	}
	stack_a = NULL;
	stack_b = NULL;
	parse_args(argc, argv, &stack_a);
	sort_stack(&stack_a, &stack_b);
	free_stack(stack_a);
	free_stack(stack_b);
	return (0);
}
