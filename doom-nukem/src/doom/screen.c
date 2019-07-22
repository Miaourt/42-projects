/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   screen.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: groberto <groberto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/18 14:47:44 by tcourtil          #+#    #+#             */
/*   Updated: 2019/05/15 15:35:57 by tcourtil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doom.h"

int		init_screen(t_win *win)
{
	win->width = W_WIDTH;
	win->height = W_HEIGHT;
	if (SDL_Init(SDL_INIT_VIDEO))
		return (err(SDL_GetError()));
	win->win = SDL_CreateWindow("Wolf3D", 0, 0, W_WIDTH, W_HEIGHT,
		SDL_WINDOW_INPUT_GRABBED | SDL_WINDOW_FULLSCREEN);
	win->rendr = SDL_CreateRenderer(win->win, -1, SDL_RENDERER_SOFTWARE);
	win->surf = SDL_CreateRGBSurface(0, W_WIDTH, W_HEIGHT, 32, 0, 0, 0, 0);
	SDL_SetRenderTarget(win->rendr, win->texture);
	SDL_ShowCursor(SDL_DISABLE);
	if (SDL_SetRelativeMouseMode(SDL_TRUE))
		return (err(SDL_GetError()));
	return (0);
}

void	clear_screen(t_win *win, int color)
{
	if (color == win->font)
		return ;
}

void	putpixel(SDL_Surface *surface, int x, int y, Uint32 pixel)
{
	Uint8	*p;

	p = (Uint8 *)surface->pixels + y * surface->pitch
		+ x * surface->format->BytesPerPixel;
	if (surface->format->BytesPerPixel == 1)
		*p = pixel;
	if (surface->format->BytesPerPixel == 2)
		*(Uint16 *)p = pixel;
	if (surface->format->BytesPerPixel == 3)
	{
		if (SDL_BYTEORDER == SDL_BIG_ENDIAN)
		{
			p[0] = (pixel >> 16) & 0xff;
			p[1] = (pixel >> 8) & 0xff;
			p[2] = pixel & 0xff;
		}
		else
		{
			p[0] = pixel & 0xff;
			p[1] = (pixel >> 8) & 0xff;
			p[2] = (pixel >> 16) & 0xff;
		}
	}
	if (surface->format->BytesPerPixel == 4)
		*(Uint32 *)p = pixel;
}

void	draw_pixel(int x, int y, t_win *win, int color)
{
	Uint32 pixel;

	if (x < 0 || x >= win->width)
		return ;
	if (y < 0 || y >= win->height)
		return ;
	pixel = color;
	putpixel(win->surf, x, y, pixel);
}
