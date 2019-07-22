/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tax.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llaporte <llaporte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/03 16:52:47 by groberto          #+#    #+#             */
/*   Updated: 2019/05/14 15:54:08 by tcourtil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doom.h"

void			set_tax(t_win *win, t_ent *ent, double dist)
{
	if (dist <= 1.25 && win->player.money >= win->cf_prix)
	{
		win->player.money -= win->cf_prix;
		win->player.taxes++;
		win->popup = "Good boi";
		win->popup2 = "You paid ur taxes!";
		win->timer = 100;
		ent->id = -1;
	}
	if (win)
		return ;
}

static int		init_taxes(t_win *win)
{
	t_entdata *e;

	if (!(e = entdatanew()))
		return (1);
	e->id = 9;
	e->collide = 1;
	e->trigger = 0;
	e->dist_collide = 0.3;
	e->ontrigger = NULL;
	e->update = NULL;
	e->onuse = &set_tax;
	e->texture = ft_arrayget(win->enttexture, 8);
	e->texture_d = ft_arrayget(win->enttexture, 8);
	ft_arrayadd(win->entdata, e);
	return (0);
}

int				init_tax(t_win *win)
{
	if (init_taxes(win))
		return (1);
	return (0);
}
