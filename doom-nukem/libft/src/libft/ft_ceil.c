/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ceil.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcourtil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/15 14:17:41 by tcourtil          #+#    #+#             */
/*   Updated: 2018/12/06 16:48:01 by tcourtil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

double		ft_ceil(double f)
{
	return (ft_floor(f) + 1);
}
