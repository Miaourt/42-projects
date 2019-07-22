/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assembler.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthuilli <dthuilli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/12 16:50:01 by llaporte          #+#    #+#             */
/*   Updated: 2018/03/22 09:23:53 by dthuilli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "assembler.h"

void	err(char *error, t_champ *champ)
{
	free_struct(champ);
	ft_putstr_fd(error, 2);
	ft_exit(1);
}

void	*s_malloc(size_t size)
{
	void	*var;

	if ((var = ft_memalloc(size)) == NULL)
		ft_exit(0);
	return (var);
}

void	readfile(char *file, t_champ *champ)
{
	char	*buffer;
	int		fd;
	int		line_nb;
	int		tmp;

	if (!(fd = open(file, O_RDONLY)) || fd == -1)
		err("Failed to open input file.\n", champ);
	line_nb = 1;
	buffer = NULL;
	while ((tmp = get_next_line(fd, &buffer)) > 0 && buffer)
	{
		if (!parse(buffer, champ))
		{
			ft_memdel((void **)&buffer);
			ft_printf_fd(2, "Error: line %i is invalid.\n", line_nb);
			err("", champ);
		}
		ft_memdel((void **)&buffer);
		++line_nb;
	}
	if (tmp < 0)
		err("Error: invalid file.\n", champ);
	ft_memdel((void **)&buffer);
	close(fd);
}

int		main(int argc, char **argv)
{
	t_champ *champ;

	ft_atexit(resource_manager_destroy);
	champ = NULL;
	if (argc != 2)
		err("Usage :\n./asm champion.s\n", champ);
	else
	{
		champ = (t_champ*)s_malloc(sizeof(t_champ));
		champ->header.magic = COREWAR_EXEC_MAGIC;
		champ->ops = NULL;
		champ->offset = 0;
		readfile(argv[1], champ);
		if (!valid_labels(champ->labels))
			err("Error: a label isn't declared.\n", champ);
		if (!champ->name || !champ->comment)
			err("Error : header incomplete, name or comment missing.\n", champ);
		if (champ->offset <= 0)
			err("Error : there is no program.\n", champ);
		encode(champ, argv[1]);
		ft_printf("Successfully compiled %s.\n", champ->header.prog_name);
		free_struct(champ);
	}
	ft_prepare_exit();
	return (0);
}
