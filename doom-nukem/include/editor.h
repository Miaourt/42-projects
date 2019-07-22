/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   editor.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llaporte <llaporte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/28 15:16:52 by llaporte          #+#    #+#             */
/*   Updated: 2019/05/14 15:47:59 by tcourtil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EDITOR_H
# define EDITOR_H

# include "doom.h"

typedef struct		s_config
{
	int				nb_taxes;
	int				money;
	int				prix;
	int				time_jacket;
	int				max_life;
	int				damage;
}					t_config;

typedef	struct		s_ed
{
	char			*line;
	t_array			*textures;
	t_array			*entities;
	t_world			*world;
	t_config		config;
	char			*path;
	char			flag_min;
	int				i;
}					t_ed;

int					editor(char *path);
int					errf(const char *msg, char **buff);
int					edit_texture (t_ed *ed);
int					edit_map(t_ed *ed);
int					edit_entity(t_ed *ed);
int					edit_spawn(t_ed *ed);
void				print_map(t_ed *ed);
int					ceil_tex(int fd);
int					uigilet_tex(int fd);
int					arial_tex(int fd);
int					errf(const char *msg, char **buff);
int					gamewin_tex(int fd);
int					floor_tex(int fd);
int					gameover_tex(int fd);
int					editor_shell(t_ed *ed);
int					editor_shell2(t_ed *ed);
int					editor_shell3(t_ed *ed);
int					add_t(t_array *a, char *file);
int					eterr(t_array *a);
int					editor_save(t_ed *ed);
void				inthandler(int dummy);
int					can_save(t_ed *ed);
int					edit_settings(t_ed *ed);
void				ed_init_config(t_ed *ed);
int					ed_save_config(int fd, t_ed *ed);
#endif
