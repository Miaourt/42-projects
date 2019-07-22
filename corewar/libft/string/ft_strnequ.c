/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnequ.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tguillem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 08:53:30 by tguillem          #+#    #+#             */
/*   Updated: 2015/11/25 08:53:31 by tguillem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strnequ(char const *s1, char const *s2, size_t n)
{
	size_t	size_s2;

	if (!s1 || !s2)
		return (0);
	size_s2 = ft_strlen(s2);
	if (ft_strlen(s1) > size_s2 && n > size_s2)
		return (0);
	return (ft_strncmp(s1, s2, n) == 0);
}
