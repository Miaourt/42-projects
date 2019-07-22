/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coin_anim.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcourtil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/15 14:43:41 by tcourtil          #+#    #+#             */
/*   Updated: 2019/05/15 15:04:03 by tcourtil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doom.h"

void	coinmove(t_win *win, t_ent *ent)
{
	if (ent->lifetime % 2 == 0)
	{
		if (ent->id == 13)
			ent->i1 = 1;
		if (ent->id == 10)
			ent->i1 = 0;
		ent->id += ent->i1 ? -1 : 1;
	}
	if (ent->lifetime > 20)
		ent->id = -1;
	if (win)
		return ;
}
