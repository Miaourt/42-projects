/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tguillem <tguillem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/04 13:03:43 by tguillem          #+#    #+#             */
/*   Updated: 2016/03/15 17:23:12 by tguillem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

int			ft_printf(const char *format, ...)
{
	va_list		args;
	int			result;

	va_start(args, format);
	result = ft_printf_fd_va(1, format, &args);
	va_end(args);
	return (result);
}

int			ft_printf_fd(int fd, const char *format, ...)
{
	va_list		args;
	int			result;

	va_start(args, format);
	result = ft_printf_fd_va(fd, format, &args);
	va_end(args);
	return (result);
}

int			ft_printf_fd_va(int fd, const char *format, va_list *args)
{
	int			result;

	result = internal_printf(format, args, 0, fd);
	return (result);
}

int			ft_error_msg(const char *format, ...)
{
	va_list		args;
	int			result;

	va_start(args, format);
	result = ft_printf_fd_va(2, format, &args);
	va_end(args);
	ft_exit(1);
	return (result);
}
