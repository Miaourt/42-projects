/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   internal_printf.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tguillem <tguillem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/26 15:58:03 by tguillem          #+#    #+#             */
/*   Updated: 2016/03/15 17:24:29 by tguillem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		manage_args(char **format, va_list *args, t_pdata *data)
{
	int			ret;
	t_manager	f;

	if (!(*(++*format)))
		return (0);
	if (!(ft_printf_parse_flags(format, data)) ||
			!(ft_printf_parse_width(format, args, data)) ||
			!(ft_printf_parse_accuracy(format, args, data)) ||
			!(ft_printf_parse_length(format, data)))
		return (-1);
	if (!**format)
		return (0);
	if (!(f = ft_printf_get_manager(**format)))
		f = &ft_printf_manage_null;
	ret = f(format, args, data);
	(*format)++;
	return (ret);
}

int		internal_printf(const char *format, va_list *args, int length, int fd)
{
	char	*next_arg;
	t_pdata	prop_data;
	int		len;

	len = 0;
	next_arg = ft_strchr(format, '%');
	if (!*format)
		return (length);
	if (!next_arg)
		return (length + write(fd, format, ft_strlen(format)));
	else if (next_arg > format)
		return (internal_printf(next_arg, args, length + write(fd, format,
						next_arg - format), fd));
	else
	{
		ft_bzero(&prop_data, sizeof(prop_data));
		prop_data.fd = fd;
		if ((len = manage_args((char**)&format, args, &prop_data)) == -1)
			return (-1);
		return (internal_printf(format, args, length + len, fd));
	}
}
