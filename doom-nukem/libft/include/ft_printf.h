/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcourtil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/16 15:22:57 by tcourtil          #+#    #+#             */
/*   Updated: 2018/12/17 15:41:03 by tcourtil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft.h"
# include <stdarg.h>

typedef struct	s_flag
{
	int			min;
	int			pres;
	int			haspres;
	int			left;
	int			sign;
	int			space;
	int			hexa;
	int			zero;
	int			flag;
	int			h;
	int			hh;
	int			l;
	int			ll;
	int			la;
}				t_flag;

int				get_params(const char *base, t_list *list, va_list *ap,
		t_flag *f);
int				csp_params(const char *base, t_list *list, va_list *ap,
		t_flag *f);
int				x_params(const char *base, t_list *list, va_list *ap,
		t_flag *f);
int				lx_params(const char *base, t_list *list, va_list *ap,
		t_flag *f);
int				llx_params(const char *base, t_list *list, va_list *ap,
		t_flag *f);
int				di_params(const char *base, t_list *list, va_list *ap,
		t_flag *f);
int				dih_params(const char *base, t_list *list, va_list *ap,
		t_flag *f);
int				o_params(const char *base, t_list *list, va_list *ap,
		t_flag *f);
int				oll_params(const char *base, t_list *list, va_list *ap,
		t_flag *f);
int				oh_params(const char *base, t_list *list, va_list *ap,
		t_flag *f);
int				ohh_params(const char *base, t_list *list, va_list *ap,
		t_flag *f);
int				u_params(const char *base, t_list *list, va_list *ap,
		t_flag *f);
int				f_params(const char *base, t_list *list, va_list *ap,
		t_flag *f);
int				get_flag(const char *base, t_list *list, va_list *ap,
		t_flag *f);

char			*get_bflags(const char *base, t_flag *f);
char			*get_b2flags(const char *base, t_flag *f);
char			*get_pres(const char *base, t_flag *f, va_list *ap);
char			*get_minchamp(const char *base, t_flag *f);
char			*get_lh(const char *base, t_flag *f);

int				mod_params(const char *base, t_list *list, t_flag *f);
int				color_params(const char *base, t_list *list);
int				getflags(const char *base, t_list *list, va_list *ap);
int				ft_printf(const char *format, ...);
void			format(t_list *list, char *arg, t_flag *f, size_t size);
void			formato(t_list *list, char *arg, t_flag *f);
void			formatp(t_list *list, char *arg, t_flag *f, char *base);
void			formatnb(t_list *list, char *arg, t_flag *f, int signe);
#endif
