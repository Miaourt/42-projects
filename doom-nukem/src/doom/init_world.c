/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_world.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llaporte <llaporte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/04 13:21:39 by tcourtil          #+#    #+#             */
/*   Updated: 2019/05/06 02:18:29 by llaporte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doom.h"

t_cam		*init_cam(void)
{
	t_cam	*c;

	if (!(c = (t_cam *)malloc(sizeof(t_cam))))
		return (NULL);
	c->x = 1.5;
	c->y = 0;
	c->z = 1.5;
	c->roty = 0;
	c->rot = 0;
	return (c);
}

int			init_map(t_world *w, int sx, int sy)
{
	int		i;
	int		j;

	i = 0;
	if (!(w->map = (int **)ft_memalloc(sy * sizeof(int *))))
		return (0);
	while (i < sy)
	{
		j = -1;
		if (!(w->map[i] = (int *)ft_memalloc(sx * sizeof(int))))
			return (0);
		while (++j < sx)
			w->map[i][j] = 0;
		i++;
	}
	return (1);
}

t_world		*init_world(int sx, int sy)
{
	t_world *w;

	w = (t_world *)malloc(sizeof(t_world));
	if (!w)
		return (NULL);
	if (!init_map(w, sx, sy))
		return (NULL);
	if (!(w->cam = init_cam()))
		return (NULL);
	w->width = sx;
	w->height = sy;
	return (w);
}
