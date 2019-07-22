/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tguillem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/23 12:49:17 by tguillem          #+#    #+#             */
/*   Updated: 2015/11/23 13:19:06 by tguillem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *s1, const char *s2)
{
	int	i;
	int	z;
	int	s2_size;

	i = 0;
	z = 0;
	s2_size = 0;
	while (s2[s2_size])
		s2_size++;
	if (!s2_size)
		return ((char *)s1);
	while (s1[i])
	{
		while (s2[z] == s1[i + z])
		{
			if (z == s2_size - 1)
				return ((char *)(s1 + i));
			z++;
		}
		z = 0;
		i++;
	}
	return (0);
}
