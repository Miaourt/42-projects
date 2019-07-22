/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplitcmp.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tguillem <tguillem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/23 16:23:56 by tguillem          #+#    #+#             */
/*   Updated: 2016/03/23 16:24:13 by tguillem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static size_t		count_words(const char *str, int (*f)(int c))
{
	size_t		result;
	int			is_word;

	result = 0;
	is_word = 0;
	while (*str)
	{
		if (is_word == 0 && !f(*str))
		{
			is_word = 1;
			result++;
		}
		else if (is_word == 1 && f(*str))
			is_word = 0;
		str++;
	}
	return (result);
}

static size_t		word_length(const char *str, int (*f)(int c))
{
	int		length;

	length = 0;
	while (!f(*str) && *str)
	{
		length++;
		str++;
	}
	return (length);
}

char				**ft_strsplitcmp(char const *s, int (*f)(int c))
{
	char	**result;
	size_t	word_count;
	size_t	i;

	if (s)
	{
		word_count = count_words(s, f);
		if ((result = (char **)ft_memalloc(sizeof(char*) * (word_count + 1))))
		{
			i = word_count;
			while (i--)
			{
				while (f(*s) && *s)
					s++;
				if (!(*(result++) = ft_strsub(s, 0, word_length(s, f))))
					return (NULL);
				s += word_length(s, f);
			}
			*result = NULL;
			return (result - word_count);
		}
	}
	return (NULL);
}
