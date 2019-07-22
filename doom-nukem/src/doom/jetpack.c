/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   jetpack.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocojeda- <ocojeda-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/02 14:17:05 by tcourtil          #+#    #+#             */
/*   Updated: 2019/05/15 16:11:15 by ocojeda-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doom.h"

void		usejetpack(t_win *win, t_ent *ent)
{
	ent->id = -1;
	win->jp_time = 200;
	win->jet_pack = 250;
	win->knees = 0;
	win->world->cam->ry = win->jet_pack;
	if (win)
		return ;
}

int			init_jetpack(t_win *win)
{
	t_entdata *e;

	if (!(e = entdatanew()))
		return (1);
	e->id = 14;
	e->collide = 0;
	e->trigger = 1;
	e->dist_collide = 0.3;
	e->ontrigger = &usejetpack;
	e->update = NULL;
	e->onuse = &usebarrel;
	e->texture = ft_arrayget(win->enttexture, 14);
	e->texture_d = ft_arrayget(win->enttexture, 14);
	ft_arrayadd(win->entdata, e);
	return (0);
}
