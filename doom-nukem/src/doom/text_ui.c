/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   text_ui.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llaporte <llaporte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/21 15:01:21 by tcourtil          #+#    #+#             */
/*   Updated: 2019/05/06 02:18:29 by llaporte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doom.h"

void		draw_char(t_win *win, int sx, int sy, char c)
{
	int	px;
	int py;
	int	x;
	int y;

	px = c % 16;
	py = c / 16;
	px *= 64;
	py *= 64;
	y = 0;
	while (y < 64)
	{
		x = 0;
		while (x < 64)
		{
			if (win->arial->data[px + x + ((py + y) * win->arial->width)]
					!= 0x00FF00FF)
				draw_pixel(sx + x, sy + y, win, win->arial->data[px + x
						+ ((py + y) * win->arial->width)]);
			x++;
		}
		y++;
	}
}

static int	haschar(char *l, char c)
{
	int	i;

	i = 0;
	while (l[i])
	{
		if (l[i] == c)
			return (1);
		i++;
	}
	return (0);
}

void		draw_str(t_win *win, int sx, int sy, char *p)
{
	int	i;
	int px;

	px = sx;
	i = 0;
	while (p[i])
	{
		draw_char(win, px, sy, p[i]);
		if (haschar("iljft", p[i]))
			px += 8;
		else if (haschar("rI", p[i]))
			px += 12;
		else if (haschar("JLTY", p[i]))
			px += 18;
		else if (haschar("V", p[i]))
			px += 24;
		else if (haschar("W", p[i]))
			px += 34;
		else if ((p[i] >= 'A' && p[i] < 'Z') || haschar("mw", p[i]))
			px += 28;
		else
			px += 18;
		i++;
	}
}
