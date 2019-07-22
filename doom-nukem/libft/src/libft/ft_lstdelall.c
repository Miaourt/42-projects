/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelall.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcourtil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/13 16:26:16 by tcourtil          #+#    #+#             */
/*   Updated: 2018/11/20 16:14:12 by tcourtil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdelall(t_list **alst)
{
	if (alst && *alst)
	{
		if ((*alst)->next)
			ft_lstdelall(&((*alst)->next));
		if (((char *)(*alst)->content))
			free((*alst)->content);
		free((*alst));
		*alst = NULL;
	}
}
