/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llaporte <llaporte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/24 17:29:20 by llaporte          #+#    #+#             */
/*   Updated: 2017/02/22 14:55:10 by llaporte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	img_pixel_put(t_data_fdf *dt, int x, int y, int color)
{
	if (x < dt->win_x && x >= 0 && y < dt->win_y && y >= 0)
		*(int *)(dt->img->ptr + ((y * dt->win_x + x)
			* (dt->img->bpp / 8))) = color;
}

void	draw_line(t_data_fdf *dt, t_point a, t_point b, int color)
{
	t_line l;

	l.dx = b.x - a.x;
	l.dy = b.y - a.y;
	l.p.x = a.x;
	l.p.y = a.y;
	if (l.dx != 0)
	{
		while (l.p.x != b.x)
		{
			l.p.y = a.y + l.dy * (l.p.x - a.x) / l.dx;
			l.p2.x = l.p.x;
			l.p2.y = a.y + l.dy * (l.p.x + 1 - a.x) / l.dx;
			draw_line(dt, l.p, l.p2, color);
			l.p.x += a.x <= b.x ? 1 : -1;
		}
	}
	else
	{
		while (l.p.y != b.y)
			img_pixel_put(dt, a.x, l.p.y += a.y <= b.y ? 1 : -1, color);
		img_pixel_put(dt, a.x, l.p.y, color);
	}
}

int		color(t_data_fdf *dt, int height)
{
	if (dt->cm == 1)
	{
		if (height <= 0)
			return (0x006205FF);
		else if (height <= 2)
			return (0x00880CFF);
		else if (height <= 5)
			return (0x009705E8);
		else if (height <= 8)
			return (0x00B80BE8);
		else if (height <= 10)
			return (0x00EA08FF);
		else if (height <= 15)
			return (0x00FF01E6);
		else if (height <= 20)
			return (0x00E8059A);
		else if (height <= 30)
			return (0x00E80B63);
		else if (height <= 40)
			return (0x00FF130C);
		else
			return (0x00FF052C);
	}
	else
		return (0x00E6E6E6);
}

void	draw_part(t_data_fdf *dt, int x, int y)
{
	t_point	a;
	t_point	b;

	if ((x + 1) < dt->map_x)
	{
		a.x = (x - y) * dt->sf + dt->sf + dt->ofx;
		a.y = (x + y - (dt->hg < 1 ?
		hxy(dt, x, y) : hxy(dt, x, y) / dt->hg)) * (dt->sf / 2) + dt->ofy;
		b.x = (x - y + 1) * dt->sf + dt->sf + dt->ofx;
		b.y = (x + y + 1 - (dt->hg < 1 ?
		hxy(dt, x, y) : hxy(dt, x + 1, y) / dt->hg)) * (dt->sf / 2) + dt->ofy;
		draw_line(dt, a, b, color(dt, hxy(dt, x, y) >= hxy(dt, x + 1, y) ?
		hxy(dt, x, y) : hxy(dt, x + 1, y)));
	}
	if ((y + 1) < dt->map_y)
	{
		a.x = (x - y - 1) * dt->sf + dt->sf + dt->ofx;
		a.y = (x + y + 1 - (dt->hg < 1 ?
		hxy(dt, x, y) : hxy(dt, x, y + 1) / dt->hg)) * (dt->sf / 2) + dt->ofy;
		b.x = (x - y) * dt->sf + dt->sf + dt->ofx;
		b.y = (x + y - (dt->hg < 1 ?
		hxy(dt, x, y) : hxy(dt, x, y) / dt->hg)) * (dt->sf / 2) + dt->ofy;
		draw_line(dt, a, b, color(dt, hxy(dt, x, y) >= hxy(dt, x, y + 1) ?
		hxy(dt, x, y) : hxy(dt, x, y + 1)));
	}
}

void	map_draw(t_data_fdf *dt)
{
	t_point pt;

	pt.y = 0;
	while (pt.y < dt->win_y)
	{
		pt.x = 0;
		while (pt.x < dt->win_x)
			img_pixel_put(dt, pt.x++, pt.y, 3158848);
		++pt.y;
	}
	pt.y = 0;
	while (pt.y < dt->map_y)
	{
		pt.x = 0;
		while (pt.x < dt->map_x)
		{
			if (hxy(dt, pt.x, pt.y) == 0 && dt->fdf_map[pt.y][pt.x][0] != '0')
				err("Invalid map, no number found on a case.\n");
			draw_part(dt, pt.x++, pt.y);
		}
		++pt.y;
	}
	mlx_put_image_to_window(dt->mlx, dt->win, dt->img->self, 0, 0);
}
