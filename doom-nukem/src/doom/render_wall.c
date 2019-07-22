/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_wall.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llaporte <llaporte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/28 15:42:21 by tcourtil          #+#    #+#             */
/*   Updated: 2019/05/15 14:37:30 by tcourtil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doom.h"

static int		getceil(t_data *data, t_ray *r, double wall_size, int i)
{
	double h;
	double dist;
	double tx;
	double ty;

	h = ((r->wall + data->win->world->cam->ry) - i) + (wall_size / 2.0f);
	dist = (wall_size / 2.0f) / tan(atan((h) / (r->dist)));
	tx = cos(r->rot) * dist + data->win->world->cam->x;
	tx = tx - floor(tx);
	ty = sin(r->rot) * dist + data->win->world->cam->z;
	ty = ty - floor(ty);
	return (get_img_pixel(data->win->ceil, tx, ty));
}

static int		getfloor(t_data *data, t_ray *r, double wall_size, int i)
{
	double h;
	double dist;
	double tx;
	double ty;

	h = ((r->wall - data->win->world->cam->ry) -
			(data->win->height - i)) + ((wall_size / 2.0f));
	dist = ((wall_size / 2.0f)) / tan(atan((h) / (r->dist)));
	tx = (cos(r->rot) * dist) + data->win->world->cam->x;
	tx = tx - floor(tx);
	ty = (sin(r->rot) * dist) + data->win->world->cam->z;
	ty = ty - floor(ty);
	return (get_img_pixel(data->win->floor, tx, ty));
}

static int		getwallcolor(t_data *data, t_ray *r, int i)
{
	float	facy;
	int		px;
	double	size;

	size = data->win->height;
	size -= r->wall * 2;
	facy = (i - (r->wall + data->win->world->cam->ry)) / size;
	px = get_img_pixel((t_img *)ft_arrayget(data->win->textures,
				r->id > 0 ? r->id : 0)
			, r->texture_pos, facy);
	if (r->dir == 0)
		return (lerp(0x00FF0000, px, 0.8f));
	if (r->dir == 1)
		return (lerp(0x00FF00FF, px, 0.8f));
	if (r->dir == 2)
		return (lerp(0x000000FF, px, 0.8f));
	if (r->dir == 3)
		return (lerp(0x0000FF00, px, 0.8f));
	return (0);
}

static void		draw_wall(t_data *data, int x, t_ray *r, double wall_size)
{
	int		i;
	int		wall;
	t_win	*win;
	int		color;

	win = data->win;
	i = -1;
	wall = wall_size;
	wall = data->win->height - wall;
	wall /= 2;
	r->wall = wall;
	while (++i < win->height)
	{
		if (i < wall + data->win->world->cam->ry)
			color = getceil(data, r, wall_size, i);
		else if (i >= data->win->height - (wall - data->win->world->cam->ry))
			color = getfloor(data, r, wall_size, i);
		else
			color = getwallcolor(data, r, i);
		data->color[(x - data->x) * win->height + i] = color;
		data->dist[((x - data->x) * win->height) + i] = r->r;
	}
}

void			render_wall(t_data *data, int x)
{
	double	rot;
	double	r;
	double	ws;
	double	id;
	t_ray	ra;

	id = x - (data->win->width / 2);
	rot = id * data->win->ray_fac + data->win->world->cam->rot;
	ra.rot = rot;
	r = ray(data->win->world, rot, &ra);
	ra.r = r;
	ra.wall = 0;
	ws = fish_eyes(r, rot - data->win->world->cam->rot);
	ra.dist = r;
	ws = wall_size(ws);
	draw_wall(data, x, &ra, ws);
}
