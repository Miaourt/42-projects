/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tguillem <tguillem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/23 12:44:50 by tguillem          #+#    #+#             */
/*   Updated: 2016/07/18 18:30:56 by tguillem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			*ft_itoa(int n)
{
	return (ft_itoa_base(n, 10));
}

char			*ft_itoa_prefix(char *prefix, int n)
{
	char		*number;
	char		*result;

	number = ft_itoa(n);
	if (number)
	{
		result = ft_strjoin(prefix, number);
		ft_strdel(&number);
		return (result);
	}
	return (NULL);
}
