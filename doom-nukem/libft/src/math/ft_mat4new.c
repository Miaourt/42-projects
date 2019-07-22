/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mat4new.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcourtil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/16 14:19:14 by tcourtil          #+#    #+#             */
/*   Updated: 2019/01/29 17:23:19 by tcourtil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_mat4	*ft_mat4new(float base)
{
	t_mat4	*mat;
	int		fail;

	if ((mat = (t_mat4 *)ft_memalloc(sizeof(t_mat4))))
	{
		if (!(mat->vec1 = ft_vec4new(base, base, base, base)))
			fail = 1;
		if (!(mat->vec2 = ft_vec4new(base, base, base, base)))
			fail = 1;
		if (!(mat->vec3 = ft_vec4new(base, base, base, base)))
			fail = 1;
		if (!(mat->vec4 = ft_vec4new(base, base, base, base)))
			fail = 1;
		if (fail)
		{
			ft_mat4free(mat);
			return (NULL);
		}
	}
	return (mat);
}
