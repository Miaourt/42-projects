/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getparams.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcourtil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/16 15:24:03 by tcourtil          #+#    #+#             */
/*   Updated: 2018/12/12 17:40:24 by tcourtil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	get_oparams(const char *base, t_list *list, va_list *ap, t_flag *f)
{
	int res;

	if ((res = oll_params(base, list, ap, f)) > 0)
		return (res);
	if ((res = ohh_params(base, list, ap, f)) > 0)
		return (res);
	if ((res = oh_params(base, list, ap, f)) > 0)
		return (res);
	if ((res = o_params(base, list, ap, f)) > 0)
		return (res);
	return (-1);
}

static int	get_xparams(const char *base, t_list *list, va_list *ap, t_flag *f)
{
	int res;

	if ((res = llx_params(base, list, ap, f)) > 0)
		return (res);
	if ((res = lx_params(base, list, ap, f)) > 0)
		return (res);
	if ((res = x_params(base, list, ap, f)) > 0)
		return (res);
	return (-1);
}

int			get_params(const char *base, t_list *list, va_list *ap, t_flag *f)
{
	int res;

	if ((res = csp_params(base, list, ap, f)) > 0)
		return (res);
	if ((res = get_xparams(base, list, ap, f)) > 0)
		return (res);
	if ((res = dih_params(base, list, ap, f)) > 0)
		return (res);
	if ((res = di_params(base, list, ap, f)) > 0)
		return (res);
	if ((res = u_params(base, list, ap, f)) > 0)
		return (res);
	if ((res = f_params(base, list, ap, f)) > 0)
		return (res);
	if ((res = get_oparams(base, list, ap, f)) > 0)
		return (res);
	if ((res = mod_params(base, list, f)) > 0)
		return (res);
	if ((res = color_params(base, list)) > 0)
		return (res);
	return (-1);
}

int			get_flag(const char *base, t_list *list, va_list *ap, t_flag *f)
{
	int flag;
	int res;

	f->haspres = 0;
	f->pres = 0;
	base = get_bflags(base, f);
	base = get_minchamp(base, f);
	base = get_pres(base, f, ap);
	base = get_lh(base, f);
	base = get_bflags(base, f);
	flag = f->flag;
	res = get_params(base, list, ap, f);
	if (res != -1)
		return (flag + res);
	return (-1);
}

int			getflags(const char *base, t_list *list, va_list *ap)
{
	t_flag	*f;
	int		res;

	res = 0;
	if (!(f = (t_flag *)malloc(sizeof(t_flag))))
		return (-1);
	f->flag = 1;
	f->space = 0;
	f->sign = 0;
	f->left = 0;
	f->zero = 0;
	f->hexa = 0;
	base++;
	res = get_flag(base, list, ap, f);
	free(f);
	f = NULL;
	return (res);
}
