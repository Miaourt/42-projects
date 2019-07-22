/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_number.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tguillem <tguillem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/26 15:49:23 by tguillem          #+#    #+#             */
/*   Updated: 2016/03/15 17:49:01 by tguillem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

ssize_t				ft_printf_manage_long_bis(char **format, va_list *args,
		t_pdata *data)
{
	uintmax_t				nbr;

	(void)format;
	if (data->got_accuracy)
		data->zero_pad = 0;
	nbr = ft_printf_get_unsigned_from_length(args, data);
	return (ft_printfu(nbr, data, "0123456789", NULL));
}

ssize_t				ft_printf_manage_long(char **format, va_list *args,
		t_pdata *data)
{
	data->length = 2;
	return (ft_printf_get_manager(ft_tolower(**format))(format, args, data));
}

ssize_t				ft_printf_manage_int(char **format, va_list *args,
		t_pdata *data)
{
	intmax_t				nbr;
	char					*prefix;

	(void)format;
	if (data->got_accuracy)
		data->zero_pad = 0;
	nbr = ft_printf_get_signed_from_length(args, data);
	if (nbr < 0 || data->force_sign || data->no_sign)
	{
		if (nbr < 0)
		{
			nbr = -nbr;
			prefix = "-";
		}
		else if (data->force_sign)
			prefix = "+";
		else if (data->no_sign)
			prefix = " ";
		else
			prefix = "";
		return (ft_printf_nbrforceprefix(nbr, "0123456789", data, prefix));
	}
	else
		return (ft_printfu(nbr, data, "0123456789", NULL));
}

ssize_t				ft_printf_manage_octal(char **format, va_list *args,
		t_pdata *data)
{
	uintmax_t	nbr;

	(void)format;
	nbr = ft_printf_get_unsigned_from_length(args, data);
	if (data->prefix && !nbr &&
			data->got_accuracy && !data->accuracy)
	{
		if (data->got_width && !data->right_pad)
			ft_printf_width_pad(1, data->width, data->zero_pad ? '0' : ' ',
					data->fd);
		ft_putstr_fd("0", data->fd);
		if (data->got_width && data->right_pad)
			ft_printf_width_pad(1, data->width, ' ', data->fd);
		return (data->got_width ? ft_max(data->width, 1) : 1);
	}
	else if (data->prefix && nbr)
	{
		data->got_accuracy = 1;
		data->accuracy = ft_max(data->accuracy,
				ft_printf_nbrlen(nbr, "01234567") + 1);
	}
	return (ft_printfu(nbr, data, "01234567", NULL));
}

ssize_t				ft_printf_manage_hexa(char **format, va_list *args,
		t_pdata *data)
{
	uintmax_t	nbr;
	char		*base;
	char		*prefix;

	nbr = ft_printf_get_unsigned_from_length(args, data);
	if (**format == 'X')
	{
		base = "0123456789ABCDEF";
		prefix = "0X";
	}
	else
	{
		base = "0123456789abcdef";
		prefix = "0x";
	}
	if (data->prefix && nbr)
		return (ft_printf_nbrforceprefix(nbr, base, data, prefix));
	return (ft_printfu(nbr, data, base, prefix));
}
