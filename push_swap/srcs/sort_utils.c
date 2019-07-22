/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llaporte <llaporte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/19 19:00:12 by llaporte          #+#    #+#             */
/*   Updated: 2018/01/09 18:23:21 by llaporte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_op(char *op, t_stack *stacks)
{
	if (ft_strcmp("oups", op))
	{
		do_op(op, stacks);
		ft_putstr(op);
		ft_putchar('\n');
	}
}

int		contain_value(int data, int *array, int len)
{
	int i;

	i = 0;
	while (i < len)
	{
		if (data == array[i])
			return (1);
		i++;
	}
	return (0);
}

int		get_biggest(t_value *stack, int *array, int len, int pos)
{
	int max;

	max = INT_MAX;
	while (stack)
	{
		if (stack->v < max && pos < stack->v &&
			!contain_value(stack->v, array, len))
			max = stack->v;
		stack = stack->next;
	}
	return (max);
}

int		is_smallest(t_value *src, t_value *cmp)
{
	src = get_min(src);
	if (src && cmp && src->v > cmp->v)
		return (1);
	return (0);
}

int		is_biggest(t_value *stack, int n, int min)
{
	if (stack->v == min || stack->next->v == min)
		return (0);
	if (stack->v < n && stack->next->v < n)
		return (1);
	return (0);
}
