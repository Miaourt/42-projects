/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   edit_settings.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llaporte <llaporte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/05 15:01:01 by llaporte          #+#    #+#             */
/*   Updated: 2019/05/14 16:08:32 by tcourtil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "editor.h"
#include "doom.h"

int			new_value(t_ed *ed, char **str)
{
	int	id;

	if (str[0] && ft_isdigit(str[0][0]) && str[1] && ft_isdigit(str[1][0]))
	{
		id = ft_atoi(str[0]);
		if (id == 1)
			ed->config.nb_taxes = ft_atoi(str[1]);
		else if (id == 2)
			ed->config.money = ft_atoi(str[1]);
		else if (id == 3)
			ed->config.prix = ft_atoi(str[1]);
		else if (id == 4)
			ed->config.time_jacket = ft_atoi(str[1]);
		else if (id == 5)
			ed->config.max_life = ft_atoi(str[1]);
		else if (id == 6)
			ed->config.damage = ft_atoi(str[1]);
		else
			ft_putendl("No setting at this ID!");
	}
	else
		ft_putendl("Impossible to extract setting edit data from command!");
	free_split(str);
	return (0);
}

int			edit_settings(t_ed *ed)
{
	ft_strdel(&(ed->line));
	ft_printf("[1] taxes : %d\n[2] money : %d\n[3] cost : %d\n[4] jackettime : \
%d\n[5] life : %d\n[6] damage : %d\nYou can edit by typing : \"<ID>,<va\
lue>\"\n->$ ", ed->config.nb_taxes, ed->config.money, ed->config.prix,
		ed->config.time_jacket, ed->config.max_life, ed->config.damage);
	while ((ed->i = get_next_line(0, &ed->line)) > 0)
	{
		if (ft_strcmp("exit", ed->line) == 0)
		{
			ft_strdel(&(ed->line));
			return (0);
		}
		if (new_value(ed, ft_strsplit(ed->line, ',')))
			return (errf("Error while editing a setting value", &(ed->line)));
		ft_printf("[1] taxes : %d\n[2] money : %d\n[3] cost : %d\n[4] jackettim\
e : %d\n[5] life : %d\n[6] damage : %d\nYou can edit by typing : \"<ID>,<va\
lue>\"\n->$ ", ed->config.nb_taxes, ed->config.money, ed->config.prix,
		ed->config.time_jacket, ed->config.max_life, ed->config.damage);
		ft_strdel(&(ed->line));
	}
	if (ed->i <= 0 || ed->i == EOF)
		return (errf("gnl error", NULL));
	return (0);
}
