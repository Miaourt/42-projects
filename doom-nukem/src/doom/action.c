/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llaporte <llaporte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/21 15:01:01 by tcourtil          #+#    #+#             */
/*   Updated: 2019/05/06 02:18:29 by llaporte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doom.h"

static void		infront(t_win *win, t_ent **best, double *max, int i)
{
	t_vec4	pos;
	t_ent	*e;

	e = ft_arrayget(win->entity, i);
	if (e->id >= 0)
	{
		pos.x = e->pos->x - win->world->cam->x;
		pos.z = e->pos->z - win->world->cam->z;
		pos.y = atan2(pos.z, pos.x);
		if (comrad(pos.y, win->world->cam->rot - 0.17,
					win->world->cam->rot + 0.17))
		{
			pos.w = pos.z * pos.z + pos.x * pos.x;
			if (!(*best) || pos.w <= *max)
			{
				*best = e;
				*max = pos.w;
			}
		}
	}
}

static t_ent	*get_entfront(t_win *win, double *dist)
{
	t_ent			*best;
	unsigned int	i;
	double			max;

	best = NULL;
	max = 0;
	i = 0;
	while (i < win->entity->length)
	{
		infront(win, &best, &max, i);
		i++;
	}
	*dist = sqrt(max);
	return (best);
}

void			action(t_win *win)
{
	t_ent		*target;
	double		dist;
	t_entdata	*data;

	target = get_entfront(win, &dist);
	if (target)
	{
		data = ft_arrayget(win->entdata, target->id);
		if (data->onuse)
			(*(data->onuse))(win, target, dist);
	}
}
