/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ser_str.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llaporte <llaporte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/02 14:17:05 by tcourtil          #+#    #+#             */
/*   Updated: 2019/05/06 02:18:29 by llaporte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doom.h"

int			write_str(int fd, char *l)
{
	int		s;

	s = ft_strlen(l);
	if (!write_int(fd, s))
		return (0);
	write(fd, l, s);
	return (1);
}

char		*read_str(int fd)
{
	int		s;
	char	*l;

	s = read_int(fd);
	if (!(l = ft_strnew(s)))
		return (NULL);
	read(fd, l, s);
	return (l);
}
