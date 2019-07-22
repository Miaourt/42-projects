/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llaporte <llaporte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/04 13:21:39 by tcourtil          #+#    #+#             */
/*   Updated: 2019/05/06 18:59:35 by tcourtil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doom.h"

double			dif(double x, double x2)
{
	if (x < x2)
		return (x2 - x);
	return (x - x2);
}

static double	calc_x(t_world *w, double b, int down, t_ray *r)
{
	double	c;
	double	x;
	double	y;

	c = w->cam->z - (w->cam->x * b);
	x = floor(w->cam->x) + (!down);
	while (x - down >= 0 && x - down < w->width)
	{
		y = x * b + c;
		if (y < 0 || floor(y) >= w->height)
			return (-1);
		if (w->map[(int)floor(y)][(int)x - down] > 0)
		{
			r->id_x = w->map[(int)floor(y)][(int)x - down] - 1;
			r->text_y = y - floor(y);
			x = dif(floor(x), w->cam->x);
			y = dif(y, w->cam->z);
			return (sqrt((x * x) + (y * y)));
		}
		x += down ? -1 : 1;
	}
	return (-1);
}

static double	calc_y(t_world *w, double b, int down, t_ray *r)
{
	double	c;
	double	x;
	double	y;

	c = w->cam->x - (w->cam->z * b);
	y = floor(w->cam->z) + (!down);
	while (y - down >= 0 && y - down < w->height)
	{
		x = y * b + c;
		if (!(x >= 0 && floor(x) < w->width))
			return (-1);
		if (w->map[(int)y - down][(int)floor(x)] > 0)
		{
			r->id_y = w->map[(int)y - down][(int)floor(x)] - 1;
			r->text_x = x - floor(x);
			x = dif(x, w->cam->x);
			y = dif(y, w->cam->z);
			return (sqrt((x * x) + (y * y)));
		}
		y += down ? -1 : 1;
	}
	return (-1);
}

int				getdir(double r1, double r2, double x, double y)
{
	if (r1 == -1)
		return (y < 0 ? 0 : 1);
	if (r2 == -1)
		return (x < 0 ? 3 : 2);
	if (r2 < r1)
		return (y < 0 ? 0 : 1);
	return (x < 0 ? 3 : 2);
}

double			ray(t_world *w, double rot, t_ray *r)
{
	double	x;
	double	y;
	double	r1;
	double	r2;

	x = cos(rot);
	y = sin(rot);
	r1 = calc_x(w, y / x, x < 0, r);
	r2 = calc_y(w, x / y, y < 0, r);
	r->dir = getdir(r1, r2, x, y);
	if (r1 == -1)
	{
		r->texture_pos = r->text_x;
		r->id = r->id_y;
		return (r2);
	}
	if (r2 == -1)
	{
		r->id = r->id_x;
		r->texture_pos = r->text_y;
		return (r1);
	}
	r->id = r1 < r2 ? r->id_x : r->id_y;
	r->texture_pos = r1 < r2 ? r->text_y : r->text_x;
	return (fmin(r1, r2));
}
