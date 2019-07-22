/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm_cycle.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tguillem <tguillem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/23 17:01:21 by tguillem          #+#    #+#             */
/*   Updated: 2018/03/17 19:57:47 by tguillem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void	corewar_ending(t_vm *ctx)
{
	t_array				*winner;
	t_array				*tmp;
	t_program_context	*winner_ctx;

	dump_vm(ctx);
	winner = NULL;
	tmp = ctx->prg_contexts;
	while (tmp)
	{
		if (!winner)
			winner = tmp;
		else if (((t_program_context*)winner->data)->last_live <=
			((t_program_context*)tmp->data)->last_live)
			winner = tmp;
		tmp = tmp->next;
	}
	if (winner)
	{
		winner_ctx = (t_program_context*)winner->data;
		ft_printf("le joueur %d(%s) a gagne\n", winner_ctx->id,
			winner_ctx->program->header->prog_name);
	}
	else
		ft_printf("No players alive :(\n");
	ft_printf("Game Over\n");
}

void	corewar_live(t_vm *vm, int32_t program_id, t_process_context *process)
{
	t_array				*prg_entry;
	t_program_context	*prg;

	prg_entry = vm->prg_contexts;
	while (prg_entry)
	{
		if (((t_program_context*)prg_entry->data)->id == program_id)
			break ;
		prg_entry = prg_entry->next;
	}
	if (prg_entry)
	{
		prg = (t_program_context*)prg_entry->data;
		if (process)
		{
			process->last_live = vm->current_cycle;
			ft_printf("un processus dit que le joueur %d(%s) est en vie\n",
				prg->id, prg->program->header->prog_name);
		}
		prg->last_live = vm->current_cycle;
		prg->alive = 1;
	}
}

void	corewar_die_cycle_cleanup(t_vm *ctx)
{
	t_array		*tmp;

	++ctx->check_count;
	if (ctx->lives >= NBR_LIVE || ctx->check_count == MAX_CHECKS)
	{
		ctx->check_count = 0;
		ctx->cycles_to_die -= CYCLE_DELTA;
		ft_printf("Cycle to die is now %d\n", ctx->cycles_to_die);
	}
	ctx->lives = 0;
	ctx->next_die = ctx->current_cycle + ctx->cycles_to_die;
	tmp = ctx->prg_contexts;
	while (tmp)
	{
		((t_program_context*)tmp->data)->alive = 0;
		tmp = tmp->next;
	}
}

void	corewar_die_cycle(t_vm *ctx)
{
	t_array				*processes;
	t_array				*tmp;
	uint32_t			proc_count;
	uint32_t			i;
	t_process_context	*process;

	i = 0;
	processes = ctx->processes;
	proc_count = array_size(processes);
	while (processes && i < proc_count)
	{
		tmp = processes;
		processes = processes->next;
		process = ((t_process_context*)tmp->data);
		if ((ctx->current_cycle - process->last_live) > ctx->cycles_to_die)
		{
			ft_printf("Process %d hasn't lived for %d cycles (CTD %d)\n",
				process->pid, ctx->current_cycle - process->last_live,
				ctx->cycles_to_die,
				process->program_context->program->header->prog_name);
			ctx->processes = array_remove(ctx->processes, tmp, 1);
		}
	}
	corewar_die_cycle_cleanup(ctx);
}

int		corewar_cycle(t_vm *ctx)
{
	t_array		*processes;
	uint32_t	i;
	uint32_t	proc_count;

	processes = ctx->processes;
	proc_count = array_size(processes);
	if (ctx->current_cycle == ctx->max_cycles || proc_count == 0)
		return (0);
	++ctx->current_cycle;
	i = 0;
	ft_printf("It is now cycle %u\n", ctx->current_cycle);
	while (processes && i < proc_count)
	{
		((t_process_context*)processes->data)->freeze--;
		if (((t_process_context*)processes->data)->freeze <= 0)
			vm_exec_inst(ctx, (t_process_context*)processes->data);
		processes = processes->next;
		i++;
	}
	if (ctx->current_cycle >= ctx->next_die)
		corewar_die_cycle(ctx);
	return (1);
}
