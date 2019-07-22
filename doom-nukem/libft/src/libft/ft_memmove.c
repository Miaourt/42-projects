/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcourtil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 18:16:35 by tcourtil          #+#    #+#             */
/*   Updated: 2018/11/14 17:14:10 by tcourtil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char		*d;
	const char	*s;
	char		*t;
	size_t		i;

	if (!(t = (char *)malloc(n * sizeof(char *))))
		return (NULL);
	d = (char *)dest;
	s = (const char *)src;
	i = 0;
	while (i < n)
	{
		t[i] = s[i];
		i++;
	}
	i = 0;
	while (i < n)
	{
		d[i] = t[i];
		i++;
	}
	free(t);
	return (dest);
}
