/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printfmod.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcourtil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/16 17:13:24 by tcourtil          #+#    #+#             */
/*   Updated: 2018/12/12 14:09:51 by tcourtil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	mod_param(t_list *list, t_flag *f)
{
	if (f->pres == 0)
		f->haspres = 0;
	format(list, "%", f, 1);
	return (1);
}

int			mod_params(const char *base, t_list *list, t_flag *f)
{
	if (base[0] == '%')
		return (mod_param(list, f));
	return (-1);
}
