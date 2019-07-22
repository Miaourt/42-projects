/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_merge.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llaporte <llaporte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/08 14:52:03 by llaporte          #+#    #+#             */
/*   Updated: 2018/01/09 18:27:15 by llaporte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		*get_sorted_array(t_value *stack, int len, int pos)
{
	int	i;
	int	*array;

	i = 0;
	if (!(array = (int*)ft_memalloc(sizeof(int) * len)))
		return (NULL);
	while (i < len)
	{
		array[i] = get_biggest(stack, array, i, pos);
		i++;
	}
	return (array);
}

void	final_sorting_and_cleanup(t_stack *stacks, int *sorted)
{
	ft_memdel((void**)&sorted);
	while (stacks->a->v > stacks->end_a->v)
		push_op("ra", stacks);
}

void	order_and_push_to_a(t_stack *stacks, int min)
{
	if (stack_len(stacks->a) > 1 && stacks->end_a->v >
		stacks->a->v)
		push_op("rra", stacks);
	while (stack_len(stacks->b) > 1)
	{
		if (stack_len(stacks->b) > 2 && stacks->b->v >
			stacks->b->next->v && stacks->b->v >
			stacks->b->next->next->v)
			rotation_chooser(stacks, min);
		while (stack_len(stacks->a) > 1 && is_biggest(stacks->a,
			stacks->b->v, min))
			rotation_selector(stacks);
		push_op("pa", stacks);
		if (stacks->a->v > stacks->a->next->v &&
			stacks->a->next->v != min)
			push_op(stack_len(stacks->b) > 1 && stacks->b->v >
				stacks->b->next->v ? "ss" : "sa", stacks);
		while (is_smallest(stacks->b, stacks->a) &&
			!is_stack_sorted(stacks->a))
			order_stacks(stacks, min);
	}
	push_op("pa", stacks);
	push_op(stacks->a->v > stacks->a->next->v &&
		stacks->a->next->v != min ? "sa" : "oups", stacks);
	push_op("ra", stacks);
}

void	reorder_b(t_stack *stacks, int *sorted, int cut)
{
	if (stack_len(stacks->b) <= 1)
		return ;
	if (stacks->b->v > stacks->end_b->v)
		push_op("rb", stacks);
	if (stacks->b->v > stacks->b->next->v &&
		stack_len(stacks->a) > 1)
	{
		if (contain_value(stacks->a->v, sorted, cut) &&
			contain_value(stacks->a->next->v, sorted, cut) &&
			stacks->a->next->v > stacks->a->v)
			push_op("ss", stacks);
	}
}

void	merge_swap(t_stack *stacks, int pos, int old_min)
{
	int			cut;
	int			*sorted;
	int			i;
	int			min;

	cut = stack_len(stacks->a) / 2;
	sorted = get_sorted_array(stacks->a, cut, pos);
	min = pos == INT_MIN ? sorted[0] : old_min;
	i = cut;
	while (i)
	{
		if (contain_value(stacks->a->v, sorted, cut) &&
			contain_value(stacks->a->next->v, sorted, cut) &&
			stacks->a->next->v > stacks->a->v)
			push_op("sa", stacks);
		if (contain_value(stacks->a->v, sorted, cut) && (--i || 1))
			push_op("pb", stacks);
		else
			push_op("ra", stacks);
		reorder_b(stacks, sorted, cut);
	}
	order_and_push_to_a(stacks, min);
	if (pos == INT_MIN)
		merge_swap(stacks, sorted[cut - 1], min);
	final_sorting_and_cleanup(stacks, sorted);
}
