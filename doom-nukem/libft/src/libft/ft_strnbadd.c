/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnbadd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcourtil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/10 12:59:47 by tcourtil          #+#    #+#             */
/*   Updated: 2018/12/13 12:56:47 by tcourtil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnbadd(char *nb1, char *nb2, size_t size)
{
	int		i;
	char	*res;
	char	r;

	i = size - 1;
	r = 0;
	res = ft_strnew(size);
	ft_memset(res, '0', size);
	while (i >= 0)
	{
		res[i] = nb1[i] + (nb2[i] - '0') + r;
		r = 0;
		if (res[i] > '9')
		{
			res[i] -= 10;
			r = 1;
		}
		i--;
	}
	return (res);
}

char	*ft_strnbaddd(char **nb1, char **nb2, size_t size, size_t del)
{
	char	*res;

	res = ft_strnbadd(*nb1, *nb2, size);
	if (del == 1 || del == 3)
		ft_strdel(nb1);
	if (del == 2 || del == 3)
		ft_strdel(nb2);
	return (res);
}
