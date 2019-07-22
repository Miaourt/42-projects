/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nav.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llaporte <llaporte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/31 16:41:52 by llaporte          #+#    #+#             */
/*   Updated: 2017/06/07 14:58:49 by llaporte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	zoom_pos(int x, int y, int value, t_data_fct *dt)
{
	if (value > 0)
	{
		dt->zoom *= 1.1;
		dt->x_margin -= (x - dt->x_margin) * 1.1 - (x - dt->x_margin);
		dt->y_margin += (dt->y_margin - y) * 1.1 - (dt->y_margin - y);
	}
	else
	{
		dt->zoom = dt->zoom / 1.1 > 2 ? dt->zoom / 1.1 : dt->zoom;
		dt->x_margin -= (x - dt->x_margin) / 1.1 - (x - dt->x_margin);
		dt->y_margin += (dt->y_margin - y) / 1.1 - (dt->y_margin - y);
	}
}

void	on_trigger(t_data_fct *dt)
{
	if (dt->keys->moreless)
		zoom_pos(dt->win_x / 2, dt->win_y / 2, dt->keys->moreless, dt);
	if (dt->keys->updown)
		dt->y_margin -= 20 * dt->keys->updown;
	if (dt->keys->leftright)
		dt->x_margin -= 20 * dt->keys->leftright;
	if (dt->keys->i)
		dt->imax += dt->imax + dt->keys->i > 0 ? dt->keys->i : 0;
	if (dt->keys->pcs)
	{
		dt->precision += dt->precision + dt->keys->pcs > 0
		&& dt->precision + dt->keys->pcs < 7 ? dt->keys->pcs : 0;
		img_clean(dt);
	}
	drawer(dt);
}
