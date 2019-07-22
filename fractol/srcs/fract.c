/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fract.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llaporte <llaporte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/19 16:17:02 by llaporte          #+#    #+#             */
/*   Updated: 2017/06/07 14:58:10 by llaporte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	itefract(t_data_fct *dt, t_complex c, t_complex z)
{
	double	tmpr;
	double	tmpi;

	while (z.r * z.r + z.i * z.i < 4 && dt->i < dt->imax)
	{
		tmpr = z.r;
		tmpi = z.i;
		z.r = tmpr * tmpr - tmpi * tmpi + c.r;
		z.i = tmpi * tmpr * 2 + c.i;
		if (z.r == tmpr && z.i == tmpi)
			dt->i = dt->imax;
		++dt->i;
	}
}

static void	itefractb(t_data_fct *dt, t_complex c, t_complex z)
{
	double	tmpr;
	double	tmpi;

	while (z.r * z.r + z.i * z.i < 4 && dt->i < dt->imax)
	{
		tmpr = ft_fabs(z.r);
		tmpi = ft_fabs(z.i);
		z.r = tmpr * tmpr - tmpi * tmpi + c.r;
		z.i = tmpi * tmpr * 2 + c.i;
		if (z.r == tmpr && z.i == tmpi)
			dt->i = dt->imax;
		++dt->i;
	}
}

static void	mandelship(t_data_fct *dt, int x, int y)
{
	dt->c.r = (x - dt->x_margin) / dt->zoom;
	dt->c.i = (y - dt->y_margin) / dt->zoom;
	dt->z.r = 0;
	dt->z.i = 0;
	if (dt->fract == 3)
		itefractb(dt, dt->c, dt->z);
	else
		itefract(dt, dt->c, dt->z);
}

static void	julia(t_data_fct *dt, int x, int y)
{
	dt->c.r = 0.265 + dt->mouse_x * 0.005 / 100.0;
	dt->c.i = dt->mouse_y * 0.01 / 100.0 - 0.03;
	dt->z.r = (x - dt->x_margin) / dt->zoom;
	dt->z.i = (y - dt->y_margin) / dt->zoom;
	itefract(dt, dt->c, dt->z);
}

int			drawer(t_data_fct *dt)
{
	int	x;
	int	y;

	y = 0;
	while (y < dt->win_y)
	{
		x = 0;
		while (x < dt->win_x)
		{
			dt->i = 0;
			if (dt->fract == 1 || dt->fract == 3)
				mandelship(dt, x, y);
			else if (dt->fract == 2)
				julia(dt, x, y);
			img_pixel_put(dt, x, y, dt->i == dt->imax ?
				0 : hv(dt->hue, dt->i * 1.0 / dt->imax));
			x += dt->precision;
		}
		y += dt->precision;
	}
	mlx_put_image_to_window(dt->mlx, dt->win, dt->img->self, 0, 0);
	if (dt->tips)
		annotate(dt);
	return (0);
}
