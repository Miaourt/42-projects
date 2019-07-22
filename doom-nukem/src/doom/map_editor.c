/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_editor.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llaporte <llaporte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/29 13:04:45 by llaporte          #+#    #+#             */
/*   Updated: 2019/05/06 19:02:12 by llaporte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "editor.h"
#include "doom.h"

void	print_map(t_ed *ed)
{
	int	y;
	int	x;

	y = 0;
	while (y < ed->world->height)
	{
		x = 0;
		while (x < ed->world->width)
		{
			ft_printf("%d", ed->world->map[y][x]);
			++x;
		}
		ft_putchar('\n');
		++y;
	}
}

int		fill_map(t_ed *ed)
{
	int	y;
	int	x;

	ed->world->map = ft_memalloc(sizeof(int *) * ed->world->height);
	if (!ed->world->map)
		return (1);
	y = 0;
	while (y < ed->world->height)
	{
		x = 0;
		ed->world->map[y] = ft_memalloc(sizeof(int) * ed->world->width);
		while (x < ed->world->width)
		{
			if (y == 0 || y == ed->world->height - 1)
				ed->world->map[y][x] = 1;
			else if (x == 0 || x == ed->world->width - 1)
				ed->world->map[y][x] = 1;
			else
				ed->world->map[y][x] = 0;
			++x;
		}
		++y;
	}
	ed->world->cam = init_cam();
	return (0);
}

int		editor_init_map(t_ed *ed)
{
	ft_putstr("[M. editor]\nInit map.\nEnter height (3-30).\n->$ ");
	ed->world = ft_memalloc(sizeof(t_world));
	if (!ed->world)
		return (1);
	get_next_line(0, &ed->line);
	if (ft_isdigit(ed->line[0]))
	{
		ed->world->height = ft_atoi(ed->line);
		ft_strdel(&(ed->line));
		ft_putstr("\nEnter width (3-30).\n->$ ");
		get_next_line(0, &ed->line);
		if (ft_isdigit(ed->line[0]))
		{
			ed->world->width = ft_atoi(ed->line);
			if (ed->world->height >= 3 && ed->world->height <= 30
				&& ed->world->width >= 3 && ed->world->width <= 30)
				return (fill_map(ed));
		}
	}
	ft_printf("%d,%d\n", ed->world->height, ed->world->width);
	ft_putstr("\nBad input while initializing the map.\nExiting.\n");
	ft_strdel(&(ed->line));
	free(ed->world);
	ed->world = NULL;
	return (0);
}

int		edit_cell(t_ed *ed, char **str)
{
	int				y;
	int				x;
	unsigned int	id;

	if (str[0] && ft_isdigit(str[0][0]) && str[1] && ft_isdigit(str[1][0])
		&& str[2] && ft_isdigit(str[2][0]))
	{
		y = ft_atoi(str[1]) - 1;
		x = ft_atoi(str[0]) - 1;
		if (y >= 0 && y < ed->world->height && x >= 0 && x < ed->world->width)
		{
			id = ft_atoi(str[2]);
			if (id <= ed->textures->length)
				ed->world->map[y + 1][x + 1] = id;
			else
				ft_putendl("There is no textures at this ID!");
		}
		else
			ft_putendl("Positions are out of bound!");
	}
	else
		ft_putendl("Impossible to extract cell edit data from command!");
	free_split(str);
	return (0);
}

int		edit_map(t_ed *ed)
{
	ft_strdel(&(ed->line));
	if (ed->world == NULL && editor_init_map(ed))
		return (errf("Error initializing the map.", &(ed->line)));
	ft_strdel(&(ed->line));
	if (ed->world == NULL)
		return (0);
	print_map(ed);
	ft_putstr("You can edit by typing : \"<x>,<y>,<ID>\"\n->$ ");
	while ((ed->i = get_next_line(0, &ed->line)) > 0)
	{
		if (ft_strcmp("exit", ed->line) == 0)
		{
			ft_strdel(&(ed->line));
			return (0);
		}
		if (edit_cell(ed, ft_strsplit(ed->line, ',')))
			return (errf("Error while editing a cell.", &(ed->line)));
		print_map(ed);
		ft_putstr("You can edit by typing : \"<x>,<y>,<ID>\"\n->$ ");
		ft_strdel(&(ed->line));
	}
	if (ed->i <= 0 || ed->i == EOF)
		return (errf("gnl error", NULL));
	return (0);
}
