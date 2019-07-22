/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_wstr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tguillem <tguillem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/26 15:59:17 by tguillem          #+#    #+#             */
/*   Updated: 2016/03/15 17:51:07 by tguillem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void			ft_putnwstr(const wchar_t *str, size_t len, int fd)
{
	size_t	i;

	i = 0;
	while (*str && i < len)
	{
		if (*str <= 0x7F)
			i++;
		else if (*str <= 0x7FF)
			i += 2;
		else if (*str <= 0xFFFF)
			i += 3;
		else if (*str <= 0x10FFFF)
			i += 4;
		if (i <= len)
			ft_putwchar_fd(*str++, fd);
	}
}

static size_t	calc_wstrlen(wchar_t *str, int precision, size_t i)
{
	if (!*str || !precision)
		return (i);
	else if (*str <= 0x7F)
		return (calc_wstrlen(str + 1, precision - 1, i + 1));
	else if (*str <= 0x7FF && precision >= 2)
		return (calc_wstrlen(str + 1, precision - 2, i + 2));
	else if (*str <= 0xFFFF && precision >= 3)
		return (calc_wstrlen(str + 1, precision - 3, i + 3));
	else if (*str <= 0x10FFFF && precision >= 4)
		return (calc_wstrlen(str + 1, precision - 4, i + 4));
	else
		return (i);
}

ssize_t			ft_printf_manage_wstr(char **format, va_list *args,
		t_pdata *data)
{
	wchar_t	*str;
	size_t	strlen;

	(void)format;
	str = va_arg(*args, wchar_t*);
	if (!str)
		str = L"(null)";
	strlen = data->got_accuracy ? calc_wstrlen(str, data->accuracy, 0) :
			ft_wstrlen(str);
	if (data->got_width && !data->right_pad)
		ft_printf_width_pad(strlen, data->width, data->zero_pad ? '0' : ' ',
				data->fd);
	ft_putnwstr(str, strlen, data->fd);
	if (data->got_width && data->right_pad)
		ft_printf_width_pad(strlen, data->width, ' ', data->fd);
	return (data->got_width ? ft_max(strlen, data->width) : (ssize_t)strlen);
}
