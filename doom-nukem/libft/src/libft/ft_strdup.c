/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcourtil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/05 17:23:50 by tcourtil          #+#    #+#             */
/*   Updated: 2018/11/12 18:36:15 by tcourtil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strdup(const char *src)
{
	int		i;
	char	*text;

	i = 0;
	while (src[i] != '\0')
		i++;
	i++;
	text = (char *)malloc(i * sizeof(*text));
	if (text == NULL)
		return (NULL);
	i = 0;
	while (src[i] != '\0')
	{
		text[i] = src[i];
		i++;
	}
	text[i] = '\0';
	return (text);
}
