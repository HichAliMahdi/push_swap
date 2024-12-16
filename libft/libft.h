/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hali-mah <hali-mah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 11:43:20 by hali-mah          #+#    #+#             */
/*   Updated: 2024/12/16 11:50:59 by hali-mah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

/* Libraries */

# include <string.h>
# include "../ft_printf/ft_printf.h"
# include <stdio.h>
# include <stddef.h>
# include <stdlib.h>
# include <ctype.h>
# include <unistd.h>

// Functions 

char	*ft_strchr(const char *s, int c);
char	*ft_strdup(const char *str);
size_t	ft_strlcpy(char *dst, const char *src, size_t destsize);
char	*ft_substr(char const *s, int start, size_t len);
char	**ft_split(char const *s, char c);

#endif