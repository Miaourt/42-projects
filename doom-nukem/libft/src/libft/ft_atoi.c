/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcourtil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 18:26:55 by tcourtil          #+#    #+#             */
/*   Updated: 2018/11/15 12:59:06 by tcourtil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static long	get(long *neg, const char *str)
{
	long nb;
	long i;

	nb = 0;
	i = 0;
	while (str[i] == ' ' || str[i] == '\n' || str[i] == '\t' ||
			str[i] == '\v' || str[i] == '\r' || str[i] == '\f')
		i++;
	if (str[i] == '-')
	{
		*neg = 1;
		i++;
	}
	else if (str[i] == '+')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		if (nb > 922337203685477580)
			return (-2);
		nb *= 10;
		nb += str[i++] - '0';
	}
	return (nb);
}

int			ft_atoi(const char *str)
{
	long neg;
	long atoi;

	atoi = 0;
	neg = 0;
	atoi = get(&neg, str);
	if (atoi > 0)
	{
		if (neg == 1)
			return (-atoi);
		else
			return (atoi);
	}
	if (atoi == -2 && neg == 1)
		return (0);
	if (atoi == -2)
		return (-1);
	if (neg == 0)
		return (0);
	return (atoi);
}
