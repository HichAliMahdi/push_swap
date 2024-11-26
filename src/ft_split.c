/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hali-mah <hali-mah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 22:56:00 by hali-mah          #+#    #+#             */
/*   Updated: 2024/11/26 02:36:07 by hali-mah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static int	count_words(char const *s, char c)
{
	int	count;
	int	i;

	count = 0;
	i = 0;
	while (s[i])
	{
		while (s[i] && s[i] == c)
			i++;
		if (s[i] && s[i] != c)
		{
			count++;
			while (s[i] && s[i] != c)
				i++;
		}
	}
	return (count);
}

static char	*malloc_word(char const *s, char c)
{
	int		len;
	int		i;
	char	*word;

	len = 0;
	i = 0;
	while (s[len] && s[len] != c)
		len++;
	word = (char *)malloc(sizeof(char) * (len + 1));
	if (!word)
		return (NULL);
	while (i < len)
	{
		word[i] = s[i];
		i++;
	}
	word[i] = '\0';
	return (word);
}

static void	free_words(char **words, int j)
{
	while (j > 0)
		free(words[--j]);
	free(words);
}

char	**ft_split(char const *s, char c)
{
	char	**result;
	int		i;
	int		j;

	i = 0;
	j = 0;
	result = malloc(sizeof(char *) * (count_words(s, c) + 1));
	if (!s || !result)
		return (NULL);
	while (s[i])
	{
		while (s[i] && s[i] == c)
			i++;
		if (s[i] && s[i] != c)
		{
			result[j] = malloc_word(&s[i], c);
			if (!result[j])
				return (free_words(result, j), NULL);
			j++;
			while (s[i] && s[i] != c)
				i++;
		}
	}
	result[j] = NULL;
	return (result);
}
