/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llaporte <llaporte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/21 15:01:01 by tcourtil          #+#    #+#             */
/*   Updated: 2019/05/06 02:18:29 by llaporte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doom.h"

void			eup(t_win *win, t_ent *e, t_entdata *data)
{
	double			x;
	double			z;

	if (data->trigger && data->ontrigger)
	{
		x = e->pos->x - win->world->cam->x;
		z = e->pos->z - win->world->cam->z;
		if (z * z + x * x <= data->dist_collide * data->dist_collide)
			(*(data->ontrigger))(win, e);
	}
	if (data->update && e->id >= 0)
		(*(data->update))(win, e);
	e->lifetime++;
}

void			entupdate(t_win *win)
{
	unsigned int	i;
	t_ent			*e;
	t_entdata		*data;

	i = 0;
	while (i < win->entity->length)
	{
		e = ft_arrayget(win->entity, i);
		if (e->id >= 0)
		{
			data = ft_arrayget(win->entdata, e->id);
			eup(win, e, data);
		}
		i++;
	}
}

int				check_event(t_win *win, SDL_bool *quit)
{
	SDL_Event	event;

	while (SDL_PollEvent(&event))
	{
		if (event.type == SDL_QUIT)
			*quit = SDL_TRUE;
		if (event.type == SDL_KEYDOWN)
			hook_keys_pressed(event.key.keysym.sym, win);
		if (event.type == SDL_KEYUP)
			hook_keys_release(event.key.keysym.sym, win);
		if (event.type == SDL_MOUSEMOTION)
			mouse_movements(win, event.motion);
	}
	return (0);
}

int				update(t_win *win)
{
	SDL_bool	quit;

	SDL_GL_SetSwapInterval(-1);
	quit = SDL_FALSE;
	while (!quit && !win->exit)
	{
		if (check_event(win, &quit))
			return (1);
		entupdate(win);
		game_loop(win);
		SDL_LockSurface(win->surf);
		if (render(win))
			return (1);
		SDL_UnlockSurface(win->surf);
		win->texture = SDL_CreateTextureFromSurface(win->rendr, win->surf);
		if (!win->texture)
			return (1);
		if (SDL_RenderCopy(win->rendr, win->texture, NULL, NULL))
			return (1);
		SDL_RenderPresent(win->rendr);
		SDL_DestroyTexture(win->texture);
	}
	return (0);
}
