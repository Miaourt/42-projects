/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llaporte <llaporte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/07 07:38:10 by llaporte          #+#    #+#             */
/*   Updated: 2018/01/15 17:48:58 by llaporte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int			check_input(t_stack *stacks, int ac, char **av)
{
	int		i;
	int		j;
	char	**exploded;
	int		tmp;
	char	*tofree;

	i = 1 + stacks->verbose;
	while (i < ac)
	{
		exploded = ft_explode(av[i]);
		j = 0;
		while (exploded[j])
		{
			tmp = ft_atoi(exploded[j]);
			if ((ft_strcmp(tofree = ft_itoa(tmp), exploded[j])))
				return (1);
			free(tofree);
			free(exploded[j]);
			j++;
		}
		free(exploded);
		i++;
	}
	return (0);
}

int			check_if_already_here(t_value *stack, t_value *cursor)
{
	while (stack)
	{
		if (cursor->v == stack->v && stack != cursor)
			return (1);
		stack = stack->next;
	}
	return (0);
}

t_value		*create_stack(t_stack *stacks, int ac, char **av)
{
	int			i;
	int			j;
	char		**exploded;
	t_value		*stack;
	t_value		*cursor;

	i = 1 + stacks->verbose;
	if (!(stack = (t_value*)ft_memalloc(sizeof(t_value))) && i < ac)
		return (NULL);
	cursor = stack;
	while (i++ < ac && cursor)
	{
		exploded = ft_explode(av[i - 1]);
		j = 0;
		while ((exploded[j++] || free_exploded(exploded)) && cursor)
		{
			cursor->v = ft_atoi_free(exploded[j - 1]);
			if (check_if_already_here(stack, cursor) || ((i < ac ||
				exploded[j - 1 + 1]) && !(cursor->next =
				(t_value*)ft_memalloc(sizeof(t_value))) && (i - 1 > 1)))
				return (NULL);
			cursor = cursor->next;
		}
	}
	return (stack);
}

int			is_stack_sorted(t_value *stack)
{
	while (stack && stack->next)
	{
		if (stack->next->v <= stack->v)
			return (0);
		stack = stack->next;
	}
	return (1);
}

int			is_sorted(t_stack *stacks)
{
	if (stacks->b)
		return (1);
	if (!is_stack_sorted(stacks->a))
		return (1);
	return (0);
}
