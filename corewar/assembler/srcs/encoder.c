/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   encoder.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tguillem <tguillem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/06 15:41:23 by dthuilli          #+#    #+#             */
/*   Updated: 2018/03/18 04:26:51 by tguillem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "assembler.h"

void		encode_parameters(t_champ *champ, int *pos)
{
	int				i;
	unsigned int	tmp;

	i = 0;
	while (i < champ->ops->op->nb_params)
	{
		if (champ->ops->args[i]->type == ARG_LDIR ||
			champ->ops->args[i]->type == ARG_LIND)
			champ->ops->args[i]->value =
				champ->ops->args[i]->label->offset - champ->offset;
		if (champ->ops->args[i]->nb_bytes == 1)
			champ->data[*pos] = (char)champ->ops->args[i]->value;
		else
		{
			if (champ->ops->args[i]->nb_bytes == 2)
				tmp = swap_ushort((short)champ->ops->args[i]->value);
			else
				tmp = swap_uint(champ->ops->args[i]->value);
			ft_memcpy(champ->data + *pos, &tmp, champ->ops->args[i]->nb_bytes);
		}
		(*pos) += champ->ops->args[i]->nb_bytes;
		++i;
	}
}

char		encode_opcode(t_ops *ops)
{
	char	result;
	char	param_code;
	int		i;

	i = 0;
	result = 0;
	while (i < 3)
	{
		if (i > (ops->op->nb_params - 1) || !ops->args[i])
			param_code = 0;
		else if (ops->args[i]->type == ARG_REG)
			param_code = REG_CODE;
		else if (ops->args[i]->type == ARG_DIR ||
			ops->args[i]->type == ARG_LDIR)
			param_code = DIR_CODE;
		else
			param_code = IND_CODE;
		result |= param_code;
		result <<= 2;
		++i;
	}
	return (result);
}

void		encode_instructions(t_champ *champ)
{
	t_ops	*head;
	int		pos;

	pos = 0;
	head = champ->ops;
	while (champ->ops)
	{
		champ->data[pos++] = (char)(champ->ops->op->opcode);
		if (champ->ops->op->has_pcode)
			champ->data[pos++] = encode_opcode(champ->ops);
		encode_parameters(champ, &pos);
		add_offset(champ);
		champ->ops = champ->ops->next;
	}
	champ->ops = head;
}

void		write_header_to_file(t_champ *champ, int fd)
{
	unsigned int	tmp;

	tmp = champ->header.prog_size;
	champ->header.magic = swap_uint(champ->header.magic);
	champ->header.prog_size = swap_uint(champ->header.prog_size);
	write(fd, &champ->header, sizeof(t_header));
	champ->header.prog_size = tmp;
}

int			encode(t_champ *champ, char *file_name)
{
	char	*file_path;
	int		fd;

	if (!(file_path = get_output_name(file_name)))
	{
		ft_memdel((void**)&file_path);
		err("Allocation error during write_output!\n", champ);
	}
	if ((fd = open(file_path, O_CREAT | O_WRONLY, 0644)) < 0)
		err("Failed to open output file.", champ);
	ft_memdel((void**)&file_path);
	champ->ops = reverse_ops(champ->ops);
	champ->header.prog_size = champ->offset;
	champ->offset = 0;
	champ->data = (char *)s_malloc(sizeof(char) * champ->header.prog_size);
	write_header_to_file(champ, fd);
	encode_instructions(champ);
	write(fd, champ->data, champ->header.prog_size);
	return (1);
}
