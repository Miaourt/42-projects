/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_loader.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tguillem <tguillem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/13 12:38:13 by tguillem          #+#    #+#             */
/*   Updated: 2018/03/17 21:06:26 by tguillem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

static int				check_header(char *path, t_header *header, off_t size)
{
	if (size <= (off_t)sizeof(t_header))
	{
		ft_printf_fd(2, "Error: File %s is too small to be a champion\n", path);
		return (1);
	}
	header->magic = swap_uint(header->magic);
	header->prog_size = swap_uint(header->prog_size);
	if (header->magic != COREWAR_EXEC_MAGIC)
	{
		ft_printf_fd(2, "Error: File %s has an invalid header\n", path);
		return (1);
	}
	return (0);
}

static int				check_prg_size(char *path, t_header *header, off_t size)
{
	off_t	real_prg_size;

	real_prg_size = size - sizeof(t_header);
	if (real_prg_size != header->prog_size)
	{
		ft_printf_fd(2, "Error: File %s has a code size that differ ", path);
		ft_printf_fd(2, "from what its header says (%d bytes != %d bytes)\n",
			real_prg_size, header->prog_size);
		return (1);
	}
	if (real_prg_size > CHAMP_MAX_SIZE)
	{
		ft_printf_fd(2,
			"Error: File %s has too large a code (%d bytes > %d bytes)\n",
			path, real_prg_size, CHAMP_MAX_SIZE);
		return (1);
	}
	return (0);
}

static t_program		*create_program(char *path, uint8_t *data, off_t size)
{
	t_program	*res;

	res = NULL;
	if (check_header(path, (t_header*)data, size) ||
			check_prg_size(path, (t_header*)data, size))
		free(data);
	else if ((res = ft_memalloc(sizeof(t_program))))
	{
		res->header = (t_header*)data;
		res->code = (data + sizeof(t_header));
		return (res);
	}
	return (NULL);
}

t_program				*load_program(char *path)
{
	char	*data;
	off_t	size;

	size = 0;
	data = get_file_content(path, &size);
	if (data == NULL)
	{
		if (size == 0)
			ft_printf_fd(2, "Can't read source file %s\n", path);
		else
			ft_printf_fd(2, "Cannot allocate memory for source file %s\n",
				path);
		return (NULL);
	}
	return (create_program(path, (uint8_t*)data, size));
}

void					destroy_program(void *data)
{
	t_program	*program;

	program = data;
	if (program)
	{
		free(program->header);
		free(program);
	}
}
