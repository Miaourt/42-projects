/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_lib.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tguillem <tguillem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/20 12:51:29 by tguillem          #+#    #+#             */
/*   Updated: 2016/09/20 13:26:43 by tguillem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_matrix.h"

t_matrix		*alloc_matrix(size_t row_length, size_t colum_length)
{
	t_matrix	*res;
	size_t		i;

	if ((res = ft_memalloc(sizeof(t_matrix))))
	{
		res->row_length = row_length;
		res->colum_length = colum_length;
		res->mem = ft_memalloc(sizeof(double*) * colum_length);
		i = 0;
		while (i < colum_length)
		{
			*(res->mem + i) = ft_memalloc(sizeof(double) * (row_length + 1));
			i++;
		}
	}
	return (res);
}

t_matrix		*dup_matrix(t_matrix *src)
{
	t_matrix	*res;
	size_t		x;
	size_t		y;

	if ((res = alloc_matrix(src->row_length, src->colum_length)))
	{
		x = src->row_length;
		while (x)
		{
			y = src->colum_length;
			while (y)
			{
				res->mem[x][y] = src->mem[x][y];
				y--;
			}
			x--;
		}
	}
	return (res);
}

void			del_matrix(t_matrix *matrix)
{
	size_t		y;

	if (matrix)
	{
		y = matrix->colum_length;
		while (y)
		{
			ft_memdel((void**)(matrix->mem + y));
			y--;
		}
		ft_memdel((void**)&matrix);
	}
}
