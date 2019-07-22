/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mat4free.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcourtil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/16 14:41:27 by tcourtil          #+#    #+#             */
/*   Updated: 2019/01/16 14:47:11 by tcourtil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_mat4free(t_mat4 *mat)
{
	if (mat)
	{
		ft_vec4free(mat->vec1);
		ft_vec4free(mat->vec2);
		ft_vec4free(mat->vec3);
		ft_vec4free(mat->vec4);
		free(mat);
	}
}
