/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tguillem <tguillem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/23 12:49:44 by tguillem          #+#    #+#             */
/*   Updated: 2018/03/17 22:53:06 by tguillem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include "ft_string.h"
# include "maths/ft_vector.h"
# include "maths/ft_matrix.h"
# include "ft_time.h"
# include "ft_printf/ft_printf.h"

void				ft_putchar(char c);
void				ft_putstr(char const *s);
void				ft_putendl(char const *s);
void				ft_putnbr(int n);
void				ft_putchar_fd(char c, int fd);
void				ft_putstr_fd(char const *s, int fd);
void				ft_putendl_fd(char const *s, int fd);
void				ft_putnbr_fd(int n, int fd);
int					ft_tolower(int c);
int					ft_toupper(int c);
int					ft_isalpha(int c);
int					ft_isdigit(int c);
int					ft_isalnum(int c);
int					ft_isascii(int c);
int					ft_isprint(int c);
int					ft_isstralnum(char *str);
int					ft_isstrnum(char *str);

typedef struct		s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}					t_list;

t_list				*ft_lstnew(void const *content, size_t content_size);
void				ft_lstdelone(t_list **alst, void (*del)(void*, size_t));
void				ft_lstdel(t_list **alst, void (*del)(void *, size_t));
void				ft_lstadd(t_list **alst, t_list *new);
void				ft_lstiter(t_list *lst, void (*f)(t_list *));
t_list				*ft_lstmap(t_list *lst, t_list *(*f)(t_list *));
t_list				*ft_lstget(t_list *lst, void *data, size_t data_size);
size_t				ft_lstsize(t_list *lst);
int					ft_iswhitespace(int c);
int					ft_isblank(int c);
int					ft_islower(int c);
int					ft_isupper(int c);
int					ft_isxdigit(int c);
int					ft_iscntrl(int c);
int					ft_max(int x, int y);
int					ft_min(int x, int y);
void				ft_putnbrbase(uintmax_t nbr, char *base);
void				ft_putnbrbase_fd(uintmax_t nbr, char *base, int fd);
size_t				ft_wstrlen(wchar_t *str);
void				ft_putwchar(wchar_t chr);
void				ft_putwchar_fd(wchar_t chr, int fd);
void				ft_putwstr(wchar_t *strr);
void				ft_putwstr_fd(wchar_t *strr, int fd);
int					ft_count_digit(long value, int base);

typedef struct		s_buff
{
	int				fd;
	char			*buff;
	struct s_buff	*next;
}					t_buff;

t_buff				**get_gnl_buffer();
int					get_next_line(int const fd, char **line);
int					ft_parse_args(int ac, char **av, void *data,
						int (*compute_options)(void*, char*));
int					ft_usage(char *prg_name, char *usage, char illegal_char);
char				*ft_error_return(char *str, char *code);
char				*ft_get_filename(char *path);
char				**ft_strsplitcmp(char const *s, int (*f)(int c));
int					ft_error_retint(char *str, int code);

typedef struct		s_array
{
	void			*data;
	struct s_array	*next;
}					t_array;

typedef void		(*t_exit_cb)(void);

t_array				*array_init(t_array *root, void *data);
t_array				*array_dup(t_array *src);
t_array				*array_remove(t_array *root, t_array *to_delete,
	int free_elem);
unsigned int		array_size(t_array *array);
void				destroy_array(t_array *array);
void				destroy_array_custom(t_array *array,
	void (*free_func)(void*));
char				*ft_trim(char *src, char excluded);
int					is_le();
int					is_be();
unsigned short		swap_ushort(unsigned short lt);
short				swap_short(short lt);
int					swap_int(int lt);
unsigned			swap_uint(unsigned int lt);
void				resource_manager_destroy(void);
void				ft_atexit(void (*func)(void));
int					ft_prepare_exit(void);
void				ft_exit(int status);
#endif
