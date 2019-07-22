/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arrayext.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcourtil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/16 17:53:37 by tcourtil          #+#    #+#             */
/*   Updated: 2019/03/06 15:06:30 by tcourtil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_arrayext(t_array *a)
{
	t_list	*tmp;
	void	**list;
	int		i;

	tmp = NULL;
	list = NULL;
	while (!tmp)
		tmp = (t_list *)malloc(sizeof(t_list));
	i = ARRAY_SIZE * sizeof(void *);
	while (!list)
		list = (void **)malloc(i);
	i = 0;
	while (i < ARRAY_SIZE)
	{
		list[i] = NULL;
		i++;
	}
	tmp->content = list;
	tmp->content_size = sizeof(void **);
	tmp->next = NULL;
	ft_lstadde(&(a->list), tmp);
}
