/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   editor.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: groberto <groberto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/28 15:01:01 by llaporte          #+#    #+#             */
/*   Updated: 2019/05/15 15:15:15 by groberto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "editor.h"
#include "doom.h"

int			editor_save2(int fd, t_ed *ed)
{
	if (!ceil_tex(fd))
		return (1);
	if (!gameover_tex(fd))
		return (1);
	if (!gamewin_tex(fd))
		return (1);
	if (!write_world(fd, ed->world))
		return (1);
	if (!write_arrayimg(fd, ed->textures))
		return (1);
	if (!write_arrayent(fd, ed->entities))
		return (1);
	if (ed_save_config(fd, ed))
		return (1);
	return (0);
}

int			entity_tex2(int fd, t_array *a)
{
	if (add_t(a, "assets/gilets.bmp"))
		return (eterr(a));
	if (add_t(a, "assets/money.bmp"))
		return (eterr(a));
	if (add_t(a, "assets/money_b.bmp"))
		return (eterr(a));
	if (add_t(a, "assets/tax.bmp"))
		return (eterr(a));
	if (add_t(a, "assets/barrelf.bmp"))
		return (eterr(a));
	if (add_t(a, "assets/coin_a.bmp"))
		return (eterr(a));
	if (add_t(a, "assets/coin_b.bmp"))
		return (eterr(a));
	if (add_t(a, "assets/coin_c.bmp"))
		return (eterr(a));
	if (add_t(a, "assets/coin_d.bmp"))
		return (eterr(a));
	if (add_t(a, "assets/jetpack.bmp"))
		return (eterr(a));
	if (!write_arrayimg(fd, a))
		return (eterr(a));
	free_textures(a);
	ft_printf("save entity texture\n");
	return (1);
}

int			entity_tex(int fd)
{
	t_array *a;

	if (!(a = ft_arraynew()))
		return (0);
	if (add_t(a, "assets/barrel.bmp"))
		return (eterr(a));
	if (add_t(a, "assets/phantom.bmp"))
		return (eterr(a));
	if (add_t(a, "assets/phantom2.bmp"))
		return (eterr(a));
	if (add_t(a, "assets/phantom3.bmp"))
		return (eterr(a));
	if (add_t(a, "assets/bbarrel.bmp"))
		return (eterr(a));
	entity_tex2(fd, a);
	return (1);
}

int			editor_save(t_ed *ed)
{
	int	fd;

	fd = open(ed->path, O_WRONLY | O_CREAT, S_IRUSR | S_IWUSR | S_IXUSR
	| S_IRGRP | S_IWGRP | S_IWOTH);
	if (!write_str(fd, "doom_map"))
		return (1);
	if (!entity_tex(fd))
		return (1);
	if (!arial_tex(fd))
		return (1);
	if (!uigilet_tex(fd))
		return (1);
	if (!floor_tex(fd))
		return (1);
	if (editor_save2(fd, ed))
		return (1);
	close(fd);
	ft_printf("save succes\n");
	return (0);
}
