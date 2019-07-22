/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tguillem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/26 11:07:00 by tguillem          #+#    #+#             */
/*   Updated: 2015/11/27 11:25:43 by tguillem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alist, void (*del)(void *, size_t))
{
	t_list *next;
	t_list *tmp;

	next = (*alist)->next;
	if (alist != NULL)
	{
		while (next != NULL)
		{
			tmp = next->next;
			ft_lstdelone(&next, del);
			next = tmp;
		}
		(*alist)->next = NULL;
		ft_lstdelone(alist, del);
	}
}
