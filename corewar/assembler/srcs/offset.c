/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   offset.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthuilli <dthuilli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/08 18:10:41 by dthuilli          #+#    #+#             */
/*   Updated: 2018/03/16 17:44:24 by dthuilli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "assembler.h"

uint32_t	handle_offset(t_champ *champ, int i)
{
	uint32_t	offset;

	offset = 0;
	if (champ->ops->args[i]->type == ARG_REG)
		offset += 1;
	else if (champ->ops->args[i]->type == ARG_IND ||
		champ->ops->args[i]->type == ARG_LIND)
		offset += 2;
	else if (champ->ops->args[i]->type == ARG_DIR ||
		champ->ops->args[i]->type == ARG_LDIR)
	{
		if (champ->ops->op->opcode <= 8 || champ->ops->op->opcode == 13)
			offset += 4;
		else
			offset += 2;
	}
	champ->ops->args[i]->nb_bytes = offset;
	return (offset);
}

void		add_offset(t_champ *champ)
{
	uint32_t	offset;
	int			i;

	offset = 1;
	offset += champ->ops->op->has_pcode;
	i = 0;
	while (i < champ->ops->op->nb_params)
	{
		offset += handle_offset(champ, i);
		++i;
	}
	champ->offset += offset;
}
