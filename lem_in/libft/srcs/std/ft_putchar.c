/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llaporte <llaporte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 12:55:46 by llaporte          #+#    #+#             */
/*   Updated: 2016/11/12 14:45:23 by llaporte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**	On putchar_fd sur la sortie 1... ¯\_(ツ)_/¯
*/

void	ft_putchar(unsigned char c)
{
	ft_putchar_fd(c, 1);
}
