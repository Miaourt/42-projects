/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   overflow.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthuilli <dthuilli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/16 15:02:32 by dthuilli          #+#    #+#             */
/*   Updated: 2018/03/16 16:16:55 by dthuilli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "assembler.h"

int		ft_count_digitl(long value, int base)
{
	int	n;

	n = 0;
	while (value)
	{
		n++;
		value /= base;
	}
	return (n);
}

char	*ft_ltoa(long value)
{
	char		*result;
	int			size;
	int			sign;

	if (!value)
		return (ft_strdup("0"));
	sign = value > 0 ? 1 : -1;
	size = ft_count_digitl(value, 10) + (sign == -1 && 10 == 10);
	if (!(result = ft_strnew(sizeof(char) * (size))))
		return (NULL);
	result += size;
	while (value)
	{
		*--result = BASE_16[(value % 10) * sign];
		value /= 10;
	}
	if (sign == -1)
		*--result = '-';
	return (result);
}

int		is_overflow(char *str, long value, int neg)
{
	char	*tofree;
	int		i;
	int		k;

	tofree = ft_ltoa(value);
	i = 0;
	k = 0;
	if (neg)
		i++;
	while (str[k] && tofree[i] && ft_isdigit(str[k]))
	{
		if ((tofree[0] == '-' && !neg) || tofree[i] != str[k])
		{
			free(tofree);
			return (1);
		}
		++i;
		++k;
	}
	free(tofree);
	return (0);
}

int		is_instring(char c, char *src_string)
{
	int i;

	i = 0;
	while (src_string[i])
		if (c == src_string[i++])
			return (1);
	return (0);
}
