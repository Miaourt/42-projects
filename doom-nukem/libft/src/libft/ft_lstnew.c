/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcourtil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/13 16:05:24 by tcourtil          #+#    #+#             */
/*   Updated: 2019/01/17 17:53:24 by tcourtil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t cs)
{
	t_list *m;

	if ((m = (t_list *)ft_memalloc(sizeof(t_list))) == NULL)
		return (NULL);
	if (content)
	{
		if ((m->content = ft_memalloc(cs)) == NULL)
			return (NULL);
		ft_memcpy(m->content, content, cs);
		m->content_size = cs;
	}
	else
	{
		m->content = NULL;
		m->content_size = 0;
	}
	m->next = NULL;
	return (m);
}
