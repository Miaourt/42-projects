/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tguillem <tguillem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/10/04 11:43:01 by zaz               #+#    #+#             */
/*   Updated: 2018/02/26 16:10:43 by tguillem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"
#include <stdlib.h>

t_op	g_op_tab[17] =
{
	{"live", 1, {T_DIR}, 1, 10, "alive", 0, 0, &op_live},
	{"ld", 2, {T_DIR | T_IND, T_REG}, 2, 5, "load", 1, 0, &op_ld},
	{"st", 2, {T_REG, T_IND | T_REG}, 3, 5, "store", 1, 0, &op_st},
	{"add", 3, {T_REG, T_REG, T_REG}, 4, 10, "addition", 1, 0, &op_add},
	{"sub", 3, {T_REG, T_REG, T_REG}, 5, 10, "soustraction", 1, 0, &op_sub},
	{"and", 3, {T_REG | T_DIR | T_IND, T_REG | T_IND | T_DIR, T_REG}, 6, 6,
		"et (and  r1, r2, r3   r1&r2 -> r3", 1, 0, &op_and},
	{"or", 3, {T_REG | T_IND | T_DIR, T_REG | T_IND | T_DIR, T_REG}, 7, 6,
		"ou  (or   r1, r2, r3   r1 | r2 -> r3", 1, 0, &op_or},
	{"xor", 3, {T_REG | T_IND | T_DIR, T_REG | T_IND | T_DIR, T_REG}, 8, 6,
		"ou (xor  r1, r2, r3   r1^r2 -> r3", 1, 0, &op_xor},
	{"zjmp", 1, {T_DIR}, 9, 20, "jump if zero", 0, 1, &op_zjmp},
	{"ldi", 3, {T_REG | T_DIR | T_IND, T_DIR | T_REG, T_REG}, 10, 25,
		"load index", 1, 1, &op_ldi},
	{"sti", 3, {T_REG, T_REG | T_DIR | T_IND, T_DIR | T_REG}, 11, 25,
		"store index", 1, 1, &op_sti},
	{"fork", 1, {T_DIR}, 12, 800, "fork", 0, 1, &op_fork},
	{"lld", 2, {T_DIR | T_IND, T_REG}, 13, 10, "long load", 1, 0, &op_lld},
	{"lldi", 3, {T_REG | T_DIR | T_IND, T_DIR | T_REG, T_REG}, 14, 50,
		"long load index", 1, 1, &op_lldi},
	{"lfork", 1, {T_DIR}, 15, 1000, "long fork", 0, 1, &op_lfork},
	{"aff", 1, {T_REG}, 16, 2, "aff", 1, 0, &op_aff},
	{0, 0, {0}, 0, 0, 0, 0, 0, 0}
};

void		op_ld(t_vm *vm, t_process_context *ctx, t_op_data *data)
{
	int32_t	*output;

	(void)vm;
	if (!(output = get_register(ctx, data, 1)))
		return ;
	ft_printf("[%d]: ld %d r%d\n", ctx->pid, data->params[0], data->params[1]);
	*output = get_value(ctx, data, 0);
	ctx->carry = *output == 0;
}

void		op_lld(t_vm *vm, t_process_context *ctx, t_op_data *data)
{
	int32_t	*output;

	(void)vm;
	if (!(output = get_register(ctx, data, 1)))
		return ;
	ft_printf("[%d]: lld %d r%d\n", ctx->pid, data->params[0], data->params[1]);
	*output = get_value(ctx, data, 0);
	ctx->carry = *output == 0;
}

void		op_st(t_vm *vm, t_process_context *ctx, t_op_data *data)
{
	int32_t		*input_one;
	int8_t		indirect_write;
	int32_t		*output;

	(void)vm;
	output = NULL;
	indirect_write = 0;
	if (!(input_one = get_register(ctx, data, 0))
					|| !(output = get_register(ctx, data, 1)))
	{
		if (input_one && is_indirect(ctx, data, 1))
			indirect_write = 1;
		else
			return ;
	}
	ft_printf("[%d]: st r%d %d\n", ctx->pid, data->params[0], data->params[1]);
	if (indirect_write)
		process_memory_write(ctx, ctx->inst_pos +
						((int16_t)data->params[1] % IDX_MOD),
						input_one,
						sizeof(*input_one));
	else
		*output = *input_one;
}

void		op_ldi(t_vm *vm, t_process_context *ctx, t_op_data *data)
{
	int32_t	input[2];
	int32_t	target_addr;
	int32_t	*output;

	(void)vm;
	if (!(output = get_register(ctx, data, 2)))
		return ;
	input[0] = get_value(ctx, data, 0);
	if (!is_register(ctx, data, 0))
		input[0] = (int16_t)input[0];
	target_addr = input[0];
	input[1] = get_value(ctx, data, 1);
	if (!is_register(ctx, data, 1))
		input[1] = (int16_t)input[1];
	target_addr += input[1];
	ft_printf("[%d]: ldi %d, %d, r%d\n", ctx->pid, data->params[0],
					data->params[1], data->params[2]);
	process_memory_read(ctx, ctx->inst_pos + (target_addr % IDX_MOD),
					output, sizeof(*output));
	*output = swap_int32(*output);
}

void		op_lldi(t_vm *vm, t_process_context *ctx, t_op_data *data)
{
	int32_t		input[2];
	int32_t		target_addr;
	int32_t		*output;

	(void)vm;
	if (!(output = get_register(ctx, data, 2)))
		return ;
	input[0] = get_value(ctx, data, 0);
	if (!is_register(ctx, data, 0))
		input[0] = (int16_t)input[0];
	target_addr = input[0];
	input[1] = get_value(ctx, data, 1);
	if (!is_register(ctx, data, 1))
		input[1] = (int16_t)input[1];
	target_addr += input[1];
	ft_printf("[%d]: lldi %d, %d, r%d\n", ctx->pid, data->params[0],
					data->params[1], data->params[2]);
	process_memory_read(ctx, ctx->inst_pos + target_addr, output,
		sizeof(*output));
	*output = swap_int32(*output);
	ctx->carry = *output == 0;
}
