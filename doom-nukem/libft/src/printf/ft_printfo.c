/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printfo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcourtil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/16 17:13:24 by tcourtil          #+#    #+#             */
/*   Updated: 2018/12/13 13:05:24 by tcourtil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static long	octal(long nb)
{
	long long	res;
	long		n;
	int			i;

	i = 0;
	res = 0;
	if (nb < 0)
		res = 1;
	res = 0;
	while (i < 22)
	{
		res *= 10;
		n = nb >> (21 - i) * 3;
		n = n & 7l;
		res += n;
		i++;
	}
	return (res);
}

static int	os_params(t_list *list, va_list *ap, t_flag *f)
{
	long	l;
	char	*arg;

	l = (long)va_arg(*ap, long);
	arg = ft_itoa(octal(l));
	formato(list, arg, f);
	free(arg);
	return (1);
}

int			o_params(const char *base, t_list *list, va_list *ap, t_flag *f)
{
	if (base[0] == 'o')
		return (os_params(list, ap, f));
	return (-1);
}
