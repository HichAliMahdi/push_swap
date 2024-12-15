/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hali-mah <hali-mah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 13:33:38 by hali-mah          #+#    #+#             */
/*   Updated: 2024/12/05 19:28:41 by hali-mah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	process_format(const char *format, va_list list, int *i)
{
	int	write_ret;

	(*i)++;
	write_ret = ft_format(format[*i], list, 1);
	if (write_ret == -1)
		return (-1);
	return (write_ret);
}

static int	process_char(char c)
{
	int	write_ret;

	write_ret = ft_putchar_fd(c, 1);
	if (write_ret == -1)
		return (-1);
	return (write_ret);
}

int	ft_printf(const char *format, ...)
{
	va_list	list;
	int		i;
	int		result;
	int		write_ret;

	if (!format)
		return (-1);
	i = 0;
	result = 0;
	va_start(list, format);
	while (format[i])
	{
		if (format[i] == '%' && format[i + 1])
			write_ret = process_format(format, list, &i);
		else
			write_ret = process_char(format[i]);
		if (write_ret == -1)
			return (-1);
		result += write_ret;
		i++;
	}
	va_end(list);
	return (result);
}
