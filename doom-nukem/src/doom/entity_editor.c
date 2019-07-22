/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   entity_editor.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: groberto <groberto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/05 15:01:01 by llaporte          #+#    #+#             */
/*   Updated: 2019/05/15 15:19:37 by groberto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "editor.h"
#include "doom.h"

int			list_entity(t_ed *ed)
{
	unsigned int	i;
	t_ent			*ent;

	i = 0;
	ft_printf("There is currently %d entities :\n"
		, ed->entities->length);
	while (i < ed->entities->length)
	{
		ent = ft_arrayget(ed->entities, i);
		ft_printf("[%d] %.0lf/%.0lf %d\n", i + 1, ent->pos->x, ent->pos->z
			, ent->id);
		++i;
	}
	return (0);
}

static int	addentity(t_ed *ed, char **str)
{
	int				y;
	int				x;
	unsigned int	id;

	if (str[0] && ft_isdigit(str[0][0]) && str[1] && ft_isdigit(str[1][0])
		&& str[2] && ft_isdigit(str[2][0]))
	{
		y = ft_atoi(str[1]);
		x = ft_atoi(str[0]);
		if (y >= 0 && y < ed->world->height && x >= 0 && x < ed->world->width)
		{
			id = ft_atoi(str[2]);
			if (id <= 14)
				ft_arrayadd(ed->entities, entitynew(x + 0.5, y + 0.5, 3, id));
			else
				ft_putendl("There is no textures at this ID!");
		}
		else
			ft_putendl("Positions are out of bound!");
	}
	else
		ft_putendl("Impossible to extract data from command!");
	free_split(str);
	return (0);
}

int			new_entity(t_ed *ed)
{
	ft_strdel(&(ed->line));
	ft_putstr("x,y,id:\n->$ ");
	get_next_line(0, &ed->line);
	if (ft_strcmp("exit", ed->line) == 0)
		return (0);
	if (addentity(ed, ft_strsplit(ed->line, ',')))
		return (errf("Error while addind an entity.", &ed->line));
	ft_strdel(&(ed->line));
	ft_printf("\nNew entity added !");
	return (0);
}

int			delete_entity(t_ed *ed)
{
	unsigned int	id;

	ft_strdel(&(ed->line));
	ft_putstr("Enter the ID of the entity to remove\
		\n(You can see IDs with the command \"list\") :\n->$ ");
	get_next_line(0, &ed->line);
	if (ft_isdigit(ed->line[0]) && ed->line[0] != '0')
	{
		id = ft_atoi(ed->line) - 1;
		if (id < ed->entities->length)
		{
			free_entity(0, (t_ent *)(ft_arrayget(ed->entities, id)), NULL);
			free(ft_arrayget(ed->entities, id));
			ft_arrayrem(ed->entities, id);
			ft_putstr("Entity successfully removed !\nExiting.");
			return (0);
		}
		ft_putstr("There's no textures having this ID.\nExiting.");
	}
	else
		ft_putstr("You entered a wrong ID.\nExiting.");
	return (0);
}

int			edit_entity(t_ed *ed)
{
	int	i;

	signal(SIGINT, inthandler);
	ft_strdel(&(ed->line));
	ft_putstr("[E. editor]\nYou can :\n new\n del\n list\n->$ ");
	while ((i = get_next_line(0, &ed->line)) > 0)
	{
		if (ed->line && ft_strcmp("new", ed->line) == 0)
			if (new_entity(ed))
				return (errf("Error while adding entity", &(ed->line)));
		if (ed->line && ft_strcmp("del", ed->line) == 0)
			if (delete_entity(ed))
				return (errf("Error while deleting entity", &(ed->line)));
		if (ed->line && ft_strcmp("list", ed->line) == 0)
			if (list_entity(ed))
				return (errf("Error while listing entities", &(ed->line)));
		if (ed->line && ft_strcmp("exit", ed->line) == 0)
			return (0);
		ft_putstr("\n[E. editor]\nYou can :\n new\n del\n list\n->$ ");
		ft_strdel(&(ed->line));
	}
	if (i <= 0 || i == EOF)
		return (errf("GNL error", &(ed->line)));
	ft_strdel(&(ed->line));
	return (0);
}
