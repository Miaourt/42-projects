/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthuilli <dthuilli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/01 13:56:44 by dthuilli          #+#    #+#             */
/*   Updated: 2018/03/17 17:45:03 by dthuilli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "assembler.h"

char	*handle_param(char *buffer, t_champ *champ, int type, int j)
{
	int neg;

	neg = 0;
	if (ft_iswhitespace(*buffer) || !*buffer)
		err("Invalid operation parameter.\n", champ);
	champ->ops->args[j]->value = ft_atol(buffer);
	champ->ops->args[j]->type = which_type(type);
	if (*buffer == '-')
	{
		++buffer;
		neg = 1;
	}
	if (!ft_isdigit(*buffer))
		err("Invalid number in parameter.\n", champ);
	while (*buffer == '0')
		++buffer;
	if (is_overflow(buffer, champ->ops->args[j]->value, neg))
		err("Overflow in parameter\n", champ);
	buffer += ft_count_digit(champ->ops->args[j]->value, 10);
	return (buffer);
}

char	*check_param(char *buffer, t_champ *champ, int type, int j)
{
	if (type != T_IND && type != T_LAB)
		++buffer;
	champ->ops->args[j] = (t_arg*)s_malloc(sizeof(t_arg));
	if (*buffer == LABEL_CHAR)
	{
		if (++buffer && !is_instring(*buffer, LABEL_CHARS))
			err("Invalid label name.\n", champ);
		champ->ops->args[j]->label = parse_label(buffer, champ);
		champ->ops->args[j]->value = champ->ops->args[j]->label->id;
		champ->ops->args[j]->type = (type == T_DIR) ? ARG_LDIR : ARG_LIND;
		buffer += ft_strlen(champ->ops->args[j]->label->name);
	}
	else
		buffer = handle_param(buffer, champ, type, j);
	while (ft_iswhitespace(*buffer))
		++buffer;
	return (buffer);
}

int		check_params(char *buffer, t_champ *champ, t_op *op)
{
	int		j;
	int		type;

	j = -1;
	while (++j < op->nb_params)
	{
		while (ft_iswhitespace(*buffer))
			++buffer;
		type = which_arg(buffer);
		if (type && type == (int)(type & op->param_types[j]))
		{
			buffer = check_param(buffer, champ, type, j);
			if (*buffer && *buffer == SEPARATOR_CHAR && (j + 1 < op->nb_params))
				++buffer;
		}
		else
			return (0);
	}
	while (ft_iswhitespace(*buffer))
		++buffer;
	if (*buffer == COMMENT_CHAR || *buffer == ALT_COMMENT_CHAR || !*buffer)
		return (1);
	return (0);
}

int		is_op(char *buffer, t_champ *champ)
{
	int		i;
	t_ops	*ops;

	i = -1;
	while (g_op_tab[++i].name)
	{
		if (!strcmps(buffer, g_op_tab[i].name, ft_strlen(g_op_tab[i].name))
			&& ft_iswhitespace(*(buffer + ft_strlen(g_op_tab[i].name))))
		{
			buffer += ft_strlen(g_op_tab[i].name);
			ops = new_ops(&g_op_tab[i], champ);
			if (!check_params(buffer, champ, &g_op_tab[i]))
			{
				champ->ops = champ->ops->next;
				free(ops);
				return (0);
			}
			add_offset(champ);
			i = -1;
			break ;
		}
	}
	if (i != -1 && ft_strcmp(buffer, ""))
		return (0);
	return (1);
}

int		parse(char *buffer, t_champ *champ)
{
	while (ft_iswhitespace(*buffer))
		++buffer;
	if (*buffer == COMMENT_CHAR || *buffer == ALT_COMMENT_CHAR)
		return (1);
	else if (!strcmps(buffer, NAME_CMD_STRING, ft_strlen(buffer))
		|| !strcmps(buffer, COMMENT_CMD_STRING, ft_strlen(buffer)))
		return (parse_nameorcomment(buffer, champ));
	else if (is_label(buffer))
	{
		define_label(parse_label(buffer, champ), champ);
		while (*buffer && *buffer != LABEL_CHAR)
			++buffer;
		++buffer;
		while (ft_iswhitespace(*buffer))
			++buffer;
		if (!*buffer || is_op(buffer, champ) || *buffer == COMMENT_CHAR
			|| *buffer == ALT_COMMENT_CHAR)
			return (1);
	}
	else if (is_op(buffer, champ))
		return (1);
	return (0);
}
