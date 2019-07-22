/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelallwith.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcourtil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/13 16:26:16 by tcourtil          #+#    #+#             */
/*   Updated: 2019/03/06 15:51:19 by tcourtil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdelallwith(t_list **alst, void (*del)(void *))
{
	if (alst && *alst)
	{
		if ((*alst)->next)
			ft_lstdelallwith(&((*alst)->next), del);
		ft_lstdelwith(alst, del);
	}
}
