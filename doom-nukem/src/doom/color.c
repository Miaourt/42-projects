/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcourtil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/08 16:30:16 by tcourtil          #+#    #+#             */
/*   Updated: 2019/04/03 15:57:59 by tcourtil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static int	red(int c1, int c2, double per)
{
	int		tc1;
	int		tc2;
	int		res;
	double	cc;

	tc1 = (c1 & 0x00FF0000) >> 16;
	tc2 = (c2 & 0x00FF0000) >> 16;
	tc2 -= tc1;
	cc = tc2;
	cc *= per;
	tc2 = cc;
	tc2 += tc1;
	res = tc2;
	res = ((int)res) << 8;
	return (res);
}

static int	green(int c1, int c2, int r, double per)
{
	int		res;
	int		tmpc;
	int		tmpc2;
	double	cc;

	res = r;
	tmpc = (c1 & 0x0000FF00) >> 8;
	tmpc2 = (c2 & 0x0000FF00) >> 8;
	tmpc2 -= tmpc;
	cc = tmpc2;
	cc *= per;
	tmpc2 = cc;
	tmpc2 += tmpc;
	res += tmpc2;
	res = res << 8;
	return (res);
}

static int	blue(int c1, int c2, int r, double per)
{
	int		res;
	int		tmpc;
	int		tmpc2;
	double	cc;

	res = r;
	tmpc = (c1 & 0x000000FF);
	tmpc2 = (c2 & 0x000000FF);
	tmpc2 -= tmpc;
	cc = tmpc2;
	cc *= per;
	tmpc2 = cc;
	tmpc2 += tmpc;
	res += tmpc2;
	return (res);
}

int			lerp(int c1, int c2, double per)
{
	int	res;

	res = red(c1, c2, per);
	res = green(c1, c2, res, per);
	res = blue(c1, c2, res, per);
	return (res);
}
