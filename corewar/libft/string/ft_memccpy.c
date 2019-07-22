/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tguillem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 08:53:24 by tguillem          #+#    #+#             */
/*   Updated: 2015/11/24 13:16:56 by tguillem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *s1, const void *s2, int c, size_t n)
{
	size_t			i;
	unsigned char	*result;
	unsigned char	*source;
	unsigned char	limit;

	result = (unsigned char*)s1;
	source = (unsigned char*)s2;
	limit = (unsigned char)c;
	i = 0;
	while (i < n)
	{
		if ((*result++ = *source++) == limit)
			return (result);
		i++;
	}
	return (NULL);
}
