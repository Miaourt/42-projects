/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tguillem <tguillem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/14 12:59:44 by tguillem          #+#    #+#             */
/*   Updated: 2018/03/19 17:21:18 by tguillem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

t_process_context	*create_process(t_vm *vm_ctx, t_program_context *prg_ctx,
	uint32_t pc)
{
	t_process_context	*res;
	t_array				*processes_root;

	if ((res = ft_memalloc(sizeof(t_process_context))))
	{
		res->registers[0] = prg_ctx->id;
		res->program_context = prg_ctx;
		res->pc = pc;
		res->entry_point = vm_ctx->memory;
		res->pid = ++vm_ctx->next_pid;
		if (!(processes_root = array_reverse_init(vm_ctx->processes, res)))
		{
			free(res);
			return (NULL);
		}
		vm_ctx->processes = processes_root;
	}
	return (res);
}

void				fork_process(t_vm *vm_ctx, t_process_context *proc_ctx,
	int16_t offset, int long_mode)
{
	t_process_context	*res;
	uint32_t			pc;
	uint32_t			pid;

	if (long_mode)
		pc = ((proc_ctx->inst_pos + offset + MEM_SIZE) % MEM_SIZE);
	else
		pc = ((proc_ctx->inst_pos + (offset % IDX_MOD) + MEM_SIZE) % MEM_SIZE);
	if ((res = create_process(vm_ctx, proc_ctx->program_context,
		proc_ctx->pc)))
	{
		pid = res->pid;
		ft_memcpy(res, proc_ctx, sizeof(t_process_context));
		res->freeze = 0;
		res->pid = pid;
		res->pc = pc;
		res->current_instruction = NULL;
	}
}

void				op_fork(t_vm *vm, t_process_context *ctx, t_op_data *data)
{
	int16_t val;

	val = data->params[0];
	ft_printf("[%d]: fork %d\n", ctx->pid, val);
	fork_process(vm, ctx, val, 0);
}

void				op_lfork(t_vm *vm, t_process_context *ctx, t_op_data *data)
{
	int16_t val;

	val = data->params[0];
	ft_printf("[%d]: lfork 0x%x\n", ctx->pid, val);
	fork_process(vm, ctx, val, 1);
}
