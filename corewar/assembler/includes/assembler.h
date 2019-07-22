/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assembler.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthuilli <dthuilli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/10/04 11:33:27 by zaz               #+#    #+#             */
/*   Updated: 2018/03/17 17:47:40 by dthuilli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ASSEMBLER_H
# define ASSEMBLER_H

# include "op.h"
# include "libft.h"
# include <fcntl.h>
# include <errno.h>

# define ARG_DIR				1
# define ARG_IND				2
# define ARG_REG				3
# define ARG_LDIR				4
# define ARG_LIND				5

typedef struct s_label	t_label;

struct					s_label
{
	int					id;
	char				*name;
	uint32_t			offset;
	int					is_def;
	t_label				*next;
};

typedef struct			s_arg
{
	char				*raw;
	int					type;
	long				value;
	t_label				*label;
	int					nb_bytes;

}						t_arg;

typedef struct s_ops	t_ops;

struct					s_ops
{
	t_op				*op;
	t_arg				*args[MAX_ARGS_NUMBER];
	t_ops				*next;

};

typedef struct			s_champ
{
	char				*name;
	char				*comment;
	t_label				*labels;
	t_ops				*ops;
	uint32_t			offset;
	t_header			header;
	char				*data;
}						t_champ;

/*
**** Functions
*/
/*
** Parser
*/
int						parse(char *buffer, t_champ *champ);
int						is_op(char *buffer, t_champ *champ);
int						check_params(char *buffer, t_champ *champ, t_op *op);
t_ops					*new_ops(t_op *op, t_champ *champ);
/*
** Parser_label
*/
t_label					*parse_label(char *buffer, t_champ *champ);
int						add_label(char *buffer, t_champ *champ, int label_size);
int						valid_labels(t_label *labels);
int						is_label(char *buffer);
int						is_instring(char c, char *src_string);

int						which_arg(char *buffer);
int						which_type(int type);
int						strcmps(char *compare, char *ref, int size);
int						is_overflow(char *str, long value, int neg);
void					define_label(t_label *label, t_champ *champ);

/*
** Parser_comment_or_name
*/
int						parse_nameorcomment(char *buffer, t_champ *champ);

/*
** Offset
*/
void					add_offset(t_champ *champ);

/*
** Encoder
*/
int						encode(t_champ *champ, char *file_name);

t_ops					*reverse_ops(t_ops *ops);
char					*get_output_name(char *path);

/*
** Free
*/
void					free_struct(t_champ *champ);
void					free_labels(t_label *labels);
void					free_ops(t_ops *ops);

/*
** Utils
*/
void					*s_malloc(size_t size);
void					err(char *error, t_champ *champ);
long					ft_atol(char *nptr);
unsigned short			swap_ushort(unsigned short lt);
#endif
