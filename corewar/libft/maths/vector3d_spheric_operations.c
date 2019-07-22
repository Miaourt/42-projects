/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector3d_spheric_operations.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tguillem <tguillem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/20 12:51:59 by tguillem          #+#    #+#             */
/*   Updated: 2016/09/20 12:53:11 by tguillem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vector.h"

double			spherical_theta(t_vec3d *vector)
{
	return (acos(ft_clamp(vector->z, -1, 1)));
}

double			spherical_phi(t_vec3d *vector)
{
	double		phi;

	phi = atan2(vector->y, vector->x);
	return (phi < 0 ? phi + 2 * M_PI : phi);
}
