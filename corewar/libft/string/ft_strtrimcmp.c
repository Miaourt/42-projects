/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrimcmp.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tguillem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/27 09:30:08 by tguillem          #+#    #+#             */
/*   Updated: 2015/11/27 13:57:03 by tguillem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrimcmp(const char *s, int (*f)(int c))
{
	char	*buf;
	long	index;

	while (f(*s))
		s++;
	buf = ft_strchr(s, '\0') - 1;
	while (f(*buf))
		buf--;
	index = buf - s + 1;
	if (index < 0)
		return (ft_strdup(""));
	return (ft_strsub(s, 0, index));
}
