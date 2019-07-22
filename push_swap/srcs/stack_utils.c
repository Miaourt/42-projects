/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llaporte <llaporte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/19 18:33:34 by llaporte          #+#    #+#             */
/*   Updated: 2018/01/09 18:24:38 by llaporte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_value	*get_max(t_value *stack)
{
	t_value *tmp;
	t_value *max;

	max = NULL;
	tmp = stack;
	while (tmp)
	{
		if (!max || tmp->v > max->v)
			max = tmp;
		tmp = tmp->next;
	}
	return (max);
}

t_value	*get_min(t_value *stack)
{
	t_value *tmp;
	t_value *min;

	min = NULL;
	tmp = stack;
	while (tmp)
	{
		if (!min || tmp->v < min->v)
			min = tmp;
		tmp = tmp->next;
	}
	return (min);
}

int		stack_len(t_value *stack)
{
	int		i;
	t_value	*tmp;

	i = 0;
	tmp = stack;
	while (tmp)
	{
		i++;
		tmp = tmp->next;
	}
	return (i);
}

int		set_ends(t_stack *stacks)
{
	t_value		*cursor;

	cursor = stacks->a;
	while (cursor && cursor->next)
		cursor = cursor->next;
	stacks->end_a = cursor;
	cursor = stacks->b;
	while (cursor && cursor->next)
		cursor = cursor->next;
	stacks->end_b = cursor;
	return (0);
}
