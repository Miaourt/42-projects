/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_editor.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llaporte <llaporte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/29 13:04:45 by llaporte          #+#    #+#             */
/*   Updated: 2019/05/08 13:17:23 by tcourtil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "editor.h"
#include "doom.h"

int			list_texture(t_ed *ed)
{
	unsigned int	i;

	i = 0;
	ft_printf("There is currently %d textures loaded :\n"
		, ed->textures->length);
	while (i < ed->textures->length)
	{
		ft_printf("[%d] %s\n", i + 1,
			((t_img *)ft_arrayget(ed->textures, i))->name);
		++i;
	}
	return (0);
}

int			new_texture(t_ed *ed)
{
	ft_strdel(&(ed->line));
	ft_putstr("Enter the texture path\n(Currently only BMP 32bit) :\n->$ ");
	get_next_line(0, &ed->line);
	if (ft_strcmp("exit", ed->line) == 0)
		return (0);
	if (file_exist(ed->line))
	{
		ft_arrayadd(ed->textures, load_texture(ed->line));
		ft_printf("\nNew texture added ! The ID is %d.", ed->textures->length);
		return (0);
	}
	return (0);
}

int			delete_texture(t_ed *ed)
{
	unsigned int	id;

	ft_strdel(&(ed->line));
	ft_putstr("Enter the ID of the texture to remove\
		\n(You can see IDs with the command \"list\") :\n->$ ");
	get_next_line(0, &ed->line);
	if (ft_isdigit(ed->line[0]))
	{
		id = ft_atoi(ed->line);
		if (id > 0 && id - 1 < ed->textures->length)
		{
			id--;
			free(((t_img *)ft_arrayget(ed->textures, id))->name);
			free(((t_img *)ft_arrayget(ed->textures, id))->data);
			free(ft_arrayget(ed->textures, id));
			ft_arrayrem(ed->textures, id);
			ft_putstr("Texture successfully removed !\nExiting.");
			return (0);
		}
		ft_putstr("There's no textures having this ID.\nExiting.");
	}
	else
		ft_putstr("You entered a wrong ID.\nExiting.");
	return (0);
}

int			edit_texture(t_ed *ed)
{
	int	i;

	signal(SIGINT, inthandler);
	ft_strdel(&(ed->line));
	ft_putstr("[T. editor]\nYou can :\n new\n del\n list\n->$ ");
	while ((i = get_next_line(0, &ed->line)) > 0)
	{
		if (ed->line && ft_strcmp("new", ed->line) == 0)
			if (new_texture(ed))
				return (errf("Error while adding textures", &(ed->line)));
		if (ed->line && ft_strcmp("del", ed->line) == 0)
			if (delete_texture(ed))
				return (errf("Error while deleting textures", &(ed->line)));
		if (ed->line && ft_strcmp("list", ed->line) == 0)
			if (list_texture(ed))
				return (errf("Error while listing textures", &(ed->line)));
		if (ed->line && ft_strcmp("exit", ed->line) == 0)
			return (0);
		ft_putstr("\n[T. editor]\nYou can :\n new\n del\n list\n->$ ");
		ft_strdel(&(ed->line));
	}
	if (i <= 0 || i == EOF)
		return (errf("GNL error", &(ed->line)));
	ft_strdel(&(ed->line));
	return (0);
}
