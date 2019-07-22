/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_trim.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tguillem <tguillem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/20 16:51:00 by tguillem          #+#    #+#             */
/*   Updated: 2016/05/20 17:15:30 by tguillem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_trim(char *src, char excluded)
{
	char	*tmp;

	while ((tmp = ft_strchr(src, excluded)))
		*tmp = *(tmp + 1);
	return (src);
}
