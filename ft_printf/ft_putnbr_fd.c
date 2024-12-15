/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hali-mah <hali-mah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 14:07:39 by hali-mah          #+#    #+#             */
/*   Updated: 2024/12/05 20:25:11 by hali-mah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	handle_minint(int fd)
{
	int	ret;

	ret = ft_putstr_fd("-2147483648", fd);
	if (ret == -1)
		return (-1);
	return (ret);
}

static int	handle_negative(int *n, int fd)
{
	int	ret;

	ret = ft_putchar_fd('-', fd);
	if (ret == -1)
		return (-1);
	*n = -*n;
	return (1);
}

int	ft_putnbr_fd(int n, int fd)
{
	int		len;
	int		ret;

	if (n == -2147483648)
		return (handle_minint(fd));
	len = 0;
	if (n < 0)
	{
		ret = handle_negative(&n, fd);
		if (ret == -1)
			return (-1);
		len = ret;
	}
	if (n > 9)
	{
		ret = ft_putnbr_fd(n / 10, fd);
		if (ret == -1)
			return (-1);
		len += ret;
	}
	ret = ft_putchar_fd((n % 10) + '0', fd);
	if (ret == -1)
		return (-1);
	return (len + 1);
}
