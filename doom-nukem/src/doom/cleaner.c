/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleaner.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llaporte <llaporte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/29 15:03:20 by tcourtil          #+#    #+#             */
/*   Updated: 2019/05/06 14:34:36 by tcourtil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doom.h"

void	free_split(char **str)
{
	int	id;

	id = 0;
	while (str[id])
	{
		free(str[id]);
		id++;
	}
	free(str);
}

void	free_entity(unsigned int i, void *content, void *p)
{
	t_ent *e;

	e = (t_ent *)content;
	free(e->pos);
	if (i == 1 && p)
		return ;
}

void	free_thread(t_win *win)
{
	int		i;
	t_data	**l;

	i = 0;
	l = (t_data **)win->data;
	if (!l)
		return ;
	while (i < NB_TH)
	{
		if (l[i]->dist)
			free(l[i]->dist);
		if (l[i]->color)
			free(l[i]->color);
		free(l[i]);
		i++;
	}
	free(l);
	free(win->thread);
}

void	free_textures(t_array *a)
{
	unsigned int	i;
	t_img			*img;

	i = 0;
	if (!a)
		return ;
	while (i < a->length)
	{
		img = (t_img *)ft_arrayget(a, i);
		if (img && img->data)
			free(img->data);
		if (img && img->name)
			free(img->name);
		i++;
	}
	ft_arrayfree(a);
}

int		clean_wolf(t_win *win)
{
	free_world(&(win->world));
	free_img(&(win->floor));
	free_img(&(win->ceil));
	free_img(&(win->arial));
	free_img(&(win->uigilet));
	free(win->dist);
	free_textures(win->textures);
	free_textures(win->enttexture);
	free_thread(win);
	if (win->entdata)
		ft_arrayfree(win->entdata);
	if (win->entity)
		ft_arrayfor(win->entity, free_entity, win);
	ft_arrayfree(win->entity);
	return (0);
}
