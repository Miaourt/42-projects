/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm_exec.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tguillem <tguillem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/19 15:54:35 by tguillem          #+#    #+#             */
/*   Updated: 2018/03/18 00:32:44 by tguillem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

int			check_param(t_op *op, t_op_data *data)
{
	int		i;

	i = -1;
	while (++i < op->nb_params)
	{
		if ((op->param_types[i] >> (data->param_pcodes[i] - 1)) % 2 == 0)
			return (1);
		if (data->param_pcodes[i] == REG_CODE && data->params[i] > REG_NUMBER)
			return (2);
	}
	return (0);
}

void		dump_registers(t_process_context *ctx)
{
	int		i;

	ft_printf("DUMP REGISTERS\n");
	i = 0;
	while (i < REG_NUMBER)
	{
		ft_printf("r%d: %x\n", i + 1, ctx->registers[i]);
		i++;
	}
	ft_printf("pc: 0x%x\n", ctx->inst_pos);
}

void		vm_exec_inst(t_vm *vm, t_process_context *ctx)
{
	t_op		*op;
	t_op_data	data;

	op = ctx->current_instruction;
	ft_bzero(&data, sizeof(data));
	if (op)
	{
		if (!decode_params(ctx, &data))
		{
			if (check_param(op, &data))
				return ;
			if (op->handle)
				op->handle(vm, ctx, &data);
			ctx->current_instruction = NULL;
		}
	}
	else if ((op = decode_instruction(ctx)))
	{
		ctx->current_instruction = op;
		ctx->freeze = op->nb_cycles - 1;
	}
}
