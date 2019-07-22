/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llaporte <llaporte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/12 17:28:58 by llaporte          #+#    #+#             */
/*   Updated: 2017/02/20 15:31:36 by llaporte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdlib.h>

static int	nb_of_word(char const *s, char c)
{
	int		t_len;
	int		i;

	i = 0;
	t_len = 0;
	while (s[i])
	{
		while (s[i] == c && s[i])
			i++;
		if (s[i] != c && s[i])
			t_len++;
		while (s[i] != c && s[i])
			i++;
	}
	return (t_len);
}

static int	map_y(char *file, t_data_fdf *dt)
{
	int		fd;
	char	*tmp;

	if ((fd = open(file, O_RDONLY)) == -1)
		err("Open failed.\n");
	dt->map_y = 0;
	while (ft_gnl(fd, &tmp))
		++dt->map_y;
	if (dt->map_y < 1)
		err("Empty file.\n");
	return (fd);
}

static int	map_x(char *file, t_data_fdf *dt)
{
	int		fd;
	char	*tmp;

	if ((fd = open(file, O_RDONLY)) == -1)
		err("Open failed.\n");
	dt->map_x = -1;
	while (ft_gnl(fd, &tmp))
	{
		if (dt->map_x == -1)
			dt->map_x = nb_of_word(tmp, ' ');
		if (nb_of_word(tmp, ' ') != dt->map_x)
			err("Map is wrong.\n");
	}
	return (fd);
}

static int	gen_map(char *file, t_data_fdf *dt)
{
	int		fd;
	int		i;
	char	*tmp;

	if (!(dt->fdf_map = (char ***)ft_memalloc(sizeof(char **)
		* (dt->map_y + 1))))
		err("ft_memalloc of fdf_map failed.\n");
	if ((fd = open(file, O_RDONLY)) == -1)
		err("Open failed.\n");
	i = 0;
	while (ft_gnl(fd, &tmp))
	{
		if (!(dt->fdf_map[i++] = ft_strsplit(tmp, ' ')))
			err("ft_strsplit failed.\n");
	}
	return (fd);
}

void		parser(char *file, t_data_fdf *dt)
{
	int	toclose1;
	int	toclose2;
	int	toclose3;

	toclose1 = map_y(file, dt);
	toclose2 = map_x(file, dt);
	toclose3 = gen_map(file, dt);
	if ((close(toclose1) == -1))
		err("Close1 failed.\n");
	if ((close(toclose2) == -1))
		err("Close1 failed.\n");
	if ((close(toclose3) == -1))
		err("Close1 failed.\n");
}
