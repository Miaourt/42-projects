/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llaporte <llaporte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/11 16:26:33 by llaporte          #+#    #+#             */
/*   Updated: 2017/06/07 15:15:07 by llaporte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H

# define FRACTOL_H

# include "../libft/includes/libft.h"
# include "mlx.h"
# include <fcntl.h>
# include "keys_macos.h"

typedef struct	s_data_img
{
	void	*self;
	void	*ptr;
	int		bpp;
	int		szl;
	int		edn;
}				t_data_img;

typedef struct	s_complex
{
	double	r;
	double	i;
}				t_complex;

typedef struct	s_data_key
{
	int	updown;
	int	leftright;
	int	moreless;
	int	i;
	int	pcs;
}				t_data_key;

typedef struct	s_data_fct
{
	void		*mlx;
	void		*win;
	t_data_img	*img;
	t_data_key	*keys;
	int			win_x;
	int			win_y;

	int			fract;
	int			i;
	int			imax;
	int			precision;
	double		zoom;
	int			hue;
	int			tips;

	int			mouselock;
	int			mouse_x;
	int			mouse_y;

	double		x_margin;
	double		y_margin;

	t_complex	c;
	t_complex	z;
}				t_data_fct;

void			err(char *err_msg);
void			img_pixel_put(t_data_fct *dt, float x, float y, int color);
int				drawer(t_data_fct *dt);
int				hooker(t_data_fct *dt);
int				rgb(int r, int g, int b);
int				hv(int hue, float val);
void			annotate(t_data_fct *dt);
void			img_clean(t_data_fct *dt);
void			zoom_pos(int x, int y, int value, t_data_fct *dt);

int				hook_keys_pressed(int key, t_data_fct *dt);
int				hook_keys_release(int key, t_data_fct *dt);
int				hook_mouse_button(int mouse, int x, int y, t_data_fct *dt);
int				hook_mouse_move(int x, int y, t_data_fct *dt);
int				hook_expose(t_data_fct *dt);

void			on_trigger(t_data_fct *dt);

#endif
