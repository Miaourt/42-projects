/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_label.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tguillem <tguillem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/14 16:11:42 by llaporte          #+#    #+#             */
/*   Updated: 2018/03/18 04:32:07 by tguillem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "assembler.h"

int		valid_labels(t_label *labels)
{
	while (labels)
	{
		if (!labels->is_def)
			return (0);
		labels = labels->next;
	}
	return (1);
}

int		is_label(char *buffer)
{
	while (is_instring(*buffer, LABEL_CHARS))
		++buffer;
	if (*buffer == LABEL_CHAR)
		return (1);
	return (0);
}

void	define_label(t_label *label, t_champ *champ)
{
	label->offset = champ->offset;
	label->is_def = 1;
}

int		add_label(char *buffer, t_champ *champ, int label_size)
{
	t_label	*label;

	label = (t_label*)s_malloc(sizeof(t_label));
	label->name = ft_strnew(sizeof(char) * label_size);
	label->name = ft_memcpy(label->name, buffer, label_size);
	if (!champ->labels)
		label->id = 0;
	else
		label->id = champ->labels->id + 1;
	label->next = champ->labels;
	label->is_def = 0;
	champ->labels = label;
	return (label->id);
}

t_label	*parse_label(char *buffer, t_champ *champ)
{
	int		i;
	t_label	*tmp;

	i = 0;
	while (*buffer && is_instring(*buffer, LABEL_CHARS))
	{
		++buffer;
		++i;
	}
	buffer -= i;
	tmp = champ->labels;
	while (tmp)
	{
		if ((size_t)i == ft_strlen(tmp->name) &&
			ft_strncmp(buffer, tmp->name, i) == 0)
			if ((size_t)i == ft_strlen(tmp->name))
				return (tmp);
		tmp = tmp->next;
	}
	add_label(buffer, champ, i);
	free(tmp);
	return (champ->labels);
}
