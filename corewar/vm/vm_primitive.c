/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm_primitive.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tguillem <tguillem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/14 15:22:18 by tguillem          #+#    #+#             */
/*   Updated: 2018/02/26 15:50:26 by tguillem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void	process_read(t_process_context *ctx, void *ptr, size_t size)
{
	if (size == 0)
	{
		return ;
	}
	process_memory_read(ctx, ctx->pc, ptr, size);
	if (size == 2)
		swap_uint16((uint16_t*)ptr);
	else if (size == 4)
		swap_uint32((uint32_t*)ptr);
	ctx->pc += size;
}

void	process_memory_read(t_process_context *ctx, uint32_t pos, void *ptr,
	size_t size)
{
	uint8_t	*data;
	size_t	i;

	data = (uint8_t*)ptr;
	i = 0;
	while (i < size)
	{
		data[i] = ctx->entry_point[(pos + i + MEM_SIZE) % MEM_SIZE];
		i++;
	}
}

void	process_memory_write(t_process_context *ctx, uint32_t pos, void *ptr,
	size_t size)
{
	uint8_t	*src;
	int32_t	i;
	int32_t	y;

	src = (uint8_t*)ptr;
	i = 0;
	y = size - 1;
	while (y >= 0)
	{
		ctx->entry_point[(pos + i + MEM_SIZE) % MEM_SIZE] = src[y];
		y--;
		i++;
	}
}
