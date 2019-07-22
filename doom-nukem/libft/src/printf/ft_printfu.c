/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printfu.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcourtil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/16 17:13:24 by tcourtil          #+#    #+#             */
/*   Updated: 2018/12/13 13:11:22 by tcourtil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	i_params(t_list *list, va_list *ap, t_flag *f)
{
	char			*arg;
	unsigned int	nb;
	int				s;

	nb = va_arg(*ap, int);
	s = 0;
	f->space = 0;
	arg = ft_utoa(nb);
	formatnb(list, arg, f, s);
	free(arg);
	return (1);
}

static int	l_params(t_list *list, va_list *ap, t_flag *f)
{
	char			*arg;
	unsigned long	nb;
	int				s;

	nb = va_arg(*ap, long);
	s = 0;
	f->space = 0;
	arg = ft_utoa(nb);
	formatnb(list, arg, f, s);
	free(arg);
	return (1);
}

static int	ll_params(t_list *list, va_list *ap, t_flag *f)
{
	char				*arg;
	unsigned long long	nb;
	int					s;

	nb = va_arg(*ap, long long);
	s = 0;
	f->space = 0;
	arg = ft_utoa(nb);
	formatnb(list, arg, f, s);
	free(arg);
	return (1);
}

int			u_params(const char *base, t_list *list, va_list *ap, t_flag *f)
{
	if (base[0] == 'u' || base[0] == 'U')
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
