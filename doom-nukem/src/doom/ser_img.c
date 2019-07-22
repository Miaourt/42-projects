/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ser_img.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llaporte <llaporte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/02 14:17:05 by tcourtil          #+#    #+#             */
/*   Updated: 2019/05/06 02:18:29 by llaporte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doom.h"

int			write_img(int fd, t_img *img)
{
	int	x;
	int	y;

	y = 0;
	if (!write_int(fd, img->width))
		return (0);
	if (!write_int(fd, img->height))
		return (0);
	if (!write_str(fd, img->name))
		return (0);
	while (y < img->height)
	{
		x = 0;
		while (x < img->width)
		{
			if (!write_int(fd, img->data[x + (y * img->width)]))
				return (0);
			x++;
		}
		y++;
	}
	return (1);
}

t_img		*read_img(int fd)
{
	int		x;
	int		y;
	t_img	*img;

	if (!(img = (t_img *)ft_memalloc(sizeof(t_img))))
		return (NULL);
	y = -1;
	img->width = read_int(fd);
	img->height = read_int(fd);
	img->name = read_str(fd);
	if (!(img->data = (int *)ft_memalloc(
					sizeof(int) * img->width * img->height)))
	{
		free(img);
		return (NULL);
	}
	while (++y < img->height)
	{
		x = -1;
		while (++x < img->width)
			img->data[x + (y * img->width)] = read_int(fd);
	}
	return (img);
}

int			write_arrayimg(int fd, t_array *a)
{
	unsigned int	i;

	i = 0;
	if (!write_int(fd, (int)a->length))
		return (0);
	while (i < a->length)
	{
		if (!write_img(fd, ft_arrayget(a, i)))
			return (0);
		i++;
	}
	return (1);
}

t_array		*read_arrayimg(int fd)
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
		ft_arrayadd(a, read_img(fd));
		i++;
	}
	return (a);
}
