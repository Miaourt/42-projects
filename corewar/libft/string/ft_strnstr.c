/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tguillem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/23 12:49:17 by tguillem          #+#    #+#             */
/*   Updated: 2015/11/27 16:17:23 by tguillem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strnstr(const char *s1, const char *s2, size_t n)
{
	size_t	i;
	char	*tmp;

	i = 0;
	tmp = ft_strnew(n);
	tmp = ft_strncpy(tmp, s1, n);
	if (!ft_strlen(s2))
		return ((char*)s1);
	while (tmp[i])
	{
		if (!ft_strncmp(tmp + i, s2, ft_strlen(s2)))
			return ((char*)(s1 + i));
		i++;
	}
	return (NULL);
}
