/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadde.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcourtil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/13 16:32:41 by tcourtil          #+#    #+#             */
/*   Updated: 2018/11/20 16:10:16 by tcourtil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadde(t_list **alst, t_list *new)
{
	if (alst && new)
	{
		if (*alst)
		{
			ft_lstadde(&(*alst)->next, new);
		}
		else
		{
			*alst = new;
		}
	}
}
