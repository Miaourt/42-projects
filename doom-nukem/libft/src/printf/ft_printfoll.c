/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printfoll.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcourtil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/16 17:13:24 by tcourtil          #+#    #+#             */
/*   Updated: 2018/12/04 17:15:06 by tcourtil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*octal(long long nb)
{
	char		*res;
	long long	n;
	int			i;

	i = 0;
	res = 0;
	res = ft_strnew(23);
	if (nb < 0)
		res[0] = '1';
	while (i < 21)
	{
		n = nb >> (20 - i) * 3;
		n = n & 7ll;
		res[i + (nb < 0 ? 1 : 0)] = '0' + n;
		i++;
	}
	return (res);
}

static int	olls_params(t_list *list, va_list *ap, t_flag *f)
{
	long	l;
	char	*arg;
	int		i;

	i = 0;
	l = (long long)va_arg(*ap, long long);
	arg = octal(l);
	while (arg[i] == '0')
		i++;
	if (arg[i] == '\0')
		formato(list, "0", f);
	else
		formato(list, &arg[i], f);
	free(arg);
	return (1);
}

int			oll_params(const char *base, t_list *list, va_list *ap, t_flag *f)
{
	if (base[0] == 'o' && f->ll)
		return (olls_params(list, ap, f));
	return (-1);
}
