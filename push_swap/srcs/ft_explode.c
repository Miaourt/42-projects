/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_explode.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llaporte <llaporte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/11 15:48:48 by llaporte          #+#    #+#             */
/*   Updated: 2018/01/11 11:54:16 by llaporte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	nb_of_word(char const *s)
{
	int		t_len;
	int		i;

	i = 0;
	t_len = 0;
	while (s[i])
	{
		while (ft_isspace(s[i]) && s[i])
			i++;
		if (!ft_isspace(s[i]) && s[i])
			t_len++;
		while (!ft_isspace(s[i]) && s[i])
			i++;
	}
	return (t_len);
}

static int	nb_of_char(char const *s)
{
	int		i;

	i = 0;
	while (!ft_isspace(s[i]) && s[i])
		i++;
	if (!i)
		i++;
	return (i);
}

char		**ft_explode(char const *s)
{
	char	**result;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!s)
		return (0);
	result = (char **)ft_memalloc(sizeof(char *) * (nb_of_word(s) + 1));
	if (!result)
		return (0);
	while (s[j])
	{
		if (ft_isspace(s[j]))
			j++;
		else
		{
			result[i] = ft_strsub(&(s[j]), 0, nb_of_char(&(s[j])));
			j = j + nb_of_char(&(s[j]));
			i++;
		}
	}
	result[i] = 0;
	return (result);
}
