/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcourtil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 16:33:34 by tcourtil          #+#    #+#             */
/*   Updated: 2018/11/28 14:05:29 by tcourtil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "string.h"

void	*ft_memset(void *str, int c, size_t n)
{
	unsigned char	*data;
	size_t			i;

	data = (unsigned char *)str;
	if (n == 0)
		return (data);
	i = 0;
	while (i < n)
	{
		data[i] = c;
		i++;
	}
	return (str);
}
