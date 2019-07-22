/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llaporte <llaporte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/11 16:56:33 by llaporte          #+#    #+#             */
/*   Updated: 2017/02/22 14:55:14 by llaporte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H

# define FDF_H

# include "libft.h"
# include "mlx.h"
# include <fcntl.h>

typedef struct	s_data_img
{
	void	*self;
	void	*ptr;
	int		bpp;
	int		szl;
	int		edn;
}				t_data_img;

typedef struct	s_data_fdf
{
	void		*mlx;
	void		*win;
	t_data_img	*img;
	char		***fdf_map;
	int			map_x;
	int			map_y;
	int			win_x;
	int			win_y;
	int			sf;
	int			hg;
	int			cm;
	int			ofx;
	int			ofy;
}				t_data_fdf;

typedef struct	s_point
{
	int	x;
	int	y;
}				t_point;

typedef struct	s_line
{
	int			dx;
	int			dy;
	t_point		p;
	t_point		p2;
}				t_line;

void			err(char *err_msg);
char			**ft_split(char *str, char c);
void			parser(char *file, t_data_fdf *dt);
int				hxy(t_data_fdf *dt, int x, int y);
void			img_pixel_put(t_data_fdf *dt, int x, int y, int color);
void			draw_line(t_data_fdf *dt, t_point a, t_point b, int color);
void			map_draw(t_data_fdf *dt);

#endif
