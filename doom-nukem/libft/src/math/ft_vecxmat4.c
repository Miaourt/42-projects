/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vecxmat4.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcourtil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/16 14:59:47 by tcourtil          #+#    #+#             */
/*   Updated: 2019/01/29 17:22:59 by tcourtil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static float	add(t_vec4 *v1, t_vec4 *v2)
{
	float res;

	res = 0;
	res += v1->x * v2->x;
	res += v1->y * v2->y;
	res += v1->z * v2->z;
	res += v1->w * v2->w;
	return (res);
}

t_vec4			*ft_vecxmat4(t_mat4 *mat, t_vec4 *vec)
{
	float	x;
	float	y;
	float	z;
	float	w;

	x = add(mat->vec1, vec);
	y = add(mat->vec2, vec);
	z = add(mat->vec3, vec);
	w = add(mat->vec4, vec);
	return (ft_vec4new(x, y, z, w));
}
