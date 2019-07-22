/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tguillem <tguillem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/13 13:34:29 by tguillem          #+#    #+#             */
/*   Updated: 2018/03/17 19:58:24 by tguillem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

off_t		get_file_size(const char *path)
{
	off_t	size;
	int		fd;

	fd = open(path, O_RDONLY);
	if (fd < 0)
		ft_error_msg("Can't read champion file %s\n", path);
	size = lseek(fd, 0, SEEK_END);
	close(fd);
	return (size);
}

char		*get_file_content(const char *path, off_t *size)
{
	int		fd;
	char	*res;

	fd = open(path, O_RDONLY);
	if (fd < 0)
		return (NULL);
	*size = lseek(fd, 0, SEEK_END);
	lseek(fd, 0, SEEK_SET);
	if ((res = ft_memalloc(*size + 1)))
		read(fd, res, *size);
	close(fd);
	return (res);
}

int			corewar_is_dead_end(t_vm *ctx)
{
	int32_t		last_id;
	t_array		*processes;

	processes = ctx->processes;
	while (processes)
	{
		if (processes == ctx->processes)
			last_id =
				((t_process_context*)processes->data)->program_context->id;
		if (((t_process_context*)processes->data)->program_context->id !=
			last_id)
			return (0);
		last_id = ((t_process_context*)processes->data)->program_context->id;
		processes = processes->next;
	}
	return (1);
}

void		swap_uint32(uint32_t *data)
{
	*data = swap_uint(*data);
}

void		swap_uint16(uint16_t *data)
{
	*data = (uint16_t)((*data >> 8) | (*data << 8));
}
