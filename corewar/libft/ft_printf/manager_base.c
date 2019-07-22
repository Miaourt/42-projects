/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manager_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tguillem <tguillem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/26 16:00:07 by tguillem          #+#    #+#             */
/*   Updated: 2016/10/06 18:10:50 by tguillem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void		init_managers(t_manager *manager)
{
	manager['%'] = &ft_printf_manage_percent;
	manager['s'] = &ft_printf_manage_str;
	manager['S'] = &ft_printf_manage_wstr;
	manager['d'] = &ft_printf_manage_int;
	manager['D'] = &ft_printf_manage_long;
	manager['i'] = &ft_printf_manage_int;
	manager['o'] = &ft_printf_manage_octal;
	manager['O'] = &ft_printf_manage_long;
	manager['u'] = &ft_printf_manage_long_bis;
	manager['U'] = &ft_printf_manage_long;
	manager['x'] = &ft_printf_manage_hexa;
	manager['X'] = &ft_printf_manage_hexa;
	manager['p'] = &ft_printf_manage_ptr;
	manager['c'] = &ft_printf_manage_char;
	manager['C'] = &ft_printf_manage_wchar;
}

t_manager		*get_printf_managers(void)
{
	static t_manager	managers[256];

	return (managers);
}

t_manager		ft_printf_get_manager(char c)
{
	static t_manager	*managers;

	managers = get_printf_managers();
	if (!*managers)
		init_managers(managers);
	return (managers[(int)c]);
}
