/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   editor4.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llaporte <llaporte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/06 17:46:12 by groberto          #+#    #+#             */
/*   Updated: 2019/05/14 15:47:10 by tcourtil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "editor.h"
#include "doom.h"

int			editor(char *path)
{
	t_ed	ed;
	int		res;

	if (!file_exist(path))
	{
		ft_bzero(&ed, sizeof(t_ed));
		ed.path = path;
		ed.textures = ft_arraynew();
		ed.entities = ft_arraynew();
		ed_init_config(&ed);
		res = editor_shell(&ed);
		free_world(&(ed.world));
		free_textures(ed.textures);
		if (ed.entities)
			ft_arrayfor(ed.entities, free_entity, NULL);
		ft_arrayfree(ed.entities);
		ft_strdel(&(ed.line));
		return (res);
	}
	else
		err("Error, a file is present.\nUsage : wolf3d -e <output path>");
	return (0);
}

int			editor_shell2(t_ed *ed)
{
	if (ed->line && ft_strequ("6", ed->line))
	{
		if (!(ed->flag_min && can_save(ed)))
			ft_putendl("can't save without a valid map");
		else
		{
			if (editor_save(ed))
				return (errf("Failed to save the map", &(ed->line)));
		}
	}
	if (ed->line && ft_strcmp("1", ed->line) == 0)
	{
		if (edit_texture(ed))
			return (errf("Error in textures editor", &(ed->line)));
	}
	if (ed->line && ft_strcmp("2", ed->line) == 0)
	{
		if (edit_map(ed))
			return (errf("Error in map editor", &(ed->line)));
		ed->flag_min = 1;
	}
	return (0);
}

int			editor_shell3(t_ed *ed)
{
	if (ed->line && ed->world && ft_strcmp("3", ed->line) == 0)
		if (edit_entity(ed))
			return (errf("Error in entity editor", &(ed->line)));
	if (ed->line && ed->world && ft_strcmp("4", ed->line) == 0)
	{
		if (!(ed->flag_min))
			ft_putendl("Can't set spawnpoint without a map");
		else
		{
			if (edit_spawn(ed))
				return (errf("Failed to set the spawn", &(ed->line)));
		}
	}
	return (0);
}

int			editor_shell4(t_ed *ed)
{
	if (ed->line && ft_strcmp("5", ed->line) == 0)
		if (edit_settings(ed))
			return (errf("Error in entity editor", &(ed->line)));
	ft_putstr("[Editor]\nYou can :\n [1] edit textures\n [2] edit map\
			\n [3] edit entity\n [4] set spawn\n [5] edit settings\n [6] save\
			\n [7] exit\n->$ ");
	return (0);
}

int			editor_shell(t_ed *ed)
{
	int i;

	ft_putstr("[Editor]\nYou can :\n [1] edit textures\n [2] edit map\
			\n [3] edit entity\n [4] set spawn\n [5] edit settings\n [6] save\
			\n [7] exit\n->$ ");
	i = 0;
	signal(SIGINT, inthandler);
	ed->flag_min = 0;
	while ((i = get_next_line(0, &ed->line)) > 0)
	{
		if (ed->line && ft_strequ("7", ed->line))
		{
			ft_strdel(&(ed->line));
			return (0);
		}
		editor_shell2(ed);
		editor_shell3(ed);
		editor_shell4(ed);
		ft_strdel(&(ed->line));
	}
	if (i <= 0)
		errf("gnl error", NULL);
	ft_strdel(&(ed->line));
	return (0);
}
