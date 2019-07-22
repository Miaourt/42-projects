CFLAGS = -Werror -Wextra -Wall -march=native -I./ -I../libft
CC = gcc

NAME = ../corewar
LIBFT = ../libft
LIBFT_A=../libft/libft.a

SRCS = main.c vm_setup.c vm_primitive.c vm_exec.c vm_cycle.c process.c decoder.c op.c op_logical.c op_specials.c op_utils.c player_loader.c utils.c lib_utils.c corewar_init.c sort_array.c champions_utils.c
OBJ = $(SRCS:.c=.o)
REMOVE = $(OBJ)

all: $(NAME)

%.o : %.c
	@$(CC) $(CFLAGS) -o $@ -c $< $(PRGFLAGS)
	@echo "$<"

$(LIBFT_A):
	@make -C $(LIBFT)

$(NAME): $(LIBFT_A) $(OBJ)
	@echo "Create $(NAME)..."
	@$(CC) -g -o $@ $(OBJ) -L./$(LIBFT) -lft
	@echo "\x1b[32;01mDone !\x1b[0m"

clean:
	@/bin/rm -f $(REMOVE)

fclean: clean
	@/bin/rm -f $(NAME)

.PHONY: clean fclean re

re: fclean all
