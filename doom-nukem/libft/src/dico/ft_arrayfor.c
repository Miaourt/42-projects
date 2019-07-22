/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arrayfor.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcourtil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/16 16:52:27 by tcourtil          #+#    #+#             */
/*   Updated: 2019/01/17 12:32:58 by tcourtil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_arrayfor(t_array *a, void (*loop)(unsigned int, void *, void *)
		, void *inf)
{
	unsigned int	i;
	t_list			*l;
	unsigned int	mod;
	void			**list;

	l = a->list;
	i = 0;
	mod = 0;
	while (i + mod < a->length)
	{
		list = (void **)l->content;
		(*loop)(i + mod, list[i], inf);
		i++;
		if (i >= ARRAY_SIZE)
		{
			l = l->next;
			mod += ARRAY_SIZE;
			i = 0;
		}
	}
}
