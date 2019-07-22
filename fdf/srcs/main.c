/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llaporte <llaporte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/11 15:18:26 by llaporte          #+#    #+#             */
/*   Updated: 2017/02/22 15:23:57 by llaporte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		err(char *err_msg)
{
	ft_putstr(err_msg);
	exit(1);
}

int			hxy(t_data_fdf *dt, int x, int y)
{
	if (x > dt->map_x || x < 0 || y > dt->map_y || y < 0)
		err("hxy only take positions inside the map, not outside");
	return (ft_atoi(dt->fdf_map[y][x]));
}

int			hook_keydown(int key, t_data_fdf *dt)
{
	if (key == 53 || key == 65307)
		exit(0);
	if (key == 87 || key == 65437)
		dt->cm = dt->cm == 1 ? 2 : 1;
	if (key == 69 || key == 65451)
		++dt->sf;
	if ((key == 78 || key == 65453) && dt->sf - 1 > 0)
		--dt->sf;
	if (key == 123 || key == 65361)
		dt->ofx += 20;
	if (key == 124 || key == 65363)
		dt->ofx -= 20;
	if (key == 125 || key == 65364)
		dt->ofy -= 20;
	if (key == 126 || key == 65362)
		dt->ofy += 20;
	if (key == 92 || key == 65434)
		++dt->hg;
	if ((key == 88 || key == 65432) && dt->hg - 1 > 0)
		--dt->hg;
	map_draw(dt);
	return (0);
}

void		mlx_create(t_data_fdf *dt)
{
	if (!(dt->mlx = mlx_init()))
		err("Error init mlx\n");
	dt->win_x = 2048;
	dt->win_y = 1000;
	dt->sf = 20;
	dt->hg = 1;
	dt->cm = 1;
	dt->ofx = dt->win_x / 2;
	dt->ofy = dt->win_y / 8;
	if (!(dt->win = mlx_new_window(dt->mlx, dt->win_x, dt->win_y, "FdF")))
		err("Error init window\n");
	if (!(dt->img = (t_data_img *)ft_memalloc(sizeof(t_data_img))))
		err("Error memalloc img\n");
	if (!(dt->img->self = mlx_new_image(dt->mlx, dt->win_x, dt->win_y)))
		err("Error init img\n");
	if (!(dt->img->ptr = mlx_get_data_addr(dt->img->self, &dt->img->bpp,
	&dt->img->szl, &dt->img->edn)))
		err("Error init2 img\n");
}

int			main(int ac, char **av)
{
	static t_data_fdf *dt;

	if (ac != 2)
		err("Error, bad usage\nUsage : ./fdf <Path to map file>\n");
	if (!(dt = (t_data_fdf *)ft_memalloc(sizeof(t_data_fdf))))
		err("ft_memalloc of data_fdf failed.\n");
	parser(av[1], dt);
	ft_putstr("Parsed file\n");
	mlx_create(dt);
	ft_putstr("Init env\n");
	map_draw(dt);
	ft_putstr("Created first image\n");
	mlx_key_hook(dt->win, hook_keydown, dt);
	ft_putstr("Keys hooked\nPrinting...\n");
	mlx_loop(dt->mlx);
	return (0);
}
