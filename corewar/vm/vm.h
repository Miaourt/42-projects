/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tguillem <tguillem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/13 13:34:48 by tguillem          #+#    #+#             */
/*   Updated: 2018/03/19 17:19:46 by tguillem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VM_H
# define VM_H
# include "libft.h"
# include "op.h"
# include <stdint.h>
# include <fcntl.h>

typedef struct			s_program
{
	t_header			*header;
	uint8_t				*code;
	int32_t				id;
	int32_t				has_arbitrary_id;
}						t_program;

typedef struct			s_vm
{
	int					players_expected;
	int					players_count;
	t_array				*prg_contexts;
	uint32_t			next_pid;
	uint8_t				*memory;
	int32_t				current_cycle;
	int32_t				max_cycles;
	int32_t				next_die;
	int32_t				cycles_to_die;
	t_array				*processes;
	uint32_t			lives;
	uint32_t			check_count;
}						t_vm;

typedef struct			s_program_context
{
	int32_t				id;
	int					alive;
	int32_t				last_live;
	t_program			*program;
}						t_program_context;

typedef struct			s_process_context
{
	uint32_t			registers[REG_NUMBER];
	int					carry;
	uint8_t				*entry_point;
	t_program_context	*program_context;
	uint32_t			pid;
	uint32_t			pc;
	uint32_t			inst_pos;
	int32_t				last_live;
	t_op				*current_instruction;
	int					freeze;
}						t_process_context;

typedef struct			s_op_data
{
	uint8_t				param_pcodes[MAX_ARGS_NUMBER];
	int32_t				params[MAX_ARGS_NUMBER];
}						t_op_data;

typedef struct			s_options
{
	t_array				*champions;
	uint32_t			dump_cycles;
}						t_options;

char					*get_file_content(const char *path, off_t *size);
t_program				*load_program(char *path);
void					destroy_program(void *data);
t_vm					*create_vm(int32_t players_expected,
	int32_t max_cycles);
t_program_context		*load_vm_program(t_vm *vm, t_program *prg);
t_process_context		*create_process(t_vm *vm_ctx,
	t_program_context *prg_ctx, uint32_t pc);
void					fork_process(t_vm *vm_ctx, t_process_context *proc_ctx,
	int16_t offset, int long_mode);

void					destroy_vn(t_vm *vm);
int						corewar_is_dead_end(t_vm *ctx);
void					swap_uint32(uint32_t *data);
int32_t					swap_int32(int32_t val);
void					swap_uint16(uint16_t *data);
void					process_read(t_process_context *ctx, void *ptr,
	size_t size);
void					process_memory_read(t_process_context *ctx,
	uint32_t pos, void *ptr, size_t size);
void					process_memory_write(t_process_context *ctx,
	uint32_t pos, void *ptr, size_t size);
t_op					*decode_instruction(t_process_context *ctx);
int						decode_params(t_process_context *ctx, t_op_data *data);
void					vm_exec_inst(t_vm *vm, t_process_context *ctx);
int						is_register(t_process_context *ctx, t_op_data *data,
	int index);
int						is_indirect(t_process_context *ctx, t_op_data *data,
	int index);
int32_t					*get_register(t_process_context *ctx, t_op_data *data,
	int index);
int32_t					get_value(t_process_context *ctx, t_op_data *data,
	int index);
void					op_aff(t_vm *vm, t_process_context *ctx,
	t_op_data *data);
void					op_ld(t_vm *vm, t_process_context *ctx,
	t_op_data *data);
void					op_st(t_vm *vm, t_process_context *ctx,
	t_op_data *data);
void					op_add(t_vm *vm, t_process_context *ctx,
	t_op_data *data);
void					op_sub(t_vm *vm, t_process_context *ctx,
	t_op_data *data);
void					op_and(t_vm *vm, t_process_context *ctx,
	t_op_data *data);
void					op_or(t_vm *vm, t_process_context *ctx,
	t_op_data *data);
void					op_xor(t_vm *vm, t_process_context *ctx,
	t_op_data *data);
void					op_lld(t_vm *vm, t_process_context *ctx,
	t_op_data *data);
void					op_ldi(t_vm *vm, t_process_context *ctx,
	t_op_data *data);
void					op_sti(t_vm *vm, t_process_context *ctx,
	t_op_data *data);
void					op_lldi(t_vm *vm, t_process_context *ctx,
	t_op_data *data);
void					op_zjmp(t_vm *vm, t_process_context *ctx,
	t_op_data *data);
void					op_fork(t_vm *vm, t_process_context *ctx,
	t_op_data *data);
void					op_lfork(t_vm *vm, t_process_context *ctx,
	t_op_data *data);
void					op_live(t_vm *vm, t_process_context *ctx,
	t_op_data *data);
void					dump_vm(t_vm *vm);
int						corewar_cycle(t_vm *ctx);
void					corewar_live(t_vm *vm, int32_t program_id,
	t_process_context *process);
void					corewar_ending(t_vm *ctx);
t_array					*array_reverse_init(t_array *root, void *data);
int						is_valid_number(const char *nbr, int min_limit);
int						execute_corewar(int ac, char **av);
t_array					*sort_champions(t_array *lst);
t_options				*destroy_options(t_options *options);
t_options				*get_options(int ac, char **av);
t_array					*reorder_champions(t_array *champions);
int						is_conflicting_id(t_array *champions, int32_t id);
void					dump_registers(t_process_context *ctx);

#endif
