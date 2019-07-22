/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libmath.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcourtil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/06 16:23:03 by tcourtil          #+#    #+#             */
/*   Updated: 2019/01/29 17:16:02 by tcourtil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBMATH_H
# define LIBMATH_H

# include "libft.h"

typedef struct			s_vec4
{
	float				x;
	float				y;
	float				z;
	float				w;
}						t_vec4;

typedef struct			s_mat4
{
	t_vec4				*vec1;
	t_vec4				*vec2;
	t_vec4				*vec3;
	t_vec4				*vec4;
}						t_mat4;

t_vec4					*ft_vec4new(float x, float y, float z, float w);
void					ft_vec4free(t_vec4 *vec);
t_mat4					*ft_mat4new(float base);
void					ft_mat4free(t_mat4 *mat);
t_vec4					*ft_vecxmat4(t_mat4 *mat, t_vec4 *vec);

#endif
