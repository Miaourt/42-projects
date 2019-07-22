/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printfoh.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcourtil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/16 17:13:24 by tcourtil          #+#    #+#             */
/*   Updated: 2018/12/04 17:17:36 by tcourtil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*octal(short nb)
{
	char	*res;
	short	n;
	int		i;

	i = 0;
	res = 0;
	res = ft_strnew(10);
	if (nb < 0)
		res[0] = '1';
	while (i < 5)
	{
		n = nb >> (4 - i) * 3;
		n = n & ((short)7);
		res[i + (nb < 0 ? 1 : 0)] = '0' + n;
		i++;
	}
	return (res);
}

static int	ohs_params(t_list *list, va_list *ap, t_flag *f)
{
	short	l;
	char	*arg;
	int		i;

	i = 0;
	l = (short)va_arg(*ap, int);
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

int			oh_params(const char *base, t_list *list, va_list *ap, t_flag *f)
{
	if (base[0] == 'o' && f->h)
		return (ohs_params(list, ap, f));
	return (-1);
}
