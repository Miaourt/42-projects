/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   editor_config.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcourtil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/14 15:37:54 by tcourtil          #+#    #+#             */
/*   Updated: 2019/05/14 15:57:11 by tcourtil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doom.h"
#include "editor.h"

void	ed_init_config(t_ed *ed)
{
	ed->config.nb_taxes = 4;
	ed->config.money = 1500;
	ed->config.prix = 300;
	ed->config.time_jacket = 200;
	ed->config.max_life = 100;
	ed->config.damage = 25;
}

int		ed_save_config(int fd, t_ed *ed)
{
	if (!write_int(fd, ed->config.nb_taxes))
		return (1);
	if (!write_int(fd, ed->config.money))
		return (1);
	if (!write_int(fd, ed->config.prix))
		return (1);
	if (!write_int(fd, ed->config.time_jacket))
		return (1);
	if (!write_int(fd, ed->config.max_life))
		return (1);
	if (!write_int(fd, ed->config.damage))
		return (1);
	return (0);
}
