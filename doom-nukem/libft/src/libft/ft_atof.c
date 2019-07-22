/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atof.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcourtil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 18:26:55 by tcourtil          #+#    #+#             */
/*   Updated: 2018/12/13 14:49:00 by tcourtil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static long	get_i(const char *str)
{
	long	i;

	i = 0;
	while (str[i] == ' ' || str[i] == '\n' || str[i] == '\t' ||
			str[i] == '\v' || str[i] == '\r' || str[i] == '\f')
		i++;
	if (str[i] == '-')
		i++;
	else if (str[i] == '+')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
		i++;
	return (i);
}

double		ft_atof(const char *str)
{
	double	nb;
	double	a;
	long	i;

	nb = 0;
	i = get_i(str);
	if (str[i] == '\0' || str[i + 1] == '\0')
		return (ft_atoi(str));
	if ((str[i] == ',' || str[i] == '.') &&
			str[i + 1] >= '0' && str[i + 1] <= '9')
	{
		nb = (double)ft_atoi(&str[i + 1]);
		while (nb > 1)
			nb /= 10;
	}
	a = ft_atoi(str);
	if (a < 0)
		nb = a - nb;
	else
		nb += (double)ft_atoi(str);
	return (nb);
}
