/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_keyvalue.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcourtil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/15 15:18:27 by tcourtil          #+#    #+#             */
/*   Updated: 2019/01/15 18:21:56 by tcourtil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"

int		ft_keyvalue(const char *key)
{
	int	val;
	int	i;

	i = 0;
	val = 0;
	while (key[i])
	{
		val += key[i];
		i++;
	}
	return (val);
}
