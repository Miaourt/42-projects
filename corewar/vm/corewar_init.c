/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar_init.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tguillem <tguillem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/17 22:02:35 by tguillem          #+#    #+#             */
/*   Updated: 2018/03/22 09:25:01 by tguillem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

int			parse_dump(t_options *options, char *val)
{
	if (is_valid_number(val, 0))
		options->dump_cycles = ft_atoi(val);
	else
	{
		ft_printf_fd(2, "Invalid number for -dump\n");
		return (1);
	}
	return (0);
}

int			parse_n_arg(t_options *res, int *i, char **av)
{
	int			player_id;
	t_program	*program;

	if (array_size(res->champions) >= MAX_PLAYERS)
	{
		ft_printf_fd(2, "Too many champions\n");
		return (1);
	}
	player_id = ft_atoi(av[++*i]);
	if (!is_valid_number(av[*i], MIN))
	{
		ft_printf_fd(2, "Invalid number for -n\n");
		return (1);
	}
	if (!(program = load_program(av[++*i])))
		return (1);
	if (is_conflicting_id(res->champions, player_id))
	{
		ft_printf_fd(2, "Conflicting player id %d!\n", player_id);
		return (1);
	}
	program->has_arbitrary_id = 1;
	program->id = player_id;
	res->champions = array_init(res->champions, program);
	return (0);
}

int			parse_standard_champ(t_options *res, char *path)
{
	t_program	*program;

	if (array_size(res->champions) >= MAX_PLAYERS)
	{
		ft_printf_fd(2, "Too many champions\n");
		return (1);
	}
	if (!(program = load_program(path)))
		return (1);
	res->champions = array_init(res->champions, program);
	return (0);
}

t_options	*new_options(void)
{
	t_options	*res;

	if (!(res = ft_memalloc(sizeof(t_options))))
		return (NULL);
	res->dump_cycles = 50000;
	return (res);
}

t_options	*get_options(int ac, char **av)
{
	t_options	*res;
	int			i;

	i = 1;
	res = new_options();
	while (res && i < ac)
	{
		if (!ft_strcmp(av[i], "-dump") && (i + 1) < ac)
		{
			if (parse_dump(res, av[++i]))
				return (destroy_options(res));
		}
		else if (!ft_strcmp(av[i], "-n") && (i + 2) < ac)
		{
			if (parse_n_arg(res, &i, av))
				return (destroy_options(res));
		}
		else
		{
			if (parse_standard_champ(res, av[i]))
				return (destroy_options(res));
		}
		i++;
	}
	return (res);
}
