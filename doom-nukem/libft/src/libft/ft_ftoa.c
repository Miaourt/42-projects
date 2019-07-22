/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ftoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llaporte <llaporte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/07 13:23:59 by tcourtil          #+#    #+#             */
/*   Updated: 2019/02/05 13:50:23 by llaporte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char		*getmat(unsigned int mat, char *nb2)
{
	char			*res;
	char			*nb;
	char			*t;
	int				i;
	unsigned int	tmp;

	res = ft_memset(ft_strnew(256), '0', 256);
	nb = ft_memset(ft_strnew(256), '0', 256);
	nb[63] = '1';
	res[63] = '1';
	i = -1;
	while (++i < 23)
	{
		t = ft_strnbdiv(nb, nb2, 256, 64);
		free(nb);
		nb = t;
		tmp = mat >> (22 - i);
		tmp = tmp & ((unsigned int)1);
		if (tmp)
			res = ft_strnbaddd(&res, &nb, 256, 1);
	}
	free(nb);
	return (res);
}

static char		*topow(int exp, char *man, char *nb)
{
	char	*res;
	int		i;
	char	*tmp;

	res = ft_memcpy(ft_strnew(256), man, 256);
	res[63] = '1';
	i = 0;
	while (i < ft_abs(exp))
	{
		tmp = res;
		if (exp >= 0)
			res = ft_strnbmul(res, nb, 256, 64);
		else
			res = ft_strnbdiv(res, nb, 256, 64);
		free(tmp);
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
	while (str[i] == '0' && i < 64)
		i++;
	size = 64 - i;
	res = ft_strnew(neg + pres + 1 + ft_max(1, size));
	if (size == 0)
		res[neg] = '0';
	if (neg)
		res[0] = '-';
	i--;
	while (++i < 64)
		res[neg + i - (64 - size)] = str[i];
	size = ft_max(size, 1) + neg;
	res[pres + 1 + size + neg] = '\0';
	res[size] = pres > 0 ? ',' : '\0';
	i = -1;
	while (++i < pres)
		res[i + size + 1] = i < 192 ? str[i + 64] : '0';
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
	nb = ft_memset(ft_strnew(256), '0', 256);
	while (pres + i < 192 && res[pres + i + 64] == '5')
		i++;
	if (pres + i < 192 && res[pres + i + 64] >= '5')
	{
		nb[63 + pres] = '1';
		res = ft_strnbaddd(&res, &nb, 256, 1);
	}
	free(nb);
	return (res);
}

char			*ft_ftoa(float f, size_t pres)
{
	unsigned int	mat;
	int				exp;
	char			*res;
	char			*nb;

	nb = ft_memset(ft_strnew(256), '0', 256);
	nb[63] = '2';
	res = NULL;
	mat = (*((unsigned int *)&f) << 9) >> 9;
	exp = (*((unsigned int *)&f) << 1) >> 24;
	exp -= 127;
	res = topow(exp, getmat(mat, nb), nb);
	res = toround(res, pres);
	free(nb);
	return (form(res, pres, f < 0));
}
