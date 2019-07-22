/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_round.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcourtil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/15 13:12:54 by tcourtil          #+#    #+#             */
/*   Updated: 2018/12/06 16:48:21 by tcourtil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

double		ft_round(double f)
{
	double test;

	test = ft_floor(f) + 0.5f;
	if (f >= test)
		return (ft_ceil(f));
	return (ft_floor(f));
}
