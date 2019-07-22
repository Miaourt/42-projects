/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llaporte <llaporte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/05 04:53:39 by llaporte          #+#    #+#             */
/*   Updated: 2018/01/11 11:55:05 by llaporte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H

# define PUSH_SWAP_H
# define INT_MAX 2147483647
# define INT_MIN -2147483648

# include "libft.h"

typedef struct		s_value
{
	int				v;
	struct s_value	*next;
}					t_value;

typedef struct		s_stack
{
	t_value			*a;
	t_value			*b;
	t_value			*end_a;
	t_value			*end_b;
	int				verbose;
}					t_stack;

int					check_input(t_stack *stacks, int ac, char **av);
int					check_if_already_here(t_value *stack, t_value *cursor);
t_value				*create_stack(t_stack *stacks, int ac, char **av);
int					set_ends(t_stack *stacks);
int					is_stack_sorted(t_value *stack);
int					is_sorted(t_stack *stacks);
t_value				*get_max(t_value *stack);
t_value				*get_min(t_value *stack);
int					stack_len(t_value *stack);
void				displayer(t_stack	*stacks);
void				verbosify(t_stack *stacks, int argc, char **argv);
void				push_s(t_stack *stacks, char mode);
void				push_p(t_stack *stacks, char mode);
void				push_r(t_stack *stacks, char mode);
void				push_rr(t_stack *stacks, char mode);
int					do_op(char *op, t_stack *stacks);
void				push_op(char *op, t_stack *stacks);
int					nb_arg(int argc);
int					contain_value(int data, int *array, int len);
void				merge_swap(t_stack *stacks, int pos, int old_min);
int					is_smallest(t_value *src, t_value *cmp);
int					is_biggest(t_value *stack, int n, int min);
void				order_stacks(t_stack *stacks, int min);
void				rotation_selector(t_stack *stacks);
void				rotation_chooser(t_stack *stacks, int min);
int					get_biggest(t_value *stack, int *array, int len, int pos);
int					operation(t_stack	*stacks);
char				**ft_explode(char const *s);
int					ft_atoi_free(char *str);
void				cleaner(t_stack *stacks);
int					ft_atoi_free(char *str);
int					free_exploded(char **str);

#endif
