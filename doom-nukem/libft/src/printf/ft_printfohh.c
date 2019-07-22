/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printfohh.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcourtil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/16 17:13:24 by tcourtil          #+#    #+#             */
/*   Updated: 2018/12/04 17:17:45 by tcourtil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*octal(char nb)
{
	char	*res;
	char	n;
	int		i;

	i = 0;
	res = 0;
	res = ft_strnew(10);
	while (i < 2)
	{
		n = nb >> (1 - i) * 3;
		n = n & ((char)7);
		res[i + 1] = '0' + n;
		i++;
	}
	n = nb >> 6;
	n = n & ((char)3);
	res[0] = '0' + n;
	return (res);
}

static int	ohhs_params(t_list *list, va_list *ap, t_flag *f)
{
	char	l;
	char	*arg;
	int		i;

	i = 0;
	l = (char)va_arg(*ap, int);
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

int			ohh_params(const char *base, t_list *list, va_list *ap, t_flag *f)
{
	if (base[0] == 'o' && f->hh)
		return (ohhs_params(list, ap, f));
	return (-1);
}
