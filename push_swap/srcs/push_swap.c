/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llaporte <llaporte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/13 16:38:27 by llaporte          #+#    #+#             */
/*   Updated: 2018/01/26 15:13:31 by llaporte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		err(char *error, t_stack *stacks)
{
	cleaner(stacks);
	ft_putstr_fd(error, 2);
	return (1);
}

void	finalize_fast_swap(t_stack *stacks)
{
	while (stack_len(stacks->b) > 0)
	{
		while (stack_len(stacks->b) > 1 && stacks->end_b->v >
			stacks->b->v)
			push_op("rrb", stacks);
		push_op("pa", stacks);
		if (stack_len(stacks->b) > 1 && stack_len(stacks->a) > 1 &&
			stacks->a->v > stacks->a->next->v &&
			stacks->b->v < stacks->b->next->v)
			push_op("ss", stacks);
		else
		{
			if (stack_len(stacks->a) > 1 && stacks->a->v >
				stacks->a->next->v)
				push_op("sa", stacks);
			if (stack_len(stacks->b) > 1 && stacks->b->v <
				stacks->b->next->v)
				push_op("sb", stacks);
		}
	}
}

void	fast_swap_operations(t_stack *stacks, t_value *max)
{
	if (stack_len(stacks->b) > 1 && stacks->a->v >
		stacks->a->next->v && stacks->b->v <
			stacks->b->next->v)
		push_op("ss", stacks);
	else if (stacks->a->v > stacks->a->next->v)
		push_op("sa", stacks);
	else if (stack_len(stacks->b) > 1 && stacks->b->v <
		stacks->b->next->v)
		push_op("sb", stacks);
	else if (max == stacks->a || (stack_len(stacks->b) > 2 &&
			stacks->a->v > stacks->a->next->v &&
			stacks->a->v > stacks->a->next->next->v))
		push_op("ra", stacks);
	while (stack_len(stacks->a) > 2 && stacks->end_a->v <
		stacks->a->v && stacks->end_a->v <
			stacks->a->next->v)
		push_op("rra", stacks);
	if (stack_len(stacks->b) > 1 && stacks->end_b->v >
		stacks->b->v)
		push_op("rrb", stacks);
}

void	fast_swap(t_stack *stacks)
{
	t_value		*max;

	max = get_max(stacks->a);
	while (stacks->a && stacks->a->next)
	{
		fast_swap_operations(stacks, max);
		if (is_stack_sorted(stacks->a))
			break ;
		push_op("pb", stacks);
		if (stack_len(stacks->b) > 2 && ((stacks->b->v <
			stacks->b->next->v && stacks->b->v <
			stacks->b->next->next->v) || stacks->end_b->v >
			stacks->b->v))
			push_op("rb", stacks);
	}
	finalize_fast_swap(stacks);
}

int		main(int argc, char **argv)
{
	t_stack	*stacks;

	if (!(stacks = (t_stack*)ft_memalloc(sizeof(t_stack))))
		return (err("Error\n", stacks));
	verbosify(stacks, argc, argv);
	if (check_input(stacks, argc, argv))
		return (err("Error\n", stacks));
	if (!(stacks->a = create_stack(stacks, argc, argv)))
		return (err("Error\n", stacks));
	if (set_ends(stacks))
		return (err("Error\n", stacks));
	if (!is_sorted(stacks))
		return (0);
	if ((argc - 1 + stacks->verbose) >= 40)
		merge_swap(stacks, INT_MIN, 0);
	else
		while (is_sorted(stacks))
			fast_swap(stacks);
	cleaner(stacks);
	return (0);
}
