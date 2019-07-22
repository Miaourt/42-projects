/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llaporte <llaporte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/12 17:50:14 by llaporte          #+#    #+#             */
/*   Updated: 2018/01/09 18:25:22 by llaporte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_s(t_stack *stacks, char mode)
{
	int	tmp;

	if ((mode == 'a' || mode == 's') && stacks->a && stacks->a->next)
	{
		tmp = stacks->a->v;
		stacks->a->v = stacks->a->next->v;
		stacks->a->next->v = tmp;
	}
	if ((mode == 'b' || mode == 's') && stacks->b && stacks->b->next)
	{
		tmp = stacks->b->v;
		stacks->b->v = stacks->b->next->v;
		stacks->b->next->v = tmp;
	}
}

void	push_p(t_stack *stacks, char mode)
{
	t_value	*tmp;

	if (mode == 'a' && stacks->b)
	{
		tmp = stacks->b->next;
		stacks->b->next = stacks->a;
		stacks->a = stacks->b;
		stacks->b = tmp;
	}
	if (mode == 'b' && stacks->a)
	{
		tmp = stacks->a->next;
		stacks->a->next = stacks->b;
		stacks->b = stacks->a;
		stacks->a = tmp;
	}
}

void	push_r(t_stack *stacks, char mode)
{
	t_value	*tmp;
	t_value	*cursor;

	if ((mode == 'a' || mode == 'r') && stacks->a && stacks->a->next)
	{
		tmp = stacks->a->next;
		cursor = stacks->a;
		while (cursor->next)
			cursor = cursor->next;
		cursor->next = stacks->a;
		stacks->a->next = NULL;
		stacks->a = tmp;
	}
	if ((mode == 'b' || mode == 'r') && stacks->b && stacks->b->next)
	{
		tmp = stacks->b->next;
		cursor = stacks->b;
		while (cursor->next)
			cursor = cursor->next;
		cursor->next = stacks->b;
		stacks->b->next = NULL;
		stacks->b = tmp;
	}
}

void	push_rr(t_stack *stacks, char mode)
{
	t_value	*cursor;

	if ((mode == 'a' || mode == 'r') && stacks->a && stacks->a->next)
	{
		cursor = stacks->a;
		while (cursor->next->next)
			cursor = cursor->next;
		cursor->next->next = stacks->a;
		stacks->a = cursor->next;
		cursor->next = NULL;
	}
	if ((mode == 'b' || mode == 'r') && stacks->b && stacks->b->next)
	{
		cursor = stacks->b;
		while (cursor->next->next)
			cursor = cursor->next;
		cursor->next->next = stacks->b;
		stacks->b = cursor->next;
		cursor->next = NULL;
	}
}

int		do_op(char *op, t_stack *stacks)
{
	if (!ft_strcmp(op, "sa") || !ft_strcmp(op, "sb")
		|| !ft_strcmp(op, "ss"))
		push_s(stacks, op[1]);
	else if (!ft_strcmp(op, "pa") || !ft_strcmp(op, "pb"))
		push_p(stacks, op[1]);
	else if (!ft_strcmp(op, "ra") || !ft_strcmp(op, "rb")
		|| !ft_strcmp(op, "rr"))
		push_r(stacks, op[1]);
	else if (!ft_strcmp(op, "rra") || !ft_strcmp(op, "rrb")
		|| !ft_strcmp(op, "rrr"))
		push_rr(stacks, op[2]);
	else
		return (1);
	if (set_ends(stacks))
		return (1);
	return (0);
}
