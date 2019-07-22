/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coin.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llaporte <llaporte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/02 14:17:05 by tcourtil          #+#    #+#             */
/*   Updated: 2019/05/15 15:00:44 by tcourtil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doom.h"

static int		init_coin0(t_win *win)
{
	t_entdata *e;

	if (!(e = entdatanew()))
		return (1);
	e->id = 10;
	e->collide = 0;
	e->trigger = 0;
	e->dist_collide = 0.75;
	e->ontrigger = NULL;
	e->update = coinmove;
	e->onuse = NULL;
	e->texture = ft_arrayget(win->enttexture, 10);
	e->texture_d = ft_arrayget(win->enttexture, 10);
	ft_arrayadd(win->entdata, e);
	return (0);
}

static int		init_coin1(t_win *win)
{
	t_entdata *e;

	if (!(e = entdatanew()))
		return (1);
	e->id = 11;
	e->collide = 0;
	e->trigger = 0;
	e->dist_collide = 0.75;
	e->onuse = NULL;
	e->ontrigger = NULL;
	e->update = coinmove;
	e->texture = ft_arrayget(win->enttexture, 11);
	e->texture_d = ft_arrayget(win->enttexture, 11);
	ft_arrayadd(win->entdata, e);
	return (0);
}

static int		init_coin2(t_win *win)
{
	t_entdata *e;

	if (!(e = entdatanew()))
		return (1);
	e->id = 12;
	e->collide = 0;
	e->trigger = 0;
	e->dist_collide = 0.75;
	e->ontrigger = NULL;
	e->update = coinmove;
	e->onuse = NULL;
	e->texture = ft_arrayget(win->enttexture, 12);
	e->texture_d = ft_arrayget(win->enttexture, 12);
	ft_arrayadd(win->entdata, e);
	return (0);
}

static int		init_coin3(t_win *win)
{
	t_entdata *e;

	if (!(e = entdatanew()))
		return (1);
	e->id = 13;
	e->collide = 0;
	e->trigger = 0;
	e->dist_collide = 0.75;
	e->ontrigger = NULL;
	e->update = coinmove;
	e->onuse = NULL;
	e->texture = ft_arrayget(win->enttexture, 13);
	e->texture_d = ft_arrayget(win->enttexture, 13);
	ft_arrayadd(win->entdata, e);
	return (0);
}

int				init_coin(t_win *win)
{
	if (init_coin0(win))
		return (1);
	if (init_coin1(win))
		return (1);
	if (init_coin2(win))
		return (1);
	if (init_coin3(win))
		return (1);
	return (0);
}
