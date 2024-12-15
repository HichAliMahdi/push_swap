/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uhex.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hali-mah <hali-mah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 15:23:29 by hali-mah          #+#    #+#             */
/*   Updated: 2024/12/05 20:58:10 by hali-mah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	reverse_str(char *str, int len)
{
	int		i;
	char	temp;

	i = 0;
	while (i < len / 2)
	{
		temp = str[i];
		str[i] = str[len - 1 - i];
		str[len - 1 - i] = temp;
		i++;
	}
}

int	ft_uhex(unsigned int n, int fd)
{
	char	*hex;
	char	result[9];
	int		len;
	int		i;

	hex = "0123456789ABCDEF";
	if (n == 0)
		return (ft_putchar_fd('0', fd));
	len = 0;
	while (n > 0)
	{
		result[len] = hex[n % 16];
		n /= 16;
		len++;
	}
	result[len] = '\0';
	reverse_str(result, len);
	i = 0;
	while (i < len)
	{
		if (ft_putchar_fd(result[i], fd) == -1)
			return (-1);
		i++;
	}
	return (len);
}
