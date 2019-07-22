# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: llaporte <llaporte@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/12/05 00:06:55 by llaporte          #+#    #+#              #
#    Updated: 2018/01/15 15:33:00 by llaporte         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := checker
NAME2 := push_swap

LIBFTDIR := libft

SRCDIR := srcs
SRC := 	checker.c \
		checks.c \
		operations.c \
		stack_utils.c \
		sort_utils.c \
		ft_explode.c \
		cleaner.c \
		bonus.c
SRC2 := push_swap.c \
		checks.c \
		operations.c \
		stack_utils.c \
		sort_utils.c \
		sort_merge.c \
		merge_utils.c \
		ft_explode.c \
		cleaner.c \
		bonus.c

SRCS := $(addprefix $(SRCDIR)/checker, $(SRC))

OBJ = $(SRC:.c=.o)
OBJ2 = $(SRC2:.c=.o)

%.o: $(SRCDIR)/%.c
	@echo "Compiling $@"
	@gcc -g -Wall -Wextra -Werror -I includes -c $< -o $@

all: $(NAME2) $(NAME)

$(NAME2): $(OBJ2)
	@make -C $(LIBFTDIR)
	@echo "Create $(NAME2)..."
	gcc -Wall -Wextra -Werror -Ofast $(OBJ2) $(LIBFTDIR)/libft.a -o $(NAME2)
	@echo "\x1b[32;01mDone !\x1b[0m"

$(NAME): $(OBJ)
	@make -C $(LIBFTDIR)
	@echo "Create $(NAME)..."
	gcc -Wall -Wextra -Werror -Ofast $(OBJ) $(LIBFTDIR)/libft.a -o $(NAME)
	@echo "\x1b[32;01mDone !\x1b[0m"

clean:
	rm -f $(OBJ) $(OBJ2)
	$(MAKE) -C $(LIBFTDIR) clean

fclean: clean
	rm -f $(NAME) $(NAME2)
	$(MAKE) -C $(LIBFTDIR) fclean

re: fclean all
