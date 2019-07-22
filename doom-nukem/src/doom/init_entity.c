/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_entity.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: groberto <groberto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/02 14:17:05 by tcourtil          #+#    #+#             */
/*   Updated: 2019/05/15 15:12:52 by groberto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doom.h"

int			init_entdata(t_win *win)
{
	if (!(win->entdata = ft_arraynew()))
		return (1);
	if (init_barrel(win))
		return (1);
	if (init_ghost(win))
		return (1);
	if (init_breakbarrel(win))
		return (1);
	if (init_gilet(win))
		return (1);
	if (init_money(win))
		return (1);
	if (init_tax(win))
		return (1);
	if (init_coin(win))
		return (1);
	if (init_jetpack(win))
		return (1);
	return (0);
}
