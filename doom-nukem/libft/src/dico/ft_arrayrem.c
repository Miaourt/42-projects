/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arrayrem.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcourtil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/16 16:38:00 by tcourtil          #+#    #+#             */
/*   Updated: 2019/01/17 12:37:16 by tcourtil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		replace(t_list *l, int m, int id)
{
	int		mod;
	int		i;
	void	**list;
	void	**list2;

	mod = m;
	i = id;
	while (i > 0)
	{
		mod++;
		list = ((void **)l->content);
		if (mod >= ARRAY_SIZE)
		{
			list2 = ((void **)l->next->content);
			list[mod - 1] = list2[0];
		}
		else
		{
			list[mod - 1] = list[mod];
		}
		i--;
	}
}

void			ft_arrayrem(t_array *a, size_t pos)
{
	int		i;
	int		mod;
	t_list	*l;

	l = a->list;
	i = pos;
	mod = i % ARRAY_SIZE;
	i = i / ARRAY_SIZE;
	while (i > 0)
	{
		l = l->next;
		i--;
	}
	replace(l, mod, a->length - pos);
	a->length--;
}
