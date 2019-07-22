/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arrayadd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcourtil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/16 16:38:00 by tcourtil          #+#    #+#             */
/*   Updated: 2019/01/17 12:23:18 by tcourtil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_arrayadd(t_array *a, void *content)
{
	int		i;
	int		mod;
	t_list	*l;
	void	**list;

	l = a->list;
	i = a->length;
	mod = i % ARRAY_SIZE;
	i = i / ARRAY_SIZE;
	while (i > 0)
	{
		if (!l->next)
			ft_arrayext(a);
		else
		{
			l = l->next;
			i--;
		}
	}
	list = ((void **)l->content);
	list[mod] = content;
	a->length++;
}
