/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collide.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llaporte <llaporte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/07 17:29:26 by tcourtil          #+#    #+#             */
/*   Updated: 2019/05/15 15:31:09 by tcourtil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doom.h"

static int		collideent(t_win *win, double px, double pz)
{
	unsigned int		i;
	t_ent				*e;
	t_entdata			*data;
	double				x;
	double				z;

	i = 0;
	while (i < win->entity->length)
	{
		e = ft_arrayget(win->entity, i);
		if (e->id >= 0)
		{
			data = ft_arrayget(win->entdata, e->id);
			if (data->collide)
			{
				x = e->pos->x - px;
				z = e->pos->z - pz;
				if (z * z + x * x <= data->dist_collide * data->dist_collide)
					return (1);
			}
		}
		i++;
	}
	return (0);
}

int				collide_walk(t_win *win, double x, double y)
{
	int px;
	int py;

	px = (int)floor(x);
	py = (int)floor(y);
	if (!(px >= 0 && px < win->world->width && py >= 0 &&
				py < win->world->height))
		return (1);
	if (win->world->map[py][px])
		return (1);
	if (win->jet_pack == 0 && collideent(win, x, y))
		return (1);
	return (0);
}
