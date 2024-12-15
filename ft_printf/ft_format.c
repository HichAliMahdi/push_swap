/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hali-mah <hali-mah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 14:39:35 by hali-mah          #+#    #+#             */
/*   Updated: 2024/12/05 19:35:15 by hali-mah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	handle_numbers(const char format, va_list args, int fd)
{
	int	write_ret;

	write_ret = 0;
	if (format == 'd' || format == 'i')
		write_ret = ft_putnbr_fd(va_arg(args, int), fd);
	else if (format == 'u')
		write_ret = ft_unsnbr(va_arg(args, unsigned int), fd);
	else if (format == 'x')
		write_ret = ft_lhex(va_arg(args, unsigned int), fd);
	else if (format == 'X')
		write_ret = ft_uhex(va_arg(args, unsigned int), fd);
	if (write_ret == -1)
		return (-1);
	return (write_ret);
}

static int	handle_chars(const char format, va_list args, int fd)
{
	int	write_ret;

	write_ret = 0;
	if (format == 'c')
	{
		write_ret = ft_putchar_fd(va_arg(args, int), fd);
		if (write_ret == -1)
			return (-1);
		return (1);
	}
	else if (format == 's')
		write_ret = ft_putstr_fd(va_arg(args, char *), fd);
	else if (format == '%')
		write_ret = ft_putchar_fd('%', fd);
	if (write_ret == -1)
		return (-1);
	return (write_ret);
}

int	ft_format(const char format, va_list args, int fd)
{
	int	write_ret;

	write_ret = 0;
	if (format == 'p')
		write_ret = ft_putptr(va_arg(args, void *));
	else if (format == 'd' || format == 'i' || format == 'u'
		|| format == 'x' || format == 'X')
		write_ret = handle_numbers(format, args, fd);
	else
		write_ret = handle_chars(format, args, fd);
	if (write_ret == -1)
		return (-1);
	return (write_ret);
}
