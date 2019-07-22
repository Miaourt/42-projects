/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tguillem <tguillem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/10/04 11:33:27 by zaz               #+#    #+#             */
/*   Updated: 2018/02/19 15:57:21 by tguillem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OP_H
# define OP_H
# define IND_SIZE				2
# define REG_SIZE				4
# define DIR_SIZE				REG_SIZE
# define REG_CODE				1
# define DIR_CODE				2
# define IND_CODE				3
# define MAX_ARGS_NUMBER		4
# define MAX_PLAYERS			4
# define MEM_SIZE				(4*1024)
# define IDX_MOD				(MEM_SIZE / 8)
# define CHAMP_MAX_SIZE			(MEM_SIZE / 6)
# define COMMENT_CHAR			'#'
# define LABEL_CHAR				':'
# define DIRECT_CHAR			'%'
# define SEPARATOR_CHAR			','
# define LABEL_CHARS			"abcdefghijklmnopqrstuvwxyz_0123456789"
# define NAME_CMD_STRING		".name"
# define COMMENT_CMD_STRING		".comment"
# define REG_NUMBER				16
# define CYCLE_TO_DIE			1536
# define CYCLE_DELTA			50
# define NBR_LIVE				21
# define MAX_CHECKS				10
# define T_REG					1
# define T_DIR					2
# define T_IND					4
# define T_LAB					8
# define PROG_NAME_LENGTH		(128)
# define COMMENT_LENGTH			(2048)
# define COREWAR_EXEC_MAGIC		0xea83f3

typedef struct s_vm					t_vm;
typedef struct s_process_context	t_process_context;
typedef struct s_op_data			t_op_data;
typedef void						(*t_op_handler)(t_vm *vm,
				t_process_context *ctx, t_op_data *data);

typedef struct						s_op
{
	char							*name;
	int								nb_params;
	unsigned int					param_types[4];
	int								opcode;
	int								nb_cycles;
	char							*desc;
	int								has_pcode;
	int								has_idx;
	t_op_handler					handle;
}									t_op;

typedef char						t_arg_type;

extern t_op							g_op_tab[17];

typedef struct						s_header
{
	unsigned int					magic;
	char							prog_name[PROG_NAME_LENGTH + 1];
	unsigned int					prog_size;
	char							comment[COMMENT_LENGTH + 1];
}									t_header;

#endif
