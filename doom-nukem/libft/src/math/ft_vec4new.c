/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vec4new.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcourtil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/16 14:19:14 by tcourtil          #+#    #+#             */
/*   Updated: 2019/01/29 17:21:20 by tcourtil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_vec4	*ft_vec4new(float x, float y, float z, float w)
{
	t_vec4	*vec;

	if ((vec = (t_vec4 *)ft_memalloc(sizeof(t_vec4))))
	{
		vec->x = x;
		vec->y = y;
		vec->z = z;
		vec->w = w;
	}
	return (vec);
}
