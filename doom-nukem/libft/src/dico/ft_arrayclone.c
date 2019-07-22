/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arrayclone.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcourtil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/07 14:48:17 by tcourtil          #+#    #+#             */
/*   Updated: 2019/03/12 16:05:47 by tcourtil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_array	*ft_arrayclone(t_array *base)
{
	t_array			*res;
	unsigned int	i;

	i = 0;
	res = ft_arraynew();
	while (i < base->length)
	{
		ft_arrayadd(res, ft_strdup(ft_arrayget(base, i)));
		i++;
	}
	return (res);
}
