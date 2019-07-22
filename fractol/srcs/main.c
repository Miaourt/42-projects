/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llaporte <llaporte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/11 16:18:26 by llaporte          #+#    #+#             */
/*   Updated: 2017/06/07 15:19:02 by llaporte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void		err(char *err_msg)
{
	ft_putstr(err_msg);
	exit(1);
}

int			quit(void)
{
	exit(0);
	return (0);
}

void		fract_init(t_data_fct *dt, char *fract)
{
	dt->hue = 4;
	dt->zoom = 200;
	dt->win_x = 1280;
	dt->win_y = 720;
	dt->x_margin = dt->win_x / 2.0;
	dt->y_margin = dt->win_y / 2.0;
	if (!ft_strcmp("mandelbrot", fract))
	{
		dt->fract = 1;
		dt->imax = 30;
	}
	else if (!ft_strcmp("julia", fract))
	{
		dt->fract = 2;
		dt->imax = 150;
	}
	else if (!ft_strcmp("burningship", fract))
	{
		dt->fract = 3;
		dt->imax = 25;
	}
	else
		err("Error\nUsage : ./fractol <julia|mandelbrot|burningship>\n");
}

void		mlx_create(t_data_fct *dt, char *name_fract)
{
	if (!(dt->mlx = mlx_init()))
		err("Error init mlx\n");
	if (!(dt->win = mlx_new_window(dt->mlx, dt->win_x, dt->win_y, name_fract)))
		err("Error init window\n");
	if (!(dt->img = (t_data_img *)ft_memalloc(sizeof(t_data_img))))
		err("Error memalloc img\n");
	if (!(dt->keys = (t_data_key *)ft_memalloc(sizeof(t_data_key))))
		err("Error memalloc keys\n");
	if (!(dt->img->self = mlx_new_image(dt->mlx, dt->win_x, dt->win_y)))
		err("Error init img\n");
	if (!(dt->img->ptr = mlx_get_data_addr(dt->img->self, &dt->img->bpp,
	&dt->img->szl, &dt->img->edn)))
		err("Error init2 img\n");
}

int			main(int ac, char **av)
{
	static t_data_fct *dt;

	if (ac != 2)
		err("Error\nUsage : ./fractol <julia|mandelbrot|burningship>\n");
	if (!(dt = (t_data_fct *)ft_memalloc(sizeof(t_data_fct))))
		err("ft_memalloc of data_fct failed.\n");
	dt->precision = 1;
	dt->tips = 1;
	dt->mouse_x = 400;
	dt->mouse_y = 400;
	dt->mouselock = 0;
	fract_init(dt, av[1]);
	mlx_create(dt, av[1]);
	mlx_do_key_autorepeaton(dt->mlx);
	mlx_hook(dt->win, 2, 1L << 0, hook_keys_pressed, dt);
	mlx_hook(dt->win, 3, 1L << 1, hook_keys_release, dt);
	if (dt->fract == 2)
		mlx_hook(dt->win, 6, 1L << 6, hook_mouse_move, dt);
	mlx_mouse_hook(dt->win, hook_mouse_button, dt);
	mlx_expose_hook(dt->win, drawer, dt);
	mlx_hook(dt->win, 17, (1L << 17), quit, dt);
	drawer(dt);
	mlx_loop(dt->mlx);
}
