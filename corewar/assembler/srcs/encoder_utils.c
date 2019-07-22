/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   encoder_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthuilli <dthuilli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/08 18:06:22 by dthuilli          #+#    #+#             */
/*   Updated: 2018/03/17 17:53:19 by dthuilli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "assembler.h"

t_ops			*reverse_ops(t_ops *ops)
{
	t_ops		*new_ops;
	t_ops		*tmp;

	new_ops = NULL;
	while (ops)
	{
		tmp = ops->next;
		ops->next = new_ops;
		new_ops = ops;
		ops = tmp;
	}
	return (new_ops);
}

char			*get_output_name(char *path)
{
	char	*new;
	int		size;
	char	*tmp;

	size = ft_strlen(path);
	new = s_malloc(size + 4);
	ft_memcpy(new, path, size);
	if (!(tmp = ft_strrchr(new, '/')))
		tmp = new;
	if ((tmp = ft_strrchr(tmp, '.')))
		*tmp = '\0';
	ft_strcat(new, ".cor");
	return (new);
}

unsigned short	swap_ushort(unsigned short lt)
{
	return ((lt << 8) | (lt >> 8));
}
