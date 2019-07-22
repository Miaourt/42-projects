/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dicoget.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcourtil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/15 15:15:33 by tcourtil          #+#    #+#             */
/*   Updated: 2019/03/06 16:07:03 by tcourtil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"

static t_page	*getpage(t_list *list, char *k)
{
	t_page	*page;

	while (list)
	{
		page = (t_page *)list->content;
		if (ft_strequ(k, page->key))
			return (page);
		list = list->next;
	}
	return (NULL);
}

void			*ft_dicoget(t_dico *dico, char *k)
{
	int		val;
	t_page	*page;

	val = ft_keyvalue(k);
	val = val % DICO_SIZE;
	page = getpage(dico->list[val], k);
	if (page)
		return (page->content);
	return (NULL);
}
