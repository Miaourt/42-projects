/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcourtil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/16 17:52:43 by tcourtil          #+#    #+#             */
/*   Updated: 2018/11/29 13:00:50 by tcourtil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_convert(unsigned long n, char *base)
{
	unsigned long	bsize;
	unsigned long	nb;
	unsigned long	nbsize;
	char			*res;

	nbsize = 1;
	nb = n;
	bsize = ft_strlen(base);
	while (nb >= bsize)
	{
		nbsize++;
		nb /= bsize;
	}
	res = ft_strnew(nbsize);
	nbsize--;
	nb = n;
	while (nb >= bsize)
	{
		res[nbsize] = base[nb % bsize];
		nb /= bsize;
		nbsize--;
	}
	res[nbsize] = base[nb % bsize];
	return (res);
}
