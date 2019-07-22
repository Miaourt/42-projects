/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcourtil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 12:52:59 by tcourtil          #+#    #+#             */
/*   Updated: 2018/11/13 15:42:17 by tcourtil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*res;
	int		i1;
	int		i2;

	i1 = 0;
	i2 = 0;
	if (!s1 || !s2)
		return (NULL);
	res = ft_strnew(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (res == NULL)
		return (NULL);
	while (s1[i1] != '\0')
	{
		res[i1] = s1[i1];
		i1++;
	}
	while (s2[i2] != '\0')
	{
		res[i1 + i2] = s2[i2];
		i2++;
	}
	return (res);
}
