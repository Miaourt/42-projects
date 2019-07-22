/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isstralnum.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tguillem <tguillem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/30 10:20:07 by tguillem          #+#    #+#             */
/*   Updated: 2016/03/30 10:27:47 by tguillem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int				ft_isstralnum(char *str)
{
	if (!str || !*str)
		return (0);
	while (*str)
		if (!ft_isalnum(*str++))
			return (0);
	return (1);
}
