/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hali-mah <hali-mah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/15 16:51:22 by hali-mah          #+#    #+#             */
/*   Updated: 2024/12/15 17:00:27 by hali-mah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t destsize)
{
	size_t	i;
	size_t	src_length;

	src_length = ft_strlen(src);
	if (!src || !dst)
		return (0);
	if (destsize > 0)
	{
		i = 0;
		while (src[i] != '\0' && (i < destsize - 1))
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = '\0';
	}
	return (src_length);
}

char	*ft_substr(char const *s, int start, size_t len)
{
	char	*substring;
	size_t	size;

	if (!s)
		return (NULL);
	if (start >= ft_strlen(s))
		return (ft_strdup(""));
	size = ft_strlen(s + start);
	if (size < len)
		len = size;
	substring = (char *)malloc(sizeof(char) * (len + 1));
	if (!substring)
		return (NULL);
	ft_strlcpy(substring, s + start, len + 1);
	return (substring);
}

char	*ft_strdup(const char *str)
{
	char	*ptr;
	int		i;

	i = 0;
	while (str[i])
		i++;
	ptr = malloc(sizeof(char) * i + 1);
	if (ptr == NULL)
		return (NULL);
	i = 0;
	while (str[i])
	{
		ptr[i] = str[i];
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}

char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i] != (char)c && s[i] != '\0')
		i++;
	if (s[i] == (char)c)
		return ((char *)s + i);
	return (NULL);
}
