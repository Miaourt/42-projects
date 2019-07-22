/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dicoput.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcourtil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/15 15:15:33 by tcourtil          #+#    #+#             */
/*   Updated: 2019/03/06 16:32:27 by tcourtil         ###   ########.fr       */
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

static t_page	*newpage(char *k, void *content)
{
	t_page	*page;

	page = (t_page *)malloc(sizeof(t_page));
	if (page)
	{
		page->key = ft_strdup(k);
		page->content = content;
	}
	return (page);
}

static t_list	*to_list(t_page *page)
{
	t_list	*tmp;

	tmp = NULL;
	while (!tmp)
		tmp = (t_list *)malloc(sizeof(t_list));
	tmp->content = page;
	tmp->content_size = sizeof(t_page *);
	tmp->next = NULL;
	return (tmp);
}

void			ft_dicoput(t_dico *dico, char *k, void *content)
{
	int		val;
	t_page	*page;

	val = ft_keyvalue(k);
	val = val % DICO_SIZE;
	page = getpage(dico->list[val], k);
	if (page)
		page->content = content;
	else
	{
		ft_lstadde(&(dico->list[val]), to_list(newpage(k, content)));
		ft_lstadde(&dico->keys, ft_lstnew(k, ft_strlen(k)));
	}
}
