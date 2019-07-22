/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printfhdi.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcourtil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/16 17:13:24 by tcourtil          #+#    #+#             */
/*   Updated: 2018/12/13 13:08:11 by tcourtil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	hh_params(t_list *list, va_list *ap, t_flag *f)
{
	char	*arg;
	short	nb;
	int		s;

	nb = (char)va_arg(*ap, int);
	s = 0;
	if (nb < 0)
		s = -1;
	if (nb >= 0 && f->sign)
		s = 1;
	arg = ft_itoa(nb >= 0 ? nb : -nb);
	if (f->haspres && f->pres == 0 && nb == 0)
		formatnb(list, "", f, 0);
	else
		formatnb(list, arg, f, s);
	free(arg);
	return (1);
}

static int	h_params(t_list *list, va_list *ap, t_flag *f)
{
	char		*arg;
	int			nb;
	int			s;

	nb = (short)va_arg(*ap, long);
	s = 0;
	if (nb < 0)
		s = -1;
	if (nb >= 0 && f->sign)
		s = 1;
	arg = ft_itoa(nb >= 0 ? nb : -nb);
	if (f->haspres && f->pres == 0 && nb == 0)
		formatnb(list, "", f, 0);
	else
		formatnb(list, arg, f, s);
	free(arg);
	return (1);
}

int			dih_params(const char *base, t_list *list, va_list *ap, t_flag *f)
{
	if (base[0] == 'i' || base[0] == 'd')
	{
		if (f->hh)
			return (hh_params(list, ap, f));
		if (f->h)
			return (h_params(list, ap, f));
	}
	return (-1);
}
