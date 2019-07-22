/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tguillem <tguillem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/11 14:02:41 by tguillem          #+#    #+#             */
/*   Updated: 2016/10/06 18:19:48 by tguillem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>
#define BUFF_SIZE 4096

static t_buff	*init_buff(t_buff *before, int fd)
{
	t_buff		*result;

	if (!(result = (t_buff*)ft_memalloc(sizeof(t_buff))) ||
			!(result->buff = ft_strnew(1)))
		return (NULL);
	result->fd = fd;
	result->next = NULL;
	if (before)
		before->next = result;
	return (result);
}

static t_buff	*get_buff(t_buff **base, int fd)
{
	t_buff		*tmp;

	tmp = *base;
	if (!*base)
	{
		*base = init_buff(NULL, fd);
		return (*base);
	}
	else
	{
		while (tmp)
		{
			if (tmp->fd == fd)
				return (tmp);
			if (!tmp->next)
				return (init_buff(tmp, fd));
			tmp = tmp->next;
		}
	}
	return (NULL);
}

static char		*joinstr(char *str, char *buffer)
{
	char		*result;

	result = ft_strjoin(str, buffer);
	ft_strdel(&str);
	return (result);
}

static char		*substr(char *str, int start, int end)
{
	char		*result;

	result = ft_strsub(str, start, end);
	ft_strdel(&str);
	return (result);
}

int				get_next_line(int const fd, char **line)
{
	t_buff			**root;
	t_buff			*c;
	char			buffer[BUFF_SIZE + 1];
	int				ret;

	root = get_gnl_buffer();
	ret = 1;
	if (!line || BUFF_SIZE <= 0 || !(c = get_buff(root, fd)))
		return (-1);
	while (!ft_strchr(c->buff, '\n') && (ret = read(fd, buffer, BUFF_SIZE)))
	{
		if (ret == -1)
			return (-1);
		*(buffer + ret) = '\0';
		c->buff = joinstr(c->buff, buffer);
	}
	if (ft_strchr(c->buff, '\n') || ((*line = ft_strdup(c->buff)) && 0))
		*line = ft_strsub(c->buff, 0, ft_strchr(c->buff, '\n') - c->buff + 1);
	if (ret)
		*(*(line) + ft_strlen(*line) - 1) = '\0';
	c->buff = substr(c->buff, ft_strchr(c->buff, '\n')
			- c->buff + 1, ft_strlen(ft_strchr(c->buff, '\n')));
	return (ret > 0 ? 1 : ft_strlen(*line) != 0);
}
