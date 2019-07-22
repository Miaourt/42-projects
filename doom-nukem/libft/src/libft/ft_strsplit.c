/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llaporte <llaporte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 13:18:39 by tcourtil          #+#    #+#             */
/*   Updated: 2019/02/05 13:46:58 by llaporte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static int	split_number(char const *s, char c)
{
	int		nb;
	char	last;
	int		i;

	i = 0;
	nb = 0;
	last = c;
	while (s[i] != '\0')
	{
		if (last != c && s[i] == c)
		{
			nb++;
		}
		last = s[i];
		i++;
	}
	if (last != c)
		nb++;
	return (nb);
}

static char	**split_new(int nb)
{
	char	**res;

	if ((res = (char**)malloc((nb + 1) * sizeof(*res))) == NULL)
		return (NULL);
	res[nb] = 0;
	return (res);
}

char		**ft_strsplit(char const *s, char c)
{
	unsigned int	i;
	int				i2;
	char			**res;
	unsigned int	start;
	char			last;

	if (!s)
		return (NULL);
	if ((res = split_new(split_number(s, c))) == NULL)
		return (NULL);
	i = 0;
	i2 = 0;
	last = c;
	while (s[i] != '\0')
	{
		if (last == c && s[i] != c)
			start = i;
		if (last != c && s[i] == c)
			res[i2++] = ft_strsub(s, start, i - start);
		last = s[i];
		i++;
	}
	if (last != c)
		res[i2] = ft_strsub(s, start, i - start);
	return (res);
}
