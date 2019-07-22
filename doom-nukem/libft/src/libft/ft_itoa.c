/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcourtil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 13:42:06 by tcourtil          #+#    #+#             */
/*   Updated: 2018/12/13 13:04:50 by tcourtil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	nb_size(long long n)
{
	if (n < 10)
		return (1);
	return (1 + nb_size(n / 10));
}

char		*ft_itoa(long long n)
{
	int			neg;
	long long	num;
	char		*res;
	int			i;

	neg = 0;
	num = n;
	if (num < 0)
		neg = 1;
	if (neg == 1)
		num = -n;
	i = neg + nb_size(num) - 1;
	if ((res = ft_strnew(i + 1)) == NULL)
		return (NULL);
	while (num >= 10)
	{
		res[i--] = (char)((num % 10) + '0');
		num /= 10;
	}
	res[i] = num + '0';
	if (neg == 1)
		res[i - 1] = '-';
	return (res);
}
