/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilities.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hali-mah <hali-mah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 11:04:29 by hali-mah          #+#    #+#             */
/*   Updated: 2024/12/16 13:38:37 by hali-mah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

// Helper function to handle the main conversion and checks
static long	parse_number(const char *str, int *i, int *sign, t_stack **stack)
{
	long	result;

	result = 0;
	if (str[*i] == '-' || str[*i] == '+')
	{
		if (str[*i] == '-')
			*sign = -1;
		else
			*sign = 1;
		(*i)++;
	}
	if (!str[*i])
		handle_error(stack);
	while (str[*i])
	{
		if (str[*i] < '0' || str[*i] > '9')
			handle_error(stack);
		result = result * 10 + (str[*i] - '0');
		if (result * (*sign) > INT_MAX || result * (*sign) < INT_MIN)
			handle_error(stack);
		(*i)++;
	}
	return (result);
}

int	ft_atoi(const char *str, t_stack **stack)
{
	int		sign;
	long	result;
	int		i;

	sign = 1;
	i = 0;
	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n'
		|| str[i] == '\v' || str[i] == '\f' || str[i] == '\r')
		i++;
	result = parse_number(str, &i, &sign, stack);
	return ((int)(result * sign));
}

int	has_duplicate(t_stack *stack, int value)
{
	while (stack)
	{
		if (stack->value == value)
			return (1);
		stack = stack->next;
	}
	return (0);
}

int	ft_abs(int n)
{
	if (n < 0)
		return (-n);
	return (n);
}
