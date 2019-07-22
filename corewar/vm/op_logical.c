/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_logical.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tguillem <tguillem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/23 10:23:17 by tguillem          #+#    #+#             */
/*   Updated: 2018/03/17 15:46:58 by tguillem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void		op_add(t_vm *vm, t_process_context *ctx, t_op_data *data)
{
	int32_t		*input_one;
	int32_t		*input_two;
	int32_t		*output;

	(void)vm;
	if (!(input_one = get_register(ctx, data, 0))
					|| !(input_two = get_register(ctx, data, 1))
					|| !(output = get_register(ctx, data, 2)))
		return ;
	ft_printf("[%d] add r%d, r%d\n", ctx->pid, data->params[0],
		data->params[1]);
	*output = *input_one + *input_two;
	ctx->carry = *output == 0;
}

void		op_sub(t_vm *vm, t_process_context *ctx, t_op_data *data)
{
	int32_t		*input_one;
	int32_t		*input_two;
	int32_t		*output;

	(void)vm;
	if (!(input_one = get_register(ctx, data, 0))
					|| !(input_two = get_register(ctx, data, 1))
					|| !(output = get_register(ctx, data, 2)))
		return ;
	ft_printf("[%d] sub r%d, r%d\n", ctx->pid, data->params[0],
		data->params[1]);
	*output = *input_one - *input_two;
	ctx->carry = *output == 0;
}

void		op_and(t_vm *vm, t_process_context *ctx, t_op_data *data)
{
	int32_t		*output;

	(void)vm;
	if (!(output = get_register(ctx, data, 2)))
		return ;
	ft_printf("[%d] and %d, %d\n", ctx->pid, data->params[0],
		data->params[1]);
	*output = get_value(ctx, data, 0) & get_value(ctx, data, 1);
	ctx->carry = *output == 0;
}

void		op_or(t_vm *vm, t_process_context *ctx, t_op_data *data)
{
	int32_t		*output;

	(void)vm;
	if (!(output = get_register(ctx, data, 2)))
		return ;
	ft_printf("[%d] or %d, %d\n", ctx->pid, data->params[0], data->params[1]);
	*output = get_value(ctx, data, 0) | get_value(ctx, data, 1);
	ctx->carry = *output == 0;
}

void		op_xor(t_vm *vm, t_process_context *ctx, t_op_data *data)
{
	int32_t		*output;

	(void)vm;
	if (!(output = get_register(ctx, data, 2)))
		return ;
	ft_printf("[%d] xor %d, %d\n", ctx->pid, data->params[0], data->params[1]);
	*output = get_value(ctx, data, 0) ^ get_value(ctx, data, 1);
	ctx->carry = *output == 0;
}
