/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ser_world.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llaporte <llaporte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/02 14:17:05 by tcourtil          #+#    #+#             */
/*   Updated: 2019/05/06 02:18:29 by llaporte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doom.h"

int				write_cam(int fd, t_cam *cam)
{
	if (!write_double(fd, cam->x))
		return (0);
	if (!write_double(fd, cam->z))
		return (0);
	return (1);
}

int				write_world(int fd, t_world *w)
{
	int	y;
	int	x;

	if (!write_cam(fd, w->cam))
		return (0);
	if (!write_int(fd, w->height))
		return (0);
	if (!write_int(fd, w->width))
		return (0);
	y = 0;
	while (y < w->height)
	{
		x = 0;
		while (x < w->width)
		{
			if (!write_int(fd, w->map[y][x]))
				return (0);
			x++;
		}
		y++;
	}
	return (1);
}

t_cam			*read_cam(int fd)
{
	t_cam *cam;

	if (!(cam = (t_cam *)ft_memalloc(sizeof(t_cam))))
		return (NULL);
	cam->x = read_double(fd);
	cam->z = read_double(fd);
	return (cam);
}

static t_world	*twerr(t_world **w)
{
	free_world(w);
	return (NULL);
}

t_world			*read_world(int fd)
{
	t_world *w;
	int		y;
	int		x;

	if (!(w = (t_world *)ft_memalloc(sizeof(t_world))))
		return (NULL);
	if (!(w->cam = read_cam(fd)))
		return (twerr(&w));
	w->height = read_int(fd);
	w->width = read_int(fd);
	if (!init_map(w, w->width, w->height))
		return (twerr(&w));
	y = 0;
	while (y < w->height)
	{
		x = 0;
		while (x < w->width)
		{
			w->map[y][x] = read_int(fd);
			x++;
		}
		y++;
	}
	return (w);
}
