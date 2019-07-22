/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resource_manager.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tguillem <tguillem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/06 17:31:35 by tguillem          #+#    #+#             */
/*   Updated: 2016/10/06 18:11:12 by tguillem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_buff				**get_gnl_buffer(void)
{
	static t_buff	*root = NULL;

	return (&root);
}

void				resource_manager_destroy(void)
{
	t_buff		**tmp;
	t_buff		*gnl;
	void		*prev;

	tmp = get_gnl_buffer();
	gnl = *tmp;
	if (gnl)
	{
		ft_strdel(&gnl->buff);
		prev = gnl;
		gnl = gnl->next;
		ft_memdel(&prev);
	}
}
