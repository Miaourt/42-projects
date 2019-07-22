/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tguillem <tguillem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 09:59:45 by tguillem          #+#    #+#             */
/*   Updated: 2016/03/23 16:21:22 by tguillem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static size_t		count_words(const char *str, char separator)
{
	size_t		result;
	int			is_word;

	result = 0;
	is_word = 0;
	while (*str)
	{
		if (is_word == 0 && *str != separator)
		{
			is_word = 1;
			result++;
		}
		else if (is_word == 1 && *str == separator)
			is_word = 0;
		str++;
	}
	return (result);
}

static size_t		word_length(const char *str, char separator)
{
	int		length;

	length = 0;
	while (*str != separator && *str)
	{
		length++;
		str++;
	}
	return (length);
}

char				**ft_strsplit(char const *s, char c)
{
	char	**result;
	size_t	word_count;
	size_t	i;

	if (s)
	{
		word_count = count_words(s, c);
		if ((result = (char **)ft_memalloc(sizeof(char*) * (word_count + 1))))
		{
			i = word_count;
			while (i--)
			{
				while (*s == c && *s)
					s++;
				if (!(*(result++) = ft_strsub(s, 0, word_length(s, c))))
					return (NULL);
				s += word_length(s, c);
			}
			*result = NULL;
			return (result - word_count);
		}
	}
	return (NULL);
}
