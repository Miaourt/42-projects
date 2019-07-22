/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_formatp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcourtil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/16 17:13:24 by tcourtil          #+#    #+#             */
/*   Updated: 2018/12/12 14:29:37 by tcourtil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		formatp(t_list *list, char *arg, t_flag *f, char *base)
{
	int		len;
	char	*space;
	char	*pres;
	int		lpres;

	len = f->min - ft_max(ft_strlen(arg), f->pres) - (f->hexa * 2);
	if (len > 0)
		space = ft_memset(ft_strnew(len), f->zero && !f->left ? '0' : ' ', len);
	if ((lpres = f->pres - ft_strlen(arg)) > 0)
		pres = ft_memset(ft_strnew(lpres), '0', lpres);
	if (f->zero && f->hexa)
		ft_lstadde(&list, ft_lstnew(base, 2));
	if (len > 0 && !f->left)
		ft_lstadde(&list, ft_lstnew(space, len));
	if (!f->zero && f->hexa)
		ft_lstadde(&list, ft_lstnew(base, 2));
	if (lpres > 0)
		ft_lstadde(&list, ft_lstnew(pres, lpres));
	ft_lstadde(&list, ft_lstnew(arg, ft_strlen(arg)));
	if (len > 0 && f->left)
		ft_lstadde(&list, ft_lstnew(space, len));
	if (len > 0)
		free(space);
	if (lpres > 0)
		free(pres);
}
