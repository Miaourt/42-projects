/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gilet.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llaporte <llaporte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/02 14:17:05 by tcourtil          #+#    #+#             */
/*   Updated: 2019/05/14 15:52:25 by tcourtil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doom.h"

void		gilettrigger(t_win *win, t_ent *ent)
{
	ent->id = -1;
	win->player.giletjaune = win->cf_time_jacket;
}

int			init_gilet(t_win *win)
{
	t_entdata *e;

	if (!(e = entdatanew()))
		return (1);
	e->id = 6;
	e->collide = 0;
	e->trigger = 1;
	e->dist_collide = 0.3;
	e->ontrigger = &gilettrigger;
	e->update = NULL;
	e->onuse = NULL;
	e->texture = ft_arrayget(win->enttexture, 5);
	e->texture_d = ft_arrayget(win->enttexture, 5);
	ft_arrayadd(win->entdata, e);
	return (0);
}
