/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hali-mah <hali-mah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 12:56:33 by hali-mah          #+#    #+#             */
/*   Updated: 2024/12/05 19:21:47 by hali-mah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdio.h>
# include <unistd.h>
# include <stdarg.h>
# include <stdlib.h>
# include <stdint.h>

int	ft_putchar_fd(char c, int fd);
int	ft_putstr_fd(char *s, int fd);
int	ft_putnbr_fd(int n, int fd);
int	ft_strlen(const char *str);
int	ft_unsnbr(unsigned int n, int fd);
int	ft_lhex(unsigned int n, int fd);
int	ft_uhex(unsigned int n, int fd);
int	ft_putptr(void *ptr);
int	ft_format(const char format, va_list args, int fd);
int	ft_printf(const char *format, ...);
#endif
