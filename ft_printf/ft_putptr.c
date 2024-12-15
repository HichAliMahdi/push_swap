/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hali-mah <hali-mah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 18:20:40 by hali-mah          #+#    #+#             */
/*   Updated: 2024/12/05 19:43:32 by hali-mah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	count_digits(uintptr_t num, int base)
{
	int	len;

	len = 0;
	if (num == 0)
		return (1);
	while (num != 0)
	{
		len++;
		num /= base;
	}
	return (len);
}

static char	*convert_to_hex(uintptr_t num, char *str, int base, int len)
{
	const char	*digits = "0123456789abcdef";

	str[len] = '\0';
	while (len--)
	{
		str[len] = digits[num % base];
		num /= base;
	}
	return (str);
}

char	*ft_itoa_base(uintptr_t num, int base)
{
	char	*str;
	int		len;

	if (base < 2 || base > 16)
		return (NULL);
	len = count_digits(num, base);
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	return (convert_to_hex(num, str, base, len));
}

int	ft_putptr(void *ptr)
{
	char		*hex_str;
	uintptr_t	addr;
	int			write_ret;

	addr = (uintptr_t)ptr;
	hex_str = ft_itoa_base(addr, 16);
	if (!hex_str)
		return (-1);
	write_ret = ft_putstr_fd("0x", 1);
	if (write_ret == -1)
	{
		free(hex_str);
		return (-1);
	}
	write_ret = ft_putstr_fd(hex_str, 1);
	free(hex_str);
	if (write_ret == -1)
		return (-1);
	return (2 + write_ret);
}
