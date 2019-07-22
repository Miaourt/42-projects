/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm_setup.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tguillem <tguillem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/13 13:34:41 by tguillem          #+#    #+#             */
/*   Updated: 2018/03/17 22:01:06 by tguillem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

t_vm					*create_vm(int32_t players_expected, int32_t max_cycles)
{
	t_vm	*res;

	if (players_expected > MAX_PLAYERS)
	{
		ft_printf_fd(2, "Too many champions\n");
		return (NULL);
	}
	if (!(res = ft_memalloc(sizeof(t_vm))))
	{
		ft_printf_fd(2, "Not enough memory to allocae the VM\n");
		return (NULL);
	}
	if (!(res->memory = ft_memalloc(sizeof(uint8_t) * MEM_SIZE)))
	{
		ft_printf_fd(2, "Not enough memory to allocae the VM memory\n");
		free(res);
		return (NULL);
	}
	res->max_cycles = max_cycles;
	res->players_expected = players_expected;
	res->cycles_to_die = CYCLE_TO_DIE;
	res->next_die = res->cycles_to_die;
	return (res);
}

t_program_context		*load_vm_program(t_vm *vm, t_program *prg)
{
	t_program_context	*res;
	t_array				*prg_contexts_root;

	if (prg && (res = ft_memalloc(sizeof(t_program_context))))
	{
		res->id = prg->id;
		res->program = prg;
		if ((prg_contexts_root = array_init(vm->prg_contexts, res)))
		{
			vm->prg_contexts = prg_contexts_root;
			ft_memcpy(
				vm->memory + (vm->players_count++) *
					(MEM_SIZE / vm->players_expected), prg->code,
					prg->header->prog_size);
			if (create_process(vm, res,
				(vm->players_count - 1) * (MEM_SIZE / vm->players_expected)))
			{
				res->alive = 0;
				corewar_live(vm, res->id, NULL);
				return (res);
			}
		}
		free(res);
	}
	return (NULL);
}

static void				free_program_context(void *data)
{
	t_program_context	*context;

	if (data)
	{
		context = (t_program_context*)data;
		free(context);
	}
}

void					destroy_vn(t_vm *vm)
{
	if (vm)
	{
		free(vm->memory);
		destroy_array_custom(vm->prg_contexts, free_program_context);
		destroy_array_custom(vm->processes, free);
		free(vm);
	}
}

void					dump_vm(t_vm *vm)
{
	int i;

	i = 0;
	ft_printf("\n0x%04x : ", i);
	while (i < MEM_SIZE)
	{
		ft_printf("%s%x ", vm->memory[i] > 15 ? "" : "0",
			vm->memory[i]);
		if (!((i + 1) % 64) && i + 1 < MEM_SIZE)
		{
			ft_printf("\n0x%04x : ", i + 1);
		}
		i++;
	}
	ft_printf("\n");
}
