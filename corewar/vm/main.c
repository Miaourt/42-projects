/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tguillem <tguillem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/13 13:35:41 by tguillem          #+#    #+#             */
/*   Updated: 2018/03/22 09:30:04 by tguillem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

static int		error_cleanup(t_vm *vm)
{
	ft_printf_fd(2, "Error during VM initialization\n");
	destroy_vn(vm);
	return (1);
}

static int		internal_execute_corewar(t_options *options)
{
	t_vm		*vm;
	int			running;
	t_array		*champions;

	champions = options->champions;
	running = 1;
	if ((vm = create_vm(array_size(options->champions), options->dump_cycles)))
	{
		while (champions)
		{
			if (!load_vm_program(vm, (t_program*)champions->data))
				return (error_cleanup(vm));
			champions = champions->next;
		}
		while (running)
			running = corewar_cycle(vm);
		corewar_ending(vm);
		destroy_vn(vm);
		return (0);
	}
	return (1);
}

int				execute_corewar(int ac, char **av)
{
	t_options	*options;
	int			res;

	if ((options = get_options(ac, av)))
	{
		options->champions = reorder_champions(options->champions);
		res = internal_execute_corewar(options);
		destroy_options(options);
		return (res);
	}
	return (1);
}

int				main(int ac, char **av)
{
	int res;

	ft_atexit(resource_manager_destroy);
	if (ac < 2)
	{
		ft_printf_fd(2,
			"%s [-dump nbr_cycles] [[-n number] champion1.cor] ...\n",
			*av);
		ft_exit(1);
	}
	res = execute_corewar(ac, av);
	ft_prepare_exit();
	return (res);
}
