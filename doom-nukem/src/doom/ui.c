/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ui.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llaporte <llaporte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/21 15:01:21 by tcourtil          #+#    #+#             */
/*   Updated: 2019/05/14 15:57:40 by tcourtil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doom.h"

int		rect_ui(t_win *win, t_rectui *rect, int color)
{
	int x;
	int y;

	rect->lenghty = rect->y + rect->lenghty;
	rect->lenghtx = rect->x + rect->lenghtx;
	x = rect->x;
	y = rect->y;
	while (y < rect->lenghty)
	{
		while (x < rect->lenghtx)
		{
			draw_pixel(x, y, win, color);
			++x;
		}
		x = rect->x;
		++y;
	}
	return (0);
}

void	draw_img(t_win *win, int sx, int sy, t_img *img)
{
	int	x;
	int y;
	int	id;

	y = 0;
	while (y < img->height)
	{
		x = 0;
		while (x < img->width)
		{
			id = x + (y * img->width);
			if (img->data[id] != 0x00FF00FF)
				draw_pixel(sx + x, sy + y, win, img->data[id]);
			x++;
		}
		y++;
	}
}

void	render_life(t_win *win)
{
	t_rectui bar_back;
	t_rectui bar_life;

	bar_back.lenghtx = 400;
	bar_back.lenghty = 40;
	bar_back.x = win->width / 2 - bar_back.lenghtx / 2;
	bar_back.y = 32;
	bar_life.lenghtx = (bar_back.lenghtx - 4)
		* win->player.life / win->player.max_life;
	bar_life.lenghty = bar_back.lenghty - 4;
	bar_life.x = win->width / 2 - bar_back.lenghtx / 2 + 2;
	bar_life.y = 33;
	rect_ui(win, &bar_back, 0x444444);
	rect_ui(win, &bar_life, 0xAA0000);
}

void	draw_nbr(t_win *win, int sx, int sy, int nb)
{
	char *str;

	str = ft_itoa(nb);
	draw_str(win, sx, sy, str);
	free(str);
}

int		render_ui(t_win *win)
{
	render_life(win);
	if (win->popup && win->timer > 0)
	{
		draw_str(win, 124, 124, win->popup);
		if (win->popup2)
			draw_str(win, 124, 152, win->popup2);
		win->timer--;
	}
	draw_nbr(win, 160, 10, win->player.money);
	draw_str(win, 24, 10, "Money : ");
	draw_nbr(win, 160, 48, win->player.taxes);
	draw_str(win, 24, 48, "Taxes :  /");
	draw_nbr(win, 200, 48, win->cf_taxes);
	draw_nbr(win, 460 + 20, 25, win->player.life);
	draw_nbr(win, 530 + 20, 25, win->player.max_life);
	draw_str(win, 374 + 20, 25, "Life :   /");
	if (win->player.giletjaune > 0)
		if (win->player.giletjaune >= 50 || win->player.giletjaune % 5 != 0)
			draw_img(win, 800, 10, win->uigilet);
	if (win->player.life <= 0)
		draw_img(win, 0, 0, win->gameover);
	if (win->player.taxes >= win->cf_taxes)
		draw_img(win, 0, 0, win->gamewin);
	return (0);
}
