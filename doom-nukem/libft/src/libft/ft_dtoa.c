/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dtoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llaporte <llaporte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/07 13:23:59 by tcourtil          #+#    #+#             */
/*   Updated: 2019/02/05 13:50:54 by llaporte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char		*getmat(unsigned long mat, char *nb2)
{
	char			*res;
	char			*nb;
	char			*t;
	int				i;
	unsigned long	tmp;

	res = ft_memset(ft_strnew(1024), '0', 1024);
	nb = ft_memset(ft_strnew(1024), '0', 1024);
	nb[511] = '1';
	res[511] = '1';
	i = -1;
	while (++i < 52)
	{
		t = ft_strnbdiv(nb, nb2, 1024, 512);
		free(nb);
		nb = t;
		tmp = mat >> (51 - i);
		tmp = tmp & ((unsigned long)1);
		if (tmp)
			res = ft_strnbaddd(&res, &nb, 1024, 1);
	}
	free(nb);
	return (res);
}

static char		*topow(int exp, char *man, char *nb)
{
	char	*res;
	int		i;
	char	*tmp;

	res = ft_memcpy(ft_strnew(1024), man, 1024);
	res[511] = '1';
	i = 0;
	while (i < ft_abs(exp))
	{
		if (exp >= 0)
			tmp = ft_strnbmul(res, nb, 1024, 512);
		else
			tmp = ft_strnbdiv(res, nb, 1024, 512);
		free(res);
		res = tmp;
		i++;
	}
	free(man);
	return (res);
}

static char		*form(char *str, size_t pres, int neg)
{
	char		*res;
	size_t		size;
	size_t		i;

	i = 0;
	while (str[i] == '0' && i < 512)
		i++;
	size = 512 - i;
	res = ft_strnew(neg + pres + 1 + ft_max(1, size));
	if (size == 0)
		res[neg] = '0';
	if (neg)
		res[0] = '-';
	i--;
	while (++i < 512)
		res[neg + i - (512 - size)] = str[i];
	size = ft_max(size, 1) + neg;
	res[pres + 1 + size + neg] = '\0';
	res[size] = pres > 0 ? ',' : '\0';
	i = -1;
	while (++i < pres)
		res[i + size + 1] = i < 512 ? str[i + 512] : '0';
	free(str);
	return (res);
}

static char		*toround(char *str, int pres)
{
	char	*res;
	char	*nb;
	int		i;

	res = str;
	i = 0;
	nb = ft_memset(ft_strnew(1024), '0', 1024);
	while (pres + i < 512 && res[pres + i + 512] == '5')
		i++;
	if (pres + i < 512 && res[pres + i + 512] >= '5')
	{
		nb[511 + pres] = '1';
		res = ft_strnbaddd(&res, &nb, 1024, 1);
	}
	free(nb);
	return (res);
}

char			*ft_dtoa(double f, size_t pres)
{
	unsigned long	mat;
	unsigned long	exp;
	char			*res;
	char			*nb;

	nb = ft_memset(ft_strnew(1024), '0', 1024);
	nb[511] = '2';
	res = NULL;
	mat = (*((unsigned long *)&f) << 12) >> 12;
	exp = (*((unsigned long *)&f) << 1) >> 53;
	exp -= 1023;
	res = topow(exp, getmat(mat, nb), nb);
	res = toround(res, pres);
	free(nb);
	return (form(res, pres, f < 0));
}
