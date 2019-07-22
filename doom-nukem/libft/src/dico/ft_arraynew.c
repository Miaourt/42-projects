/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arraynew.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcourtil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/16 16:32:50 by tcourtil          #+#    #+#             */
/*   Updated: 2019/03/06 15:02:31 by tcourtil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_array		*ft_arraynew(void)
{
	t_array *array;

	if ((array = (t_array *)malloc(sizeof(t_array))))
	{
		array->list = NULL;
		array->length = 0;
		ft_arrayext(array);
	}
	return (array);
}
