/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lib.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcourtil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/06 16:23:03 by tcourtil          #+#    #+#             */
/*   Updated: 2019/03/07 14:52:48 by tcourtil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIB_H
# define LIB_H

# define DICO_SIZE 10000
# define ARRAY_SIZE 1024

# include "string.h"
# include <stdlib.h>

typedef struct		s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}					t_list;

typedef struct		s_page
{
	char			*key;
	void			*content;
}					t_page;

typedef struct		s_dico
{
	t_list			**list;
	t_list			*keys;
}					t_dico;

typedef struct		s_array
{
	t_list			*list;
	unsigned int	length;
}					t_array;

t_array				*ft_arraynew();
void				ft_arrayfree(t_array *a);
void				ft_arrayadd(t_array *a, void *content);
void				ft_arrayfor(t_array *a, void (*loop)
		(unsigned int, void *, void *), void *inf);
void				ft_arrayext(t_array *a);
void				*ft_arrayget(t_array *c, size_t pos);
void				ft_arrayrem(t_array *c, size_t pos);
t_array				*ft_arrayclone(t_array *base);

t_dico				*ft_diconew();
int					ft_keyvalue(const char *key);
void				ft_dicoput(t_dico *dico, char *k, void *content);
void				*ft_dicoget(t_dico *dico, char *k);
int					ft_dicohaskey(t_dico *dico, char *k);
void				ft_dicofreewith(t_dico *d, void (*clean)(void *));
void				ft_dicofree(t_dico *d);

float				ft_floor(float f);
double				ft_ceil(double f);
double				ft_round(double f);
int					ft_abs(int n);
char				*ft_ftoa(float f, size_t pres);
char				*ft_dtoa(double f, size_t pres);
double				ft_atof(const char *f);
int					ft_pow(int x, int p);
double				ft_min(double a, double b);
double				ft_max(double a, double b);
double				ft_clamp(double v, double in, double max);
char				*ft_convert(unsigned long n, char *base);

int					ft_lstsize(const t_list *l);
t_list				*ft_lstnew(void const *content, size_t cs);
void				ft_lstdelone(t_list **alst, void (*del)(void *, size_t));
void				ft_lstdel(t_list **alst, void (*del)(void *, size_t));
void				ft_lstdelwith(t_list **alst, void (*del)(void *));
void				ft_lstdelallwith(t_list **alst, void (*del)(void *));
void				ft_lstadd(t_list **alst, t_list *new);
void				ft_lstiter(t_list *lst, void (*f)(t_list *elem));
t_list				*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));
void				ft_lstadde(t_list **lst, t_list *new);
int					ft_strpbrki(const char *base, const char *str);
void				ft_lstdelall(t_list **alst);
char				*ft_strnbadd(char *nb1, char *nb2, size_t size);
char				*ft_strnbrem(char *nb1, char *nb2, size_t size);
char				*ft_strnbaddd(char **nb1, char **nb2, size_t s, size_t de);
char				*ft_strnbremd(char **nb1, char **nb2, size_t s, size_t de);
char				*ft_strnbdiv(char *nb1, char *nb2, size_t size, size_t vir);
char				*ft_strnbmul(char *nb1, char *nb2, size_t size, size_t vir);

void				*ft_memalloc(size_t size);
void				ft_memdel(void **ap);
char				*ft_strnew(size_t size);
void				ft_strdel(char **as);
void				ft_strclr(char *s);
void				ft_striter(char *s, void (*f)(char *));
void				ft_striteri(char *s, void (*f)(unsigned int, char *));
char				*ft_strmap(char *s, char (*f)(char));
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
int					ft_strequ(char const *s1, char const *s2);
int					ft_strnequ(char const *s1, char const *s2, size_t n);
char				*ft_strsub(char const *s, unsigned int start, size_t len);
char				*ft_strjoin(char const *s1, char const *s2);
char				*ft_strtrim(char const *s);
char				**ft_strsplit(char const *s, char c);
char				*ft_itoa(long long n);
char				*ft_utoa(unsigned long long n);
void				ft_putchar(char c);
void				ft_putstr(char const *s);
void				ft_putendl(char const *s);
void				ft_putnbr(int n);
void				ft_putchar_fd(char c, int fd);
void				ft_putstr_fd(char const *s, int fd);
void				ft_putendl_fd(char const *s, int fd);
void				ft_putnbr_fd(int n, int fd);

void				*ft_memset(void *s, int c, size_t n);
void				ft_bzero(void *s, size_t n);
void				*ft_memcpy(void *dest, const void *str, size_t n);
void				*ft_memccpy(void *dest, const void *str, int c, size_t n);
void				*ft_memmove(void *dest, const void *str, size_t n);
void				*ft_memchr(const void *s, int c, size_t n);
int					ft_memcmp(const void *s1, const void *s2, size_t n);
size_t				ft_strlen(const char *str);
char				*ft_strdup(const char *str);
char				*ft_strcpy(char *dest, const char *src);
char				*ft_strncpy(char *dest, const char *src, size_t n);
char				*ft_strcat(char *dest, const char *src);
char				*ft_strncat(char *dest, const char *src, size_t n);
size_t				ft_strlcat(char *dest, const char *src, size_t n);
char				*ft_strchr(const char *s, int c);
char				*ft_strrchr(const char *s, int c);
char				*ft_strstr(const char *base, const char *str);
char				*ft_strnstr(const char *base, const char *str, size_t len);
int					ft_strcmp(const char *str1, const char *str2);
int					ft_strncmp(const char *str1, const char *str2, size_t len);
int					ft_atoi(const char *nb);
int					ft_tolower(int c);
int					ft_toupper(int c);
int					ft_isprint(int c);
int					ft_isascii(int c);
int					ft_isalpha(int c);
int					ft_isdigit(int c);
int					ft_isalnum(int c);

#endif
