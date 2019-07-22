/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tguillem <tguillem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/19 16:04:00 by tguillem          #+#    #+#             */
/*   Updated: 2018/02/26 15:33:17 by tguillem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

int32_t	swap_int32(int32_t val)
{
	val = ((val << 8) & 0xFF00FF00) | ((val >> 8) & 0xFF00FF);
	return ((val << 16) | ((val >> 16) & 0xFFFF));
}

int		is_register(t_process_context *ctx, t_op_data *data, int index)
{
	int32_t		ptype;
	int32_t		param;
	int32_t		pcode;

	ptype = ctx->current_instruction->param_types[index];
	param = data->params[index];
	pcode = data->param_pcodes[index];
	return ((ptype == T_REG || ((ptype & T_REG) && pcode == REG_CODE))
					&& param > 0 && param <= REG_NUMBER);
}

int		is_indirect(t_process_context *ctx, t_op_data *data, int index)
{
	int32_t		ptype;
	int32_t		pcode;

	ptype = ctx->current_instruction->param_types[index];
	pcode = data->param_pcodes[index];
	return (ptype == T_IND || ((ptype & T_IND) && pcode == IND_CODE));
}

int32_t	*get_register(t_process_context *ctx, t_op_data *data, int index)
{
	int32_t		param;

	param = data->params[index];
	if (is_register(ctx, data, index))
		return ((int32_t *)(ctx->registers + param - 1));
	else
		return (NULL);
}

int32_t	get_value(t_process_context *ctx, t_op_data *data, int index)
{
	int32_t	*tmp;
	int32_t	tmp_ind;

	tmp_ind = data->params[index];
	if (ctx->current_instruction->opcode != 0xA
		&& ctx->current_instruction->opcode != 0xD
		&& ctx->current_instruction->opcode != 0xE)
		tmp_ind %= IDX_MOD;
	if ((tmp = get_register(ctx, data, index)))
		return (*tmp);
	else if (is_indirect(ctx, data, index))
	{
		process_memory_read(ctx, ctx->inst_pos + tmp_ind, &tmp_ind,
			sizeof(tmp_ind));
		return (swap_int32(tmp_ind));
	}
	return (data->params[index]);
}
