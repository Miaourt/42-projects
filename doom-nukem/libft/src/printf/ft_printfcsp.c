/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printfcsp.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcourtil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/16 17:13:24 by tcourtil          #+#    #+#             */
/*   Updated: 2018/12/13 14:48:22 by tcourtil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	s_params(t_list *list, va_list *ap, t_flag *f)
{
	char	*arg;

	arg = va_arg(*ap, char *);
	if (arg == NULL)
		arg = "(null)";
	format(list, arg, f, ft_strlen(arg));
	return (1);
}

static int	c_params(t_list *list, va_list *ap, t_flag *f)
{
	char	*arg;
	char	tmp;

	tmp = va_arg(*ap, int);
	arg = ft_strnew(1);
	arg[0] = tmp;
	f->haspres = 0;
	f->pres = 0;
	format(list, arg, f, 1);
	ft_strdel(&arg);
	return (1);
}

static int	p_params(t_list *list, va_list *ap, t_flag *f)
{
	char			*conv;
	unsigned long	l;

	l = (unsigned long)va_arg(*ap, void *);
	conv = ft_convert(l, "0123456789abcdef");
	f->hexa = 1;
	formatp(list, conv, f, "0x");
	free(conv);
	return (1);
}

int			csp_params(const char *base, t_list *list, va_list *ap, t_flag *f)
{
	if (base[0] == 's')
		return (s_params(list, ap, f));
	if (base[0] == 'c')
		return (c_params(list, ap, f));
	if (base[0] == 'p')
		return (p_params(list, ap, f));
	return (-1);
}
