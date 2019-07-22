/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printfcolor.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcourtil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/16 17:13:24 by tcourtil          #+#    #+#             */
/*   Updated: 2018/12/12 15:20:42 by tcourtil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	mod_param(t_list *list, char *str, size_t size)
{
	ft_lstadde(&list, ft_lstnew(str, size));
	return (0);
}

int			color_params(const char *base, t_list *list)
{
	if (ft_strnequ(base, "{black}", 7))
		return (mod_param(list, "\x1b[30m", 5) + 7);
	if (ft_strnequ(base, "{green}", 7))
		return (mod_param(list, "\x1b[92m", 5) + 7);
	if (ft_strnequ(base, "{red}", 5))
		return (mod_param(list, "\x1b[91m", 5) + 5);
	if (ft_strnequ(base, "{yellow}", 8))
		return (mod_param(list, "\x1b[93m", 5) + 8);
	if (ft_strnequ(base, "{blue}", 6))
		return (mod_param(list, "\x1b[94m", 5) + 6);
	if (ft_strnequ(base, "{purple}", 8))
		return (mod_param(list, "\x1b[95m", 5) + 8);
	if (ft_strnequ(base, "{cyan}", 6))
		return (mod_param(list, "\x1b[96m", 5) + 6);
	if (ft_strnequ(base, "{white}", 7))
		return (mod_param(list, "\x1b[97m", 5) + 7);
	if (ft_strnequ(base, "{eoc}", 5))
		return (mod_param(list, "\x1b[0m", 4) + 5);
	return (-1);
}
