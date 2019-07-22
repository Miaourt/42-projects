/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tguillem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/26 12:03:38 by tguillem          #+#    #+#             */
/*   Updated: 2015/11/27 15:25:39 by tguillem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*result;
	t_list	*cursor;
	t_list	*tmp;
	t_list	*prev;
	size_t	size;

	if (!(result = f(lst)))
		return (NULL);
	size = result->content_size;
	result = ft_lstnew(result->content, result->content_size);
	result->content_size = size;
	result->next = NULL;
	prev = result;
	cursor = lst->next;
	while (cursor != NULL && (tmp = f(cursor)))
	{
		size = tmp->content_size;
		tmp = ft_lstnew(tmp->content, tmp->content_size);
		tmp->content_size = size;
		prev->next = tmp;
		prev = tmp;
		cursor = cursor->next;
	}
	return (result);
}
