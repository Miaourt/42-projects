/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_floor.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcourtil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/15 14:00:45 by tcourtil          #+#    #+#             */
/*   Updated: 2018/12/11 13:13:03 by tcourtil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

float	ft_floor(float fl)
{
	unsigned int		nb;
	float				cp;
	unsigned int		man;
	int					exp;

	cp = fl;
	nb = *((unsigned int *)(&cp));
	man = nb & 0x007fffff;
	exp = nb & 0x7f800000;
	exp = exp >> 23;
	exp -= 127;
	if (exp < 0)
		return (0.0f);
	if (exp == 0)
		return (1.0f);
	if (exp >= 23)
		return (fl);
	nb = nb ^ man;
	man = man >> (23 - exp);
	man = man << (23 - exp);
	nb = nb | man;
	return (*((float *)&nb));
}
