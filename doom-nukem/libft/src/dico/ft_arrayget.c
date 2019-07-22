/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arrayget.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcourtil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/17 12:00:12 by tcourtil          #+#    #+#             */
/*   Updated: 2019/01/17 12:11:25 by tcourtil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_arrayget(t_array *a, size_t pos)
{
	size_t	i;
	size_t	mod;
	t_list	*l;
	void	**list;

	l = a->list;
	if (pos < a->length)
	{
		i = pos;
		mod = i % ARRAY_SIZE;
		i = i / ARRAY_SIZE;
		while (i > 0)
		{
			l = l->next;
			i--;
		}
		list = ((void **)l->content);
		return (list[mod]);
	}
	return (NULL);
}
