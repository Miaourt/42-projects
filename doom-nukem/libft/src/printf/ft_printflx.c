/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printflx.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llaporte <llaporte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/16 17:13:24 by tcourtil          #+#    #+#             */
/*   Updated: 2019/02/05 14:11:22 by llaporte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*hexa(unsigned long nb, int size, char *base)
{
	char			*res;
	unsigned long	n;
	int				i;

	i = 0;
	res = 0;
	res = ft_strnew(size);
	while (i < size)
	{
		n = nb >> (size - 1 - i) * 4;
		n = n & ((unsigned long)15);
		res[i] = base[n];
		i++;
	}
	return (res);
}

static char	*hex(unsigned long nb, int size, char *base)
{
	int		i;
	char	*res;
	char	*tmp;

	i = 0;
	tmp = NULL;
	res = hexa(nb, size, base);
	while (res[i] == '0')
		i++;
	if (res[i] == '\0')
	{
		ft_memset(res, '\0', size);
		res[0] = '0';
		return (res);
	}
	tmp = ft_strnew(size - i);
	ft_strcpy(tmp, &res[i]);
	ft_strdel(&res);
	return (tmp);
}

static int	ax_params(t_list *list, va_list *ap, t_flag *f, char *base)
{
	char			*conv;
	unsigned long	l;

	l = (unsigned long)va_arg(*ap, long);
	conv = hex(l, 16, base);
	if (l == 0 && f->haspres && f->pres == 0)
	{
		f->hexa = 0;
		formatp(list, "", f, &base[16]);
	}
	else
		formatp(list, conv, f, &base[16]);
	free(conv);
	return (1);
}

int			lx_params(const char *base, t_list *list, va_list *ap, t_flag *f)
{
	if (base[0] == 'x' && f->l)
		return (ax_params(list, ap, f, "0123456789abcdef0x"));
	if (base[0] == 'X' && f->l)
		return (ax_params(list, ap, f, "0123456789ABCDEF0X"));
	return (-1);
}
