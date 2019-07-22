/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llaporte <llaporte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/09 17:15:43 by llaporte          #+#    #+#             */
/*   Updated: 2018/01/15 17:45:36 by llaporte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	verbosify(t_stack *stacks, int argc, char **argv)
{
	if (argc > 1)
	{
		if (!ft_strcmp(argv[1], "-v"))
			stacks->verbose = 1;
		else
			stacks->verbose = 0;
	}
}

void	displayer(t_stack *stacks)
{
	t_value *tmp_value_a;
	t_value *tmp_value_b;

	tmp_value_a = stacks->a;
	tmp_value_b = stacks->b;
	ft_putstr("\e[1;33m[\e[0;35mA\e[1;33m][\e[0;35mB\e[1;33m]\e[0m\n");
	while (tmp_value_a || tmp_value_b)
	{
		ft_putstr("\e[0;37m⟨\e[0;36m");
		if (tmp_value_a)
			ft_putnbr(tmp_value_a->v);
		else
			ft_putstr("\e[0;36m-");
		ft_putstr("\e[0;37m⟩⟨\e[0;36m");
		if (tmp_value_b)
			ft_putnbr(tmp_value_b->v);
		else
			ft_putstr("\e[0;36m-");
		ft_putstr("\e[0;37m⟩\n\e[0m");
		if (tmp_value_a)
			tmp_value_a = tmp_value_a->next;
		if (tmp_value_b)
			tmp_value_b = tmp_value_b->next;
	}
}
