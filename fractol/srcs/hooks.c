/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llaporte <llaporte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/22 18:03:27 by llaporte          #+#    #+#             */
/*   Updated: 2017/06/07 14:31:21 by llaporte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	hook_keys_pressed(int key, t_data_fct *dt)
{
	if (key == KEY_ESCAPE)
		exit(0);
	else if (key == KEY_PAD_ADD || key == KEY_PAD_SUB)
		dt->keys->moreless = key == KEY_PAD_ADD ? 1 : -1;
	else if (key == KEY_LEFT || key == KEY_RIGHT)
		dt->keys->leftright = key == KEY_LEFT ? -1 : 1;
	else if (key == KEY_UP || key == KEY_DOWN)
		dt->keys->updown = key == KEY_UP ? -1 : 1;
	else if (key == KEY_PAD_9 || key == KEY_PAD_6)
		dt->keys->i = key == KEY_PAD_9 ? 1 : -1;
	else if (key == KEY_PAD_8 || key == KEY_PAD_5)
		dt->keys->pcs = key == KEY_PAD_8 ? 1 : -1;
	else if (key == KEY_PAD_MULTIPLY)
		dt->hue = dt->hue + 1 <= 6 ? dt->hue + 1 : 1;
	else if (key == KEY_PAD_DIVIDE)
		dt->tips = dt->tips == 1 ? 0 : 1;
	else if (key == KEY_PAD_DOT)
		dt->mouselock = dt->mouselock == 1 ? 0 : 1;
	on_trigger(dt);
	return (0);
}

int	hook_keys_release(int key, t_data_fct *dt)
{
	if (key == KEY_PAD_ADD || key == KEY_PAD_SUB)
		dt->keys->moreless = 0;
	else if (key == KEY_LEFT || key == KEY_RIGHT)
		dt->keys->leftright = 0;
	else if (key == KEY_UP || key == KEY_DOWN)
		dt->keys->updown = 0;
	else if (key == KEY_PAD_9 || key == KEY_PAD_6)
		dt->keys->i = 0;
	else if (key == KEY_PAD_8 || key == KEY_PAD_5)
		dt->keys->pcs = 0;
	return (0);
}

int	hook_mouse_button(int mouse, int x, int y, t_data_fct *dt)
{
	if (mouse == MOUSE_SCROLL_DOWN || mouse == MOUSE_LEFT_CLICK)
		zoom_pos(x, y, (dt->zoom * 1.0 / 100), dt);
	else if (mouse == MOUSE_SCROLL_UP || mouse == MOUSE_RIGHT_CLICK)
		zoom_pos(x, y, (dt->zoom * 1.0 / 100), dt);
	drawer(dt);
	return (0);
}

int	hook_mouse_move(int x, int y, t_data_fct *dt)
{
	if (!dt->mouselock)
	{
		dt->mouse_x = x;
		dt->mouse_y = y;
		drawer(dt);
	}
	return (0);
}
