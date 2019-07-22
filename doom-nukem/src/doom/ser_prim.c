/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ser_prim.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llaporte <llaporte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/02 14:17:05 by tcourtil          #+#    #+#             */
/*   Updated: 2019/05/06 02:18:29 by llaporte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doom.h"

int			write_int(int fd, int nb)
{
	char	*tmp;
	int		n;

	n = nb;
	tmp = (char *)&n;
	return (write(fd, tmp, 4) == 4);
}

int			read_int(int fd)
{
	int		nb;
	char	buf[4];

	if (read(fd, buf, 4) != 4)
		return (0);
	nb = *((int *)buf);
	return (nb);
}

int			write_double(int fd, double nb)
{
	char	*tmp;
	double	n;

	n = nb;
	tmp = (char *)&n;
	return (write(fd, tmp, 8) == 8);
}

double		read_double(int fd)
{
	double	nb;
	char	buf[8];

	if (read(fd, buf, 8) != 8)
		return (0);
	nb = *((double *)buf);
	return (nb);
}
