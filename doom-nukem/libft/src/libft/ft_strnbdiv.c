/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnbdiv.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcourtil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/10 16:07:53 by tcourtil          #+#    #+#             */
/*   Updated: 2018/12/13 13:03:56 by tcourtil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	x10(char *nb, size_t size)
{
	int	i;

	i = 0;
	while (i < (int)size - 1)
	{
		nb[i] = nb[i + 1];
		i++;
	}
	nb[size - 1] = '0';
}

char		*ft_strnbdiv(char *nb1, char *nb2, size_t size, size_t vir)
{
	int		i;
	char	*res;
	char	*n;

	n = ft_memset(ft_strnew(size), '0', size);
	res = ft_memset(ft_strnew(size), '0', size);
	i = 0;
	while (i < (int)size)
	{
		x10(n, size);
		n[vir - 1] = nb1[i];
		while (ft_strcmp(n, nb2) >= 0)
		{
			n = ft_strnbremd(&n, &nb2, size, 1);
			res[i] += 1;
		}
		i++;
	}
	free(n);
	return (res);
}
