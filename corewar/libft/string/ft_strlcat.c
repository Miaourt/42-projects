/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tguillem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/23 12:46:54 by tguillem          #+#    #+#             */
/*   Updated: 2015/11/24 16:21:00 by tguillem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	char		*tmp1;
	const char	*tmp2;
	size_t		i;
	size_t		dlen;

	tmp1 = dst;
	tmp2 = src;
	i = size;
	while (i-- && *tmp1)
		tmp1++;
	dlen = tmp1 - dst;
	i = size - dlen;
	if (!i)
		return (dlen + ft_strlen(tmp2));
	while (*tmp2)
	{
		if (i != 1)
		{
			*tmp1++ = *tmp2;
			i--;
		}
		tmp2++;
	}
	*tmp1 = '\0';
	return (dlen + (tmp2 - src));
}
