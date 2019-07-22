/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tguillem <tguillem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/26 15:56:54 by tguillem          #+#    #+#             */
/*   Updated: 2016/01/27 12:55:49 by tguillem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_printf_parse_flags(char **format, t_pdata *data)
{
	if (**format == '#' || **format == '0' || **format == '-' ||
			**format == '+' || **format == ' ')
	{
		if (**format == '#')
			data->prefix = 1;
		else if (**format == '0')
			data->zero_pad = 1;
		else if (**format == '-')
			data->right_pad = 1;
		else if (**format == '+')
			data->force_sign = 1;
		else if (**format == ' ')
			data->no_sign = 1;
		(*format)++;
		if (data->right_pad)
			data->zero_pad = 0;
		return (ft_printf_parse_flags(format, data));
	}
	return (*format);
}

char	*ft_printf_parse_accuracy(char **format, va_list *list, t_pdata *data)
{
	int acc;

	if (**format == '.')
	{
		(*format)++;
		if (**format == '*')
		{
			(*format)++;
			if ((acc = va_arg(*list, int)) >= 0)
			{
				data->got_accuracy = 1;
				data->accuracy = acc;
			}
			return (*format);
		}
		else
		{
			while (ft_isdigit(**format))
				data->accuracy = data->accuracy * 10 + (*(*format)++ - '0');
			data->got_accuracy = 1;
			return (*format);
		}
	}
	return (*format);
}

char	*ft_printf_parse_width(char **format, va_list *list, t_pdata *data)
{
	int		got;

	data->width = 0;
	while (**format == '*' || ft_isdigit(**format))
	{
		if (**format == '*')
		{
			(*format)++;
			got = va_arg(*list, int);
			if (got < 0)
				data->right_pad = 1;
			data->width = ABS(got);
			data->got_width = 1;
		}
		if (ft_isdigit(**format))
		{
			data->got_width = 1;
			data->width = 0;
			while (ft_isdigit(**format))
				data->width = data->width * 10 + (*(*format)++ - '0');
		}
	}
	return (*format);
}

char	*ft_printf_parse_length(char **format, t_pdata *data)
{
	if (**format == 'h' && *(*format + 1) == 'h')
	{
		data->length = 6;
		return (*format += 2);
	}
	else if (**format == 'l' && *(*format + 1) == 'l')
	{
		data->length = 5;
		return (*format += 2);
	}
	else if (**format == 'h' || **format == 'l' || **format == 'j' ||
			**format == 'z')
	{
		if (**format == 'h')
			data->length = 1;
		else if (**format == 'l')
			data->length = 2;
		else if (**format == 'j')
			data->length = 3;
		else if (**format == 'z')
			data->length = 4;
		return ((*format)++);
	}
	return (*format);
}
