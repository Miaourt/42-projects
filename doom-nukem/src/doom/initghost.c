/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initghost.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llaporte <llaporte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/02 14:17:05 by tcourtil          #+#    #+#             */
/*   Updated: 2019/05/06 02:18:29 by llaporte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doom.h"

static int		init_ghost0(t_win *win)
{
	t_entdata *e;

	if (!(e = entdatanew()))
		return (1);
	e->id = 1;
	e->collide = 0;
	e->trigger = 1;
	e->dist_collide = 0.75;
	e->ontrigger = ghosttrigger;
	e->update = ghostmove;
	e->onuse = NULL;
	e->texture = ft_arrayget(win->enttexture, 1);
	e->texture_d = ft_arrayget(win->enttexture, 1);
	ft_arrayadd(win->entdata, e);
	return (0);
}

static int		init_ghost1(t_win *win)
{
	t_entdata *e;

	if (!(e = entdatanew()))
		return (1);
	e->id = 2;
	e->collide = 0;
	e->trigger = 1;
	e->dist_collide = 0.75;
	e->onuse = NULL;
	e->ontrigger = ghosttrigger;
	e->update = ghostmove;
	e->texture = ft_arrayget(win->enttexture, 2);
	e->texture_d = ft_arrayget(win->enttexture, 2);
	ft_arrayadd(win->entdata, e);
	return (0);
}

static int		init_ghost2(t_win *win)
{
	t_entdata *e;

	if (!(e = entdatanew()))
		return (1);
	e->id = 3;
	e->collide = 0;
	e->trigger = 1;
	e->dist_collide = 0.75;
	e->ontrigger = ghosttrigger;
	e->update = ghostmove;
	e->onuse = NULL;
	e->texture = ft_arrayget(win->enttexture, 3);
	e->texture_d = ft_arrayget(win->enttexture, 3);
	ft_arrayadd(win->entdata, e);
	return (0);
}

static int		init_ghost3(t_win *win)
{
	t_entdata *e;

	if (!(e = entdatanew()))
		return (1);
	e->id = 4;
	e->collide = 0;
	e->trigger = 1;
	e->dist_collide = 0.75;
	e->ontrigger = ghosttrigger;
	e->update = ghostmove;
	e->onuse = NULL;
	e->texture = ft_arrayget(win->enttexture, 2);
	e->texture_d = ft_arrayget(win->enttexture, 2);
	ft_arrayadd(win->entdata, e);
	return (0);
}

int				init_ghost(t_win *win)
{
	if (init_ghost0(win))
		return (1);
	if (init_ghost1(win))
		return (1);
	if (init_ghost2(win))
		return (1);
	if (init_ghost3(win))
		return (1);
	return (0);
}
