/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tguillem <tguillem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/26 15:50:36 by tguillem          #+#    #+#             */
/*   Updated: 2016/03/15 17:32:23 by tguillem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

unsigned int		ft_printf_maxstrlen(uintmax_t nbr, char *base, char *p,
		t_pdata *data)
{
	unsigned int	len;
	unsigned int	result;

	len = ft_printf_nbrlen(nbr, base);
	if (!nbr && data->got_accuracy && !data->accuracy)
		result = 0;
	else if (data->got_accuracy)
		result = ft_max(len, data->accuracy);
	else
		result = len;
	if (data->prefix && p && nbr)
		result += ft_strlen(p);
	return (result);
}

void				ft_printf_width_pad(int nbrstrlen, int width,
		char padwith, int fd)
{
	while (nbrstrlen < width)
	{
		ft_putchar_fd(padwith, fd);
		nbrstrlen++;
	}
}

uintmax_t			ft_printf_get_unsigned_from_length(va_list *datas,
		t_pdata *data)
{
	uintmax_t	nbr;

	nbr = va_arg(*datas, uintmax_t);
	if (data->length == 6)
		nbr = (unsigned char)nbr;
	else if (data->length == 1)
		nbr = (unsigned short int)nbr;
	else if (data->length == 2)
		nbr = (unsigned long int)nbr;
	else if (data->length == 5)
		nbr = (unsigned long long int)nbr;
	else if (data->length == 3)
		nbr = (uintmax_t)nbr;
	else if (data->length == 4)
		nbr = (size_t)nbr;
	else
		nbr = (unsigned int)nbr;
	return (nbr);
}

intmax_t			ft_printf_get_signed_from_length(va_list *args,
		t_pdata *data)
{
	intmax_t	nbr;

	nbr = va_arg(*args, intmax_t);
	if (data->length == 6)
		nbr = (char)nbr;
	else if (data->length == 1)
		nbr = (short int)nbr;
	else if (data->length == 2)
		nbr = (long int)nbr;
	else if (data->length == 5)
		nbr = (long long int)nbr;
	else if (data->length == 3)
		nbr = (intmax_t)nbr;
	else if (data->length == 4)
		nbr = (size_t)nbr;
	else
		nbr = (int)nbr;
	return (nbr);
}

ssize_t				ft_printf_nbrforceprefix(uintmax_t nbr, char *base,
		t_pdata *data, char *prefix)
{
	unsigned	len;
	size_t		cut;

	len = ft_printf_maxstrlen(nbr, base, NULL, data) + ft_strlen(prefix);
	cut = ft_strlen(prefix);
	if (data->got_width && !data->right_pad && !data->zero_pad)
	{
		ft_printf_width_pad(len, data->width, ' ', data->fd);
		cut += ft_max(data->width - len, 0);
		data->got_width = 0;
	}
	else if (data->got_width)
		data->width -= ft_strlen(prefix);
	ft_putstr_fd(prefix, data->fd);
	return (ft_printfu(nbr, data, base, NULL) + cut);
}
