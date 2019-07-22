/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_render.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llaporte <llaporte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/28 15:42:21 by tcourtil          #+#    #+#             */
/*   Updated: 2019/05/06 02:18:29 by llaporte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doom.h"

static int	init_datat(t_win *win, t_data **data)
{
	int		i;

	i = -1;
	while (++i < NB_TH)
	{
		if (!(data[i] = (t_data*)ft_memalloc(sizeof(t_data))))
			return (1);
		data[i]->id = i;
		data[i]->win = win;
		data[i]->len = i == NB_TH - 1 ? win->width - (win->width / NB_TH) *
			(NB_TH - 1) : win->width / NB_TH;
		data[i]->x = (win->width / NB_TH) * i;
		data[i]->dist = (double *)ft_memalloc(sizeof(double) * data[i]->len *
				win->height);
		data[i]->color = (int *)ft_memalloc(sizeof(int) * data[i]->len *
				win->height);
	}
	return (0);
}

int			init_data(t_win *win)
{
	t_data	**data;

	if (!(data = (t_data **)ft_memalloc(sizeof(t_data *) * NB_TH)))
		return (1);
	if (!(win->thread = (pthread_t *)ft_memalloc(sizeof(pthread_t) * NB_TH)))
		return (1);
	init_datat(win, data);
	if (!(win->dist = (double *)ft_memalloc(sizeof(double) * win->width *
					win->height)))
		return (1);
	win->data = data;
	return (0);
}
