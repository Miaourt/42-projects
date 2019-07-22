/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printfdi.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcourtil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/16 17:13:24 by tcourtil          #+#    #+#             */
/*   Updated: 2018/12/13 13:06:55 by tcourtil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	i_params(t_list *list, va_list *ap, t_flag *f)
{
	char	*arg;
	long	nb;
	int		s;

	nb = va_arg(*ap, int);
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

static int	l_params(t_list *list, va_list *ap, t_flag *f)
{
	char		*arg;
	long long	nb;
	int			s;

	nb = va_arg(*ap, long);
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

static int	ll_params(t_list *list, va_list *ap, t_flag *f)
{
	char		*arg;
	long long	nb;
	int			s;

	nb = va_arg(*ap, long long);
	s = 0;
	if (nb < 0)
		s = -1;
	if (nb >= 0 && f->sign)
		s = 1;
	arg = ft_itoa(nb >= 0 ? nb : -nb);
	if (nb < -9223372036854775807ll)
		formatnb(list, "9223372036854775808", f, -1);
	else if (f->haspres && f->pres == 0 && nb == 0)
		formatnb(list, "", f, 0);
	else
		formatnb(list, arg, f, s);
	free(arg);
	return (1);
}

int			di_params(const char *base, t_list *list, va_list *ap, t_flag *f)
{
	if (base[0] == 'i' || base[0] == 'd')
	{
		if (f->hh)
			return (i_params(list, ap, f));
		if (f->ll)
			return (ll_params(list, ap, f));
		if (f->h)
			return (i_params(list, ap, f));
		if (f->l)
			return (l_params(list, ap, f));
		return (i_params(list, ap, f));
	}
	return (-1);
}
