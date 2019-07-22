/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcourtil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/16 15:24:03 by tcourtil          #+#    #+#             */
/*   Updated: 2018/12/13 14:44:17 by tcourtil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <unistd.h>

static int	recomp(t_list *list)
{
	t_list	*elem;
	int		size;

	size = 0;
	elem = list;
	while (elem)
	{
		size += elem->content_size;
		write(1, (char *)elem->content, elem->content_size);
		elem = elem->next;
	}
	ft_lstdelall(&list);
	return (size);
}

static void	sub(t_list **list, const char *base, int i, int next)
{
	char	*tmp;

	tmp = ft_strsub(base, i, next);
	ft_lstadde(list, ft_lstnew(tmp, next));
	free(tmp);
}

static int	readstr(const char *base, va_list *ap)
{
	t_list	*list;
	int		i;
	int		next;
	int		tmp;

	i = 0;
	list = NULL;
	while (base[i])
	{
		if ((next = ft_strpbrki(&base[i], "%")) == -1)
		{
			next = ft_strlen(&base[i]);
			sub(&list, base, i, next);
			i += next;
		}
		else
		{
			sub(&list, base, i, next);
			if ((tmp = getflags(&base[i + next], list, ap)) == -1)
				return (recomp(list));
			i += next + ft_max(tmp, 1);
		}
	}
	return (recomp(list));
}

int			ft_printf(const char *base, ...)
{
	va_list ap;
	int		res;

	va_start(ap, base);
	res = readstr(base, &ap);
	va_end(ap);
	return (res);
}
