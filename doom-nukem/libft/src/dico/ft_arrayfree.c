/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arrayfree.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcourtil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/16 16:35:55 by tcourtil          #+#    #+#             */
/*   Updated: 2019/03/06 15:54:14 by tcourtil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	free_array(void *p)
{
	void	**l;
	int		i;

	if (!p)
		return ;
	i = 0;
	l = (void **)p;
	while (i < ARRAY_SIZE)
	{
		free(l[i]);
		i++;
	}
	free(l);
}

void		ft_arrayfree(t_array *a)
{
	if (a)
	{
		ft_lstdelallwith(&(a->list), &free_array);
		free(a);
	}
}
