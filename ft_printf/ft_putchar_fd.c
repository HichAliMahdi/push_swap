/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hali-mah <hali-mah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 13:37:22 by hali-mah          #+#    #+#             */
/*   Updated: 2024/12/05 20:12:42 by hali-mah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar_fd(char c, int fd)
{
	char		buffer[1];
	ssize_t		ret;

	buffer[0] = c;
	ret = write(fd, buffer, 1);
	if (ret == -1)
		return (-1);
	return (1);
}
