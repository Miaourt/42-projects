/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_array.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tguillem <tguillem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/14 09:01:19 by tguillem          #+#    #+#             */
/*   Updated: 2018/03/17 22:52:26 by tguillem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_array			*array_init(t_array *root, void *data)
{
	t_array		*result;
	t_array		*tmp;

	tmp = root;
	if (!(result = (t_array*)malloc(sizeof(t_array))))
		return (NULL);
	result->data = data;
	result->next = NULL;
	if (tmp)
	{
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = result;
		return (root);
	}
	return (result);
}

void			destroy_array(t_array *array)
{
	destroy_array_custom(array, free);
}

void			destroy_array_custom(t_array *array, void (*free_func)(void*))
{
	t_array	*to_del;
	t_array	*tmp;

	if (array)
	{
		tmp = array;
		while (tmp)
		{
			to_del = tmp;
			tmp = tmp->next;
			if (free_func)
				free_func(to_del->data);
			free(to_del);
		}
	}
}

t_array			*array_remove(t_array *root, t_array *to_delete, int free_elem)
{
	t_array	*tmp;
	t_array	*prev;

	prev = NULL;
	tmp = root;
	while (tmp)
	{
		if (tmp == to_delete)
		{
			if (!prev)
				root = tmp->next;
			else
				prev->next = tmp->next;
		}
		prev = tmp;
		tmp = tmp->next;
	}
	if (free_elem)
		free(to_delete->data);
	free(to_delete);
	return (root);
}

unsigned int	array_size(t_array *array)
{
	unsigned int	i;

	i = 0;
	while (array)
	{
		i++;
		array = array->next;
	}
	return (i);
}
