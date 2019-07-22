/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tguillem <tguillem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/01 13:58:50 by dthuilli          #+#    #+#             */
/*   Updated: 2018/03/22 07:18:09 by tguillem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "assembler.h"

int		strcmps(char *compare, char *ref, int size)
{
	int		i;

	i = 0;
	while (*ref && *(ref + 1) && (*compare == *ref) && i < size)
	{
		++compare;
		++ref;
		++i;
	}
	return (*compare - *ref);
}

int		which_arg(char *buffer)
{
	if (*buffer == REGISTER_CHAR)
		return (T_REG);
	else if (*buffer == DIRECT_CHAR)
		return (T_DIR);
	else if (ft_isdigit(*buffer) || *buffer == LABEL_CHAR)
		return (T_IND);
	else if ((*buffer == '-' && ft_isdigit(*(++buffer))) ||
		*buffer == LABEL_CHAR)
		return (T_IND);
	return (0);
}

int		which_type(int type)
{
	if (type == T_DIR)
		return (ARG_DIR);
	else if (type == T_IND)
		return (ARG_IND);
	else
		return (ARG_REG);
}

long	ft_atol(char *nptr)
{
	long		i;
	long		n;
	long		sign;

	i = 0;
	n = 0;
	sign = 1;
	while ((nptr[i] == ' ') || (nptr[i] == '\t') || (nptr[i] == '\n')
			|| (nptr[i] == '\v') || (nptr[i] == '\f') || (nptr[i] == '\r'))
		i++;
	sign = (nptr[i] == '-') ? -1 : 1;
	i = (nptr[i] == '-' || nptr[i] == '+') ? i + 1 : i;
	while (nptr[i] && nptr[i] >= '0' && nptr[i] <= '9')
	{
		n = n * 10 + (nptr[i] - '0');
		i++;
	}
	return (n * sign);
}

t_ops	*new_ops(t_op *op, t_champ *champ)
{
	t_ops	*ops;

	ops = (t_ops*)s_malloc(sizeof(t_ops));
	ops->op = op;
	ops->next = champ->ops;
	champ->ops = ops;
	return (ops);
}
