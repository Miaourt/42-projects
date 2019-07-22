/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcourtil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 15:30:11 by tcourtil          #+#    #+#             */
/*   Updated: 2018/11/20 17:01:49 by tcourtil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "string.h"

char	*ft_strstr(const char *base, const char *str)
{
	int i;
	int a;

	if (!base || !str)
		return (NULL);
	i = 0;
	while (base[i] != '\0')
	{
		a = 0;
		while (str[a] != '\0' && str[a] == base[i + a])
			a++;
		if (str[a] == '\0')
			return ((char *)&base[i]);
		i++;
	}
	if (str[0] == '\0')
		return ((char *)&base[i]);
	return (NULL);
}
