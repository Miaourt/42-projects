# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: llaporte <llaporte@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/12/05 00:06:55 by llaporte          #+#    #+#              #
#    Updated: 2018/03/18 03:19:34 by llaporte         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := ../asm

LIBFT := ../libft
LIBFT_A=../libft/libft.a

SRCDIR := srcs
SRC := 	assembler.c \
		parser.c \
		parser_utils.c \
		parser_comment_or_name.c \
		parser_label.c \
		op.c \
		encoder.c \
		free.c \
		encoder_utils.c \
		offset.c \
		overflow.c \


CFLAGS = -Wextra -Wall -Werror -march=native -Iincludes -I$(LIBFT)

SRCS := $(addprefix $(SRCDIR)/checker, $(SRC))

OBJ = $(SRC:.c=.o)

all: $(NAME)

%.o: $(SRCDIR)/%.c
	@echo "Compiling $@"
	@gcc $(CFLAGS) -c $< -o $@

$(LIBFT_A):
	@make -C $(LIBFT)

$(NAME): $(LIBFT_A) $(OBJ)
	@echo "Create $(NAME)..."
	@gcc $(CFLAGS) $(OBJ) -o $(NAME) -L./$(LIBFT) -lft
	@echo "\x1b[32;01mDone !\x1b[0m"

clean:
	@rm -f $(OBJ)

fclean: clean
	@rm -f $(NAME)

.PHONY: clean fclean re

re: fclean all
