/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcourtil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 15:30:11 by tcourtil          #+#    #+#             */
/*   Updated: 2018/11/12 11:06:01 by tcourtil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "string.h"

char	*ft_strnstr(const char *base, const char *str, size_t len)
{
	size_t i;
	size_t a;

	i = 0;
	while (base[i] != '\0' && i < len)
	{
		a = 0;
		while (str[a] != '\0' && str[a] == base[i + a] && i + a < len)
			a++;
		if (str[a] == '\0')
			return ((char *)&base[i]);
		i++;
	}
	return (NULL);
}
