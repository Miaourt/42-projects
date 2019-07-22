/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ser_ent.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llaporte <llaporte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/02 14:17:05 by tcourtil          #+#    #+#             */
/*   Updated: 2019/05/06 18:37:00 by tcourtil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doom.h"

int			write_ent(int fd, t_ent *ent)
{
	if (!write_int(fd, ent->id))
		return (0);
	if (!write_double(fd, ent->rot))
		return (0);
	if (!write_double(fd, ent->pos->x))
		return (0);
	if (!write_double(fd, ent->pos->z))
		return (0);
	return (1);
}

t_ent		*read_ent(int fd)
{
	int		id;
	double	rot;
	double	x;
	double	z;

	id = read_int(fd);
	rot = read_double(fd);
	x = read_double(fd);
	z = read_double(fd);
	return (entitynew(x, z, rot, id));
}

int			write_arrayent(int fd, t_array *a)
{
	unsigned int	i;

	i = 0;
	if (!write_int(fd, (int)a->length))
		return (0);
	while (i < a->length)
	{
		if (!write_ent(fd, ft_arrayget(a, i)))
			return (0);
		i++;
	}
	return (1);
}

t_array		*read_arrayent(int fd)
{
	t_array			*a;
	unsigned int	i;
	unsigned int	max;

	if (!(a = ft_arraynew()))
		return (NULL);
	max = (unsigned int)read_int(fd);
	i = 0;
	while (i < max)
	{
		ft_arrayadd(a, read_ent(fd));
		i++;
	}
	return (a);
}
