/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gameloop.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocojeda- <ocojeda-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/21 15:01:01 by tcourtil          #+#    #+#             */
/*   Updated: 2019/05/15 16:18:15 by ocojeda-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doom.h"

void			game_loop_o(t_win *win)
{
	if (win->forward)
		up(win);
	if (win->back)
		down(win);
	if (win->move_right)
		straff(win, -1);
	if (win->move_left)
		straff(win, 1);
}

int				game_loop(t_win *win)
{
	game_loop_o(win);
	if (win->action && win->player.action)
	{
		action(win);
		win->player.action = 0;
	}
	if (!win->action && !win->player.action)
		win->player.action = 1;
	if (win->player.giletjaune > 0)
		win->player.giletjaune--;
	if (win->jp_time > 0)
	{
		if (!(--win->jp_time))
		{
			win->jet_pack = 0;
			win->world->cam->ry = 0;
		}
	}
	return (0);
}

void			y_axis_mov(t_win *win, int y)
{
	if (win->knees)
	{
		win->world->cam->ry -= (y * (M_PI / 2.0));
		if (win->world->cam->ry > -250)
			win->world->cam->ry = -250;
	}
	else if (win->jet_pack)
	{
		win->world->cam->ry -= (y * (M_PI / 2.0));
		if (win->world->cam->ry < 250)
			win->world->cam->ry = 250;
	}
	else
		win->world->cam->ry -= (y * (M_PI / 2.0));
}

void			mouse_movements(t_win *win, SDL_MouseMotionEvent motion)
{
	if (motion.xrel)
		win->world->cam->rot += (motion.xrel * (M_PI / 1500.0));
	if (motion.yrel)
		y_axis_mov(win, motion.yrel);
	if (win->world->cam->ry > 500)
		win->world->cam->ry = 500;
	if (win->world->cam->ry < -500)
		win->world->cam->ry = -500;
}
