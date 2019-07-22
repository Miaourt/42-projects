/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcourtil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 13:42:06 by tcourtil          #+#    #+#             */
/*   Updated: 2018/11/28 18:35:32 by tcourtil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	nb_size(unsigned long long n)
{
	if (n < 10)
		return (1);
	return (1 + nb_size(n / 10));
}

char		*ft_utoa(unsigned long long n)
{
	unsigned long long	num;
	char				*res;
	int					i;

	num = n;
	i = nb_size(num) - 1;
	if ((res = ft_strnew(i + 1)) == NULL)
		return (NULL);
	while (num >= 10)
	{
		res[i--] = (char)((num % 10) + '0');
		num /= 10;
	}
	res[i] = num + '0';
	return (res);
}
