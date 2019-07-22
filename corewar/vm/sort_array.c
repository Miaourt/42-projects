/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_array.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tguillem <tguillem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/17 22:01:58 by tguillem          #+#    #+#             */
/*   Updated: 2018/03/17 22:01:58 by tguillem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

static int		prg_id_cmp(t_array *array1, t_array *array2)
{
	return (((t_program*)array1->data)->id > ((t_program*)array2->data)->id);
}

static void		swap_array(t_array **array1, t_array **array2)
{
	void	*data;

	data = (*array1)->data;
	(*array1)->data = (*array2)->data;
	(*array2)->data = data;
}

static void		internal_sort(t_array **lst, int (*cmp)(t_array *array1, t_array
			*array2))
{
	t_array *tmp1;
	t_array *tmp2;

	tmp1 = *lst;
	while (tmp1)
	{
		tmp2 = tmp1->next;
		while (tmp2)
		{
			if (cmp(tmp1, tmp2) > 0)
				swap_array(&tmp1, &tmp2);
			tmp2 = tmp2->next;
		}
		tmp1 = tmp1->next;
	}
}

t_array			*sort_champions(t_array *lst)
{
	t_array	*result;

	if (!lst)
		return (NULL);
	result = lst;
	internal_sort(&result, prg_id_cmp);
	return (result);
}
