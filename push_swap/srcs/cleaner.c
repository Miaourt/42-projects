/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleaner.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llaporte <llaporte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/11 11:16:22 by llaporte          #+#    #+#             */
/*   Updated: 2018/01/11 12:07:14 by llaporte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	cleaner(t_stack *stacks)
{
	t_value *tofree;

	while (stacks->a)
	{
		tofree = stacks->a;
		stacks->a = stacks->a->next;
		free(tofree);
	}
	while (stacks->b)
	{
		tofree = stacks->b;
		stacks->b = stacks->b->next;
		free(tofree);
	}
	free(stacks);
}

int		ft_atoi_free(char *str)
{
	int result;

	result = ft_atoi(str);
	free(str);
	return (result);
}

int		free_exploded(char **str)
{
	free(str);
	return (0);
}
