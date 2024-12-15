/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hali-mah <hali-mah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 13:55:35 by hali-mah          #+#    #+#             */
/*   Updated: 2024/12/05 19:24:13 by hali-mah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putstr_fd(char *s, int fd)
{
	int	len;
	int	write_ret;

	if (!s)
		s = "(null)";
	len = 0;
	while (s[len])
	{
		write_ret = write(fd, &s[len], 1);
		if (write_ret == -1)
			return (-1);
		len++;
	}
	return (len);
}
