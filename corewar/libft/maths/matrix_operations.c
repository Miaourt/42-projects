/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_operations.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tguillem <tguillem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/20 12:51:38 by tguillem          #+#    #+#             */
/*   Updated: 2016/09/20 13:35:52 by tguillem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_matrix.h"

double			get_matrix_entry(t_matrix *matrix, size_t y, size_t x)
{
	if (matrix && matrix->row_length > x && matrix->colum_length > y)
		return (matrix->mem[y][x]);
	return (0.0F);
}

t_matrix		*cross_matrix(t_matrix *a, t_matrix *b)
{
	t_matrix	*c;
	size_t		pos[2];
	size_t		k;
	double		sum;

	c = NULL;
	if (b->colum_length == a->row_length &&
		(c = alloc_matrix(b->row_length, b->colum_length)))
	{
		pos[0] = -1;
		while ((++pos[0]) < b->row_length)
		{
			pos[1] = -1;
			while ((++pos[1]) < a->colum_length)
			{
				sum = 0;
				k = -1;
				while ((++k) < b->colum_length)
					sum += get_matrix_entry(b, k, pos[0]) *
						get_matrix_entry(a, pos[1], k);
				c->mem[pos[1]][pos[0]] = sum;
			}
		}
	}
	return (c);
}

t_matrix		*transpose_matrix(t_matrix *source)
{
	t_matrix	*res;
	size_t		i;
	size_t		j;

	res = NULL;
	j = 0;
	if (source &&
		(res = alloc_matrix(source->colum_length, source->row_length)))
	{
		while ((++j) <= source->colum_length)
		{
			i = 0;
			while ((++i) <= source->row_length)
			{
				res->mem[i - 1][j - 1] = source->mem[j - 1][i - 1];
			}
		}
	}
	return (res);
}
