/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llaporte <llaporte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/05 00:05:55 by llaporte          #+#    #+#             */
/*   Updated: 2018/01/26 15:12:39 by llaporte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		err(char *error, t_stack *stacks)
{
	cleaner(stacks);
	ft_putstr_fd(error, 2);
	return (1);
}

int		operation_check(t_stack *stacks)
{
	char *buffer;

	while ((ft_gnl(0, &buffer)))
	{
		if (do_op(buffer, stacks))
			return (1);
		if (stacks->verbose)
		{
			ft_putstr("\e[0;35mOP\e[0;33m -> \e[0;91m");
			ft_putstr(buffer);
			ft_putstr("\n\n\e[0m");
			displayer(stacks);
			ft_putstr("\n\n");
		}
		free(buffer);
	}
	return (0);
}

int		main(int argc, char **argv)
{
	t_stack	*stacks;

	if (!(stacks = (t_stack*)ft_memalloc(sizeof(t_stack))))
		return (err("Error\n", stacks));
	verbosify(stacks, argc, argv);
	if ((argc - stacks->verbose) <= 1)
		return (0);
	if (check_input(stacks, argc, argv))
		return (err("Error\n", stacks));
	if (!(stacks->a = create_stack(stacks, argc, argv)))
		return (err("Error\n", stacks));
	if (operation_check(stacks))
		return (err("Error\n", stacks));
	if (is_sorted(stacks))
		return (err("KO\n", stacks));
	cleaner(stacks);
	ft_putstr("OK\n");
	return (0);
}
