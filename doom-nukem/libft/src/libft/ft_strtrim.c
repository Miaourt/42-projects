/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcourtil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 13:04:00 by tcourtil          #+#    #+#             */
/*   Updated: 2018/11/13 15:50:17 by tcourtil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	char	*res;
	int		i;
	int		size;
	int		start;

	if (!s)
		return (NULL);
	size = ft_strlen(s);
	i = size - 1;
	while ((s[i] == ' ' || s[i] == '\n' || s[i] == '\t') && i >= 0)
		i--;
	size = i + 1;
	i = 0;
	while ((s[i] == ' ' || s[i] == '\n' || s[i] == '\t') && i < size)
		i++;
	start = i;
	if ((res = ft_strnew(size - i)) == NULL)
		return (NULL);
	while (i < size)
	{
		res[i - start] = s[i];
		i++;
	}
	return (res);
}
