/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   merge_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llaporte <llaporte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/08 17:29:59 by llaporte          #+#    #+#             */
/*   Updated: 2018/01/09 18:22:17 by llaporte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	order_stacks(t_stack *stacks, int min)
{
	if (stacks->a->v > stacks->a->next->v &&
		stacks->a->next->v != min && stacks->a->v != min)
		push_op("sa", stacks);
	if (stacks->end_a->v > stacks->a->v && stacks->a->v
		!= min)
	{
		push_op("rra", stacks);
		push_op("sa", stacks);
	}
	if (stack_len(stacks->b) > 2 && stacks->b->v >
		stacks->b->next->v && stacks->b->v >
			stacks->b->next->next->v)
		push_op("rr", stacks);
	else
		push_op("ra", stacks);
}

int		need_reverse_rotation(t_stack *stacks)
{
	int		len;
	int		min;
	int		index;
	int		i;
	t_value	*tmp;

	min = INT_MAX;
	len = stack_len(stacks->b);
	i = 0;
	tmp = stacks->b;
	while (tmp)
	{
		if (min > tmp->v)
		{
			min = tmp->v;
			index = i;
		}
		i++;
		tmp = tmp->next;
	}
	if (index > (len / 2))
		return (1);
	else
		return (0);
}

void	rotation_selector(t_stack *stacks)
{
	if (need_reverse_rotation(stacks))
		push_op("rrb", stacks);
	else
		push_op("rb", stacks);
}

void	rotation_chooser(t_stack *stacks, int min)
{
	t_value		*small;

	small = get_min(stacks->b);
	if (small->v > stacks->a->v && stacks->a->v != min)
		push_op("rr", stacks);
	else
		push_op("rb", stacks);
}
