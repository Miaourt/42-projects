/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   money.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: groberto <groberto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/03 16:28:12 by groberto          #+#    #+#             */
/*   Updated: 2019/05/15 15:00:05 by tcourtil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doom.h"

void			set_money(t_win *win, t_ent *ent, double dist)
{
	t_ent	*e;

	if (dist <= 1.25)
	{
		win->player.money += win->cf_money;
		win->popup = "Good jobs";
		win->popup2 = "You took the booty!";
		win->timer = 100;
		ent->id = 8;
		e = entitynew(ent->pos->x, ent->pos->z, 0, 10);
		if (e)
			ft_arrayadd(win->entity, e);
	}
	if (win)
		return ;
}

static int		init_money_a(t_win *win)
{
	t_entdata *e;

	if (!(e = entdatanew()))
		return (1);
	e->id = 7;
	e->collide = 1;
	e->trigger = 0;
	e->dist_collide = 0.3;
	e->ontrigger = NULL;
	e->update = NULL;
	e->onuse = &set_money;
	e->texture = ft_arrayget(win->enttexture, 6);
	e->texture_d = ft_arrayget(win->enttexture, 6);
	ft_arrayadd(win->entdata, e);
	return (0);
}

static int		init_money_b(t_win *win)
{
	t_entdata *e;

	if (!(e = entdatanew()))
		return (1);
	e->id = 8;
	e->collide = 0;
	e->trigger = 0;
	e->dist_collide = 0.5;
	e->ontrigger = NULL;
	e->update = NULL;
	e->onuse = NULL;
	e->texture = ft_arrayget(win->enttexture, 7);
	e->texture_d = ft_arrayget(win->enttexture, 7);
	ft_arrayadd(win->entdata, e);
	return (0);
}

int				init_money(t_win *win)
{
	if (init_money_a(win))
		return (1);
	if (init_money_b(win))
		return (1);
	return (0);
}
