/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_specials.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tguillem <tguillem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/23 11:13:41 by tguillem          #+#    #+#             */
/*   Updated: 2018/03/12 14:12:26 by tguillem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void		op_live(t_vm *vm, t_process_context *ctx, t_op_data *data)
{
	(void)vm;
	(void)ctx;
	ft_printf("[%d] live %x\n", ctx->pid, data->params[0]);
	corewar_live(vm, data->params[0], ctx);
	vm->lives++;
}

void		op_aff(t_vm *vm, t_process_context *ctx, t_op_data *data)
{
	int32_t	*input;

	(void)vm;
	if ((input = get_register(ctx, data, 0)))
	{
		ft_printf("[%d] aff: %c\n", ctx->pid, (char)(*input % 256));
	}
}

void		op_sti(t_vm *vm, t_process_context *ctx, t_op_data *data)
{
	int32_t		input[2];
	int32_t		target_addr;
	int32_t		*input_reg;

	(void)vm;
	if (!(input_reg = get_register(ctx, data, 0)))
		return ;
	input[0] = get_value(ctx, data, 1);
	if (!is_register(ctx, data, 1))
		input[0] = (int16_t)input[0];
	target_addr = input[0];
	input[1] = get_value(ctx, data, 2);
	if (!is_register(ctx, data, 2))
		input[1] = (int16_t)input[1];
	target_addr += input[1];
	ft_printf("[%d]: sti r%d, %d, %d\n", ctx->pid, data->params[0],
					data->params[1], data->params[2]);
	process_memory_write(ctx, ctx->inst_pos + (target_addr % IDX_MOD),
		input_reg, sizeof(int32_t));
}

void		op_zjmp(t_vm *vm, t_process_context *ctx, t_op_data *data)
{
	int32_t	target;

	(void)vm;
	ft_printf("[%d]: zjmp 0x%x\n", ctx->pid, data->params[0]);
	target = ((ctx->inst_pos + ((int16_t)data->params[0] % IDX_MOD)
							+ MEM_SIZE) % MEM_SIZE);
	if (ctx->carry)
		ctx->pc = target;
}
