/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hali-mah <hali-mah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 02:07:56 by hali-mah          #+#    #+#             */
/*   Updated: 2024/11/26 02:30:33 by hali-mah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	is_valid_number(char *str)
{
	long	num;
	char	*endptr;

	if (!str || *str == '\0')
		return (0);
	num = strtol(str, &endptr, 10);
	if (*endptr != '\0')
		return (0);
	if (num < INT_MIN || num > INT_MAX)
		return (0);
	return (1);
}

int	has_duplicates(char **argv, int argc)
{
	int	i;
	int	j;

	i = 1;
	while (i < argc)
	{
		j = i + 1;
		while (j < argc)
		{
			if (atoi(argv[i]) == atoi(argv[j]))
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}
