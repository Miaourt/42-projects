/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcourtil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 11:24:16 by tcourtil          #+#    #+#             */
/*   Updated: 2018/11/28 14:07:31 by tcourtil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strnew(size_t size)
{
	char	*res;

	res = (char *)malloc((size + 1) * sizeof(*res));
	if (res == NULL)
		return (NULL);
	ft_memset(res, '\0', size + 1);
	return ((void *)res);
}
