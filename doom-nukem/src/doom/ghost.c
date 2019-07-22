/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ghost.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llaporte <llaporte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/02 14:17:05 by tcourtil          #+#    #+#             */
/*   Updated: 2019/05/15 14:43:18 by tcourtil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doom.h"

void		ghosttrigger(t_win *win, t_ent *ent)
{
	win->player.life -= win->cf_damage;
	ent->pos->x = sin(ent->lifetime) * 123456;
	ent->pos->x = ent->pos->x - floor(ent->pos->x);
	ent->pos->x *= win->world->width * 2;
	ent->pos->z = sin(ent->lifetime + 1) * 123456;
	ent->pos->z = ent->pos->z - floor(ent->pos->z);
	ent->pos->z *= win->world->height * 2;
	if (win && ent)
		return ;
}

static void	gmove(t_win *win, double ang, t_vec4 *dir)
{
	if (comrad(win->world->cam->rot + M_PI, ang - (M_PI / 25),
				ang + (M_PI / 25)))
	{
		dir->x *= 0.3 * (win->player.giletjaune > 0 ? -1 : 1);
		dir->z *= 0.3 * (win->player.giletjaune > 0 ? -1 : 1);
	}
	else if (comrad(win->world->cam->rot + M_PI, ang - (M_PI / 2),
				ang + (M_PI / 2)))
	{
		dir->x *= -0.0025;
		dir->z *= -0.0025;
	}
	else
	{
		dir->x *= 0.025;
		dir->z *= 0.025;
	}
}

void		ghostmove(t_win *win, t_ent *ent)
{
	t_vec4	dir;
	double	dist;
	double	ang;

	dir.x = ent->pos->x - win->world->cam->x;
	dir.z = ent->pos->z - win->world->cam->z;
	dist = sqrt(dir.x * dir.x + dir.z * dir.z);
	dir.x /= dist;
	dir.z /= dist;
	ang = atan2(win->world->cam->z - ent->pos->z,
			win->world->cam->x - ent->pos->x);
	gmove(win, ang, &dir);
	ent->pos->x -= dir.x;
	ent->pos->z -= dir.z;
	if (ent->lifetime % 5 == 0)
	{
		ent->id++;
		if (ent->id == 5)
			ent->id = 1;
	}
}
