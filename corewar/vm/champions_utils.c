/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   champions_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tguillem <tguillem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/17 22:36:30 by tguillem          #+#    #+#             */
/*   Updated: 2018/03/18 00:25:44 by tguillem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

int				is_conflicting_id(t_array *champions, int32_t id)
{
	t_program	*champ;

	while (champions)
	{
		champ = champions->data;
		if (champ->id == id)
			return (1);
		champions = champions->next;
	}
	return (0);
}

static int32_t	get_new_program_id(t_array *champions)
{
	int			rtn;
	int			found;
	uint32_t	i;
	uint32_t	size;
	t_program	*champ;

	size = array_size(champions);
	rtn = 1;
	found = 0;
	while (!found)
	{
		i = 0;
		found = 1;
		while (i < size)
		{
			champ = champions->data;
			if (champ->id == rtn && (found = 0))
				break ;
			i++;
		}
		if (!found)
			rtn++;
	}
	return (rtn);
}

t_array			*reorder_champions(t_array *champions)
{
	t_array		*tmp;
	t_program	*champ;

	tmp = champions;
	while (tmp)
	{
		champ = tmp->data;
		if (!champ->has_arbitrary_id)
			champ->id = get_new_program_id(champions);
		tmp = tmp->next;
	}
	champions = sort_champions(champions);
	return (champions);
}
