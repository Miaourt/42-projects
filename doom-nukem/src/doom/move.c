/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llaporte <llaporte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/07 17:29:26 by tcourtil          #+#    #+#             */
/*   Updated: 2019/05/08 17:01:54 by llaporte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doom.h"

void	walk(t_win *win)
{
	win->walktime += M_PI / 15;
	if (win->walktime > M_PI * 50)
		win->walktime -= M_PI * 52;
}

void	up(t_win *win)
{
	t_cam	*cam;
	double	mx;
	double	my;

	cam = win->world->cam;
	mx = cos(cam->rot) * (win->speed + (win->shift * 0.05));
	my = sin(cam->rot) * (win->speed + (win->shift * 0.05));
	if (collide_walk(win, cam->x + mx * 5.0f, cam->z + my * 5.0f))
		return ;
	win->world->cam->x += mx;
	win->world->cam->z += my;
	walk(win);
}

void	straff(t_win *win, float dir)
{
	t_cam	*cam;
	double	mx;
	double	my;

	cam = win->world->cam;
	mx = cos(cam->rot + (M_PI / 2)) * -win->speed * dir;
	my = sin(cam->rot + (M_PI / 2)) * -win->speed * dir;
	if (collide_walk(win, cam->x + mx * 5.0f, cam->z + my * 5.0f))
		return ;
	win->world->cam->x += mx;
	win->world->cam->z += my;
	walk(win);
}

void	down(t_win *win)
{
	t_cam	*cam;
	double	mx;
	double	my;

	cam = win->world->cam;
	mx = cos(cam->rot) * -win->speed;
	my = sin(cam->rot) * -win->speed;
	if (collide_walk(win, cam->x + mx * 5.0f, cam->z + my * 5.0f))
		return ;
	win->world->cam->x += mx;
	win->world->cam->z += my;
	walk(win);
}
