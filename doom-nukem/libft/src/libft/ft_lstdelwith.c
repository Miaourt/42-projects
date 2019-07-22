/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelwith.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcourtil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/13 16:12:55 by tcourtil          #+#    #+#             */
/*   Updated: 2019/03/06 15:49:14 by tcourtil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdelwith(t_list **alst, void (*del)(void *))
{
	if (alst && *alst)
	{
		if (del && (*alst)->content)
			(del)((*alst)->content);
		free(*alst);
		*alst = NULL;
	}
}
