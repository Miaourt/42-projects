/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstget.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tguillem <tguillem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/27 10:44:06 by tguillem          #+#    #+#             */
/*   Updated: 2016/04/27 10:47:14 by tguillem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list				*ft_lstget(t_list *lst, void *data, size_t data_size)
{
	while (lst)
	{
		if (lst->content_size == data_size &&
			ft_memcmp(data, lst->content, data_size))
			return (lst);
		lst = lst->next;
	}
	return (NULL);
}
