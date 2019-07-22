/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrimch.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tguillem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/27 13:55:25 by tguillem          #+#    #+#             */
/*   Updated: 2015/11/27 13:55:55 by tguillem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrimch(const char *s, char c)
{
	char	*buf;
	long	index;

	while (*s == c)
		s++;
	buf = ft_strchr(s, '\0') - 1;
	while (*buf == c)
		buf--;
	index = buf - s + 1;
	if (index < 0)
		return (ft_strdup(""));
	return (ft_strsub(s, 0, index));
}
