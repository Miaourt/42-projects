/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llaporte <llaporte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/16 17:13:24 by tcourtil          #+#    #+#             */
/*   Updated: 2019/02/05 14:10:59 by llaporte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		format(t_list *list, char *arg, t_flag *f, size_t size)
{
	int		len;
	char	*space;
	char	*str;

	len = f->min - ft_min(size, f->pres > 0 ? (size_t)f->pres : size);
	if (len > 0)
		space = ft_memset(ft_strnew(len), f->zero &&
				len > f->pres && !f->left ? '0' : ' ', len);
	str = NULL;
	if (len > 0 && !f->left)
		ft_lstadde(&list, ft_lstnew(space, len));
	if (f->pres > 0 && f->pres < (int)size)
	{
		str = ft_strncpy(ft_strnew(f->pres), arg, f->pres);
		ft_lstadde(&list, ft_lstnew(str, f->pres));
		free(str);
	}
	else if (!f->haspres || f->pres >= (int)size)
		ft_lstadde(&list, ft_lstnew(arg, size));
	if (len > 0 && f->left)
		ft_lstadde(&list, ft_lstnew(space, len));
	if (len > 0)
		free(space);
}

static void	setarg(t_list *list, char *arg, t_flag *f)
{
	char	*str;

	str = ft_memset(ft_strnew(f->pres), '0', f->pres);
	ft_strcpy(&str[f->pres - ft_strlen(arg)], arg);
	ft_lstadde(&list, ft_lstnew(str, f->pres));
	free(str);
}

void		formatnb(t_list *list, char *arg, t_flag *f, int s)
{
	int		len;
	char	*space;

	len = f->min - ft_max(ft_strlen(arg), f->pres > 0 ?
			(size_t)f->pres : ft_strlen(arg)) - (s != 0 || f->space);
	if (s != 0 && f->zero)
		ft_lstadde(&list, ft_lstnew(s == 1 ? "+" : "-", 1));
	if (s == 0 && f->space)
		ft_lstadde(&list, ft_lstnew(" ", 1));
	if (len > 0)
		space = ft_memset(ft_strnew(len), f->zero &&
				!f->haspres && !f->left ? '0' : ' ', len);
	if (len > 0 && !f->left)
		ft_lstadde(&list, ft_lstnew(space, len));
	if (s != 0 && !f->zero)
		ft_lstadde(&list, ft_lstnew(s == 1 ? "+" : "-", 1));
	if (f->pres > 0 && (int)ft_strlen(arg) < f->pres)
		setarg(list, arg, f);
	else
		ft_lstadde(&list, ft_lstnew(arg, ft_strlen(arg)));
	if (len > 0 && f->left)
		ft_lstadde(&list, ft_lstnew(space, len));
	if (len > 0)
		free(space);
}

void		formato(t_list *list, char *arg, t_flag *f)
{
	int		len;
	char	*space;

	if (f->pres > 0)
		len = f->min - ft_max(ft_strlen(arg), f->pres) - f->hexa;
	else
		len = f->min - ft_strlen(arg) - f->hexa;
	if (f->pres == 0 && f->haspres)
		len += ft_strlen(arg);
	if (len > 0)
		space = ft_memset(ft_strnew(len), f->zero && !f->left ? '0' : ' ', len);
	if (len > 0 && !f->left)
		ft_lstadde(&list, ft_lstnew(space, len));
	if (f->hexa)
		ft_lstadde(&list, ft_lstnew("0", 1));
	if (f->pres > 0)
		setarg(list, arg, f);
	else if (!f->haspres)
		ft_lstadde(&list, ft_lstnew(arg, ft_strlen(arg)));
	if (len > 0 && f->left)
		ft_lstadde(&list, ft_lstnew(space, len));
	if (len > 0)
		free(space);
}
