/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   endian.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthuilli <dthuilli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/18 18:32:10 by tguillem          #+#    #+#             */
/*   Updated: 2018/03/17 17:47:10 by dthuilli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			is_le(void)
{
	unsigned int		x;

	x = 1;
	return ((int)(((char *)&x)[0]));
}

int			is_be(void)
{
	return (!is_le());
}

short		swap_short(short lt)
{
	return ((lt << 8) | ((lt >> 8) & 0xFF));
}

int			swap_int(int lt)
{
	lt = ((lt << 8) & 0xFF00FF00) | ((lt >> 8) & 0xFF00FF);
	return ((lt << 16) | ((lt >> 16) & 0xFFFF));
}

unsigned	swap_uint(unsigned int lt)
{
	lt = (((lt >> 24) & 0xff)
				| ((lt << 8) & 0xff0000)
				| ((lt >> 8) & 0xff00)
				| ((lt << 24) & 0xff000000));
	return (lt);
}
