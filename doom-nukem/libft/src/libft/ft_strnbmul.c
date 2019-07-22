/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnbmul.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcourtil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/10 13:20:34 by tcourtil          #+#    #+#             */
/*   Updated: 2018/12/13 14:42:58 by tcourtil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnbmul(char *nb1, char *nb2, size_t size, size_t vir)
{
	char	*res;
	int		i;
	char	a;
	char	*f;

	res = ft_memset(ft_strnew(size), '0', size);
	f = ft_memcpy(ft_memset(ft_strnew(size), '0', size), nb2, size);
	i = size - 1;
	while (ft_memset(f, '0', size) && i >= 0)
	{
		if ((a = '0') == '0' && i >= (int)vir)
			ft_memcpy(&f[(size - vir) - (size - (i + 1))], nb2,
				i - ((size - vir) - (size - (i))));
		else
			ft_memcpy(f, &nb2[size - (i + 1) - (size - vir)], i + 1);
		while (a++ < nb1[i])
			res = ft_strnbaddd(&res, &f, size, 1);
		i--;
	}
	free(f);
	return (res);
}
