/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hali-mah <hali-mah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/15 16:47:08 by hali-mah          #+#    #+#             */
/*   Updated: 2024/12/15 17:03:53 by hali-mah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

char	**split_args(char *str)
{
	char	**result;
	char	*tmp;
	int		i;

	tmp = str;
	while (*tmp)
	{
		if (*tmp != ' ' && (*tmp < '0' || *tmp > '9')
			&& *tmp != '-' && *tmp != '+')
			return (NULL);
		tmp++;
	}
	result = ft_split(str, ' ');
	if (!result)
		return (NULL);
	i = 0;
	while (result[i])
		i++;
	if (i == 0)
	{
		free(result);
		return (NULL);
	}
	return (result);
}

void	free_split(char **split)
{
	int	i;

	i = 0;
	while (split[i])
	{
		free(split[i]);
		i++;
	}
	free(split);
}

void	process_split_arg(char *arg, t_stack **stack_a)
{
	char	**split;
	int		j;
	int		value;

	split = split_args(arg);
	if (!split)
		handle_error(stack_a);
	j = 0;
	while (split[j])
	{
		value = ft_atoi(split[j], stack_a);
		add_to_stack(stack_a, value);
		j++;
	}
	free_split(split);
}
