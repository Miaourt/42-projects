/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tguillem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/26 11:57:55 by tguillem          #+#    #+#             */
/*   Updated: 2015/11/26 12:03:16 by tguillem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_lstsize(t_list *lst)
{
	size_t	result;
	t_list	*tmp;

	result = 0;
	tmp = lst;
	if (lst != NULL)
	{
		result++;
		while (tmp != NULL)
		{
			tmp = tmp->next;
			result++;
		}
	}
	return (result);
}
