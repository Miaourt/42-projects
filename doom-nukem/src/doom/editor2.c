/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   editor2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: groberto <groberto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/06 17:45:18 by groberto          #+#    #+#             */
/*   Updated: 2019/05/14 15:35:40 by tcourtil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "editor.h"
#include "doom.h"

int				add_t(t_array *a, char *file)
{
	t_img	*img;

	if (!file_exist(file))
		return (1);
	if (!(img = load_texture(file)))
		return (1);
	ft_arrayadd(a, img);
	return (0);
}

int				arial_tex(int fd)
{
	t_img	*img;

	if (!file_exist("assets/arial.bmp"))
		return (0);
	if (!(img = load_texture("assets/arial.bmp")))
		return (0);
	if (!write_img(fd, img))
	{
		free_img(&img);
		return (0);
	}
	free_img(&img);
	return (1);
}

int				uigilet_tex(int fd)
{
	t_img	*img;

	if (!file_exist("assets/uigilet.bmp"))
		return (0);
	if (!(img = load_texture("assets/uigilet.bmp")))
		return (0);
	if (!write_img(fd, img))
	{
		free_img(&img);
		return (0);
	}
	free_img(&img);
	return (1);
}

int				eterr(t_array *a)
{
	free_textures(a);
	return (0);
}

int				ceil_tex(int fd)
{
	t_img	*img;

	if (!file_exist("assets/ceil.bmp"))
		return (0);
	if (!(img = load_texture("assets/ceil.bmp")))
		return (0);
	if (!write_img(fd, img))
	{
		free_img(&img);
		return (0);
	}
	free_img(&img);
	return (1);
}
