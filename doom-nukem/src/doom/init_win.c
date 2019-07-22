/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_win.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llaporte <llaporte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/02 14:17:05 by tcourtil          #+#    #+#             */
/*   Updated: 2019/05/14 15:52:05 by tcourtil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doom.h"

static void		init_win2(t_win *win)
{
	win->world->cam->rot = 3.14f / 2.0f;
	win->world->cam->roty = 0;
	win->speed = 0.05;
	win->walktime = 0;
	win->ground = 1;
	win->action = 0;
	win->forward = 0;
	win->back = 0;
	win->debug = 0;
	win->jump = 0;
	win->up = 0;
	win->move_left = 0;
	win->move_right = 0;
	win->down = 0;
	win->left = 0;
	win->right = 0;
	win->exit = 0;
	win->timej = 0;
	win->popup = NULL;
	win->popup2 = NULL;
	win->timer = 0;
}

static int		map_hasborder(t_world *world)
{
	int i;

	i = 0;
	while (i < world->width)
	{
		if (world->map[0][i] == 0 || world->map[world->height - 1][i] == 0)
			return (1);
		i++;
	}
	i = 0;
	while (i < world->height)
	{
		if (world->map[i][0] == 0 || world->map[i][world->width - 1] == 0)
			return (1);
		i++;
	}
	return (0);
}

int				init_win(t_win *win, char *file)
{
	win->world = NULL;
	win->font = 0;
	if (doom_load(win, file))
		return (err("Failed to read game data!"));
	if (init_entdata(win))
		return (err("Error loading entity \n"));
	if (map_hasborder(win->world))
		return (err("The map hasn't border !"));
	init_win2(win);
	win->player.max_life = win->cf_max_life;
	win->player.money = 0;
	win->player.taxes = 0;
	win->player.life = win->player.max_life;
	init_screen(win);
	win->ray_fac = 1.0472 / win->width;
	init_data(win);
	disp(win->world);
	return (0);
}
