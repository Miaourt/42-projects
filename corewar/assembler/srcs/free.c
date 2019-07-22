/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthuilli <dthuilli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/07 16:10:49 by dthuilli          #+#    #+#             */
/*   Updated: 2018/03/16 16:32:26 by dthuilli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "assembler.h"

void	free_ops(t_ops *ops)
{
	t_ops		*tmp;
	int			i;

	tmp = ops;
	while (tmp)
	{
		tmp = ops->next;
		i = 0;
		while (ops->args[i])
		{
			ft_memdel((void **)&ops->args[i]->raw);
			ft_memdel((void **)&ops->args[i]);
			++i;
		}
		ft_memdel((void **)&ops);
		ops = tmp;
	}
}

void	free_labels(t_label *labels)
{
	t_label		*tmp;

	tmp = labels;
	while (tmp)
	{
		tmp = labels->next;
		ft_memdel((void **)&labels->name);
		ft_memdel((void **)&labels);
		labels = tmp;
	}
}

void	free_struct(t_champ *champ)
{
	if (champ)
	{
		if (champ->labels)
			free_labels(champ->labels);
		if (champ->ops)
			free_ops(champ->ops);
		if (champ->data)
			ft_memdel((void **)&champ->data);
		ft_memdel((void **)&champ);
	}
}
