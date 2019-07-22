/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_sprite.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llaporte <llaporte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/28 15:42:21 by tcourtil          #+#    #+#             */
/*   Updated: 2019/05/06 18:59:58 by tcourtil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doom.h"

int				getx(t_win *win, double rot)
{
	int		id;
	double	rot2;
	int		x;

	x = 0;
	while (x < win->width)
	{
		id = x - (win->width / 2);
		rot2 = id * win->ray_fac + win->world->cam->rot;
		if (comrad(rot, rot2, rot2 + win->ray_fac))
			return (x);
		x++;
	}
	return (0);
}

static int		drawysprite(t_win *win, int x, int y, t_rend *rend)
{
	double tx;
	double ty;

	tx = x - (rend->bx - (rend->ws / 2));
	tx /= rend->ws;
	ty = y - (rend->wall + win->world->cam->ry);
	ty /= rend->ws;
	if (tx < 0 || ty < 0 || tx > 1 || ty > 1)
		return (1);
	if ((get_img_pixel(rend->img, tx, ty) != 0x00FF00FF))
	{
		if (win->dist[(x * win->height) + y] > rend->dist)
		{
			draw_pixel(x, y, win, get_img_pixel(rend->img, tx, ty));
			win->dist[(x * win->height) + y] = rend->dist;
		}
	}
	return (0);
}

static int		drawsprite(t_win *win, t_rend *rend)
{
	int		x;
	int		wall;
	int		y;
	double	ws;

	ws = fish_eyes(rend->dist, rend->ang - win->world->cam->rot);
	ws = wall_size(ws);
	rend->ws = ws;
	x = rend->bx - (ws / 2);
	wall = (win->height - ws) / 2;
	rend->wall = wall;
	x = x <= 0 ? 0 : x;
	while (x < win->width && x < rend->bx + (ws / 2))
	{
		y = wall + win->world->cam->ry;
		y = y <= 0 ? 0 : y;
		while (y < win->height && y < win->height -
				(wall - win->world->cam->ry))
		{
			drawysprite(win, x, y, rend);
			y++;
		}
		x++;
	}
	return (0);
}

static void		canbedraw(t_win *win, t_vec4 *dist, t_ent *ent)
{
	double	ang;
	double	ws;
	t_rend	rend;

	ang = atan2(dist->z, dist->x);
	if (comrad(ang, win->world->cam->rot - 0.52, win->world->cam->rot + 0.52))
	{
		ws = sqrt(dist->x * dist->x + dist->z * dist->z);
		rend.ang = ang;
		rend.dist = ws;
		rend.ws = 0;
		rend.wall = 0;
		rend.bx = getx(win, ang);
		rend.img = ((t_entdata *)ft_arrayget(win->entdata, ent->id))->texture;
		if (comrad(ang + M_PI, ent->rot - (M_PI / 2), ent->rot + (M_PI / 2)))
			rend.img = ((t_entdata *)ft_arrayget(win->entdata,
						ent->id))->texture_d;
		drawsprite(win, &rend);
	}
}

int				rendersprite(t_win *win)
{
	unsigned int	i;
	t_ent			*ent;
	t_vec4			dist;

	i = 0;
	while (i < win->entity->length)
	{
		ent = ft_arrayget(win->entity, i);
		if (ent->id >= 0)
		{
			dist.x = ent->pos->x - win->world->cam->x;
			dist.y = ent->pos->y - win->world->cam->y;
			dist.z = ent->pos->z - win->world->cam->z;
			canbedraw(win, &dist, ent);
		}
		i++;
	}
	return (0);
}
