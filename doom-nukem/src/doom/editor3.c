/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   editor3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: groberto <groberto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/06 17:45:26 by groberto          #+#    #+#             */
/*   Updated: 2019/05/14 15:35:47 by tcourtil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "editor.h"
#include "doom.h"

int				can_save(t_ed *ed)
{
	int	max;
	int	x;
	int	y;

	if (!ed->world)
		return (0);
	y = 0;
	max = 0;
	while (y < ed->world->height)
	{
		x = 0;
		while (x < ed->world->width)
		{
			if (ed->world->map[y][x] > max)
				max = ed->world->map[y][x];
			x++;
		}
		y++;
	}
	return (ed->textures->length >= (unsigned int)max);
}

int				floor_tex(int fd)
{
	t_img	*img;

	if (!file_exist("assets/floor.bmp"))
		return (0);
	if (!(img = load_texture("assets/floor.bmp")))
		return (0);
	if (!write_img(fd, img))
	{
		free_img(&img);
		return (0);
	}
	free_img(&img);
	return (1);
}

int				gameover_tex(int fd)
{
	t_img	*img;

	if (!file_exist("assets/gameover.bmp"))
		return (0);
	if (!(img = load_texture("assets/gameover.bmp")))
		return (0);
	if (!write_img(fd, img))
	{
		free_img(&img);
		return (0);
	}
	free_img(&img);
	return (1);
}

int				gamewin_tex(int fd)
{
	t_img	*img;

	if (!file_exist("assets/wingame.bmp"))
		return (0);
	if (!(img = load_texture("assets/wingame.bmp")))
		return (0);
	if (!write_img(fd, img))
	{
		free_img(&img);
		return (0);
	}
	free_img(&img);
	return (1);
}

int				errf(const char *msg, char **buff)
{
	ft_strdel(buff);
	return (err(msg));
}
