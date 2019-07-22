/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   editor_spawn.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llaporte <llaporte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/05 17:01:01 by llaporte          #+#    #+#             */
/*   Updated: 2019/05/06 17:46:06 by tcourtil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "editor.h"
#include "doom.h"

int		set_spawn(t_ed *ed, char **str)
{
	int y;
	int x;

	if (!ed->world)
		return (0);
	if (str[0] && ft_isdigit(str[0][0]) && str[1] && ft_isdigit(str[1][0]))
	{
		y = ft_atoi(str[1]);
		x = ft_atoi(str[0]);
		if (y >= 0 && y < ed->world->height && x >= 0 && x < ed->world->width
				&& ed->world->map[y][x] == 0)
		{
			ed->world->cam->x = x + 0.5;
			ed->world->cam->z = y + 0.5;
			ft_putendl("Spawnpoint successfully set!");
		}
		else
			ft_putendl("Positions are out of bound!");
	}
	else
		ft_putendl("Impossible to extract cell edit data from command!");
	free_split(str);
	return (0);
}

int		edit_spawn(t_ed *ed)
{
	ft_strdel(&(ed->line));
	print_map(ed);
	ft_putendl("\nEnter spawn coordinates : \"<x>,<y>\"");
	get_next_line(0, &ed->line);
	if (ft_strcmp("exit", ed->line) == 0)
	{
		ft_strdel(&(ed->line));
		return (0);
	}
	if (set_spawn(ed, ft_strsplit(ed->line, ',')))
		return (errf("Error while editing a cell.", &(ed->line)));
	ft_strdel(&(ed->line));
	return (0);
}
