/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unsnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hali-mah <hali-mah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 14:15:38 by hali-mah          #+#    #+#             */
/*   Updated: 2024/12/05 20:10:03 by hali-mah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_unsnbr(unsigned int n, int fd)
{
	int	write_ret;
	int	len;

	len = 0;
	if (n >= 10)
	{
		write_ret = ft_unsnbr(n / 10, fd);
		if (write_ret == -1)
			return (-1);
		len += write_ret;
	}
	write_ret = ft_putchar_fd((n % 10) + '0', fd);
	if (write_ret == -1)
		return (-1);
	return (len + 1);
}
