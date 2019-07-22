/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printff.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcourtil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/16 17:13:24 by tcourtil          #+#    #+#             */
/*   Updated: 2018/12/13 14:40:25 by tcourtil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	fla_params(t_list *list, va_list *ap, t_flag *f)
{
	long double		l;
	char			*arg;
	int				i;
	float			a;

	i = 0;
	l = (long double)va_arg(*ap, long double);
	a = l < 0 ? -l : l;
	arg = ft_dtoa(a, f->haspres ? f->pres : 6);
	a = l < 0 ? -1 : 0;
	if (l >= 0 && f->sign)
		a = 1;
	if (f->pres)
		f->haspres = 0;
	f->pres = 0;
	formatnb(list, &arg[i], f, a);
	free(arg);
	return (1);
}

static int	fl_params(t_list *list, va_list *ap, t_flag *f)
{
	double		l;
	char		*arg;
	int			i;
	float		a;

	i = 0;
	l = (double)va_arg(*ap, double);
	a = l < 0 ? -l : l;
	arg = ft_dtoa(a, f->haspres ? f->pres : 6);
	a = l < 0 ? -1 : 0;
	if (l >= 0 && f->sign)
		a = 1;
	if (f->pres)
		f->haspres = 0;
	f->pres = 0;
	formatnb(list, &arg[i], f, a);
	free(arg);
	return (1);
}

static int	fa_params(t_list *list, va_list *ap, t_flag *f)
{
	float		l;
	char		*arg;
	int			i;
	float		a;

	i = 0;
	l = (float)va_arg(*ap, double);
	a = l < 0 ? -l : l;
	arg = ft_ftoa(a, f->haspres ? f->pres : 6);
	a = l < 0 ? -1 : 0;
	if (l >= 0 && f->sign)
		a = 1;
	if (f->pres)
		f->haspres = 0;
	f->pres = 0;
	formatnb(list, &arg[i], f, a);
	free(arg);
	return (1);
}

int			f_params(const char *base, t_list *list, va_list *ap, t_flag *f)
{
	if (base[0] == 'f' || base[0] == 'F')
	{
		if (f->l)
			return (fl_params(list, ap, f));
		if (f->la)
			return (fla_params(list, ap, f));
		return (fa_params(list, ap, f));
	}
	return (-1);
}
