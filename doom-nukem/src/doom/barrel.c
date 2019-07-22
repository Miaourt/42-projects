/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   barrel.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llaporte <llaporte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/02 14:17:05 by tcourtil          #+#    #+#             */
/*   Updated: 2019/05/08 13:36:01 by tcourtil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doom.h"

void		usebarrel(t_win *win, t_ent *ent, double dist)
{
	if (dist <= 1.25)
		ent->id = 5;
	if (win)
		return ;
}

int			init_barrel(t_win *win)
{
	t_entdata *e;

	if (!(e = entdatanew()))
		return (1);
	e->id = 0;
	e->collide = 1;
	e->trigger = 0;
	e->dist_collide = 0.3;
	e->ontrigger = NULL;
	e->update = NULL;
	e->onuse = &usebarrel;
	e->texture = ft_arrayget(win->enttexture, 0);
	e->texture_d = ft_arrayget(win->enttexture, 9);
	ft_arrayadd(win->entdata, e);
	return (0);
}

int			init_breakbarrel(t_win *win)
{
	t_entdata *e;

	if (!(e = entdatanew()))
		return (1);
	e->id = 5;
	e->collide = 0;
	e->trigger = 0;
	e->dist_collide = 0.5;
	e->ontrigger = NULL;
	e->update = NULL;
	e->onuse = NULL;
	e->texture = ft_arrayget(win->enttexture, 4);
	e->texture_d = ft_arrayget(win->enttexture, 4);
	ft_arrayadd(win->entdata, e);
	return (0);
}
