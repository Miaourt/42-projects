/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llaporte <llaporte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/28 15:42:21 by tcourtil          #+#    #+#             */
/*   Updated: 2019/05/06 18:59:45 by tcourtil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doom.h"

int		fog(int c, double fac, double dist)
{
	int		res;
	double	tmp;

	tmp = fmin(dist, 1500);
	tmp *= fmin(fac, 1);
	tmp /= 1500;
	res = c;
	res = lerp(c, 0x00222222, tmp);
	return (res);
}

void	*run(void *arg)
{
	int		i;
	t_data	*data;

	data = (t_data *)arg;
	i = 0;
	while (i < data->len)
	{
		render_wall(data, i + data->x);
		i++;
	}
	return (NULL);
}

void	display(t_data *data)
{
	int		x;
	int		y;
	int		id;

	x = 0;
	while (x < data->len)
	{
		y = 0;
		while (y < data->win->height)
		{
			id = (x * data->win->height) + y;
			draw_pixel(x + data->x, y, data->win, data->color[id]);
			data->win->dist[((x + data->x) * data->win->height) + y] =
				data->dist[id];
			y++;
		}
		x++;
	}
}

int		render(t_win *win)
{
	t_data	**data;
	int		i;

	data = (t_data **)win->data;
	i = 0;
	while (i < NB_TH)
	{
		if (pthread_create(&(win->thread[i]), NULL, run, data[i]) == -1)
			return (err("Error creating the threads."));
		i++;
	}
	i = 0;
	while (i < NB_TH)
	{
		if (pthread_join(win->thread[i], NULL))
			return (err("Error joining the threads."));
		display(data[i]);
		i++;
	}
	rendersprite(win);
	render_ui(win);
	return (0);
}
