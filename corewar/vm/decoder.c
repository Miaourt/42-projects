/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   decoder.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tguillem <tguillem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/19 15:54:30 by tguillem          #+#    #+#             */
/*   Updated: 2018/03/19 17:21:31 by tguillem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

uint8_t		get_param_size(t_op *op, uint8_t pcode)
{
	if (pcode == REG_CODE)
		return (1);
	else if ((pcode == DIR_CODE && op->has_idx) || (pcode == IND_CODE))
		return (IND_SIZE);
	else if (pcode == DIR_CODE && !op->has_idx)
		return (DIR_SIZE);
	return (0);
}

t_op		*decode_instruction(t_process_context *ctx)
{
	uint8_t	opcode;

	opcode = 0;
	ctx->inst_pos = ctx->pc;
	process_read(ctx, &opcode, 1);
	if (opcode == 0 || opcode > 16)
		return (NULL);
	return (&g_op_tab[opcode - 1]);
}

void		parse_pcodes(uint8_t raw_pcode, uint8_t *param_pcodes)
{
	int	i;

	i = 4;
	while (--i >= 0)
	{
		param_pcodes[i] = raw_pcode % 4;
		raw_pcode >>= 2;
	}
}

int			decode_params(t_process_context *ctx, t_op_data *data)
{
	int		i;
	uint8_t	raw_pcode;

	if (ctx->current_instruction == NULL || data == NULL)
		return (1);
	if (ctx->current_instruction->has_pcode)
	{
		process_read(ctx, &raw_pcode, 1);
		parse_pcodes(raw_pcode, data->param_pcodes);
	}
	else
		data->param_pcodes[0] = DIR_CODE;
	i = 0;
	while (i < ctx->current_instruction->nb_params)
	{
		process_read(ctx, &data->params[i],
		get_param_size(ctx->current_instruction, data->param_pcodes[i]));
		i++;
	}
	return (0);
}
