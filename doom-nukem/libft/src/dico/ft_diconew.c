/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_diconew.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcourtil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/15 15:06:50 by tcourtil          #+#    #+#             */
/*   Updated: 2019/03/06 15:42:20 by tcourtil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"

t_dico	*ft_diconew(void)
{
	t_dico	*res;
	int		i;

	if (!(res = (t_dico *)malloc(sizeof(t_dico))))
		return (NULL);
	i = DICO_SIZE * sizeof(t_list *);
	res->list = (t_list **)malloc(i);
	i = 0;
	if (!res->list)
	{
		free(res);
		return (NULL);
	}
	while (i < DICO_SIZE)
	{
		res->list[i] = NULL;
		i++;
	}
	res->keys = NULL;
	return (res);
}
