/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llaporte <llaporte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/03 14:17:05 by llaporte          #+#    #+#             */
/*   Updated: 2019/05/08 13:44:20 by tcourtil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doom.h"

int				file_exist(char *filepath)
{
	int fd;

	fd = open(filepath, O_RDWR);
	if (fd == -1)
	{
		close(fd);
		return (0);
	}
	close(fd);
	return (1);
}

static t_img	*ferr(t_img **img)
{
	free(*img);
	*img = NULL;
	ft_printf("error on load image!");
	return (NULL);
}

t_img			*load_texture(char *path)
{
	char		*buffer;
	t_img		*texture;
	size_t		size;
	int			fd;

	texture = ft_memalloc(sizeof(t_img));
	buffer = ft_strnew(8);
	fd = open(path, O_RDONLY);
	read(fd, buffer, 8);
	size = *((int *)(&buffer[0x2]));
	free(buffer);
	close(fd);
	buffer = ft_strnew(size);
	read((fd = open(path, O_RDONLY)), buffer, size);
	texture->width = *(int*)&(buffer[0x12]);
	texture->height = *(int*)&(buffer[0x16]);
	if (!(texture->data = ft_memalloc((texture->width * texture->height)
		* (sizeof(int)))))
		return (ferr(&texture));
	ft_memcpy(texture->data, &buffer[(int)buffer[0xA]],
			texture->width * texture->height * 4);
	texture->name = ft_strdup(path);
	free(buffer);
	close(fd);
	return (texture);
}
