/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llaporte <llaporte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/31 15:11:09 by llaporte          #+#    #+#             */
/*   Updated: 2017/06/07 14:34:51 by llaporte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void		img_pixel_put(t_data_fct *dt, float x, float y, int color)
{
	*(int *)(dt->img->ptr + (((int)(y + 0.5) * dt->win_x + (int)(x + 0.5))
		* (dt->img->bpp / 8))) = color;
}

int			rgb(int r, int g, int b)
{
	int		hex;

	hex = 0;
	hex += (int)(r) << 16;
	hex += (int)(g) << 8;
	hex += (int)(b);
	return (hex);
}

int			hv(int hue, float val)
{
	int	r;
	int	g;
	int	b;

	r = 0;
	g = 0;
	b = 0;
	if (hue == 1 || hue == 4 || hue == 5)
		r = 255;
	if (hue == 2 || hue == 5 || hue == 6)
		g = 255;
	if (hue == 3 || hue == 4 || hue == 6)
		b = 255;
	return (rgb(r * val, g * val, b * val));
}

void		img_clean(t_data_fct *dt)
{
	int	y;
	int	x;

	y = 0;
	while (y++ < dt->win_y)
	{
		x = 0;
		while (x < dt->win_x)
			img_pixel_put(dt, x++, y - 1, 0);
	}
}

void		annotate(t_data_fct *dt)
{
	int		c;

	c = rgb(255, 255, 255);
	mlx_string_put(dt->mlx, dt->win, 0, 0, c, "[+] [-] [molette] = zoom");
	mlx_string_put(dt->mlx, dt->win, 0, 20, c, "[9]/[6] = iterations -/+");
	mlx_string_put(dt->mlx, dt->win, 0, 40, c, "[8]/[5] = precision -/+");
	mlx_string_put(dt->mlx, dt->win, dt->win_x - 332, 0, c,
		"[up] [down] [left] [right] = move");
	mlx_string_put(dt->mlx, dt->win, dt->win_x - 122, 20, c, "[*] = colors");
	mlx_string_put(dt->mlx, dt->win, dt->win_x - 152, 40, c, "[/] = hide tips");
	if (dt->fract == 2)
	{
		mlx_string_put(dt->mlx, dt->win, 0, 60, c, "Move mouse = transform");
		if (!dt->mouselock)
			mlx_string_put(dt->mlx, dt->win, 0, 80, c, "[.] = lock mouse");
		else
			mlx_string_put(dt->mlx, dt->win, 0, 80, c, "[.] = unlock mouse");
	}
}
