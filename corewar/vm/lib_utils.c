/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lib_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tguillem <tguillem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/17 15:38:29 by tguillem          #+#    #+#             */
/*   Updated: 2018/03/19 16:58:29 by tguillem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

t_array			*array_reverse_init(t_array *root, void *data)
{
	t_array		*result;

	if (!(result = (t_array*)malloc(sizeof(t_array))))
		return (NULL);
	result->data = data;
	result->next = root;
	return (result);
}

int				ft_isspace(int c)
{
	c = (unsigned char)c;
	if (c == '\t' || c == '\n' || c == '\v' || c == '\f' || c == '\r'
		|| c == ' ')
		return (1);
	return (0);
}

intmax_t		atom(const char *str)
{
	int			negate;
	intmax_t	rtn;
	intmax_t	i;

	rtn = 0;
	i = 0;
	negate = 0;
	while (ft_isspace(str[i]))
		i++;
	if (str[i] == '-')
		negate = 1;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i] && ft_isdigit(str[i]))
	{
		rtn *= 10;
		if (negate)
			rtn -= str[i] - 48;
		else
			rtn += str[i] - 48;
		i++;
	}
	return (rtn);
}

int				is_valid_number(const char *nbr, int min_limit)
{
	int			i;
	intmax_t	tmp;

	i = 0;
	if (nbr[0] == '-' && ft_strlen(nbr) > 11)
		return (0);
	if (nbr[0] != '-' && ft_strlen(nbr) > 10)
		return (0);
	tmp = atom(nbr);
	if (tmp > MAX || tmp < min_limit)
		return (0);
	while (nbr[i])
	{
		if ((nbr[i] >= '0' && nbr[i] <= '9') || (i == 0 && nbr[0] == '-'))
		{
			i++;
			continue ;
		}
		else
			return (0);
	}
	return (1);
}

t_options		*destroy_options(t_options *options)
{
	if (options->champions)
		destroy_array_custom(options->champions, destroy_program);
	free(options);
	return (NULL);
}
