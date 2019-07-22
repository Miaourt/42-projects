/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tguillem <tguillem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/04 14:56:21 by tguillem          #+#    #+#             */
/*   Updated: 2016/10/06 17:40:02 by tguillem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include "libft.h"
# include <unistd.h>
# include <stdarg.h>
# include <stdlib.h>
# include <inttypes.h>

typedef struct		s_pdata
{
	int				prefix;
	int				zero_pad;
	int				right_pad;
	int				force_sign;
	int				no_sign;
	int				got_width;
	int				got_accuracy;
	int				fd;
	unsigned int	width;
	unsigned int	accuracy;
	unsigned int	length;
}					t_pdata;

char				*ft_printf_parse_flags(char **format, t_pdata *data);
char				*ft_printf_parse_width(char **format, va_list *list,
		t_pdata *data);
char				*ft_printf_parse_accuracy(char **format, va_list *list,
		t_pdata *data);
char				*ft_printf_parse_length(char **format, t_pdata *data);
int					ft_printf(const char *format, ...);
int					ft_printf_fd(int fd, const char *format, ...);
int					ft_printf_fd_va(int fd, const char *format, va_list *args);
int					ft_error_msg(const char *format, ...);

int					internal_printf(const char *format, va_list *args,
		int length, int fd);
intmax_t			ft_printf_get_signed_from_length(va_list *args,
		t_pdata *data);
ssize_t				ft_printf_manage_wchar(char **format, va_list *args,
		t_pdata *data);
ssize_t				ft_printf_manage_char(char **format, va_list *args,
		t_pdata *data);
ssize_t				ft_printf_manage_str(char **format, va_list *args,
		t_pdata *data);
ssize_t				ft_printf_manage_wstr(char **format, va_list *args,
		t_pdata *data);
ssize_t				ft_printf_manage_long(char **format, va_list *args,
		t_pdata *data);
ssize_t				ft_printf_manage_long_bis(char **format, va_list *args,
		t_pdata *data);
ssize_t				ft_printf_manage_int(char **format, va_list *args,
		t_pdata *data);
ssize_t				ft_printf_manage_octal(char **format, va_list *args,
		t_pdata *data);
ssize_t				ft_printf_manage_hexa(char **format, va_list *args,
		t_pdata *data);
ssize_t				ft_printf_manage_ptr(char **format, va_list *args,
		t_pdata *data);
ssize_t				ft_printf_manage_percent(char **format, va_list *args,
		t_pdata *data);
ssize_t				ft_printf_manage_null(char **format, va_list *args,
		t_pdata *data);
ssize_t				ft_printf_nbrforceprefix(uintmax_t nbr, char *base,
		t_pdata *data, char *prefix);
ssize_t				ft_printfu(uintmax_t nbr, t_pdata *data, char *base,
		char *prefix);
typedef ssize_t		(*t_manager)(char**, va_list*, t_pdata*);
t_manager			*get_printf_managers();
t_manager			ft_printf_get_manager(char c);
uintmax_t			ft_printf_get_unsigned_from_length(va_list *datas,
		t_pdata *data);
unsigned int		ft_printf_maxstrlen(uintmax_t nbr, char *base, char *p,
		t_pdata *data);
unsigned int		ft_printf_nbrlen(uintmax_t nbr, char *base);
void				ft_printf_width_pad(int nbrstrlen, int width,
		char padwith, int fd);
#endif
