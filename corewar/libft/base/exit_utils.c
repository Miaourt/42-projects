/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tguillem <tguillem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/12 18:37:53 by tguillem          #+#    #+#             */
/*   Updated: 2018/02/12 18:37:53 by tguillem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_array *g_exit;

void	ft_atexit(void (*func)(void))
{
	t_array			*tmp;

	tmp = g_exit;
	while (tmp)
	{
		if (tmp->data == func)
			return ;
		tmp = tmp->next;
	}
	g_exit = array_init(g_exit, func);
}

int		ft_prepare_exit(void)
{
	t_array			*tmp;
	t_exit_cb		func;

	while (g_exit)
	{
		tmp = g_exit;
		func = g_exit->data;
		func();
		g_exit = g_exit->next;
		free(tmp);
	}
	return (1);
}

void	ft_exit(int status)
{
	ft_prepare_exit();
	exit(status);
}
