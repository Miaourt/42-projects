/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   doom.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocojeda- <ocojeda-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/03 17:16:52 by tcourtil          #+#    #+#             */
/*   Updated: 2019/05/15 15:42:09 by ocojeda-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOOM_H
# define DOOM_H

# define CASE 64
# define PROJ 295
# define SAVE_PROJ 886
# define WALL 128
# define W_WIDTH 1024
# define W_HEIGHT 756
# define NB_TH 8

# include <pthread.h>
# include "libft.h"
# include "SDL2/SDL.h"
# include "SDL2/SDL_mixer.h"
# include "math.h"
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <signal.h>

typedef	struct		s_rectui
{
	int				x;
	int				y;
	int				lenghtx;
	int				lenghty;
}					t_rectui;

typedef struct		s_cam
{
	double			x;
	double			y;
	double			z;
	int				ry;
	double			rot;
	double			roty;
}					t_cam;

typedef struct		s_world
{
	t_cam			*cam;
	int				**map;
	int				height;
	int				width;
}					t_world;

typedef struct		s_tri
{
	t_vec4			*a;
	t_vec4			*b;
	t_vec4			*c;
}					t_tri;

typedef struct		s_img
{
	int				*data;
	int				width;
	int				height;
	char			*name;
}					t_img;

typedef struct		s_player
{
	int				life;
	int				max_life;
	int				money;
	int				giletjaune;
	int				taxes;
	int				weapon;
	int				action;
}					t_player;

typedef struct		s_ent
{
	int				id;
	double			rot;
	int				lifetime;
	t_vec4			*pos;
	int				i1;
	int				i2;
	int				i3;
	double			d1;
	double			d2;
	double			d3;
}					t_ent;

typedef struct		s_win
{
	t_array			*entity;
	t_array			*entdata;
	t_array			*enttexture;
	t_img			*arial;
	t_img			*uigilet;
	int				cf_taxes;
	int				cf_money;
	int				cf_prix;
	int				cf_time_jacket;
	int				cf_max_life;
	int				cf_damage;
	char			*popup;
	t_img			*gameover;
	t_img			*gamewin;
	char			*popup2;
	int				timer;
	double			*dist;
	t_player		player;
	int				nb_textures;
	int				width;
	int				height;
	int				font;
	t_world			*world;
	double			ray_fac;
	int				exit;
	int				action;
	int				forward;
	int				back;
	int				up;
	int				down;
	int				left;
	int				right;
	int				shift;
	int				jump;
	int				move_left;
	int				move_right;
	int				ground;
	int				debug;
	int				knees;
	int				jet_pack;
	int				jp_time;
	double			timej;
	double			walktime;
	double			speed;
	void			*data;
	t_img			*floor;
	t_img			*ceil;
	t_array			*textures;
	pthread_t		*thread;
	SDL_Window		*win;
	SDL_Renderer	*rendr;
	SDL_Surface		*surf;
	SDL_Texture		*texture;
}					t_win;

typedef struct		s_data
{
	t_win			*win;
	int				id;
	int				x;
	int				len;
	double			*dist;
	int				*color;
}					t_data;

typedef struct		s_ray
{
	int				dir;
	double			dist;
	double			rot;
	double			r;
	double			texture_pos;
	double			text_x;
	double			text_y;
	int				wall;
	int				id;
	int				id_x;
	int				id_y;
}					t_ray;

typedef struct		s_entdata
{
	int				id;
	int				collide;
	int				trigger;
	double			dist_collide;
	void			(*ontrigger)(t_win *win, t_ent *ent);
	void			(*update)(t_win *win, t_ent *ent);
	void			(*onuse)(t_win *win, t_ent *ent, double dist);
	t_img			*texture;
	t_img			*texture_d;
}					t_entdata;

typedef struct		s_rend
{
	double			dist;
	double			ang;
	t_img			*img;
	double			ws;
	double			wall;
	int				bx;
}					t_rend;

int					init_screen(t_win *win);
void				clear_screen(t_win *win, int color);
void				draw_pixel(int x, int y, t_win *win, int color);
t_world				*init_world(int sx, int sy);
double				ray(t_world *w, double rot, t_ray *r);
double				wall_size(double dist);
double				fish_eyes(double ws, double dc);
int					render(t_win *win);
int					update(t_win *win);
int					hook_keys_pressed(int key, t_win *win);
int					hook_keys_release(int key, t_win *win);
void				up(t_win *win);
void				down(t_win *win);
double				dif(double x, double x2);
int					reader(t_win *win, char *file);
int					lerp(int c1, int c2, double per);
int					clean_wolf(t_win *win);
int					init_data(t_win *win);
void				straff(t_win *win, float dir);
int					in_triangle(t_tri *tri, t_vec4 *ray, t_vec4 *pos,
		float *dist);
int					get_img_pixel(t_img *img, float x, float y);
t_img				*load_texture(char *path);
int					file_exist(char *filepath);
int					err(const char *msg);
int					render_ui(t_win *win);
double				normrad(double ang);
int					comrad(double ang, double min, double max);
int					init_ghost(t_win *win);
void				ghosttrigger(t_win *win, t_ent *ent);
void				ghostmove(t_win *win, t_ent *ent);
t_entdata			*entdatanew();
void				usebarrel(t_win *win, t_ent *ent, double dist);
int					init_barrel(t_win *win);
int					init_breakbarrel(t_win *win);
void				disp(t_world *w);
t_ent				*entitynew(double x, double z, double rot, int id);
int					init_entity(t_win *win);
int					init_win(t_win *win, char *file);
void				render_wall(t_data *data, int x);
int					rendersprite(t_win *win);
void				action(t_win *win);
int					game_loop(t_win *win);
void				mouse_movements(t_win *win, SDL_MouseMotionEvent motion);
int					collide_walk(t_win *win, double x, double y);
void				free_world(t_world **world);
void				free_img(t_img **img);
void				free_sdl(t_win *win);
int					init_entdata(t_win *win);
int					init_map(t_world *w, int sx, int sy);
int					write_int(int fd, int nb);
int					read_int(int fd);
int					write_double(int fd, double nb);
double				read_double(int fd);
int					write_str(int fd, char *l);
char				*read_str(int fd);
int					write_img(int fd, t_img *img);
t_img				*read_img(int fd);
int					write_arrayimg(int fd, t_array *a);
t_array				*read_arrayimg(int fd);
int					write_cam(int fd, t_cam *cam);
t_cam				*read_cam(int fd);
int					write_world(int fd, t_world *w);
t_world				*read_world(int fd);
int					write_ent(int fd, t_ent *ent);
t_ent				*read_ent(int fd);
int					write_arrayent(int fd, t_array *a);
t_array				*read_arrayent(int fd);
int					init_gilet(t_win *win);
void				draw_char(t_win *win, int sx, int sy, char c);
void				draw_str(t_win *win, int sx, int sy, char *p);
t_cam				*init_cam(void);
void				free_textures(t_array *a);
int					init_money(t_win *win);
int					init_tax(t_win *win);
void				free_split(char **str);
void				free_entity(unsigned int i, void *content, void *p);
int					doom_load(t_win *win, char *file);
int					init_coin(t_win *win);
void				coinmove(t_win *win, t_ent *ent);
int					init_jetpack(t_win *win);
#endif
