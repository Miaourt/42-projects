/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getflag.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcourtil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/16 15:24:03 by tcourtil          #+#    #+#             */
/*   Updated: 2018/12/12 15:31:51 by tcourtil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*get_lh(const char *base, t_flag *f)
{
	f->l = base[0] == 'l';
	f->ll = f->l && base[1] == 'l';
	f->h = base[0] == 'h';
	f->la = base[0] == 'L';
	f->hh = f->h && base[1] == 'h';
	if (f->l || f->h || f->la)
		base++;
	if (f->ll || f->hh)
		base++;
	if (f->l || f->h)
		f->flag++;
	if (f->ll || f->hh)
		f->flag++;
	return ((char *)base);
}

char	*get_pres(const char *base, t_flag *f, va_list *ap)
{
	if (base[0] == '.')
	{
		base++;
		f->flag++;
		f->haspres = 1;
		if (base[0] == '*')
		{
			f->flag++;
			base++;
			f->pres = (int)va_arg(*ap, int);
			return (get_pres(base, f, ap));
		}
		f->pres = ft_atoi(base);
		while (base[0] >= '0' && base[0] <= '9')
		{
			base++;
			f->flag++;
		}
		return (get_pres(base, f, ap));
	}
	return ((char *)base);
}

char	*get_minchamp(const char *base, t_flag *f)
{
	f->min = ft_atoi(base);
	if (f->min != 0)
	{
		while (base[0] >= '0' && base[0] <= '9')
		{
			f->flag++;
			base++;
		}
	}
	return ((char *)base);
}

char	*get_b2flags(const char *base, t_flag *f)
{
	if (base[0] == '#')
	{
		base++;
		f->hexa = 1;
		f->flag++;
		return (get_bflags(base, f));
	}
	if (base[0] == '0')
	{
		base++;
		f->zero = 1;
		f->flag++;
		return (get_bflags(base, f));
	}
	return ((char *)base);
}

char	*get_bflags(const char *base, t_flag *f)
{
	if (base[0] == '-')
	{
		base++;
		f->left = 1;
		f->flag++;
		return (get_bflags(base, f));
	}
	if (base[0] == '+')
	{
		base++;
		f->sign = 1;
		f->flag++;
		return (get_bflags(base, f));
	}
	if (base[0] == ' ')
	{
		base++;
		f->space = 1;
		f->flag++;
		return (get_bflags(base, f));
	}
	return (get_b2flags(base, f));
}
