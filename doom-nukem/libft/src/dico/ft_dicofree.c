/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dicofree.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcourtil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/15 15:06:50 by tcourtil          #+#    #+#             */
/*   Updated: 2019/03/06 16:32:48 by tcourtil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"

static void	clean(t_list **alst, void (*del)(void *))
{
	t_page	*p;

	if (alst && *alst)
	{
		if (del && (*alst)->content)
		{
			p = (t_page *)(*alst)->content;
			free(p->key);
			(del)(p->content);
			free(p);
		}
		free(*alst);
		*alst = NULL;
	}
}

static void	clean_all(t_list **alst, void (*del)(void *))
{
	if (alst && *alst)
	{
		if ((*alst)->next)
			clean_all(&((*alst)->next), del);
		clean(alst, del);
	}
}

void		ft_dicofreewith(t_dico *d, void (*clean)(void *))
{
	int		i;

	i = 0;
	if (d)
	{
		while (i < DICO_SIZE)
		{
			clean_all(&(d->list[i]), clean);
			i++;
		}
		free(d->list);
		ft_lstdelall(&(d->keys));
		free(d);
	}
}

void		ft_dicofree(t_dico *d)
{
	ft_dicofreewith(d, free);
}
