/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_path.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tguillem <tguillem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/22 15:40:17 by tguillem          #+#    #+#             */
/*   Updated: 2016/03/22 15:51:27 by tguillem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_get_filename(char *path)
{
	char	*result;
	char	*tmp;
	int		length;

	result = path;
	tmp = ft_strstr(result, "/");
	while (tmp)
	{
		length = ft_strlen(tmp) + 1;
		result = &result[ft_strlen(result) - length + 2];
		tmp = ft_strstr(result, "/");
	}
	return (result);
}
