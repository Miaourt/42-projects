/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_comment_or_name.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthuilli <dthuilli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/14 13:22:52 by llaporte          #+#    #+#             */
/*   Updated: 2018/03/16 16:31:03 by dthuilli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "assembler.h"

int		set_string(char *str, char **buffer, int size)
{
	int		i;
	char	*tmp;

	while (ft_iswhitespace(**buffer))
		++*buffer;
	if (**buffer == '"')
		++*buffer;
	else
		return (0);
	tmp = *buffer;
	i = 0;
	while (tmp[i] != '"' && i < size)
	{
		str[i] = tmp[i];
		++i;
	}
	if (tmp[i] == '"')
	{
		*buffer = &tmp[i];
		return (1);
	}
	return (0);
}

int		parse_nameorcomment(char *buffer, t_champ *champ)
{
	if (!strcmps(buffer, NAME_CMD_STRING, ft_strlen(NAME_CMD_STRING)))
	{
		if (ft_strcmp(champ->header.prog_name, ""))
			err("Error: prog_name already set.\n", champ);
		buffer += ft_strlen(NAME_CMD_STRING);
		if (!set_string(champ->header.prog_name, &buffer, PROG_NAME_LENGTH))
			return (0);
		champ->name = champ->header.prog_name;
	}
	else if (!strcmps(buffer, COMMENT_CMD_STRING,
		ft_strlen(COMMENT_CMD_STRING)))
	{
		if (ft_strcmp(champ->header.comment, ""))
			err("Error: prog_comment already set.\n", champ);
		buffer += ft_strlen(COMMENT_CMD_STRING);
		if (!set_string(champ->header.comment, &buffer, COMMENT_LENGTH))
			return (0);
		champ->comment = champ->header.comment;
	}
	++buffer;
	while (ft_iswhitespace(*buffer))
		++buffer;
	if (!*buffer || *buffer == COMMENT_CHAR || *buffer == ALT_COMMENT_CHAR)
		return (1);
	return (0);
}
