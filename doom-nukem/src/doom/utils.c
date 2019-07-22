/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llaporte <llaporte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/02 14:17:05 by tcourtil          #+#    #+#             */
/*   Updated: 2019/05/06 02:18:29 by llaporte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doom.h"

double			normrad(double ang)
{
	double res;

	res = ang + M_PI;
	while (res < 0)
		res += M_PI * 2;
	while (res >= M_PI * 2)
		res -= M_PI * 2;
	return (res);
}

int				comrad(double ang, double min, double max)
{
	ang = normrad(ang);
	min = normrad(min);
	max = normrad(max);
	if (min > max && ang <= min && ang <= max)
		return (1);
	if (min > max && ang >= min && ang >= max)
		return (1);
	if (ang >= min && ang <= max)
		return (1);
	return (0);
}

void			disp(t_world *w)
{
	int		y;
	int		x;

	y = 0;
	while (y < w->height)
	{
		x = 0;
		while (x < w->width)
		{
			ft_printf("%d", w->map[y][x]);
			x++;
		}
		ft_printf("\n");
		y++;
	}
}

t_ent			*entitynew(double x, double z, double rot, int id)
{
	t_vec4	*pos;
	t_ent	*ent;

	if (!(pos = ft_vec4new(x, 0, z, 0.0f)))
		return (NULL);
	if (!(ent = (t_ent *)ft_memalloc(sizeof(t_ent))))
		return (NULL);
	ent->pos = pos;
	ent->lifetime = 0;
	ent->rot = rot;
	ent->id = id;
	return (ent);
}

t_entdata		*entdatanew(void)
{
	t_entdata *ent;

	if (!(ent = (t_entdata *)ft_memalloc(sizeof(t_entdata))))
		return (NULL);
	ent->id = 0;
	ent->collide = 0;
	ent->trigger = 0;
	ent->dist_collide = 0;
	ent->ontrigger = NULL;
	ent->update = NULL;
	ent->onuse = NULL;
	ent->texture = NULL;
	ent->texture_d = NULL;
	return (ent);
}
