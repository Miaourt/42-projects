/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcourtil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 11:24:16 by tcourtil          #+#    #+#             */
/*   Updated: 2018/11/28 14:07:55 by tcourtil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

void	*ft_memalloc(size_t size)
{
	char	*res;

	if (size > 2147483647)
		return (NULL);
	if ((res = (char *)malloc(size)) == NULL)
		return (NULL);
	ft_memset(res, 0, size);
	return ((void *)res);
}
