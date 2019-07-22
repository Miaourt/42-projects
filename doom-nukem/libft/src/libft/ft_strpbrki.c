/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strpbrki.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcourtil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 15:30:11 by tcourtil          #+#    #+#             */
/*   Updated: 2018/11/19 15:58:58 by tcourtil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "string.h"

int		ft_strpbrki(const char *base, const char *str)
{
	int i;
	int a;

	i = 0;
	while (base[i] != '\0')
	{
		a = 0;
		while (str[a] != '\0')
		{
			if (str[a] == base[i])
				return (i);
			a++;
		}
		i++;
	}
	return (-1);
}
