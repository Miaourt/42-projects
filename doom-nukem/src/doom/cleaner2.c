/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleaner2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llaporte <llaporte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/29 15:03:20 by tcourtil          #+#    #+#             */
/*   Updated: 2019/05/06 02:18:29 by llaporte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doom.h"

void	free_world(t_world **world)
{
	int	i;

	i = 0;
	if (!*world)
		return ;
	free((*world)->cam);
	while (i < (*world)->height)
	{
		free((*world)->map[i]);
		i++;
	}
	free((*world)->map);
	free((*world));
}

void	free_img(t_img **img)
{
	if (img && *img)
	{
		free((*img)->data);
		free((*img)->name);
		free(*img);
		*img = NULL;
	}
}

void	free_sdl(t_win *win)
{
	SDL_DestroyTexture(win->texture);
	SDL_FreeSurface(win->surf);
	SDL_DestroyRenderer(win->rendr);
	SDL_DestroyWindow(win->win);
	SDL_Quit();
}
